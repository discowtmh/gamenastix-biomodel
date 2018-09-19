// This file is a part of treadmill-t2-biomodel project.
// Copyright 2018 Disco WTMH S.A.

#pragma once

#include <Node.h>


namespace biomodel {
namespace deepModel {

struct Model
{
    Model(Node&& node)
            : root(node)
            , frame(root.getFrameDescription())
    {
        std::cout << frame.dump() << std::endl;
    }

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
        for(auto& frameRef : frame.model)
        {
            if (frameRef.part == part)
            {
                frameRef.params = params;
            }
        }
    }

    Node root;
    Frame frame;
};
}
}
