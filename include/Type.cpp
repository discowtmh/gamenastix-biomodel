// This file is a part of Treadmill project.
// Copyright 2018 Disco WTMH S.A.

#include "Type.h"


std::vector<std::string> TypeString{
        "DISPLACEMENT",
        "ORIENTATION",
        "TRACKER"};

std::ostream &operator<<(std::ostream &os, Type &type)
{
    os << TypeString[static_cast<int>(type)];
    return os;
}


