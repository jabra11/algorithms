#include <vector>

#include <gtest/gtest.h>

#include <sorting/insertion_sort.hpp>
#include <sorting/selection_sort.hpp>

#include <jab_utils/utils.hpp>


TEST(insertion_sort_test, PositiveNos)
{
    auto vec = jab::utility::generate_randomly_filled_vec<int>(1000);
    jab::sorting::insertion_sort(vec.begin(), vec.end());

    EXPECT_TRUE(jab::utility::is_sorted(vec.begin(), vec.end()));
}

TEST(selection_sort_test, PositiveNos)
{
    auto vec = jab::utility::generate_randomly_filled_vec<int>(1000);
    jab::sorting::selection_sort(vec.begin(), vec.end());

    EXPECT_TRUE(jab::utility::is_sorted(vec.begin(), vec.end()));
}
