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
#include <boost/algorithm/string.hpp>
#include <ostream>
#include "dogen/cppim/io/feature_io.hpp"
#include "dogen/cppim/types/licence.hpp"


inline std::string tidy_up_string(std::string s) {
    boost::replace_all(s, "\r\n", "<new_line>");
    boost::replace_all(s, "\n", "<new_line>");
    boost::replace_all(s, "\"", "<quote>");
    return s;
}

namespace std {

inline std::ostream& operator<<(std::ostream& s, const std::pair<std::string, std::string>& v) {
    s << "{ " << "\"__type__\": " << "\"std::pair\"" << ", ";

    s << "\"first\": " << "\"" << tidy_up_string(v.first) << "\"" << ", ";
    s << "\"second\": " << "\"" << tidy_up_string(v.second) << "\"";
    s << " }";
    return s;
}

}

namespace std {

inline std::ostream& operator<<(std::ostream& s, const std::list<std::pair<std::string, std::string> >& v) {
    s << "[ ";
    for (auto i(v.begin()); i != v.end(); ++i) {
        if (i != v.begin()) s << ", ";
        s << *i;
    }
    s << "] ";
    return s;
}

}

namespace dogen {
namespace cppim {

licence::licence(
    const std::list<std::pair<std::string, std::string> >& copyright_holders,
    const std::string& licence_text)
    : dogen::cppim::feature(),
      copyright_holders_(copyright_holders),
      licence_text_(licence_text) { }

void licence::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"dogen::cppim::licence\"" << ", "
      << "\"__parent_0__\": ";
    feature::to_stream(s);
    s << ", "
      << "\"copyright_holders\": " << copyright_holders_ << ", "
      << "\"licence_text\": " << "\"" << tidy_up_string(licence_text_) << "\""
      << " }";
}

void licence::swap(licence& other) noexcept {
    feature::swap(other);

    using std::swap;
    swap(copyright_holders_, other.copyright_holders_);
    swap(licence_text_, other.licence_text_);
}

bool licence::equals(const dogen::cppim::feature& other) const {
    const licence* const p(dynamic_cast<const licence* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool licence::operator==(const licence& rhs) const {
    return feature::compare(rhs) &&
        copyright_holders_ == rhs.copyright_holders_ &&
        licence_text_ == rhs.licence_text_;
}

licence& licence::operator=(licence other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const std::list<std::pair<std::string, std::string> >& licence::copyright_holders() const {
    return copyright_holders_;
}

std::list<std::pair<std::string, std::string> >& licence::copyright_holders() {
    return copyright_holders_;
}

void licence::copyright_holders(const std::list<std::pair<std::string, std::string> >& v) {
    copyright_holders_ = v;
}

void licence::copyright_holders(const std::list<std::pair<std::string, std::string> >&& v) {
    copyright_holders_ = std::move(v);
}

const std::string& licence::licence_text() const {
    return licence_text_;
}

std::string& licence::licence_text() {
    return licence_text_;
}

void licence::licence_text(const std::string& v) {
    licence_text_ = v;
}

void licence::licence_text(const std::string&& v) {
    licence_text_ = std::move(v);
}

} }