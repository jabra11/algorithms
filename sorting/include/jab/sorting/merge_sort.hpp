#ifndef JAB_MERGE_SORT_HPP
#define JAB_MERGE_SORT_HPP

#include <concepts>
#include <iterator>
#include <vector>

namespace jab::sorting::detail
{

// O(n), Omega(n)
template<typename T>
requires(std::random_access_iterator<T> &&
    std::totally_ordered<std::iter_value_t<T>>)
void merge(T begin, T end, T q)
{
    using type = typename std::iter_value_t<T>;

    const std::size_t sz_left = std::distance(begin, q)+1;
    const std::size_t sz_right = std::distance(q+1, end)+1;

    auto left = std::vector<type>(sz_left);
    auto right = std::vector<type>(sz_right);
    
    for (std::size_t i=0; i<sz_left; ++i)
    {
        left[i] = *(begin+i);
    }

    for (std::size_t i=0; i<sz_right; ++i)
    {
        right[i] = *(q+i+1);
    }

    auto l = std::begin(left);
    auto r = std::begin(right);

    for (std::size_t i=0; i<sz_left+sz_right; ++i)
    {
        if (*l < *r)
        {
            *(begin+i) = *l;
            ++l;
            if (l == std::end(left))
            {
                while (r != std::end(right))
                {
                    ++i;
                    *(begin+i) = *r;
                    ++r;
                }
                return;
            }
        }
        else
        {
            *(begin+i) = *r;
            ++r;
            if (r == std::end(right))
            {
                while (l != std::end(left))
                {
                    ++i;
                    *(begin+i) = *l;
                    ++l;
                }
                return;
            }
        }
    }
}

// O(n lg n), Omega(n lg n)
template<typename T>
requires(std::random_access_iterator<T> &&
    std::totally_ordered<std::iter_value_t<T>>)
void merge_sort_impl(T begin, T end)
{
    if (begin < end) 
    {
        auto q = begin + std::distance(begin, end)/2;

        merge_sort_impl(begin, q);
        merge_sort_impl(q+1, end);
        merge(begin, end, q);
    }
}

} // namespace jab::sorting::detail

namespace jab::sorting
{

// O(n lg n), Omega(n lg n)
template<typename T>
requires(std::random_access_iterator<T> &&
    std::totally_ordered<std::iter_value_t<T>>)
void merge_sort(T begin, T end)
{
    detail::merge_sort_impl(begin, end-1);
}

} // namespace jab::sorting

 
#endif // JAB_MERGE_SORT_HPP
