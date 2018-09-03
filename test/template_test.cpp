// This file is a part of treadmill-t2-biomodel project.
// Copyright 2018 Disco WTMH S.A.

#include "googletest"


TEST(suite, case)
{
    // given
    int two = 2;

    // when
    int result = two * two;

    // then
    EXPECT_EQ(result, 4);
}


GTEST_MAIN()
