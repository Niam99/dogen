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
#include "dogen/formatters/types/sequence_formatter.hpp"
#include "dogen/cpp/types/formatters/test_data/class_header_formatter_stitch.hpp"

namespace dogen {
namespace cpp {
namespace formatters {
namespace test_data {

dogen::formatters::file class_header_formatter_stitch(
    formatters::entity_formatting_assistant& fa,
    const formattables::class_info& c) {

    {
        auto sbf(fa.make_scoped_boilerplate_formatter());
        {
            auto snf(fa.make_scoped_namespace_formatter());

fa.stream() << std::endl;
fa.stream() << "class " << c.name() << "_generator {" << std::endl;
fa.stream() << "public:" << std::endl;
fa.stream() << "    " << c.name() << "_generator();" << std::endl;
fa.stream() << std::endl;
fa.stream() << "public:" << std::endl;
fa.stream() << "    typedef " << c.qualified_name() << " result_type;" << std::endl;
fa.stream() << std::endl;
fa.stream() << "public:" << std::endl;
            if (!c.is_immutable())
fa.stream() << "    static void populate(const unsigned int position, result_type& v);" << std::endl;
            if (!c.is_parent()) {
fa.stream() << "    static result_type create(const unsigned int position);" << std::endl;
fa.stream() << "    result_type operator()();" << std::endl;
fa.stream() << std::endl;
fa.stream() << "private:" << std::endl;
fa.stream() << "    unsigned int position_;" << std::endl;
            }
fa.stream() << "public:" << std::endl;
fa.stream() << "    static result_type* create_ptr(const unsigned int position);" << std::endl;
fa.stream() << "};" << std::endl;
fa.stream() << std::endl;
        } // snf
fa.stream() << std::endl;
    } // sbf
    return fa.make_file();
}
} } } }
