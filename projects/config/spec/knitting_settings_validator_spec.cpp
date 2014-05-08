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
#include <sstream>
#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include "dogen/utility/test/logging.hpp"
#include "dogen/config/types/knitting_settings.hpp"
#include "dogen/config/types/knitting_settings_validator.hpp"
#include "dogen/config/types/configuration_error.hpp"
#include "dogen/config/test/mock_settings_factory.hpp"
#include "dogen/utility/test/exception_checkers.hpp"

namespace {

const std::string empty;
const boost::filesystem::path empty_dir;
const std::string test_module("config");
const std::string test_suite("knitting_settings_validator_spec");

const boost::filesystem::path target("some_target");
const boost::filesystem::path src_dir("src directory");
const boost::filesystem::path include_dir("include directory");
const boost::filesystem::path project_dir("proj directory");
const std::string epp("package::path");

const std::string missing_target("Mandatory parameter target is missing");
const std::string missing_source_include("You must supply source and include");
const std::string missing_project_dir("You must supply the project directory");
const std::string unexpected_source_include("Source and include directories");
const std::string unexpected_project_dir("Project directories cannot be");

dogen::config::knitting_settings target_source_and_include() {
    return dogen::config::test::mock_settings_factory::
        build_knitting_settings(target, src_dir, include_dir, epp);
}

dogen::config::knitting_settings target_only() {
    return dogen::config::test::mock_settings_factory::
        build_knitting_settings(target, empty_dir, empty_dir, empty);
}

dogen::config::knitting_settings split_project(const bool split) {
    auto s(target_only());
    auto cpp(s.cpp());
    cpp.split_project(split);
    s.cpp(cpp);
    return s;
}

dogen::config::knitting_settings
split_project(const bool split, const boost::filesystem::path& include,
    const boost::filesystem::path& src) {
    auto s(target_only());
    auto cpp(s.cpp());
    cpp.split_project(split);
    cpp.include_directory(include);
    cpp.source_directory(src);

    if (!split)
        cpp.project_directory(project_dir);
    s.cpp(cpp);
    return s;
}

dogen::config::knitting_settings
split_project(const bool split, const boost::filesystem::path& proj) {
    auto s(target_only());
    auto cpp(s.cpp());
    cpp.split_project(split);
    cpp.project_directory(proj);

    if (split) {
        cpp.include_directory(include_dir);
        cpp.source_directory(src_dir);
    }
    s.cpp(cpp);
    return s;
}

}

using dogen::utility::test::contains_checker;
using dogen::config::configuration_error;

BOOST_AUTO_TEST_SUITE(knitting_settings_validator)

BOOST_AUTO_TEST_CASE(settings_without_a_target_throw) {
    SETUP_TEST_LOG_SOURCE("settings_without_a_target_throw");

    dogen::config::knitting_settings s;
    BOOST_CHECK(s.input().target().empty());
    contains_checker<configuration_error> c(missing_target);
    BOOST_CHECK_EXCEPTION(
        dogen::config::knitting_settings_validator::validate(s),
        configuration_error, c);
}

BOOST_AUTO_TEST_CASE(settings_with_a_target_are_valid) {
    SETUP_TEST_LOG_SOURCE("settings_with_a_target_are_valid");

    // we cannot test with target only here, as this is not a valid
    // scenario; for split projects we must supply the include and
    // source directories and for non-split we need project
    // directories. so we just chose one of the two.
    dogen::config::knitting_settings_validator::validate(
        target_source_and_include());
}

BOOST_AUTO_TEST_CASE(settings_for_non_split_projects_without_a_project_directory_throw) {
    SETUP_TEST_LOG_SOURCE("settings_for_non_split_projects_without_a_project_directory_throw");

    auto s(split_project(false));
    contains_checker<configuration_error> c(missing_project_dir);
    BOOST_CHECK_EXCEPTION(
        dogen::config::knitting_settings_validator::validate(s),
        configuration_error, c);
}

BOOST_AUTO_TEST_CASE(settings_for_split_projects_with_a_project_directory_are_valid) {
    SETUP_TEST_LOG_SOURCE("settings_for_split_projects_with_a_project_directory_are_valid");
    dogen::config::knitting_settings_validator::validate(
        split_project(false, project_dir));
}

BOOST_AUTO_TEST_CASE(settings_for_non_split_projects_with_include_or_source_directories_throw) {
    SETUP_TEST_LOG_SOURCE("settings_for_non_split_projects_with_include_or_source_directories_throw");

    auto s(split_project(false, include_dir, src_dir));
    contains_checker<configuration_error> c(unexpected_source_include);
    BOOST_CHECK_EXCEPTION(
        dogen::config::knitting_settings_validator::validate(s),
        configuration_error, c);

    s = split_project(false, include_dir, empty_dir);
    BOOST_CHECK_EXCEPTION(
        dogen::config::knitting_settings_validator::validate(s),
        configuration_error, c);

    s = split_project(false, empty_dir, src_dir);
    BOOST_CHECK_EXCEPTION(
        dogen::config::knitting_settings_validator::validate(s),
        configuration_error, c);
}

BOOST_AUTO_TEST_CASE(settings_for_split_projects_without_source_or_include_directories_throw) {
    SETUP_TEST_LOG_SOURCE("settings_for_split_projects_without_source_or_include_directories_throw");

    auto s(split_project(true));
    contains_checker<configuration_error> c(missing_source_include);
    BOOST_CHECK_EXCEPTION(
        dogen::config::knitting_settings_validator::validate(s),
        configuration_error, c);

    s = split_project(true, include_dir, empty_dir);
    BOOST_CHECK_EXCEPTION(
        dogen::config::knitting_settings_validator::validate(s),
        configuration_error, c);

    s = split_project(true, empty_dir, src_dir);
    BOOST_CHECK_EXCEPTION(
        dogen::config::knitting_settings_validator::validate(s),
        configuration_error, c);

    dogen::config::knitting_settings_validator::validate(
        split_project(true, include_dir, src_dir));
}

BOOST_AUTO_TEST_CASE(settings_for_split_projects_with_source_and_include_directories_are_valid) {
    SETUP_TEST_LOG_SOURCE("settings_for_split_projects_with_source_and_include_directories_are_valid");
    dogen::config::knitting_settings_validator::validate(
        split_project(true, include_dir, src_dir));
}

BOOST_AUTO_TEST_CASE(settings_for_split_projects_with_project_directory_throw) {
    SETUP_TEST_LOG_SOURCE("settings_for_split_projects_with_project_directory_throw");

    const auto s(split_project(true, project_dir));
    contains_checker<configuration_error> c(unexpected_project_dir);
    BOOST_CHECK_EXCEPTION(
        dogen::config::knitting_settings_validator::validate(s),
        configuration_error, c);
}

BOOST_AUTO_TEST_SUITE_END()
