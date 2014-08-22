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
#ifndef DOGEN_TEST_MODELS_STEREOTYPES_TYPES_IDENTITY_POD_UNVERSIONED_KEY_HPP
#define DOGEN_TEST_MODELS_STEREOTYPES_TYPES_IDENTITY_POD_UNVERSIONED_KEY_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "dogen/test_models/stereotypes/serialization/identity_pod_unversioned_key_fwd_ser.hpp"
#include "dogen/test_models/stereotypes/types/value.hpp"

namespace dogen {
namespace test_models {
namespace stereotypes {

/**
 * @brief Unversioned key for identity_pod
 */
class identity_pod_unversioned_key final {
public:
    identity_pod_unversioned_key() = default;
    identity_pod_unversioned_key(const identity_pod_unversioned_key&) = default;
    identity_pod_unversioned_key(identity_pod_unversioned_key&&) = default;
    ~identity_pod_unversioned_key() = default;

public:
    explicit identity_pod_unversioned_key(const dogen::test_models::stereotypes::value& prop_0);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const identity_pod_unversioned_key& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, identity_pod_unversioned_key& v, unsigned int version);

public:
    /**
     * @brief Identity property.
     *
     */
    /**@{*/
    const dogen::test_models::stereotypes::value& prop_0() const;
    dogen::test_models::stereotypes::value& prop_0();
    void prop_0(const dogen::test_models::stereotypes::value& v);
    void prop_0(const dogen::test_models::stereotypes::value&& v);
    /**@}*/

public:
    bool operator==(const identity_pod_unversioned_key& rhs) const;
    bool operator!=(const identity_pod_unversioned_key& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(identity_pod_unversioned_key& other) noexcept;
    identity_pod_unversioned_key& operator=(identity_pod_unversioned_key other);

private:
    dogen::test_models::stereotypes::value prop_0_;
};

} } }

namespace std {

template<>
inline void swap(
    dogen::test_models::stereotypes::identity_pod_unversioned_key& lhs,
    dogen::test_models::stereotypes::identity_pod_unversioned_key& rhs) {
    lhs.swap(rhs);
}

}

#endif
