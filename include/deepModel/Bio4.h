// This file is a part of Treadmill project.
// Copyright 2018 Disco WTMH S.A.

#pragma once

#include "Medium.h"
#include <deepModel/Model.h>
#include <segment/BodySegment.h>


namespace biomodel {
namespace deepModel {

struct Bio4 : public Medium
{
    Model getModel() const override
    {
        static const char* modelDescription =
            "PELVIS ORIENTATION DYNAMIC "
            " LEFT_LEG_OFFSET DISPLACEMENT STATIC 0.0 0.0 0.0 "
            "  LEFT_LEG_UPPER ORIENTATION DYNAMIC "
            "   LEFT_LEG_LOWER ORIENTATION DYNAMIC "
            " RIGHT_LEG_OFFSET DISPLACEMENT STATIC 0.0 0.0 0.0 "
            "  RIGHT_LEG_UPPER ORIENTATION DYNAMIC "
            "   RIGHT_LEG_LOWER ORIENTATION DYNAMIC ";

        static Model model = {Node(modelDescription)};
        return model;
    }
};
}
}