// This file is a part of treadmill-t2-biomodel project.
// Copyright 2018 Disco WTMH S.A.

#pragma once

#include <segment/Segment.h>


namespace biomodel {
namespace segment {

struct BodySegment : public Segment
{
};

SEGMENT(Head, BodySegment);

SEGMENT(Chest, BodySegment);

SEGMENT(Pelvis, BodySegment);

SEGMENT(ShoulderLeft, BodySegment);

SEGMENT(ShoulderRight, BodySegment);

SEGMENT(UpperArmLeft, BodySegment);

SEGMENT(UpperArmRight, BodySegment);

SEGMENT(ForearmLeft, BodySegment);

SEGMENT(ForearmRight, BodySegment);

SEGMENT(HandLeft, BodySegment);

SEGMENT(HandRight, BodySegment);

SEGMENT(UpperLegLeft, BodySegment);

SEGMENT(UpperLegRight, BodySegment);

SEGMENT(LowerLegLeft, BodySegment);

SEGMENT(LowerLegRight, BodySegment);

SEGMENT(FootLeft, BodySegment);

SEGMENT(FootRight, BodySegment);
}
}
