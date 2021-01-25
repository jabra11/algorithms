#include <iterator>
#include <concepts>

#include <utils.hpp>

// returns an iterator to the searched object.
// if the object wasn't found, the end iterator is returned
template<typename T> 
    requires(std::forward_iterator<T> && std::equality_comparable<std::iter_value_t<T>>)
T linear_search(T begin, T end, std::iter_value_t<T>&& obj)
{
    for (auto i = begin; i!=end; ++i)
    {
        if (*i == obj)
            return i;
    }
    return end;
}
