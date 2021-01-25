#include <iostream>
#include <vector>

#include "linear_search.hpp"

int main()
{
    std::vector vec {1,2,3};

    if (auto it = linear_search(std::begin(vec), std::end(vec), 1); it != std::end(vec))
    {
        std::cout << "found!\n";
        return 0;
    }
    std::cout << "not found!\n";
}
