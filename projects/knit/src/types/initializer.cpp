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
#include "dogen/cpp/types/initializer.hpp"
#include "dogen/tack_json/types/initializer.hpp"
#include "dogen/tack_dia/types/initializer.hpp"
#include "dogen/knit/types/initializer.hpp"

namespace dogen {
namespace knit {

void initializer::initialize() {
    dogen::tack_json::initializer::initialize();
    dogen::tack_dia::initializer::initialize();
    dogen::cpp::initializer::initialize();
}

} }
