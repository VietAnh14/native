/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

extern "C" {
#include "../../../unit_test.h"
}

#include "ArrayList.hpp"

using namespace Java::Lang;

TEST(JavaLang, ArrayListConstructor) {
    // Test constructor no argument
    Array<int> validArray;
    int expect = 0;
    int result = validArray.length();
    ASSERT_EQUAL(expect, result);

    // Test constructor with length
    Array<int> validArray1(10);
    expect = 10;
    result = validArray1.length();
    ASSERT_EQUAL(expect, result);

    // Test constructor with initialize list
    Array<byte> bytes = {64, 65, 66};
    ASSERT_EQUAL(3, bytes.length());
}

TEST(JavaLang, ArrayListDestructor) {

}

TEST(JavaLang, ArrayListLength) {
    // Test length of empty Array
    Array<int> emptyArray;
    int expect = 0;
    int result = emptyArray.length();
    ASSERT_EQUAL(expect, result);

    // Test is empty
    boolean isEmpty = emptyArray.isEmpty();
    ASSERT_TRUE(isEmpty);

    // Test length of empty Array
    int length = 10;
    Array<int> validArray(length);
    result = validArray.length();
    ASSERT_EQUAL(length, result);

    // Test is not empty
    boolean notEmpty = validArray.isEmpty();
    ASSERT_FALSE(notEmpty);

    // Test length of validArray after push one element
    validArray.push(123);
    expect = 11;
    result = validArray.length();
    ASSERT_EQUAL(expect, result);
}

TEST(Javalang, ArrayListFunction) {

}

TEST(JavaLang, ArrayListOperator) {
    // Test operator+= with std::initializer_list
    Array<byte> byteArray = {12, 13, 14};
    byteArray += {15, 16, 17};
    int expect = 6;
    int result = byteArray.length();
    ASSERT_EQUAL(expect, result);

    // Test operator=
    // Create new Array equal to target Array
    Array<byte> copyArray = byteArray;
    expect = 6;
    result = byteArray.length();
    ASSERT_EQUAL(expect, result);

    // Test operator+
    // Create new Array from two Array
    Array<byte> totalArray = byteArray + copyArray;
    expect = 12;
    result = totalArray.length();
    ASSERT_EQUAL(expect, result);
}
