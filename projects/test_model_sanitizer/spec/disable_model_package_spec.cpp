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
#include "dogen/utility/io/vector_io.hpp"
#include "dogen/utility/test/logging.hpp"
#include "dogen/utility/test/canned_tests.hpp"
#include "dogen/dmp/domain/all.hpp"
#include "dogen/dmp/io/all_io.hpp"
#include "dogen/dmp/serialization/all_ser.hpp"
#include "dogen/dmp/serialization/registrar_ser.hpp"
#include "dogen/dmp/test_data/all_td.hpp"
#include "dogen/dmp/hash/all_hash.hpp"

template<typename Archive> void register_types(Archive& ar) {
    dogen::dmp::register_types<Archive>(ar);
}

namespace {

const std::string empty;
const std::string test_module("test_model_sanitizer");
const std::string test_suite("disable_model_package");

}

using namespace dogen::dmp;
using namespace dogen::dmp::package1;
using namespace dogen::utility::test;

BOOST_AUTO_TEST_SUITE(disable_model_package)

BOOST_AUTO_TEST_CASE(validate_equality) {
    SETUP_TEST_LOG("validate_equality");
    test_equality<first_class_generator>();
    test_equality<versioned_key_generator>();
    test_equality<unversioned_key_generator>();
}

BOOST_AUTO_TEST_CASE(validate_serialisation) {
    SETUP_TEST_LOG("validate_serialisation");
    rountrip_type<first_class_generator>();
    rountrip_type<versioned_key_generator>();
    rountrip_type<unversioned_key_generator>();
}

BOOST_AUTO_TEST_CASE(validate_hashing) {
    SETUP_TEST_LOG("validate_hashing");
    test_hashing<first_class_generator>();
    test_hashing<versioned_key_generator>();
    test_hashing<unversioned_key_generator>();
}

BOOST_AUTO_TEST_CASE(validate_swap) {
    SETUP_TEST_LOG("validate_hashing");
    test_swap<first_class_generator>();
    test_swap<versioned_key_generator>();
    test_swap<unversioned_key_generator>();
}

BOOST_AUTO_TEST_CASE(validate_io) {
    SETUP_TEST_LOG("validate_io");
    test_io<first_class_generator>();
    test_io<versioned_key_generator>();
    test_io<unversioned_key_generator>();
}

BOOST_AUTO_TEST_SUITE_END()
