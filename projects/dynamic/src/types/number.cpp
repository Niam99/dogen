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
#include <ostream>
#include "dogen/dynamic/io/value_io.hpp"
#include "dogen/dynamic/types/number.hpp"

namespace dogen {
namespace dynamic {

number::number()
    : content_(static_cast<int>(0)) { }

number::number(
    const dogen::dynamic::value_types& type,
    const int content)
    : dogen::dynamic::value(type),
      content_(content) { }

void number::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"dogen::dynamic::number\"" << ", "
      << "\"__parent_0__\": ";
    value::to_stream(s);
    s << ", "
      << "\"content\": " << content_
      << " }";
}

void number::swap(number& other) noexcept {
    value::swap(other);

    using std::swap;
    swap(content_, other.content_);
}

bool number::equals(const dogen::dynamic::value& other) const {
    const number* const p(dynamic_cast<const number* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool number::operator==(const number& rhs) const {
    return value::compare(rhs) &&
        content_ == rhs.content_;
}

number& number::operator=(number other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

int number::content() const {
    return content_;
}

void number::content(const int v) {
    content_ = v;
}

} }