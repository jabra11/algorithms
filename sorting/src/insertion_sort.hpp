#include <iterator>

#include <utils.hpp>


// O(n^2), Omega(n)
template<std::random_access_iterator T>
void insertion_sort(T begin, T end)
{
    for (auto i = begin+1; i != end; ++i)
    {
        jab::val_type<T> tmp = *i;

        auto j = i-1; 
        while (j >= begin && tmp < *j)
        {
            *(j+1) = *j;
            --j;
        }
        *(j+1) = tmp;
    }
}
