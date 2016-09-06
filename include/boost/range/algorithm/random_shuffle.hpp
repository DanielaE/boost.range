//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_ALGORITHM_RANDOM_SHUFFLE_HPP_INCLUDED
#define BOOST_RANGE_ALGORITHM_RANDOM_SHUFFLE_HPP_INCLUDED

#include <boost/concept_check.hpp>
#include <boost/range/begin.hpp>
#include <boost/range/end.hpp>
#include <boost/range/concepts.hpp>
#include <algorithm>
#include <random>

namespace boost
{
    namespace detail
    {
inline std::random_device & get_common_random_device() {
	static std::random_device generator;
	return generator;
}
	}

    namespace range
    {

/// \brief template function random_shuffle
///
/// range-based version of the random_shuffle std algorithm
///
/// \pre RandomAccessRange is a model of the RandomAccessRangeConcept
/// \pre Generator is a model of the UnaryFunctionConcept
template<class RandomAccessRange>
inline RandomAccessRange& random_shuffle(RandomAccessRange& rng)
{
    BOOST_RANGE_CONCEPT_ASSERT(( RandomAccessRangeConcept<RandomAccessRange> ));
    std::shuffle(boost::begin(rng), boost::end(rng), std::default_random_engine(boost::detail::get_common_random_device()()));
    return rng;
}

/// \overload
template<class RandomAccessRange>
inline const RandomAccessRange& random_shuffle(const RandomAccessRange& rng)
{
    BOOST_RANGE_CONCEPT_ASSERT(( RandomAccessRangeConcept<const RandomAccessRange> ));
    std::shuffle(boost::begin(rng), boost::end(rng), std::default_random_engine(boost::detail::get_common_random_device()()));
    return rng;
}

/// \overload
template<class RandomAccessRange, class Generator>
inline RandomAccessRange& random_shuffle(RandomAccessRange& rng, Generator& gen)
{
    BOOST_RANGE_CONCEPT_ASSERT(( RandomAccessRangeConcept<RandomAccessRange> ));
    std::shuffle(boost::begin(rng), boost::end(rng), std::default_random_engine(static_cast<unsigned>(gen(UINT_MAX))));
    return rng;
}

/// \overload
template<class RandomAccessRange, class Generator>
inline const RandomAccessRange& random_shuffle(const RandomAccessRange& rng, Generator& gen)
{
    BOOST_RANGE_CONCEPT_ASSERT(( RandomAccessRangeConcept<const RandomAccessRange> ));
    std::shuffle(boost::begin(rng), boost::end(rng), std::default_random_engine(static_cast<unsigned>(gen(UINT_MAX))));
    return rng;
}

    } // namespace range
    using range::random_shuffle;
} // namespace boost

#endif // include guard
