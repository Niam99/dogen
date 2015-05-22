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
#ifndef DOGEN_UTILITY_IO_ARRAY_IO_HPP
#define DOGEN_UTILITY_IO_ARRAY_IO_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <array>
#include <ostream>
#include "dogen/needle/core/io/jsonify.hpp"
#include "dogen/needle/core/io/constants.hpp"

namespace std {

template<typename Containee, std::size_t Size>
inline ostream& operator<<(ostream& s, const array<Containee, Size>& a) {
    using namespace dogen::needle::core::io;
    s << constants::open_array();
    for(auto i(a.cbegin()); i != a.end(); ++i) {
        if (i != a.begin())
            s << constants::separator();
        s << dogen::needle::core::io::jsonify(*i);
    }
    s << constants::close_array();
    return(s);
}

}

#endif
