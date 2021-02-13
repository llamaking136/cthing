// auto-generated by makeNewFile
// compiled at 2021-02-12 12:01:59.119869
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

#include "argparser.h"

int usage() {
    fprintf(stderr, "usage: cthing <file> [args]\n");
    return 1;
}

int helppage() {
    usage();
    fprintf(stderr, "args:\n");
    fprintf(stderr, " -v: print current version\n");
    fprintf(stderr, " -h: pull up this help page\n");
    return 1;
}

int printversion() {
    fprintf(stderr, VERSION);
    return 0;
}

int parseargs(int argc, char** argv) {
    int optind;
    if (argc <= 1) {
        exit(usage());
    }

    for (optind = 1; optind < argc && argv[optind][0] == '-'; optind++) {
        switch (argv[optind][1]) {
            case 'h':
                exit(helppage());
                break;
            case 'v':
                exit(printversion());
                break;
            default:
                fprintf(stderr, "fatal error: unknown option: %c", argv[optind][1]);
                exit(1);
                break;
        }
    }
    return 0;
}