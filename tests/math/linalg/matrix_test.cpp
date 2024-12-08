//
// Created by osklot12 on 12/7/24.
//

#include <gtest/gtest.h>
#include <linalg/Matrix.h>

// default constructor should succeed
TEST(matrix_test, default_constructor) {
    Matrix<int> mat;

    int defaultValue = mat.at(0, 0);

    EXPECT_EQ(defaultValue, 0);
}


// constructing matrix with custom valid dimensions should succeed
TEST(matrix_test, dimension_constructor_success) {
    const size_t rows = 10;
    const size_t cols = 15;
    Matrix<int> mat(rows, cols);

    int actual_rows = mat.rows();
    int actual_cols = mat.cols();

    EXPECT_EQ(actual_rows, rows);
    EXPECT_EQ(actual_cols, cols);
}

// constructing matrix with invalid dimensions should throw exception
TEST(matrix_test, dimension_constructor_invalid_dimensions) {
    const size_t rows = 0;
    const size_t cols = -5;

    EXPECT_THROW(Matrix<int>(rows, cols), std::invalid_argument);
}

// constructing matrix with valid initializer list should succeed
TEST(matrix_test, initializer_list_constructor_success) {
    const std::initializer_list<std::initializer_list<int>> entries = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    Matrix<int> mat(entries);

    EXPECT_EQ(mat.rows(), entries.size());
    EXPECT_EQ(mat.cols(), entries.begin()->size());

    size_t row = 0;
    for (const auto &row_list: entries) {
        size_t col = 0;
        for (const auto &value: row_list) {
            EXPECT_EQ(mat.at(row, col), value)
                                << "Mismatch at (" << row << ", " << col << ")";
            ++col;
        }
        ++row;
    }
}

// constructing matrix with inconsistent rows in list should throw exception
TEST(matrix_test, initializer_list_constructor_inconsistent_rows) {
    const std::initializer_list<std::initializer_list<int>> entries = {
            {1, 2, 3},
            {4, 5},
            {7, 8, 9}
    };

    EXPECT_THROW(Matrix<int>{entries}, std::invalid_argument);
}

// constructing matrix with empty rows should throw exception
TEST(matrix_test, initializer_list_constructor_empty_list) {
    EXPECT_THROW(Matrix<int>{{}}, std::invalid_argument);
}

// index operator should return expected rows
TEST(matrix_test, index_operator) {
    const std::initializer_list<std::initializer_list<int>> entries = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    Matrix<int> mat(entries);
    const int n = 2;
    const int m = 2;

    const int value = mat[n][m];

    EXPECT_EQ(value, mat.at(n, m));
}

// at function with arguments out of range should throw exception
TEST(matrix_test, at_out_of_range) {
    Matrix<int> mat(2, 2);

    EXPECT_THROW(mat.at(2, 2), std::out_of_range);
}

// equals operator for two equal matrices should return true
TEST(matrix_test, equals_operator_same_matrix) {
    Matrix<int> mat1{
            {1, 2},
            {3, 4}
    };
    Matrix<int> mat2{
            {1, 2},
            {3, 4}
    };

    bool equals = mat1 == mat2;

    EXPECT_TRUE(equals);
}

// equals operator for two different matrices should return false
TEST(matrix_test, equals_operator_different_matrices) {
    Matrix<int> mat1{
            {1, 2},
            {3, 4}
    };
    Matrix<int> mat2{
            {1, 2},
            {3, 0}
    };

    bool equals = mat1 == mat2;

    EXPECT_FALSE(equals);
}

// += operator for valid matrices should give expected result
TEST(matrix_test, plus_equal_operator_success) {
    Matrix<int> mat1{
            {1, 2},
            {3, 4}
    };
    Matrix<int> mat2{
            {5, 6},
            {7, 8}
    };
    Matrix<int> result{
            {6,  8},
            {10, 12}
    };

    mat1 += mat2;

    EXPECT_EQ(mat1, result);
}

// += operator for matrices of different dimensions should throw exception
TEST(matrix_test, plus_equal_operator_inconsistent_matrices) {
    Matrix<int> mat1{
            {1, 2},
            {3, 4}
    };
    Matrix<int> mat2{
            {5, 6, 7},
            {8, 9, 10}
    };

    EXPECT_THROW(mat1 += mat2, std::invalid_argument);
}

// + operator for valid matrices should give expected result
TEST(matrix_test, plus_operator_success) {
    Matrix<int> mat1{
            {1, 2},
            {3, 4}
    };
    Matrix<int> mat2{
            {5, 6},
            {7, 8}
    };
    Matrix<int> result{
            {6,  8},
            {10, 12}
    };

    mat1 = mat1 + mat2;

    EXPECT_EQ(mat1, result);
}

// + operator for matrices of different dimensions should throw exception
TEST(matrix_test, plus_operator_inconsistent_matrices) {
    Matrix<int> mat1{
            {1, 2},
            {3, 4}
    };
    Matrix<int> mat2{
            {5, 6, 7},
            {8, 9, 10}
    };

    EXPECT_THROW(mat1 + mat2, std::invalid_argument);
}