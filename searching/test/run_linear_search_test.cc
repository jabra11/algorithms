#include <vector>

#include <gtest/gtest.h>

#include <jab/searching/linear_search.hpp>
#include <jab/utils/utils.hpp>


TEST(linear_search_test, randomly_filled_vec)
{
    using elem_type = int;
    auto vec = jab::utility::generate_randomly_filled_vec<elem_type>(10000, -1000, 1000);
    int target = jab::utility::generate_randomly_filled_vec<elem_type>(1,-1000,1000)[0];

    auto my = jab::searching::linear_search(vec.begin(), vec.end(), target);
    auto std = std::find(vec.begin(), vec.end(), target);

    EXPECT_EQ(my, std);
}
