// This file is a part of treadmill-t2-biomodel project.
// Copyright 2018 Disco WTMH S.A.

#pragma once

#include <segment/Segment.h>


namespace biomodel {
namespace segment {
    
struct CyborgSegment : public Segment
{
};

SEGMENT(Backpack, CyborgSegment);

SEGMENT(Crane, CyborgSegment);
}
}