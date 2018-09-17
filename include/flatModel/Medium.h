// This file is a part of treadmill-t2-biomodel project.
// Copyright 2018 Disco WTMH S.A.

#pragma once

#include <flatModel/Model.h>


namespace biomodel {
namespace flatModel {

struct Medium
{
    virtual Model getModel() const = 0;
};
}
}