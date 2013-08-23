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
#ifndef DOGEN_CPPIM_TYPES_FEATURE_HPP
#define DOGEN_CPPIM_TYPES_FEATURE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <iosfwd>
#include "dogen/cppim/serialization/feature_fwd_ser.hpp"
#include "dogen/cppim/types/feature_visitor.hpp"

namespace dogen {
namespace cppim {

class feature {
public:
    feature() = default;
    feature(const feature&) = default;
    feature(feature&&) = default;
    feature& operator=(const feature&) = default;

    virtual ~feature() noexcept = 0;

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const feature& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, feature& v, unsigned int version);

public:
    virtual void accept(const feature_visitor& v) const = 0;
    virtual void accept(feature_visitor& v) const = 0;
    virtual void accept(const feature_visitor& v) = 0;
    virtual void accept(feature_visitor& v) = 0;

public:
    virtual void to_stream(std::ostream& s) const;

protected:
    bool compare(const feature& rhs) const;
public:
    virtual bool equals(const feature& other) const = 0;

protected:
    void swap(feature& other) noexcept;

};

inline feature::~feature() noexcept { }

inline bool operator==(const feature& lhs, const feature& rhs) {
    return lhs.equals(rhs);
}

} }

#endif
