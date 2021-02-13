#ifndef JAB_BINARY_SEARCH_HPP
#define JAB_BINARY_SEARCH_HPP

#include <iterator>
#include <concepts>

namespace jab::searching
{
// returns an iterator to the searched object.
// if the object wasn't found, the end iterator is returned
// Requirements: the sequence [begin, end) must be sorted
// such that *begin <= *end

template<typename T, typename ItV = std::iter_value_t<T>> 
requires(std::random_access_iterator<T> && std::totally_ordered<ItV>
    && std::same_as<std::remove_cvref_t<ItV>, std::remove_cvref_t<std::iter_value_t<T>>>)
T binary_search(T begin, T end, ItV&& obj)
{
    T low = begin; 
    T hi = end-1;
    while (low <= hi)
    {
        T mid = low+std::distance(low, hi)/2;

        if (*mid > obj)
        {
            hi = mid-1;
        }
        else if (*mid < obj)
        {
            low = mid+1;
        }
        else
        {
            return mid;
        }
    }
    return end;
}

} // namespace jab::searching

#endif // JAB_BINARY_SEARCH_HPP
