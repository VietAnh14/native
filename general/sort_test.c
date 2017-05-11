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

#include "../unit_test.h"
#include <stdlib.h>
#include <time.h>

TEST(General, QuickSort) {
    srand(time(NULL));

    int *array_int = malloc(50 * sizeof(int));
    srand(time(NULL));
    int index = 0;
    for (; index < 50; ++index) {
        array_int[index] = rand();
    }
    sort_int(array_int, 0, 49);
    int result = is_increase_int_array(array_int, 50);
    free(array_int);
    ASSERT_TRUE(result);

    // FLOAT
    float *array_float = malloc(50 * sizeof(float));
    srand((unsigned int)time(NULL));
    index = 0;
    for (; index < 50; index++) {
        array_float[index] = ((float)rand()/(float)(RAND_MAX)) * 100.0;
    }
    sort_float(array_float, 0, 49);
    result = is_increase_float_array(array_float, 50);
    free(array_float);
    ASSERT_TRUE(result);
}

TEST(General, DistributionCountingSort) {
    int *array_int = malloc(50 * sizeof(int));
    int index = 0;
    for (; index < 50; ++index) {
        array_int[index] = rand() % (10) + 1;
    }
    distribution_counting_sort(array_int, 50, 10);
    int result = is_increase_int_array(array_int, 50);
    ASSERT_TRUE(result);
}

