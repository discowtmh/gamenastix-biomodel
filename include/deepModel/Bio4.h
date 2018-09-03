// This file is a part of treadmill-t2-biomodel project.
// Copyright 2018 Disco WTMH S.A.

#pragma once

#include <deepModel/Model.h>
#include <segment/BodySegment.h>
#include "Medium.h"


namespace biomodel {
namespace deepModel {

struct Bio4 : public Medium
{
    Model getModel() const override
    {
        static Model model = {
            biomodel::deepModel::Node{
                biomodel::segment::Pelvis{}.getEnum(),
                {biomodel::deepModel::Node{
                     biomodel::segment::UpperLegLeft{}.getEnum(),
                     {biomodel::deepModel::Node{
                         biomodel::segment::LowerLegLeft{}.getEnum(),
                         {}}}},
                 biomodel::deepModel::Node{
                     biomodel::segment::UpperLegRight{}.getEnum(),
                     {biomodel::deepModel::Node{
                         biomodel::segment::LowerLegRight{}.getEnum(), {}}}}}}};
        return model;
    }
};
}
}