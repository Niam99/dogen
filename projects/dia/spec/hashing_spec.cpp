/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2012 Kitanda <info@kitanda.co.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */
#include <boost/test/unit_test.hpp>
#include "dogen/utility/test/logging.hpp"
#include "dogen/utility/test/canned_tests.hpp"
#include "dogen/dia/types/all.hpp"
#include "dogen/dia/io/all_io.hpp"
#include "dogen/dia/hash/all_hash.hpp"
#include "dogen/dia/test_data/all_td.hpp"

namespace {

const std::string empty;
const std::string test_module("dia");
const std::string test_suite("hashing_spec");

}

using namespace dogen::dia;
using namespace dogen::utility::test;

BOOST_AUTO_TEST_SUITE(hashing)

BOOST_AUTO_TEST_CASE(validate_hashing) {
    SETUP_TEST_LOG("validate_hashing");

    test_hashing<attribute_generator>();
    test_hashing<boolean_generator>();
    test_hashing<child_node_generator>();
    test_hashing<color_generator>();
    // FIXME: bug in composition?
    // test_hashing<composite_generator>();
    test_hashing<connection_generator>();
    test_hashing<diagram_data_generator>();
    test_hashing<diagram_generator>();
    test_hashing<enumeration_generator>();
    test_hashing<font_generator>();
    test_hashing<integer_generator>();
    test_hashing<layer_generator>();
    test_hashing<object_generator>();
    test_hashing<point_generator>();
    test_hashing<real_generator>();
    test_hashing<rectangle_generator>();
    test_hashing<string_generator>();
}

BOOST_AUTO_TEST_SUITE_END()
