// This file is a part of treadmill-t2-biomodel project.
// Copyright 2018 Disco WTMH S.A.

#pragma once

#include <flatModel/Medium.h>
#include <segment/BodySegment.h>


namespace biomodel {
namespace flatModel {

struct Bio8 : public Medium
{
    Model getModel() const override
    {
        static Model model = {
            segment::UpperArmLeft{}.getEnum(),
            segment::ForearmLeft{}.getEnum(),
            segment::UpperArmRight{}.getEnum(),
            segment::ForearmRight{}.getEnum(),
            segment::UpperLegLeft{}.getEnum(),
            segment::LowerLegLeft{}.getEnum(),
            segment::UpperLegRight{}.getEnum(),
            segment::LowerLegRight{}.getEnum()};
        return model;
    }
};
}
}
