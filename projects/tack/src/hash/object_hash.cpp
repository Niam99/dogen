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
#include "dogen/tack/hash/name_hash.hpp"
#include "dogen/tack/hash/type_hash.hpp"
#include "dogen/tack/hash/object_hash.hpp"
#include "dogen/tack/hash/property_hash.hpp"
#include "dogen/tack/hash/object_types_hash.hpp"
#include "dogen/tack/hash/relationship_types_hash.hpp"

namespace {

template <typename HashableType>
inline void combine(std::size_t& seed, const HashableType& value) {
    std::hash<HashableType> hasher;
    seed ^= hasher(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

inline std::size_t hash_std_list_dogen_tack_property(const std::list<dogen::tack::property>& v) {
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, i);
    }
    return seed;
}

inline std::size_t hash_std_unordered_map_dogen_tack_name_std_list_dogen_tack_property_(const std::unordered_map<dogen::tack::name, std::list<dogen::tack::property> >& v) {
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, i.first);
        combine(seed, hash_std_list_dogen_tack_property(i.second));
    }
    return seed;
}

inline std::size_t hash_std_list_dogen_tack_name(const std::list<dogen::tack::name>& v) {
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, i);
    }
    return seed;
}

inline std::size_t hash_std_unordered_map_dogen_tack_relationship_types_std_list_dogen_tack_name_(const std::unordered_map<dogen::tack::relationship_types, std::list<dogen::tack::name> >& v) {
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, i.first);
        combine(seed, hash_std_list_dogen_tack_name(i.second));
    }
    return seed;
}

}

namespace dogen {
namespace tack {

std::size_t object_hasher::hash(const object& v) {
    std::size_t seed(0);

    combine(seed, dynamic_cast<const dogen::tack::type&>(v));

    combine(seed, hash_std_list_dogen_tack_property(v.all_properties()));
    combine(seed, hash_std_list_dogen_tack_property(v.local_properties()));
    combine(seed, hash_std_unordered_map_dogen_tack_name_std_list_dogen_tack_property_(v.inherited_properties()));
    combine(seed, v.is_parent());
    combine(seed, v.is_visitable());
    combine(seed, v.is_immutable());
    combine(seed, v.is_fluent());
    combine(seed, v.is_child());
    combine(seed, v.is_original_parent_visitable());
    combine(seed, hash_std_unordered_map_dogen_tack_relationship_types_std_list_dogen_tack_name_(v.relationships()));
    combine(seed, v.object_type());
    combine(seed, v.is_final());

    return seed;
}

} }
