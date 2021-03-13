// auto-generated by makeNewFile
// compiled at 2021-02-12 12:44:36.007185
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

#include "fileread.h"

/*
char* fileread(char* filename) {
    FILE* fp;

	struct stat st;
	stat(filename, &st);

	off_t buffer_size = st.st_size;

    char buffer[buffer_size];
    if (access(filename, F_OK) != 0) {
        fprintf(stderr, "fatal error: cannot open file %s for reading [errno %d]\n", filename, errno);
        exit(1);
    } else if (errno != 0) {
        fprintf(stderr, "fatal error: cannot open file %s for reading [errno %d]\n", filename, errno);
        exit(1);
    }
    // printf("[+]: i shouldn't be here!\n");
    fp = fopen(filename, "r");
    fgets(buffer, FILE_BUFF, fp);
    fclose(fp);
    char* data = buffer;

    return data;
}
*/
char *fileread(char *filename)
{
    long int size = 0;
    FILE *file = fopen(filename, "r");
    
    if(!file) {
        fputs("File error.\n", stderr);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    char *result = (char *) malloc(size);
    if(!result) {
        fputs("Memory error.\n", stderr);
        fclose(file);
        return NULL;
    }

    if(fread(result, 1, size, file) != size) {
        fputs("Read error.\n", stderr);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return result;
}
