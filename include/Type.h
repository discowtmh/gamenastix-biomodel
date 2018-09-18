// This file is a part of Treadmill project.
// Copyright 2018 Disco WTMH S.A.

#pragma once

#include <string>
#include <vector>


enum Type
{
    DISPLACEMENT,
    ORIENTATION,
    TRACKER
};

extern std::vector<std::string> TypeString;

std::ostream &operator<<(std::ostream &os, Type &type);
