// This file is a part of treadmill-t2-biomodel project.
// Copyright 2018 Disco WTMH S.A.

#include "googletest"
#include <deepModel/Bio4.h>
#include <deepModel/Model.h>
#include <deepModel/Node.h>
#include <segment/BodySegment.h>


namespace {
bool hasSegment(biomodel::deepModel::Node& node, biomodel::segment::Enum segmentEnum)
{
    return ((node.segmentEnum == segmentEnum)
            || std::any_of(
                   node.children.cbegin(),
                   node.children.cend(),
                   [segmentEnum](biomodel::deepModel::Node childNode) {
                       return hasSegment(childNode, segmentEnum);
                   }));
}

bool hasSegment(biomodel::deepModel::Model& model, biomodel::segment::Enum segmentEnum)
{
    return hasSegment(model.root, segmentEnum);
}
}


TEST(SkeletonTestSuite, FullStructure)
{
    // given
    biomodel::deepModel::Model skeleton = biomodel::deepModel::Bio4{}.getModel();

    // when

    // then
    EXPECT_TRUE(hasSegment(skeleton, biomodel::segment::Pelvis{}.getEnum()));
    EXPECT_TRUE(hasSegment(skeleton, biomodel::segment::UpperLegLeft{}.getEnum()));
    EXPECT_TRUE(hasSegment(skeleton, biomodel::segment::LowerLegLeft{}.getEnum()));
    EXPECT_TRUE(hasSegment(skeleton, biomodel::segment::UpperLegRight{}.getEnum()));
    EXPECT_TRUE(hasSegment(skeleton, biomodel::segment::LowerLegRight{}.getEnum()));
    EXPECT_FALSE(hasSegment(skeleton, biomodel::segment::Head{}.getEnum()));
}


GTEST_MAIN()
