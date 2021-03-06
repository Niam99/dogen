/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright(C) 2012 Kitanda <info@kitanda.co.uk>
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
#include "dogen/cpp/types/formatters/test_data/string_helper_stitch.hpp"
#include "dogen/formatters/types/cpp/scoped_namespace_formatter.hpp"

namespace dogen {
namespace cpp {
namespace formatters {
namespace test_data {

void string_helper_stitch(
    formatters::nested_type_formatting_assistant& fa,
    const formattables::nested_type_info& /*t*/) {
fa.stream() << std::endl;
fa.stream() << "std::string create_std_string(const unsigned int position) {" << std::endl;
fa.stream() << "    std::ostringstream s;" << std::endl;
fa.stream() << "    s << \"a_string_\" << position;" << std::endl;
fa.stream() << "    return s.str();" << std::endl;
fa.stream() << "}" << std::endl;
}
} } } }
