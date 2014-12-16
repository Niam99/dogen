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
#include "dogen/dynamic/test_data/boolean_collection_td.hpp"
#include "dogen/dynamic/test_data/boolean_td.hpp"
#include "dogen/dynamic/test_data/number_collection_td.hpp"
#include "dogen/dynamic/test_data/number_td.hpp"
#include "dogen/dynamic/test_data/text_collection_td.hpp"
#include "dogen/dynamic/test_data/text_td.hpp"
#include "dogen/dynamic/test_data/value_td.hpp"
#include "dogen/dynamic/test_data/value_types_td.hpp"

namespace {

dogen::dynamic::value_types
create_dogen_dynamic_value_types(const unsigned int position) {
    return dogen::dynamic::value_types_generator::create(position);
}

}

namespace dogen {
namespace dynamic {


void value_generator::
populate(const unsigned int position, result_type& v) {
    v.type(create_dogen_dynamic_value_types(position + 0));
}

value_generator::result_type*
value_generator::create_ptr(const unsigned int position) {
    if ((position % 5) == 0)
        return dogen::dynamic::text_collection_generator::create_ptr(position);
    if ((position % 5) == 1)
        return dogen::dynamic::number_generator::create_ptr(position);
    if ((position % 5) == 2)
        return dogen::dynamic::boolean_generator::create_ptr(position);
    if ((position % 5) == 3)
        return dogen::dynamic::number_collection_generator::create_ptr(position);
    if ((position % 5) == 4)
        return dogen::dynamic::boolean_collection_generator::create_ptr(position);
    return dogen::dynamic::text_generator::create_ptr(position);
}


} }