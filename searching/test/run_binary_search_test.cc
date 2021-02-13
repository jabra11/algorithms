#include <vector>

#include <gtest/gtest.h>

#include <jab/searching/binary_search.hpp>
#include <jab/utils/utils.hpp>


TEST(binary_search_test, randomly_filled_vec)
{
    using elem_type = int;
    auto vec = jab::utility::generate_randomly_filled_vec<elem_type>(10000, -1000, 1000);
    int target = jab::utility::generate_randomly_filled_vec<elem_type>(1, -1000,1000)[0];

    std::sort(vec.begin(), vec.end());
    auto my = jab::searching::binary_search(vec.begin(), vec.end(), target);
    auto std = std::find(vec.begin(), vec.end(), target);

    if (std != vec.end())
    {
        // mustn't point to the same element, if there are duplicates
        EXPECT_EQ(*my, *std);
    }
    else
    {
        EXPECT_EQ(my, std);
    }
}
