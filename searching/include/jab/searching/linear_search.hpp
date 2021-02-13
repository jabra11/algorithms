#ifndef JAB_LINEAR_SEARCH_HPP
#define JAB_LINEAR_SEARCH_HPP

#include <iterator>
#include <concepts>

namespace jab::searching
{

// returns an iterator to the searched object.
// if the object wasn't found, the end iterator is returned
template<typename T, typename ItV = std::iter_value_t<T>> 
requires(std::forward_iterator<T> && std::equality_comparable<ItV>
    && std::same_as<std::remove_cvref_t<ItV>, std::remove_cvref_t<std::iter_value_t<T>>>)
T linear_search(T begin, T end, ItV&& obj)
{
    for (auto i = begin; i!=end; ++i)
    {
        if (*i == obj)
            return i;
    }
    return end;
}

} // namespace jab::searching

#endif // JAB_LINEAR_SEARCH_HPP
