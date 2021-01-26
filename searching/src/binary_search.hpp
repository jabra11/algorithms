#include <iterator>
#include <concepts>

#include <utils.hpp>

#include <iostream>

namespace jab::searching
{
// returns an iterator to the searched object.
// if the object wasn't found, the end iterator is returned
// Requirements: the sequence [begin, end) must be sorted
// such that *begin <= *end
template<typename T> 
    requires(std::random_access_iterator<T> && std::totally_ordered<std::iter_value_t<T>>)
T binary_search(T begin, T end, std::iter_value_t<T>&& obj)
{
    T low = begin; 
    T hi = end-1;
    while (low <= hi)
    {
        T mid = low+std::distance(low, hi)/2;
        std::cout << *mid << '\n';

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
