// This file is a part of Treadmill project.
// Copyright 2018 Disco WTMH S.A.

#pragma once

#include <string>
#include <vector>


enum Part
{
    CRANE,
    DISTANCE,
    BACKPACK,
    LEFT_LEG_OFFSET,
    LEFT_LEG_UPPER,
    LEFT_LEG_LOWER,
    RIGHT_LEG_OFFSET,
    RIGHT_LEG_UPPER,
    RIGHT_LEG_LOWER
};

extern std::vector<std::string> PartString;

std::ostream &operator<<(std::ostream &os, Part &part);
