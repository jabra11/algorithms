#include <iterator>

// O(n^2), Omega(n^2)
template<std::random_access_iterator T>
void selection_sort(T begin, T end)
{
    for (auto i = begin; i < end-1; ++i)    
    {
        auto min = i;  
        for (auto j = i+1; j != end; ++j)
        {
            if (*j < *min)
            {
                min=j;
            }
        }
        std::iter_value_t<T> tmp = *i;
        *i = *min;
        *min = tmp;
    }
}
