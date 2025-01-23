//
// Created by osklot12 on 12/7/24.
//

#include <gtest/gtest.h>

#include "../math/linalg/Matrix.h"

// default constructor should succeed
TEST(matrix_test, default_constructor) {
    Math::Matrix<int> mat;

    int defaultValue = mat.at(0, 0);

    EXPECT_EQ(defaultValue, 0);
}


// constructing matrix with custom valid dimensions should succeed
TEST(matrix_test, dimension_constructor_success) {
    const size_t rows = 10;
    const size_t cols = 15;
    Math::Matrix<int> mat{rows, cols};

    size_t actual_rows = mat.rows();
    size_t actual_cols = mat.cols();

    EXPECT_EQ(actual_rows, rows);
    EXPECT_EQ(actual_cols, cols);
}

// constructing matrix with custom valid dimensions and custom filler should succeed
TEST(matrix_test, dimension_constructor_custom_fill_success) {
    const size_t rows = 10;
    const size_t cols = 15;
    const double fill = 3.6;
    Math::Matrix<double> mat{rows, cols, fill};

    double value = mat.at(3, 3);

    EXPECT_EQ(value, fill);
}

// constructing matrix with invalid dimensions should throw exception
TEST(matrix_test, dimension_constructor_invalid_dimensions) {
    const size_t rows = 0;
    const size_t cols = -5;

    EXPECT_THROW((Math::Matrix<int>{rows, cols}), std::invalid_argument);
}

// constructing matrix with valid initializer list should succeed
TEST(matrix_test, initializer_list_constructor_success) {
    const std::initializer_list<std::initializer_list<int> > entries = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Math::Matrix<int> mat{entries};

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
    const std::initializer_list<std::initializer_list<int> > entries = {
        {1, 2, 3},
        {4, 5},
        {7, 8, 9}
    };

    EXPECT_THROW(Math::Matrix<int>{entries}, std::invalid_argument);
}

// constructing matrix with empty rows should throw exception
TEST(matrix_test, initializer_list_constructor_empty_list) {
    EXPECT_THROW(Math::Matrix<int>{{}}, std::invalid_argument);
}

// index operator should return expected rows
TEST(matrix_test, index_operator) {
    const std::initializer_list<std::initializer_list<int> > entries = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Math::Matrix<int> mat{entries};
    const int n = 2;
    const int m = 2;

    const int value = mat[n][m];

    EXPECT_EQ(value, mat.at(n, m));
}

// at function with arguments out of range should throw exception
TEST(matrix_test, at_out_of_range) {
    Math::Matrix<int> mat{2, 2};

    EXPECT_THROW(mat.at(2, 2), std::out_of_range);
}

// equals operator for two equal matrices should return true
TEST(matrix_test, equals_operator_same_matrix) {
    Math::Matrix<int> mat1{
        {1, 2},
        {3, 4}
    };
    Math::Matrix<int> mat2{
        {1, 2},
        {3, 4}
    };

    bool equals = mat1 == mat2;

    EXPECT_TRUE(equals);
}

// equals operator for two different matrices should return false
TEST(matrix_test, equals_operator_different_matrices) {
    Math::Matrix<int> mat1{
        {1, 2},
        {3, 4}
    };
    Math::Matrix<int> mat2{
        {1, 2},
        {3, 0}
    };

    bool equals = mat1 == mat2;

    EXPECT_FALSE(equals);
}

// += operator for valid matrices should give expected result
TEST(matrix_test, plus_equal_operator_success) {
    Math::Matrix<int> mat1{
        {1, 2},
        {3, 4}
    };
    Math::Matrix<int> mat2{
        {5, 6},
        {7, 8}
    };
    Math::Matrix<int> result{
        {6, 8},
        {10, 12}
    };

    mat1 += mat2;

    EXPECT_EQ(mat1, result);
}

// += operator for matrices of different dimensions should throw exception
TEST(matrix_test, plus_equal_operator_inconsistent_matrices) {
    Math::Matrix<int> mat1{
        {1, 2},
        {3, 4}
    };
    Math::Matrix<int> mat2{
        {5, 6, 7},
        {8, 9, 10}
    };

    EXPECT_THROW(mat1 += mat2, std::invalid_argument);
}

// + operator for valid matrices should give expected result
TEST(matrix_test, plus_operator_success) {
    Math::Matrix<int> mat1{
        {1, 2},
        {3, 4}
    };
    Math::Matrix<int> mat2{
        {5, 6},
        {7, 8}
    };
    Math::Matrix<int> expected{
        {6, 8},
        {10, 12}
    };

    mat1 = mat1 + mat2;

    EXPECT_EQ(mat1, expected);
}

// + operator for matrices of different dimensions should throw exception
TEST(matrix_test, plus_operator_inconsistent_matrices) {
    Math::Matrix<int> mat1{
        {1, 2},
        {3, 4}
    };
    Math::Matrix<int> mat2{
        {5, 6, 7},
        {8, 9, 10}
    };

    EXPECT_THROW(mat1 + mat2, std::invalid_argument);
}

// square matrices multiplied together should yield expected result
TEST(matrix_test, multiply_square_matrices_success) {
    Math::Matrix<double> mat1{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Math::Matrix<double> mat2{
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    Math::Matrix<double> expected{
        {30, 24, 18},
        {84, 69, 54},
        {138, 114, 90}
    };

    mat1 *= mat2;

    EXPECT_EQ(mat1, expected);
}

// matrices with equal inner dimensions should give expected result
TEST(matrix_test, multiply_nonsquare_matrices_success) {
    Math::Matrix<int> mat1{
        {1, 2, 3},
        {4, 5, 6}
    };
    Math::Matrix<int> mat2{
        {1, 2},
        {3, 4},
        {5, 6}
    };
    Math::Matrix<int> expected{
        {22, 28},
        {49, 64}
    };

    auto result = mat1 * mat2;

    EXPECT_EQ(result, expected);
}

// a matrix times the identity matrix should be equal to itself
TEST(matrix_test, multiply_identity_matrix_success) {
    Math::Matrix<int> mat1{
        {1, 16, 8},
        {13, 4, 5},
        {10, 4, -2}
    };
    Math::Matrix<int> i{
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    auto result = mat1 * i;

    EXPECT_EQ(result, mat1);
}

// *= operator using a scalar should return expected result
TEST(matrix_test, scale_matrix_self_success) {
    const std::initializer_list<std::initializer_list<double> > entries{
        {1, 5},
        {8, 3}
    };
    Math::Matrix<double> mat1{entries};
    const double scalar = 3;

    mat1 *= scalar;

    for (size_t i = 0; i < mat1.rows(); ++i) {
        for (size_t j = 0; j < mat1.cols(); ++j) {
            ASSERT_EQ(mat1.at(i, j), entries.begin()[i].begin()[j] * scalar);
        }
    }
}

// * operator using a scalar should return expected result
TEST(matrix_test, scale_matrix_success) {
    const std::initializer_list<std::initializer_list<double> > entries{
        {17.5, 5.07},
        {8.7, 3.13}
    };
    Math::Matrix<double> mat1{entries};
    const double scalar = 3;

    const auto result = mat1 * scalar;

    for (size_t i = 0; i < result.rows(); ++i) {
        for (size_t j = 0; j < result.cols(); ++j) {
            ASSERT_EQ(result.at(i, j), entries.begin()[i].begin()[j] * scalar);
        }
    }
}

// * operator using a scalar in reverse order should return expected result
TEST(matrix_test, scale_matrix_reverse_order_success) {
    const std::initializer_list<std::initializer_list<double> > entries{
        {17.5, 5.07},
        {8.7, 3.13}
    };
    Math::Matrix<double> mat1{entries};
    const double scalar = 3;

    const auto result = scalar * mat1;

    for (size_t i = 0; i < result.rows(); ++i) {
        for (size_t j = 0; j < result.cols(); ++j) {
            ASSERT_EQ(result.at(i, j), entries.begin()[i].begin()[j] * scalar);
        }
    }
}

// transposing a matrix should yield expected result
TEST(matrix_test, transpose_success) {
    const Math::Matrix<int> mat{
        {1, 2},
        {3, 4},
        {5, 6}
    };
    const size_t rows = mat.rows();
    const size_t cols = mat.cols();
    const auto trans = mat.t();

    // expecting dimensions to swap
    ASSERT_EQ(rows, trans.cols());
    ASSERT_EQ(cols, trans.rows());

    // expecting rows to become columns
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            ASSERT_EQ(mat.at(i, j), trans.at(j, i));
        }
    }
}
