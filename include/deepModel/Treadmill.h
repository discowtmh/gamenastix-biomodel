// This file is a part of Treadmill project.
// Copyright 2018 Aleksander Gajewski <adiog@brainfuck.pl>.

#pragma once

#include "Medium.h"
#include <deepModel/Model.h>
#include <segment/BodySegment.h>

namespace biomodel {
namespace deepModel {

/**
 * Treadmill Model
 *
 * @brief Complete model for Treadmill 2.0
 *
 * Model has a following structure: \n
 * \n
 * CRANE ORIENTATION DYNAMIC \n
 * \ DISTANCE DISPLACEMENT DYNAMIC \n
 * \ \ BACKPACK ORIENTATION DYNAMIC \n
 * \ \ \ LEFT_LEG_OFFSET DISPLACEMENT STATIC 0 0.0 0.0 \n
 * \ \ \ \ LEFT_LEG_UPPER ORIENTATION DYNAMIC \n
 * \ \ \ \ \ LEFT_LEG_LOWER ORIENTATION DYNAMIC \n
 * \ \ \ RIGHT_LEG_OFFSET DISPLACEMENT STATIC 0.0 0.0 0.0 \n
 * \ \ \ \ RIGHT_LEG_UPPER ORIENTATION DYNAMIC \n
 * \ \ \ \ \ RIGHT_LEG_LOWER ORIENTATION DYNAMIC \n
 * \n
 * Each frame contains the current orientation (euler yaw/pitch/roll angles)
 * and displacement (3 dimensional relative offset) for each dynamic component:\n
 * \n
 * CRANE\n
 * DISTANCE\n
 * BACKPACK\n
 * LEFT_LEG_UPPER\n
 * LEFT_LEG_LOWER\n
 * RIGHT_LEG_UPPER\n
 * RIGHT_LEG_LOWER
 **/
struct Treadmill : public Medium
{
    Model getModel() const override
    {
        static const char* modelDescription =
            "CRANE ORIENTATION DYNAMIC "
            " DISTANCE DISPLACEMENT DYNAMIC "
            "  BACKPACK ORIENTATION DYNAMIC "
            "   LEFT_LEG_OFFSET DISPLACEMENT STATIC 0.0 0.0 0.0 "
            "    LEFT_LEG_UPPER ORIENTATION DYNAMIC "
            "     LEFT_LEG_LOWER ORIENTATION DYNAMIC "
            "   RIGHT_LEG_OFFSET DISPLACEMENT STATIC 0.0 0.0 0.0 "
            "    RIGHT_LEG_UPPER ORIENTATION DYNAMIC "
            "     RIGHT_LEG_LOWER ORIENTATION DYNAMIC ";

        static Model model = Model{Node(modelDescription)};
        return model;
    }
};
}
}
