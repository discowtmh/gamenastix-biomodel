// This file is a part of Treadmill project.
// Copyright 2018 Disco WTMH S.A.

#include "Mode.h"


std::vector<std::string> ModeString{
    "STATIC",
    "DYNAMIC"};

std::ostream &operator<<(std::ostream &os, Mode &mode)
{
    os << ModeString[static_cast<int>(mode)];
    return os;
}
