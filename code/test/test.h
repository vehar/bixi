/*
 * "Bixi" - Basic types management C89 library
 *
 *  Copyright (C) Alexey Shishkin 2017
 *
 *  This file is part of Project "Bixi".
 *
 *  Project "Bixi" is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Project "Bixi" is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with Project "Bixi". If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TEST_H
#define TEST_H

#include <libbixi.h>

#include "./definitions/tst_bxiexport.h"
#include "./definitions/tst_bxiarch.h"
#include "./definitions/tst_bxiassert.h"
#include "./definitions/tst_bximacros.h"
#include "./graph/tst_bxicolour.h"
#include "./hashes/tst_bxihash.h"
#include "./hashes/tst_bximd5.h"
#include "./hashes/tst_bxiuuid.h"
#include "./math/tst_bxiplan.h"
#include "./math/tst_bximath.h"
#include "./random/tst_bxirand.h"
#include "./serials/tst_bxiserread.h"
#include "./serials/tst_bxiserwrite.h"
#include "./strings/tst_bxistrconv.h"
#include "./strings/tst_bxistring.h"
#include "./thread/tst_bxithread.h"
#include "./time/tst_bxisleep.h"
#include "./time/tst_bxitime.h"
#include "./types/tst_bxiarrays.h"
#include "./types/tst_bxiboints.h"
#include "./types/tst_bxibools.h"
#include "./types/tst_bxifloats.h"
#include "./types/tst_bxiints.h"
#include "./utils/tst_bxibitutils.h"
#include "./utils/tst_bximemutils.h"

#define print_info  printf("\033[1;33m%s\033[0m\n", __FILE__)

#define TEST_SPEED_INIT                \
    struct timespec time_s = { 0, 0 }; \
    struct timespec time_f = { 0, 0 }; \
    double time_n_s = 0;               \
    double time_n_f = 0;               \
    double sum_org = 0;                \
    double sum_new = 0
#define TEST_SPEED_START               \
    clock_gettime(CLOCK_MONOTONIC, &time_s)
#define TEST_SPEED_STOP                \
    clock_gettime(CLOCK_MONOTONIC, &time_f); \
    time_n_s = time_s.tv_nsec + time_s.tv_sec * 1e9; \
    time_n_f = time_f.tv_nsec + time_f.tv_sec * 1e9
#define TEST_SPEED_SAY(name)           \
    printf("            speedtest: %-12s: %8.5f\n", \
        name, (time_n_f - time_n_s) / (f64)1e9)
#define TEST_SPEED_CHECK    \
    if (sum_org != sum_new) \
        print_failed()

#define FAILED print_failed(__FILE__, __LINE__)

void print_macro_name          (const char * name);
void print_macro_undefined_exit(void);
void print_macro_value_string  (const char * value);
void print_macro_value_signed  (i32 value);
void print_macro_value_unsigned(u32 value);

void print_passed(void);
void print_failed(void);

#endif /* TEST_H */

