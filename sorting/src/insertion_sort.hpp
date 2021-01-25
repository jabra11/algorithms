#include <iterator>

// O(n^2), Omega(n)
template<std::random_access_iterator T>
void insertion_sort(T begin, T end)
{
    for (auto i = begin+1; i != end; ++i)
    {
        std::iter_value_t<T> tmp = *i;

        auto j = i-1; 
        while (j >= begin && tmp < *j)
        {
            *(j+1) = *j;
            --j;
        }
        *(j+1) = tmp;
    }
}
