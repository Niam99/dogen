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
#include "dogen/stitch/types/block.hpp"

namespace dogen {
namespace stitch {

block::block()
    : type_(static_cast<dogen::stitch::block_types>(0)) { }

block::block(
    const dogen::stitch::block_types type,
    const std::string& content)
    : type_(type),
      content_(content) { }

void block::swap(block& other) noexcept {
    using std::swap;
    swap(type_, other.type_);
    swap(content_, other.content_);
}

bool block::operator==(const block& rhs) const {
    return type_ == rhs.type_ &&
        content_ == rhs.content_;
}

block& block::operator=(block other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

dogen::stitch::block_types block::type() const {
    return type_;
}

void block::type(const dogen::stitch::block_types v) {
    type_ = v;
}

const std::string& block::content() const {
    return content_;
}

std::string& block::content() {
    return content_;
}

void block::content(const std::string& v) {
    content_ = v;
}

void block::content(const std::string&& v) {
    content_ = std::move(v);
}

} }
