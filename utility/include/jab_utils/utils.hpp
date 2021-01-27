#ifndef JAB_UTILS_HPP
#define JAB_UTILS_HPP 

#include <iterator>
#include <concepts>
#include <vector>
#include <random>

namespace jab::utility
{

template<typename T> 
    requires(std::forward_iterator<T> && std::totally_ordered<std::iter_value_t<T>>)
bool is_sorted(T begin, T end)
{
    for (auto it = begin; it != end-1; ++it)
    {
        if (*it > *(it+1))
        {
            return false;
        }
    }
    return true;
}

template<std::integral T>
std::vector<T> generate_randomly_filled_vec(std::size_t size, 
        T min = std::numeric_limits<T>::min(),
        T max = std::numeric_limits<T>::max())
{
    auto distr = std::uniform_int_distribution(min, max);
    auto gen = std::mt19937_64(std::random_device()());

    auto out = std::vector<T>(size);
    for (auto& i : out)
        i = distr(gen);

    return out;
}

}
#endif // JAB_UTILS_HPP
