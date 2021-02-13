// auto-generated by makeNewFile
// compiled at 2021-02-11 21:12:51.356587
// created by llamaking136

// Copyright 2021 llamaking136

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "array.h"

void initArray(TokenArray* t, size_t initialSize) {
    t->array = (Token*)malloc(initialSize * sizeof(Token));
    t->used = 0;
    t->size = initialSize;
}

void insertArray(TokenArray* t, Token element) {
    if (t->used == t->size) {
        t->size *= 2;
        t->array = (Token*)realloc(t->array, t->size * sizeof(Token));
    }
    t->array[t->used++] = element;
}

void freeArray(TokenArray* t) {
    free(t->array);
    t->array = NULL;
    t->used = t->size = 0;
}

void printArray(TokenArray* t) {
    for (size_t i = 0; i < t->used; i++) {
        printf("'%s', ", t->array[i].data);
    }
    printf("\n");
}