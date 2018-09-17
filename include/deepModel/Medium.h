// This file is a part of treadmill-t2-biomodel project.
// Copyright 2018 Disco WTMH S.A.

#pragma once

#include <deepModel/Model.h>


namespace biomodel {
namespace deepModel {

struct Medium
{
    virtual Model getModel() const = 0;
};
}
}