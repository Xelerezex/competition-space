# Задаём содержимое для файла NAME.cpp
$cppContent =
@"
#include <gtest/gtest.h>

class Solution
{
public:

};

TEST (SolutionTest, Example1)
{
    const auto result = true; // Solution{};
    const auto& expected = true;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
"@
