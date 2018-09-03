// This file is a part of treadmill-t2-biomodel project.
// Copyright 2018 Disco WTMH S.A.

#include "googletest"
#include <segment/Segment.h>
#include <memory>
#include <segment/BodySegment.h>


TEST(SkeletonTestSuite, FullStructure)
{
    // given
    std::unique_ptr<biomodel::segment::Segment> pelvis = std::make_unique<biomodel::segment::Pelvis>();
    std::unique_ptr<biomodel::segment::Segment> pelvisCopy = std::make_unique<biomodel::segment::Pelvis>();
    std::unique_ptr<biomodel::segment::Segment> head = std::make_unique<biomodel::segment::Head>();

    // when

    // then
    EXPECT_EQ(pelvis->getEnum(), pelvisCopy->getEnum());
    EXPECT_NE(head->getEnum(), pelvis->getEnum());
}


GTEST_MAIN()
