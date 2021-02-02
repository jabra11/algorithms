#ifndef JAB_UTILS_HPP
#define JAB_UTILS_HPP 

#include <iterator>
#include <concepts>
#include <variant>
#include <chrono>
#include <vector>
#include <random>

namespace jab::utility
{

template<typename T>
struct return_vals
{
    T ret_val {};
    long long time_elapsed=0;
};

template<>
struct return_vals<void>
{
    long long time_elapsed=0;
};

template<typename Func, typename... Args>
requires(std::invocable<Func, Args...>)
auto measure_elapsed_time(Func&& func, Args&&... args)
{
    using return_type = typename std::invoke_result_t<Func,Args...>;

    if constexpr (std::same_as<return_type, void>)
    {
        auto start = std::chrono::steady_clock::now();
        std::forward<Func>(func)(std::forward<Args>(args)...);
        auto stop = std::chrono::steady_clock::now();
        return return_vals<void>{std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count()};
    }
    else
    {
        auto start = std::chrono::steady_clock::now();
        auto res = std::forward<Func>(func)(std::forward<Args>(args)...);
        auto stop = std::chrono::steady_clock::now();
        return return_vals<return_type> {res, std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count()};
    }
}


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
    auto gen = std::mt19937(std::random_device()());

    auto out = std::vector<T>(size);
    for (auto& i : out)
        i = distr(gen);

    return out;
}

}
#endif // JAB_UTILS_HPP
