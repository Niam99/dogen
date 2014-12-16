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
#include <boost/throw_exception.hpp>
#include "dogen/utility/log/logger.hpp"
#include "dogen/dynamic/types/workflow_error.hpp"
#include "dogen/dynamic/types/workflow.hpp"

namespace {

using namespace dogen::utility::log;
static logger lg(logger_factory("dynamic.workflow"));

const std::string duplicate_field_definition(
    "Field definition already inserted: ");

}

namespace dogen {
namespace dynamic {

std::shared_ptr<registrar> workflow::registrar_;

dynamic::registrar& workflow::registrar() {
    if (!registrar_)
        registrar_ = std::make_shared<dynamic::registrar>();

    return *registrar_;
}

workflow::workflow() :
    field_definitions_by_complete_name_(
        obtain_field_definitions_by_complete_name_activity()) { }

std::unordered_map<std::string, field_definition> workflow::
obtain_field_definitions_by_complete_name_activity() const {
    std::unordered_map<std::string, field_definition> r;

    registrar().validate();
    for (const auto& fd : registrar().field_definitions()) {
        const auto cn(fd.name().complete_name());
        const auto result(r.insert(std::make_pair(cn, fd)));
        if (!result.second) {
            BOOST_LOG_SEV(lg, error) << duplicate_field_definition << cn;
            BOOST_THROW_EXCEPTION(workflow_error(
                    duplicate_field_definition + cn));
        }
    }
    return r;
}

} }