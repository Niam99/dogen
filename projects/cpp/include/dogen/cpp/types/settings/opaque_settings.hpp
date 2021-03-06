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
#ifndef DOGEN_CPP_TYPES_SETTINGS_OPAQUE_SETTINGS_HPP
#define DOGEN_CPP_TYPES_SETTINGS_OPAQUE_SETTINGS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include <algorithm>
#include "dogen/cpp/serialization/settings/opaque_settings_fwd_ser.hpp"

namespace dogen {
namespace cpp {
namespace settings {

class opaque_settings {
public:
    opaque_settings() = default;
    opaque_settings(const opaque_settings&) = default;
    opaque_settings(opaque_settings&&) = default;
    opaque_settings& operator=(const opaque_settings&) = default;

    virtual ~opaque_settings() noexcept = 0;

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const opaque_settings& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, opaque_settings& v, unsigned int version);

public:
    virtual void to_stream(std::ostream& s) const;

protected:
    bool compare(const opaque_settings& rhs) const;
public:
    virtual bool equals(const opaque_settings& other) const = 0;

protected:
    void swap(opaque_settings& other) noexcept;

};

inline opaque_settings::~opaque_settings() noexcept { }

inline bool operator==(const opaque_settings& lhs, const opaque_settings& rhs) {
    return lhs.equals(rhs);
}

} } }

#endif
