#include <iterator>
#include <concepts>

#include <utils.hpp>


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
        jab::val_type<T> tmp = *i;
        *i = *min;
        *min = tmp;
    }
}
