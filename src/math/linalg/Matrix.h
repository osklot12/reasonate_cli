//
// Created by osklot12 on 12/5/24.
//

#ifndef REASONATE_CLI_MATRIX_H
#define REASONATE_CLI_MATRIX_H

#include <vector>
#include <stdexcept>

const size_t DEFAULT_N_ROWS = 3;
const size_t DEFAULT_N_COLS = 1;

template<typename T> requires std::is_arithmetic_v<T>
class Matrix {
public:
    // constructor with default dimensions
    Matrix() : n(DEFAULT_N_ROWS), m(DEFAULT_N_COLS), data(n, std::vector<T>(m, 0)) {};

    // constructor with explicit dimensions
    Matrix(size_t n_, size_t m_) : n(n_), m(m_) {
        if (n_ <= 0 || m_ <= 0) {
            throw std::invalid_argument("Dimensions must be greater than zero");
        }
        data = std::vector<std::vector<T>>(n, std::vector<T>(m, 0));
    };

    // constructor with initializer list
    Matrix(std::initializer_list<std::initializer_list<T>> init_list)
            : n(init_list.size()), m(0), data() {
        if (init_list.size() == 0) {
            throw std::invalid_argument("Initializer list cannot be empty");
        }

        m = init_list.begin() -> size();
        if (n > 0 && m == 0) {
            throw std::invalid_argument("Initializer list cannot have empty rows");
        }

        data.resize(n, std::vector<T>(m));

        size_t row = 0;
        for (const auto &row_list: init_list) {
            if (row_list.size() != m) {
                throw std::invalid_argument("All rows must have the same number of entries");
            }
            data[row++] = std::vector<T>(row_list);
        }
    }

    const std::vector<T> &operator[](size_t n_) const {
        return data[n_];
    };

    T &at(size_t n_, size_t m_) {
        if (n_ >= n || m_ >= m) {
            throw std::out_of_range("Index out of range");
        }

        return data[n_][m_];
    }

    const T &at(size_t n_, size_t m_) const {
        if (n < n_ || m < m_) {
            throw std::out_of_range("Index out of range");
        }

        return data[n_][m_];
    }

    bool operator==(const Matrix &other) const {
        if (n != other.n || m != other.m) {
            return false;
        }

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (data[i][j] != other.data[i][j]) return false;
            }
        }

        return true;
    }

    Matrix operator+=(const Matrix &other) {
        if (n != other.n || m != other.m) {
            throw std::invalid_argument("Matrices must have same dimensions");
        }

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return *this;
    }

    Matrix operator+(const Matrix &other) const {
        if (n != other.n || m != other.m) {
            throw std::invalid_argument("Matrices must have same dimensions");
        }

        Matrix result(n, m);
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                result.at(i, j) = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    size_t rows() const {
        return n;
    }

    size_t cols() const {
        return m;
    }
private:
    size_t n; // rows
    size_t m; // columns
    std::vector<std::vector<T>> data;
};


#endif //REASONATE_CLI_MATRIX_H
