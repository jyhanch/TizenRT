/****************************************************************************
 *
 * Copyright 2018 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <iterator>

// class ostreambuf_iterator

// ostreambuf_iterator<charT,traits>& operator++();
// ostreambuf_iterator<charT,traits>& operator++(int);

#include <iterator>
#include <sstream>
#include <cassert>
#include "libcxx_tc_common.h"

int tc_libcxx_iterators_ostreambuf_iter_ops_increment(void)
{
    {
        std::ostringstream outf;
        std::ostreambuf_iterator<char> i(outf);
        std::ostreambuf_iterator<char>& iref = ++i;
        TC_ASSERT_EXPR(&iref == &i);
        std::ostreambuf_iterator<char>& iref2 = i++;
        TC_ASSERT_EXPR(&iref2 == &i);
    }
    {
        std::wostringstream outf;
        std::ostreambuf_iterator<wchar_t> i(outf);
        std::ostreambuf_iterator<wchar_t>& iref = ++i;
        TC_ASSERT_EXPR(&iref == &i);
        std::ostreambuf_iterator<wchar_t>& iref2 = i++;
        TC_ASSERT_EXPR(&iref2 == &i);
    }
    TC_SUCCESS_RESULT();
    return 0;
}
