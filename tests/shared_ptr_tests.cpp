#include "../project-headers/shared_ptr.h"
#include <gtest/gtest.h>
#include <string>

TEST(SharedPtrConstructor, DefaultConstructorUseCount)
{
    sSTL::shared_ptr<int> sptr {};
    EXPECT_EQ(sptr.use_count(), 0);
    EXPECT_EQ(sptr.get(), nullptr);
}

TEST(SharedPtrConstructor, BasicConstructorUseCount)
{
    sSTL::shared_ptr<int> sptr {new int {10}};
    EXPECT_EQ(sptr.use_count(), 1);
}

TEST(SharedPtrConstructor, CopyConstructorUseCount)
{
    sSTL::shared_ptr<int> sptr1 {new int {10}};
    sSTL::shared_ptr<int> sptr2 {sptr1};
    EXPECT_EQ(sptr1.use_count(), 2);
    EXPECT_EQ(sptr2.use_count(), 2);
}

TEST(SharedPtrCopying, MultipleCopiesShareTheSameControlBlock)
{
    sSTL::shared_ptr<std::string> a{new std::string{"hello"}};
    EXPECT_EQ(a.use_count(), 1);

    {
        sSTL::shared_ptr<std::string> b{a};
        EXPECT_EQ(a.get(), b.get());
        EXPECT_EQ(a.use_count(), 2);
        EXPECT_EQ(b.use_count(), 2);

        {
            sSTL::shared_ptr<std::string> c{b};
            EXPECT_EQ(a.get(), c.get());
            EXPECT_EQ(a.use_count(), 3);
            EXPECT_EQ(b.use_count(), 3);
            EXPECT_EQ(c.use_count(), 3);
        }
        EXPECT_EQ(a.use_count(), 2);
        EXPECT_EQ(b.use_count(), 2);
    }
    EXPECT_EQ(a.use_count(), 1);
}

TEST(SharedPtrGet, BasicGet)
{
    sSTL::shared_ptr<int> sptr {new int {10}};
    EXPECT_EQ(*sptr.get(), 10);
}

TEST(SharedPtrGet, BasicGetObject)
{
    struct A
    {
        int number {10};
    };

    sSTL::shared_ptr<A> sptr {new A {}};
    EXPECT_EQ(sptr.get()->number, 10);
}

TEST(SharedPtrScopes, CountsDecreaseOnScopeExit)
{
    sSTL::shared_ptr<int> root{new int{42}};
    EXPECT_EQ(root.use_count(), 1);

    {
        sSTL::shared_ptr<int> c1{root};
        EXPECT_EQ(root.use_count(), 2);

        {
            sSTL::shared_ptr<int> c2{root};
            EXPECT_EQ(root.use_count(), 3);
            EXPECT_EQ(*c2.get(), 42);
        }

        EXPECT_EQ(root.use_count(), 2);
        EXPECT_EQ(*c1.get(), 42);
    }

    EXPECT_EQ(root.use_count(), 1);
    EXPECT_EQ(*root.get(), 42);
}

TEST(SharedPtrMove, DISABLED_MoveConstructorTransfersOwnershipSafely)
{
    sSTL::shared_ptr<int> a{new int{123}};
    EXPECT_EQ(a.use_count(), 1);

    sSTL::shared_ptr<int> b{std::move(a)};
    EXPECT_EQ(a.get(), nullptr);
    EXPECT_EQ(a.use_count(), 0);
    EXPECT_EQ(b.use_count(), 1);
    EXPECT_NE(b.get(), nullptr);
    EXPECT_EQ(*b.get(), 123);
}

TEST(SharedPtrMove, DISABLED_MoveAssignmentTransfersOwnershipSafely)
{
    sSTL::shared_ptr<int> a{new int{10}};
    sSTL::shared_ptr<int> b{new int{20}};

    b = std::move(a);
    EXPECT_EQ(a.get(), nullptr);
    EXPECT_EQ(a.use_count(), 0);
    EXPECT_EQ(b.use_count(), 1);
    EXPECT_NE(b.get(), nullptr);
    EXPECT_EQ(*b.get(), 10);
}