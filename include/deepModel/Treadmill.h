// This file is a part of Treadmill project.
// Copyright 2018 Aleksander Gajewski <adiog@brainfuck.pl>.

#pragma once

#include "Medium.h"
#include <deepModel/Model.h>
#include <segment/BodySegment.h>

namespace biomodel {
namespace deepModel {

struct Treadmill : public Medium
{
    Model getModel() const override
    {
        static const char* modelDescription =
            "CRANE ORIENTATION DYNAMIC "
            " DISTANCE DISPLACEMENT DYNAMIC "
            "  BACKPACK ORIENTATION DYNAMIC "
            "   LEFT_LEG_OFFSET DISPLACEMENT STATIC 1230.0 0.0 0.0 "
            "    LEFT_LEG_UPPER ORIENTATION DYNAMIC "
            "     LEFT_LEG_LOWER ORIENTATION DYNAMIC "
            "   RIGHT_LEG_OFFSET DISPLACEMENT STATIC 0.0 0.0 0.0 "
            "    RIGHT_LEG_UPPER ORIENTATION DYNAMIC "
            "     RIGHT_LEG_LOWER ORIENTATION DYNAMIC ";

        static Model model = {Node(modelDescription)};
        return model;
    }
};
}
}
