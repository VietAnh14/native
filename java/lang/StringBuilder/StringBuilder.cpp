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

#include "../StringBuilder/StringBuilder.hpp"

using namespace Java::Lang;

StringBuilder::StringBuilder() : StringBuilder(16) { }

StringBuilder::StringBuilder(int capacity) {
    int numberOfBytesForCapacity = capacity * sizeof(char);
    this->original = (string)malloc((size_t)numberOfBytesForCapacity);
    this->currentLength = 0;
    this->currentCapacity = capacity;
}

StringBuilder::StringBuilder(const string target) {
    int stringLength = (int)strlen(target);
    int newCapacity = 16 + stringLength;
    this->ensureCapacity(newCapacity);
    this->append(target);
}

StringBuilder::StringBuilder(const String &target) {
    int newCapacity = 16 + target.length();
    this->ensureCapacity(newCapacity);
    this->append(target.toString());
}

StringBuilder::StringBuilder(const std::initializer_list<char> &target) {
    int newCapacity = 16 + (int)target.size();
    this->ensureCapacity(newCapacity);
    this->append(target);
}

StringBuilder::StringBuilder(const StringBuilder &target) {
    int numberOfBytesOfCapacity = target.currentCapacity * sizeof(char);
    this->original = (string)malloc((size_t)numberOfBytesOfCapacity);
    #ifdef __linux__
    register
#endif
    int index;
    for (index = 0; index < target.currentLength; index++) {
        this->original[index] = target.original[index];
    }
    this->currentLength = target.currentLength;
    this->currentCapacity = target.currentCapacity;
}

StringBuilder::~StringBuilder() {
    free(original);
}

StringBuilder StringBuilder::append(const Array<Character> &target) {
    int newLength = this->currentLength + target.length;
    this->ensureCapacity(newLength);
#ifdef __linux__
    register
#endif
    int indexOfOriginal = this->currentLength;
    for (Character character : target) {
        this->original[indexOfOriginal] = character.charValue();
        indexOfOriginal = indexOfOriginal + 1;
    }
    this->currentLength = newLength;
    return *this;
}

StringBuilder StringBuilder::append(const string target) {
    int stringLength = (int)strlen(target);
    int newLength = this->currentLength + stringLength;
    this->ensureCapacity(newLength);
#ifdef __linux__
    register
#endif
    int indexOfOriginal;
#ifdef __linux__
    register
#endif
    int indexOfString = 0;
    for (indexOfOriginal = this->currentLength; indexOfOriginal < newLength; indexOfOriginal++) {
        this->original[indexOfOriginal] = target[indexOfString];
        indexOfString = indexOfString + 1;
    }
    this->currentLength = newLength;
    return *this;
}

StringBuilder StringBuilder::append(const std::initializer_list<char> &target) {
    int newLength = this->currentLength + (int)target.size();
    this->ensureCapacity(newLength);
#ifndef __linux__
    register
#endif
    int index = this->currentLength;
    std::initializer_list<char>::const_iterator listIterator;
    for (listIterator = target.begin(); listIterator != target.end(); listIterator++) {
        this->original[index] = *listIterator;
        index = index + 1;
    }
    this->currentLength = newLength;
    return *this;
}

StringBuilder StringBuilder::append(const String &target) {
    return this->append(target.toString());
}

int StringBuilder::capacity() const {
    return this->currentCapacity;
}

char StringBuilder::charAt(int index) const {
    if (index < 0 || index >= this->currentLength) {
        throw std::invalid_argument("index is out of range");
    }

    return this->original[index];
}

void StringBuilder::ensureCapacity(int minimumCapacity) {
    if ((minimumCapacity > 0) && (minimumCapacity > this->currentCapacity)) {
        int newCapacity = this->currentCapacity * 2 + 2;
        if (newCapacity < minimumCapacity) {
            newCapacity = minimumCapacity;
        }
        int numberOfBytes = newCapacity * sizeof(char);
        this->original = (string)realloc(this->original, (size_t)numberOfBytes);
        this->currentCapacity = newCapacity;
    }
}

int StringBuilder::length() const {
    return this->currentLength;
}

string StringBuilder::toString() const {
    int numberOfBytes = (this->currentLength + 1) * sizeof(char); // increases by 1 for null terminator.
    string content = (string)malloc((size_t)numberOfBytes);
#ifdef __linux__
    register
#endif
    int index;
    for (index = 0; index < this->currentLength; index++) {
        content[index] = this->original[index];
    }
    content[this->currentLength] = '\0';
    return content;
}

void StringBuilder::trimToSize() {
    if (this->currentCapacity > this->currentLength) {
        int numberOfBytesForCapacity = this->currentLength * sizeof(char);
        this->original = (string)realloc(this->original, (size_t)numberOfBytesForCapacity);
        this->currentCapacity = this->currentLength;
    }
}
