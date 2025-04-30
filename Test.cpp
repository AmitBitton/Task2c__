//amiteste.bitton@msmail.ariel.ac.il
// Created by amit on 4/24/25.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.h"

using namespace matrix;

TEST_CASE("Constructor") {
    SUBCASE("Valid size") {
        SquareMat mat(3);
        CHECK(mat.getSize() == 3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                CHECK(mat[i][j]== 0.0);
            }
        }
    }

    SUBCASE("Invalid size (negative)") {
        CHECK_THROWS_AS(SquareMat(-1), std::invalid_argument);
    }

    SUBCASE("Invalid size (zero)") {
        CHECK_THROWS_AS(SquareMat(0), std::invalid_argument);
    }
}

TEST_CASE("Copy Constructor") {
    SquareMat mat(2);
    mat[0][0] = 1.0;
    mat[1][1] = 5.0;
    SquareMat copy(mat);
    CHECK(copy.getSize() == mat.getSize());
    CHECK(copy[0][0] == mat[0][0]);
    CHECK(copy[1][1] == mat[1][1]);
}

TEST_CASE("Assignment Operator") {
    SquareMat mat(2);
    mat[0][0] = 11.0;
    mat[1][1] = 4.0;
    SquareMat copy(3);
    copy = mat;
    CHECK(copy.getSize() == mat.getSize());
    CHECK(copy[0][0] == mat[0][0]);
    CHECK(copy[1][1] == mat[1][1]);

}


TEST_CASE("Operator[]") {
    SquareMat mat(2);
    mat[0][0] = 3.0;
    CHECK(mat[0][0] == 3.0);

    SUBCASE("Out of bounds access") {
        CHECK_THROWS_AS(mat[4][0], std::invalid_argument);
        CHECK_THROWS_AS(mat[1][-5], std::invalid_argument);
        CHECK_THROWS_AS(mat[-1][0], std::invalid_argument);

    }
}

TEST_CASE("Addition Operator") {
    SquareMat mat1(2), mat2(2);
    mat1[0][0] = 11.5;
    mat2[0][0] = 22.5;
    SquareMat result = mat1 + mat2;
    CHECK(result[0][0] == 34.0);

    SUBCASE("Size mismatch") {
        SquareMat mat3(3);
        CHECK_THROWS_AS(mat1 + mat3, std::invalid_argument);
    }
}

TEST_CASE("Subtraction Operator") {
    SquareMat mat1(2), mat2(2);
    mat1[0][0] = 3.0;
    mat2[0][0] = 2.0;
    SquareMat result = mat1 - mat2;
    CHECK(result[0][0] == 1.0);

    SUBCASE("Size mismatch") {
        SquareMat mat3(8);
        CHECK_THROWS_AS(mat1 - mat3, std::invalid_argument);
    }
}

TEST_CASE("Unary Negation Operator") {
    SquareMat mat1(2);
    mat1[0][0] = 22.0;
    SquareMat result1 = -mat1;
    CHECK(result1[0][0] == -22.0);


    SquareMat mat2(2);
    mat2[0][0] = 22.0;
    mat2[0][1] = -5.0;
    mat2[1][0] = 0.0;
    mat2[1][1] = 10.0;
    SquareMat result2 = -mat2;
    CHECK(result2[0][0] == -22.0);
    CHECK(result2[0][1] == 5.0);
    CHECK(result2[1][0] == 0.0);
    CHECK(result2[1][1] == -10.0);

}

TEST_CASE("Multiplication Operator (Matrix * Matrix)") {
    SquareMat mat1(2), mat2(2);
    mat1[0][0] = 1.0;
    mat1[0][1] = 2.0;
    mat2[0][0] = 3.0;
    mat2[1][0] = 4.0;
    SquareMat result = mat1 * mat2;
    CHECK(result[0][0] == 11.0); // 1*3 + 2*4

    SUBCASE("Size mismatch") {
        SquareMat mat3(3);
        CHECK_THROWS_AS(mat1 * mat3, std::invalid_argument);
    }
}

TEST_CASE("Scalar Multiplication") {
    SquareMat mat(2);
    mat[0][0] = 22.0;
    mat[0][1] = -5.0;
    mat[1][1] = 0.0;
    SquareMat result = mat * 3.0;
    CHECK(result[0][0] == 66.0);

    SquareMat result2 = 3.0 * mat;
    CHECK(result2[0][0] == 66.0);

    SUBCASE("Negative scalar") {
        SquareMat result = mat * -2.0;
        CHECK(result[0][0] == -44.0);
        CHECK(result[0][1] == 10.0);
        CHECK(result[1][1] == 0.0);
    }

    SUBCASE("Zero scalar") {
        SquareMat result = mat * 0.0;
        CHECK(result[0][0] == 0.0);
        CHECK(result[0][1] == 0.0);
        CHECK(result[1][1] == 0.0);
    }
}

TEST_CASE("Element-wise Multiplication Operator (%)") {
    SquareMat mat1(3), mat2(3);
    mat1[0][0] = 2.0;
    mat1[0][1] = -3.0;
    mat1[1][0] = 0.0;
    mat2[0][0] = 3.0;
    mat2[0][1] = 4.0;
    mat2[1][0] = 5.0;
    SquareMat result = mat1 % mat2;
    CHECK(result[0][0] == 6.0);
    CHECK(result[0][1] == -12.0);
    CHECK(result[1][0] == 0.0);

    SUBCASE("Size mismatch") {
        SquareMat mat3(6);
        CHECK_THROWS_AS(mat1 % mat3, std::invalid_argument);
    }
}

TEST_CASE("Modulo Operator (%) with Scalar") {
    SquareMat mat1(2);
    mat1[0][0] = 5.0;
    SquareMat result1 = mat1 % 3;
    CHECK(result1[0][0] == 2.0);

    SquareMat mat2(3);
    mat2[0][0] = 3.0;
    SquareMat result2 = mat2 % 3;
    CHECK(result2[0][0] == 0.0);

    SquareMat mat3(3);
    mat3[0][0] = 22.5;
    SquareMat result3 = mat3 % 2;
    CHECK(result3[0][0] == doctest::Approx(0.5));

    SUBCASE("Modulo by zero") {
        CHECK_THROWS_AS(mat1 % 0, std::invalid_argument);
    }
}

TEST_CASE("Division by Scalar") {
    SquareMat mat(5);
    mat[0][0] = 6.0;
    mat[0][1] = -8.0;
    mat[1][0] = 0.0;

    SUBCASE("Positive scalar") {
        SquareMat result = mat / 2.0;
        CHECK(result[0][0] == 3.0);
        CHECK(result[0][1] == -4.0);
        CHECK(result[1][0] == 0.0);
    }

    SUBCASE("Negative scalar") {
        SquareMat result = mat / -2.0;
        CHECK(result[0][0] == -3.0);
        CHECK(result[0][1] == 4.0);
        CHECK(result[1][0] == 0.0);
    }

    SUBCASE("Division by zero") {
        CHECK_THROWS_AS(mat / 0.0, std::invalid_argument);
    }
}

TEST_CASE("Power Operator (^)") {
    SquareMat mat(2);
    mat[0][0] = 1.0;
    mat[0][1] = 1.0;
    mat[1][0] = 1.0;
    mat[1][1] = 1.0;
    SquareMat result = mat ^ 2;
    CHECK(result[0][0] == 2.0);

    SUBCASE("Zero exponent") {
        SquareMat identity = mat ^ 0;
        CHECK(identity[0][0] == 1.0);
        CHECK(identity[0][1] == 0.0);
        CHECK(identity[1][0] == 0.0);
        CHECK(identity[1][1] == 1.0);
    }

    SUBCASE("Negative exponent") {
        CHECK_THROWS_AS(mat ^ -1, std::invalid_argument);
    }
}

TEST_CASE("Pre/Post Increment/Decrement Operators") {
    SquareMat mat(2);
    mat[0][0] = 1.0;
    SquareMat preInc = ++mat;
    CHECK(preInc[0][0] == 2.0);
    CHECK(mat[0][0] == 2.0);

    SquareMat postInc = mat++;
    CHECK(postInc[0][0] == 2.0);
    CHECK(mat[0][0] == 3.0);

    SquareMat preDec = --mat;
    CHECK(preDec[0][0] == 2.0);
    CHECK(mat[0][0] == 2.0);

    SquareMat postDec = mat--;
    CHECK(postDec[0][0] == 2.0);
    CHECK(mat[0][0] == 1.0);
}

TEST_CASE("Transpose Operator (~)") {
    SquareMat mat(2);
    mat[0][1] = 5.5;
    SquareMat transposed = ~mat;
    CHECK(transposed[1][0] == 5.5);
}

TEST_CASE("Comparison Operators") {
    SquareMat mat1(2), mat2(2);
    mat1[0][0] = 1.0;
    mat2[0][0] = 2.0;
    CHECK(mat1 < mat2);
    CHECK(mat1 <= mat2);
    CHECK(mat2 > mat1);
    CHECK(mat2 >= mat1);
    CHECK(mat1 != mat2);
    mat2[0][0] = 1.0;
    CHECK(mat1 == mat2);

    SquareMat mat3(2), mat4(2);
    mat3[0][0] = 5.0;
    mat4[1][1] = 5.0;
    CHECK(mat3 == mat4);
}

TEST_CASE("Determinant Operator (!)") {

    SUBCASE("1x1 Matrix") {
        SquareMat mat1x1(1);
        mat1x1[0][0] = 5.0;
        CHECK(!mat1x1 == 5.0);
    }
    SUBCASE("2x2 Matrix") {
        SquareMat mat(2);
        mat[0][0] = 1.0;
        mat[0][1] = 2.0;
        mat[1][0] = 3.0;
        mat[1][1] = 4.0;
        CHECK(!mat == -2.0); // 1*4 - 2*3
    }
    SUBCASE("3x3 Matrix") {
        SquareMat mat(3);
        mat[0][0] = 6.0;
        mat[0][1] = 1.0;
        mat[0][2] = 1.0;
        mat[1][0] = 4.0;
        mat[1][1] = -2.0;
        mat[1][2] = 5.0;
        mat[2][0] = 2.0;
        mat[2][1] = 8.0;
        mat[2][2] = 7.0;

        CHECK(!mat == -306.0);
    }
}

TEST_CASE("Compound Assignment Operators") {
    SquareMat mat1(2), mat2(2);
    mat1[0][0] = 1.0;
    mat2[0][0] = 2.0;
    mat1 += mat2;
    CHECK(mat1[0][0] == 3.0);

    mat1 -= mat2;
    CHECK(mat1[0][0] == 1.0);

    mat1 *= 2.0;
    CHECK(mat1[0][0] == 2.0);

    mat1 /= 2.0;
    CHECK(mat1[0][0] == 1.0);

    mat1 %= mat2;
    CHECK(mat1[0][0] == 2.0);

    mat1 %= 3;
    CHECK(mat1[0][0] == 2.0);

    mat1 *= mat2;
    CHECK(mat1[0][0] == 4.0);
}

TEST_CASE("Output Operator") {
    SquareMat mat(2);
    mat[0][0] = 1.0;
    mat[0][1] = 2.0;
    mat[1][0] = 3.0;
    mat[1][1] = 4.0;
    std::ostringstream oss;
    oss << mat;
    CHECK(oss.str() == "[1  2 ] \n[3  4 ] ");
}