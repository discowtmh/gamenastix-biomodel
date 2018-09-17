// This file is a part of treadmill-t2-biomodel project.
// Copyright 2018 Disco WTMH S.A.

#include "googletest"
#include <deepModel/Bio4.h>
#include <deepModel/Model.h>
#include <deepModel/Node.h>
#include <segment/BodySegment.h>
#include <flatModel/Model.h>
#include <flatModel/Bio4.h>


namespace {
bool hasSegment(biomodel::flatModel::Model& model, biomodel::segment::Enum segmentEnum)
{
    return std::any_of(
        model.cbegin(),
        model.cend(),
        [segmentEnum](biomodel::segment::Enum testedSegment) {
            return segmentEnum == testedSegment;
        });
}
}


TEST(SkeletonTestSuite, FullStructure)
{
    // given
    biomodel::flatModel::Model skeleton = biomodel::flatModel::Bio4{}.getModel();

    // when

    // then
    EXPECT_TRUE(hasSegment(skeleton, biomodel::segment::UpperLegLeft{}.getEnum()));
    EXPECT_TRUE(hasSegment(skeleton, biomodel::segment::LowerLegLeft{}.getEnum()));
    EXPECT_TRUE(hasSegment(skeleton, biomodel::segment::UpperLegRight{}.getEnum()));
    EXPECT_TRUE(hasSegment(skeleton, biomodel::segment::LowerLegRight{}.getEnum()));
    EXPECT_FALSE(hasSegment(skeleton, biomodel::segment::Head{}.getEnum()));
}


GTEST_MAIN()
