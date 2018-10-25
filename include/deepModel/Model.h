// This file is a part of treadmill-t2-biomodel project.
// Copyright 2018 Disco WTMH S.A.

#pragma once

#include <Node.h>
#include <Protocol.h>


namespace biomodel {
namespace deepModel {

struct Model
{
    Model(Node&& node)
            : root(node)
            , frameDescription(root.getFrameDescription())
            , frame(frameDescription)
            , staticDescription(root.getStaticDescription())
    {
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

    Params get(Part part)
    {
        for(auto& frameRef : frame.model)
        {
            if (frameRef.part == part)
            {
                return frameRef.params;
            }
        }

        for(auto& modelRef : staticDescription)
        {
            if (modelRef.first == part)
            {
                return modelRef.second;
            }
        }

        throw std::runtime_error("");
    }

    void update(Message& message)
    {
        frame = Frame(reinterpret_cast<const char *>(&message[1]), frameDescription);
    }

    Node root;
    FrameDescription frameDescription;
    StaticDescription staticDescription;
    Frame frame;
};
}
}
