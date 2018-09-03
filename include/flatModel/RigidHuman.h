// This file is a part of treadmill-t2-biomodel project.
// Copyright 2018 Disco WTMH S.A.

#pragma once

#include <flatModel/Medium.h>
#include <segment/BodySegment.h>


namespace biomodel {
namespace flatModel {
struct RigidBody : public Medium
{
    Model getModel() const override
    {
        static Model model = {
            segment::Head{}.getEnum(),
            segment::Chest{}.getEnum(),
            segment::Pelvis{}.getEnum(),
            segment::ShoulderLeft{}.getEnum(),
            segment::ShoulderRight{}.getEnum(),
            segment::UpperArmLeft{}.getEnum(),
            segment::UpperArmRight{}.getEnum(),
            segment::ForearmLeft{}.getEnum(),
            segment::ForearmRight{}.getEnum(),
            segment::HandLeft{}.getEnum(),
            segment::HandRight{}.getEnum(),
            segment::UpperLegLeft{}.getEnum(),
            segment::UpperLegRight{}.getEnum(),
            segment::LowerLegLeft{}.getEnum(),
            segment::LowerLegRight{}.getEnum(),
            segment::FootLeft{}.getEnum(),
            segment::FootRight{}.getEnum()};
        return model;
    }
};
}
}