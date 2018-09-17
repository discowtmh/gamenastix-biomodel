// This file is a part of Treadmill project.
// Copyright 2018 Disco WTMH S.A.

#include <string>
#include <vector>


enum Mode
{
    STATIC,
    DYNAMIC
};

extern std::vector<std::string> ModeString;

std::ostream &operator<<(std::ostream &os, Mode &mode);
