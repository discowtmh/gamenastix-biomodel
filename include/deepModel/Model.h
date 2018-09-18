// This file is a part of treadmill-t2-biomodel project.
// Copyright 2018 Disco WTMH S.A.

#pragma once

#include <Node.h>


namespace biomodel {
namespace deepModel {

struct Model
{
    Node root;
    std::vector<uint8_t> getSerializedModel()
    {
        return root.getSerializedModel();
    }

    std::vector<uint8_t> getSerializedFrame()
    {
        return frame.serialize();

   }
    void update(Part part, Params params)
    {
        frame.modelMap[part]->params = params;
    }
        Frame frame;
};
}
}
