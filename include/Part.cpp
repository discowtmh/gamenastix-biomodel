// This file is a part of Treadmill project.
// Copyright 2018 Disco WTMH S.A.

#include "Part.h"
#include <string>
#include <vector>


std::vector<std::string> PartString = {
    "CRANE",
    "DISTANCE",
    "BACKPACK",
    "LEFT_LEG_OFFSET",
    "LEFT_LEG_UPPER",
    "LEFT_LEG_LOWER",
    "RIGHT_LEG_OFFSET",
    "RIGHT_LEG_UPPER",
    "RIGHT_LEG_LOWER"};

std::ostream &operator<<(std::ostream &os, Part &part)
{
    os << PartString[static_cast<int>(part)];
    return os;
}
