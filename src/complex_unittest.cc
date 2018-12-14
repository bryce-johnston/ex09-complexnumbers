 // Copyright 2018, Allan Knight.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Allan Knight nor the names of other
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A unit tester for EX01-HelloWorld in CS140 at Santa Barbara City College.
//
// Author: ahknight@pipeline.sbcc.edu (Allan Knight)


// Includes for google test and the unit under test.

#include <climits>
#include <sstream>

#include "complex.h"
#include "gtest/gtest.h"
namespace {

// Tests edu::sbcc:cs140::Complex.

    using edu::vcccd::vc::csv13::Complex;

    using std::istringstream;
    using std::ostringstream;
    using std::string;

    using namespace ::testing_internal;

    typedef uint64_t uint;

    class ComplexNumbersTest : public ::testing::Test {
    protected:
        static const uint MAX_TESTED_SCORE = 20;
        static const uint MAX_OVERALL_SCORE = 25;
        static uint _testScore;

    protected:
        static void TearDownTestCase() {
            if (_testScore == MAX_TESTED_SCORE) {
                std::cout << std::endl << "Your unit test score is "
                          << _testScore << " out of "
                          << MAX_TESTED_SCORE << std::endl;
            } else {
                std::cout << "Your unit test score is "
                          << _testScore << " out of "
                          << MAX_TESTED_SCORE << " ("<< (int)(_testScore - MAX_TESTED_SCORE)
                          << ")" << std::endl;
            }

            std::cout << "The assignment is worth a total of " << MAX_OVERALL_SCORE
                      << " where the remaining points" << std::endl;
            std::cout << "comes from grading related to documentation, algorithms, and other"
                      << std::endl;
            std::cout << "criteria." << std::endl << std::endl;
        }
    };

    uint ComplexNumbersTest::_testScore = 0;

    TEST_F(ComplexNumbersTest, Identity) {
        // This test is named "Identity", it checks that the basic identity
        // complex number, i, has the correct values for real and imaginary
        // parts.
        ASSERT_EQ(0.0, Complex::i.getRealPart());
        ASSERT_EQ(1.0, Complex::i.getImaginaryPart());

        _testScore += 2;
    }

    TEST_F(ComplexNumbersTest, IdentityOperators) {
        // This test is named "IdentityOperators", it checks that the operators
        // all work for the identity complex number, i.
        ASSERT_EQ(Complex::i, Complex::i);
        ASSERT_NE(Complex(0), Complex::i);
        ASSERT_EQ(0.0, Complex::i - Complex::i);
        ASSERT_EQ(Complex(0.0, 2.0), Complex::i + Complex::i);
        ASSERT_EQ(-1.0, Complex::i * Complex::i);

        _testScore += 2;
    }

    TEST_F(ComplexNumbersTest, Common) {
        // This test is named "Common", it tests common complex numbers and that
        // the have the correct values for real and imaginary parts based on the
        // parameters passed to the constructor.
        Complex a( 1.0,  2.0);
        Complex b(-1.0);
        Complex c(0.0, 2.0);

        ASSERT_EQ(1.0, a.getRealPart());
        ASSERT_EQ(2.0, a.getImaginaryPart());
        ASSERT_EQ(-1.0, b.getRealPart());
        ASSERT_EQ(0.0, b.getImaginaryPart());
        ASSERT_EQ(0.0, c.getRealPart());
        ASSERT_EQ(2.0, c.getImaginaryPart());

        _testScore += 2;
    }

    TEST_F(ComplexNumbersTest, CommonArithmeticOperators) {
        // This test is named "CommonArithmethicOperators", it tests common complex
        // numbers with arithmetic operators +, -, * to make sure they compute the
        // correct results.
        Complex a(1.0, 1.0);
        Complex b(1.0);

        Complex sum1 = a + b;
        Complex dif1 = a - b;
        Complex dif2 = b - a;
        Complex mul1 = a * b;
        Complex mul2 = b * a;

        ASSERT_EQ(2.0, sum1.getRealPart());
        ASSERT_EQ(1.0, sum1.getImaginaryPart());
        ASSERT_EQ(0.0, dif1. getRealPart());
        ASSERT_EQ(1.0, dif1.getImaginaryPart());
        ASSERT_EQ(0.0, dif2.getRealPart());
        ASSERT_EQ(-1.0, dif2.getImaginaryPart());
        ASSERT_EQ(1.0, mul1.getRealPart());
        ASSERT_EQ(1.0, mul1.getImaginaryPart());
        ASSERT_EQ(1.0, mul2.getRealPart());
        ASSERT_EQ(1.0, mul2.getImaginaryPart());

        _testScore += 2;
    }

    TEST_F(ComplexNumbersTest, CommonRelationalOperators) {
        // This test is named "CommonRelationalOperators", it tests that
        // the relational operators work properly for common complex
        // numbers, that they produce the correct result.
        ASSERT_EQ(Complex::i, Complex::i);
        ASSERT_NE(Complex::i, 0.0);
        ASSERT_NE(0.0, Complex::i);

        Complex a(1.0, 2.0);
        Complex b(3.0, 2.0);

        ASSERT_EQ(a, a);
        ASSERT_EQ(b, b);
        ASSERT_NE(a, b);
        ASSERT_NE(b, a);

        _testScore + 2;
    }

    TEST_F(ComplexNumbersTest, IOOutput) {
        // This test is named "IOOutput", it tests that the output
        // created by calling the << operator is formatted as
        // specified in the assignment description.
        ostringstream out;
        out << Complex::i;

        ASSERT_EQ("i", out.str());

        out.seekp(ostringstream::beg);
        out << Complex(0.0, 0.0);

        ASSERT_EQ("0", out.str());

        _testScore += 1;

        out.seekp(ostringstream::beg);
        out << Complex(1.0, 1.0);

        ASSERT_EQ("1 + i", out.str());

        out.seekp(ostringstream::beg);
        out << Complex(2.0, -2.0);

        ASSERT_EQ("2 - 2i", out.str());

        out.seekp(ostringstream::beg);
        out << Complex(-1.1, -1.1);

        ASSERT_EQ("-1.1 - 1.1i", out.str());

        out.str("");
        out.seekp(ostringstream::beg);
        out << Complex(-1.0, 1.0);

        ASSERT_EQ("-1 + i", out.str());

        _testScore += 1;

        out.str("");
        out.seekp(ostringstream::beg);
        out << Complex(1.0, 0);

        ASSERT_EQ("1", out.str());

        out.seekp(ostringstream::beg);
        out << Complex(-1.0);

        ASSERT_EQ("-1", out.str());

        out.seekp(ostringstream::beg);
        out << Complex(0, -1.0);

        ASSERT_EQ("-i", out.str());

        _testScore += 1;
    }

    TEST_F(ComplexNumbersTest, IOInput) {
        // This test is named "IOInput", it test that the input
        // operator >> properly sets the real and imaginary parts
        // of a Complex object based on the given input sequence.
        Complex c(0.0);
        istringstream in("-1 - i");
        in >> c;

        ASSERT_EQ(-1.0, c.getRealPart());
        ASSERT_EQ(-1.0, c.getImaginaryPart());

        in.clear();
        in.str("2.0+3.0i");
        in >> c;

        ASSERT_EQ(2.0, c.getRealPart());
        ASSERT_EQ(3.0, c.getImaginaryPart());

        in.clear();
        in.str("0+3.0i");
        in >> c;

        ASSERT_EQ(0.0, c.getRealPart());
        ASSERT_EQ(3.0, c.getImaginaryPart());

        in.clear();
        in.str("1.0+0i");
        in >> c;

        ASSERT_EQ(1.0, c.getRealPart());
        ASSERT_EQ(0.0, c.getImaginaryPart());

        _testScore += 1;

        in.str("-1");
        in >> c;

        ASSERT_EQ(-1.0, c.getRealPart());
        ASSERT_EQ(0.0, c.getImaginaryPart());

        in.clear();
        in.str("1");
        in >> c;

        ASSERT_EQ(1.0, c.getRealPart());
        ASSERT_EQ(0.0, c.getImaginaryPart());

        _testScore += 2;

        in.clear();
        in.str("i");
        in >> c;

        ASSERT_EQ(0.0, c.getRealPart());
        ASSERT_EQ(1.0, c.getImaginaryPart());

        in.clear();
        in.str("-i");
        in >> c;

        ASSERT_EQ(0.0, c.getRealPart());
        ASSERT_EQ(-1.0, c.getImaginaryPart());

        _testScore += 2;

        in.clear();
        in.str("-3i");
        in >> c;

        ASSERT_EQ(0.0, c.getRealPart());
        ASSERT_EQ(-3.0, c.getImaginaryPart());

        in.clear();
        in.str("-3");
        in >> c;

        ASSERT_EQ(-3.0, c.getRealPart());
        ASSERT_EQ(0.0, c.getImaginaryPart());

        // A little extra credit for getting all the input formats
        // to work
        _testScore += 3;
    }

    TEST_F(ComplexNumbersTest, IOInputBadInput) {
        // This test is named "IOInputBadInput", it tests that the
        // implementation of the >> operator properly detects bad
        // input and does not update the real and imaginary parts.
        Complex c(1.0);
        istringstream in("-1 * i");
        in >> c;

        ASSERT_EQ(1.0, c.getRealPart());
        ASSERT_EQ(0.0, c.getImaginaryPart());

        _testScore += 2;

        in.str("a");
        in >> c;

        ASSERT_EQ(1.0, c.getRealPart());
        ASSERT_EQ(0.0, c.getImaginaryPart());

        _testScore += 2;

        in.clear();
        in.str("-1 a i");
        in >> c;

        ASSERT_EQ(1.0, c.getRealPart());
        ASSERT_EQ(0.0, c.getImaginaryPart());

        _testScore += 2;
    }
}  // namespace