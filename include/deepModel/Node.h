// This file is a part of treadmill-t2-biomodel project.
// Copyright 2018 Disco WTMH S.A.

#pragma once

#include <vector>
#include <segment/Segment.h>


namespace biomodel {
namespace deepModel {

    struct Node
{
    segment::Enum segmentEnum;
    std::vector<Node> children;
};
}
}
