#include <iostream>
#include <span>
#include <iterator>
#include <vector>


#include "selection_sort.hpp"

int main()
{
    std::vector<int> arr = {4,3,2,22};
    selection_sort(std::begin(arr), std::end(arr));

    for (auto i : arr)
    {
        std::cout << i << '\n';
    }
}
