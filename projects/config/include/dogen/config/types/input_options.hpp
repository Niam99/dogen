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
#ifndef DOGEN_CONFIG_TYPES_INPUT_OPTIONS_HPP
#define DOGEN_CONFIG_TYPES_INPUT_OPTIONS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <vector>
#include <algorithm>
#include "dogen/config/types/input_descriptor.hpp"
#include "dogen/config/serialization/input_options_fwd_ser.hpp"

namespace dogen {
namespace config {

/**
 * @brief Options related to the input files.
 */
class input_options final {
public:
    input_options() = default;
    input_options(const input_options&) = default;
    input_options(input_options&&) = default;
    ~input_options() = default;

public:
    input_options(
        const dogen::config::input_descriptor& target,
        const std::vector<dogen::config::input_descriptor>& references);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const input_options& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, input_options& v, unsigned int version);

public:
    /**
     * @brief Path to the Dia diagram that contains the model to
     *  generate.
     */
    /**@{*/
    const dogen::config::input_descriptor& target() const;
    dogen::config::input_descriptor& target();
    void target(const dogen::config::input_descriptor& v);
    void target(const dogen::config::input_descriptor&& v);
    /**@}*/

    /**
     * @brief All external models in which this model depends.
     */
    /**@{*/
    const std::vector<dogen::config::input_descriptor>& references() const;
    std::vector<dogen::config::input_descriptor>& references();
    void references(const std::vector<dogen::config::input_descriptor>& v);
    void references(const std::vector<dogen::config::input_descriptor>&& v);
    /**@}*/

public:
    bool operator==(const input_options& rhs) const;
    bool operator!=(const input_options& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(input_options& other) noexcept;
    input_options& operator=(input_options other);

private:
    dogen::config::input_descriptor target_;
    std::vector<dogen::config::input_descriptor> references_;
};

} }

namespace std {

template<>
inline void swap(
    dogen::config::input_options& lhs,
    dogen::config::input_options& rhs) {
    lhs.swap(rhs);
}

}

#endif
