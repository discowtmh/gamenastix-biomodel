// This file is a part of treadmill-t2-biomodel project.
// Copyright 2018 Disco WTMH S.A.

#pragma once


namespace biomodel {
namespace segment {

using Enum = int;

struct SegmentEnumerator
{
    static Enum get()
    {
        static SegmentEnumerator segmentEnumerator;
        return segmentEnumerator.maxValue++;
    }

    Enum maxValue;
};

#define SEGMENT(segment, baseSegment)                     \
    struct segment : public baseSegment                   \
    {                                                     \
        Enum getEnum() override                           \
        {                                                 \
            static Enum value = SegmentEnumerator::get(); \
            return value;                                 \
        }                                                 \
    }

struct Segment
{
    virtual Enum getEnum() = 0;
};
}
}
