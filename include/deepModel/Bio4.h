// This file is a part of Treadmill project.
// Copyright 2018 Disco WTMH S.A.

#pragma once

#include "Medium.h"
#include <deepModel/Model.h>
#include <segment/BodySegment.h>


namespace biomodel {
namespace deepModel {

/**
 * Simplified Legs Model
 *
 * @brief Simplified Legs model for Treadmill 2.0
 *
 * Model has a following structure: \n
 * \n
 * PELVIS ORIENTATION DYNAMIC \n
 * \ LEFT_LEG_OFFSET DISPLACEMENT STATIC 0.0 0.0 0.0 \n
 * \ \ LEFT_LEG_UPPER ORIENTATION DYNAMIC \n
 * \ \ \ LEFT_LEG_LOWER ORIENTATION DYNAMIC \n
 * \ RIGHT_LEG_OFFSET DISPLACEMENT STATIC 0.0 0.0 0.0 \n
 * \ \ RIGHT_LEG_UPPER ORIENTATION DYNAMIC \n
 * \ \ \ RIGHT_LEG_LOWER ORIENTATION DYNAMIC \n
 * \n
 * Each frame contains the current orientation (euler yaw/pitch/roll angles)
 * and displacement (3 dimensional relative offset) for each dynamic component:\n
 * \n
 * PELVIS\n
 * LEFT_LEG_UPPER\n
 * LEFT_LEG_LOWER\n
 * RIGHT_LEG_UPPER\n
 * RIGHT_LEG_LOWER
 **/
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
