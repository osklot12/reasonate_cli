//
// Created by osklot12 on 1/22/25.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <ostream>
#include <stdexcept>
#include <type_traits>
#include <vector>

constexpr size_t DEFAULT_N_ROWS = 3;
constexpr size_t DEFAULT_N_COLS = 1;

namespace Math {
    template<typename T> requires std::is_arithmetic_v<T>
    class Matrix {
    public:
        // constructor with default dimensions
        Matrix() : m(DEFAULT_N_ROWS), n(DEFAULT_N_COLS), filler(T{}), data(m, std::vector<T>(n, filler)) {
        };

        // constructor with explicit dimensions and filler
        Matrix(size_t m_, size_t n_, T fill = T{}) : m(m_), n(n_), filler(fill) {
            if (m_ < 1 || n_ < 1) {
                throw std::invalid_argument("Dimensions must be greater than zero");
            }
            data = std::vector<std::vector<T> >(m_, std::vector<T>(n, fill));
        };

        // constructor with initializer list
        Matrix(std::initializer_list<std::initializer_list<T> > init_list)
            : m(init_list.size()), n(0), data() {
            if (init_list.size() == 0) {
                throw std::invalid_argument("Initializer list cannot be empty");
            }

            n = init_list.begin()->size();
            if (m > 0 && n == 0) {
                throw std::invalid_argument("Initializer list cannot have empty rows");
            }

            data.resize(m, std::vector<T>(n));

            size_t row = 0;
            for (const auto &row_list: init_list) {
                if (row_list.size() != n) {
                    throw std::invalid_argument("All rows must have the same number of entries");
                }
                data[row++] = std::vector<T>(row_list);
            }
        }

        // access a row using the [] operator
        std::vector<T> &operator[](size_t i) {
            return data[i];
        };

        // reads a row using the [] operator
        const std::vector<T> &operator[](size_t i) const {
            return data[i];
        };

        // safe access an entry
        T &at(size_t i, size_t j) {
            if (i >= m || j >= n) {
                throw std::out_of_range("Index out of range");
            }
            return data[i][j];
        }

        // safe read an entry
        const T &at(size_t i, size_t j) const {
            if (i >= m || j >= n) {
                throw std::out_of_range("Index out of range");
            }
            return data[i][j];
        }

        // compares matrices
        bool operator==(const Matrix &other) const {
            if (differ_dim(other)) {
                return false;
            }

            for (size_t i = 0; i < m; ++i) {
                for (size_t j = 0; j < n; ++j) {
                    if (data[i][j] != other.data[i][j]) return false;
                }
            }

            return true;
        }

        // adds a matrix to this one
        Matrix &operator+=(const Matrix &other) {
            return entry_arithmetic(*this, other, sum_entries);
        }

        // summing this matrix with another
        Matrix operator+(const Matrix &other) const {
            return entry_arithmetic(other, sum_entries);
        }

        // subtracts a matrix from this one
        Matrix &operator-=(const Matrix &other) {
            return entry_arithmetic(*this, other, subtract_entries);
        }

        // subtracts another matrix from this one
        Matrix operator-(const Matrix &other) const {
            return entry_arithmetic(other, subtract_entries);
        }

        // multiplies a matrix on this one
        Matrix &operator*=(const Matrix &other) {
            return *this = multiply(other);
        }

        // multiplies a matrix with this one
        Matrix operator*(const Matrix &other) {
            return multiply(other);
        }

        // scales this matrix by some scalar
        Matrix &operator*=(const T scalar) {
            for (size_t i = 0; i < rows(); ++i) {
                for (size_t j = 0; j < cols(); ++j) {
                    data[i][j] *= scalar;
                }
            }
            return *this;
        }

        // scales a copy of this matrix with some scalar
        Matrix operator*(const T scalar) const {
            Matrix result = *this;
            return result *= scalar;
        }

        // scales a copy of this matrix with some scalar in reverse order
        friend Matrix<T> operator*(const T scalar, const Matrix<T> &mat) {
            return mat * scalar;
        }

        // transpose matrix
        Matrix t() const {
            Matrix<T> result(n, m);
            for (size_t i = 0; i < m; ++i) {
                for (size_t j = 0; j < n; ++j) {
                    result.data[j][i] = data[i][j];
                }
            }
            return result;
        }

        // returns the number of rows
        [[nodiscard]] size_t rows() const {
            return m;
        }

        // returns the number of columns
        [[nodiscard]] size_t cols() const {
            return n;
        }

        // prints the matrix
        friend std::ostream &operator<<(std::ostream &out, const Matrix &mat) {
            for (size_t i = 0; i < mat.m; ++i) {
                for (size_t j = 0; j < mat.n; ++j) {
                    out << mat.data[i][j] << ",";
                    if (j < mat.n - 1) out << " ";
                }
                if (i < mat.m - 1) out << std::endl;
            }
            return out;
        }

    private:
        size_t m, n; // dimensions
        T filler;
        std::vector<std::vector<T> > data;

        // checks whether another matrix has different dimensions to this one
        bool differ_dim(const Matrix &other) const {
            return (m != other.m || n != other.n);
        }

        // handles differing dimension issues
        void ensure_same_dimensions(const Matrix &other) const {
            if (differ_dim(other)) {
                throw std::invalid_argument("Matrices must have same dimensions");
            }
        }

        // performs some arithmetic for each pair of entries in this and another matrix
        template<typename F>
        Matrix &entry_arithmetic(Matrix &result, const Matrix &other, F func) {
            ensure_same_dimensions(other);
            for (size_t i = 0; i < m; ++i) {
                for (size_t j = 0; j < n; ++j) {
                    result.data[i][j] = func(data[i][j], other.data[i][j]);
                }
            }
            return result;
        }

        // performs some arithmetic for each pair of entries in this and another matrix
        template<typename F>
        Matrix entry_arithmetic(const Matrix &other, F func) const {
            ensure_same_dimensions(other);
            Matrix result(m, n);
            for (size_t i = 0; i < m; ++i) {
                for (size_t j = 0; j < n; ++j) {
                    result.data[i][j] = func(data[i][j], other.data[i][j]);
                }
            }
            return result;
        }

        // sums two entries
        static constexpr auto sum_entries = [](T a, T b) {
            return a + b;
        };

        // subtracts two entries
        static constexpr auto subtract_entries = [](T a, T b) {
            return a - b;
        };

        // performs matrix multiplication
        Matrix multiply(const Matrix &other) const {
            if (n != other.m) {
                throw std::invalid_argument("Number of columns in matrix A must match number of rows in matrix B");
            }

            Matrix result{m, other.n};
            for (size_t i = 0; i < result.m; ++i) {
                for (size_t j = 0; j < result.n; ++j) {
                    result.data[i][j] = 0;
                    for (size_t k = 0; k < n; ++k) {
                        result.data[i][j] += data[i][k] * other.data[k][j];
                    }
                }
            }
            return result;
        }
    };
}

#endif //MATRIX_H
