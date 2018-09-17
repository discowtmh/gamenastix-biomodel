// This file is a part of treadmill-t2-biomodel project.
// Copyright 2018 Disco WTMH S.A.

#pragma once

#include <flatModel/Medium.h>
#include <segment/BodySegment.h>
#include <segment/CyborgSegment.h>


namespace biomodel {
namespace flatModel {
struct RigidBody : public Medium
{
    Model getModel() const override
    {
        static Model model = {
            segment::UpperLegLeft{}.getEnum(),
            segment::LowerLegLeft{}.getEnum(),
            segment::UpperLegRight{}.getEnum(),
            segment::LowerLegRight{}.getEnum(),
            segment::Backpack{}.getEnum(),
            segment::Crane{}.getEnum(),
        };
        return model;
    }
};
}
}