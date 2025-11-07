#include "../small-STL-headers/vector.h"
#include <gtest/gtest.h>
#include <string>

TEST(VectorBasic, DefaultConstructedIsEmpty)
{
    sSTL::vector<int> v;
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 0);
}

TEST(VectorBasic, SizedConstructionInitializesWithDefaultValues)
{
    sSTL::vector<int> v(5);
    ASSERT_EQ(v.size(), 5);
    ASSERT_EQ(v.capacity(), 5);
    for (size_t i = 0; i < v.size(); ++i)
        EXPECT_EQ(v[i], 0);
}

TEST(VectorInitList, InitializesWithElements)
{
    sSTL::vector<int> v{1, 2, 3};
    ASSERT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
}

TEST(VectorPushBack, GrowsCapacityAndKeepsValues)
{
    sSTL::vector<int> v;
    v.push_back(10);
    EXPECT_EQ(v.size(), 1);
    EXPECT_GE(v.capacity(), 1);
    EXPECT_EQ(v[0], 10);

    v.push_back(20);
    v.push_back(30);
    EXPECT_EQ(v.size(), 3);
    EXPECT_GE(v.capacity(), 3);
    EXPECT_EQ(v[1], 20);
    EXPECT_EQ(v[2], 30);
}

TEST(VectorIndexing, AtThrowsOnOutOfRange)
{
    sSTL::vector<int> v{1, 2};
    EXPECT_NO_THROW(v.at(0));
    EXPECT_NO_THROW(v.at(1));
    EXPECT_THROW(v.at(2), std::out_of_range);
}

TEST(VectorIndexing, SubscriptReturnsReference)
{
    sSTL::vector<int> v{5, 6, 7};
    int& ref = v[1];
    ref = 42;
    EXPECT_EQ(v[1], 42);
}

TEST(VectorPopBack, ReducesSizeAndKeepsFront)
{
    sSTL::vector<std::string> v{"a", "b", "c"};
    v.pop_back();
    ASSERT_EQ(v.size(), 2);
    EXPECT_EQ(v[0], "a");
    EXPECT_EQ(v[1], "b");
}

TEST(VectorReserve, IncreasesCapacityWithoutChangingSizeOrValues)
{
    sSTL::vector<int> v{1, 2, 3};
    const auto old_size = v.size();
    const auto old_cap  = v.capacity();
    v.reserve(old_cap + 10);
    EXPECT_EQ(v.size(), old_size);
    EXPECT_GE(v.capacity(), old_cap + 10);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
}

TEST(VectorShrinkToFit, BasicShrink)
{
    sSTL::vector<int> v{1, 2, 3};
    v.pop_back();
    v.shrink_to_fit();
    EXPECT_EQ(v.capacity(), v.size());
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
}

TEST(VectorMoveSemantics, MoveConstructorTransfersOwnership)
{
    sSTL::vector<int> src{1, 2, 3, 4};
    const auto cap_before = src.capacity();
    sSTL::vector<int> dst(std::move(src));

    ASSERT_EQ(dst.size(), 4);
    ASSERT_GE(dst.capacity(), cap_before);
    EXPECT_EQ(dst[0], 1);
    EXPECT_EQ(dst[3], 4);

    EXPECT_EQ(src.size(), 0);
    EXPECT_EQ(src.capacity(), 0);
}

TEST(VectorMoveSemantics, MoveAssignmentTransfersOwnership)
{
    sSTL::vector<int> a{7, 8};
    sSTL::vector<int> b;
    b = std::move(a);

    ASSERT_EQ(b.size(), 2);
    EXPECT_EQ(b[0], 7);
    EXPECT_EQ(b[1], 8);

    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.capacity(), 0);
}

TEST(VectorMoveSemantics, CheckIfDataIsProperlyDeallocated)
{
    sSTL::vector<int> a{1, 2};
    sSTL::vector<int> b{3, 4, 5};
    b = std::move(a);

    ASSERT_EQ(b.size(), 2);
    EXPECT_EQ(b[0], 1);
    EXPECT_EQ(b[1], 2);

    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.capacity(), 0);
}