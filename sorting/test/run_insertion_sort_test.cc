#include <vector>

#include <gtest/gtest.h>

#include <jab/sorting/insertion_sort.hpp>
#include <jab/utils/utils.hpp>


TEST(insertion_sort_test, randomly_filled_vec)
{
    auto vec = jab::utility::generate_randomly_filled_vec<int>(1000);
    jab::sorting::insertion_sort(vec.begin(), vec.end());

    EXPECT_TRUE(jab::utility::is_sorted(vec.begin(), vec.end()));
}
