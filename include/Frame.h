// This file is a part of Treadmill project.
// Copyright 2018 Disco WTMH S.A.

#pragma once

#include <Part.h>
#include <Type.h>
#include <cstring>
#include <iostream>
#include <sstream>
#include "Parser.h"

using FrameDescription = std::vector<std::pair<Part, Type>>;

using Params = std::vector<float>;

struct FrameElement
{
    Part part;
    Type type;
    Params params;
};


struct Frame
{
    static int getParamsLength(Type type)
    {
        if (type == Type::TRACKER)
        {
            return 6;
        }
        else
        {
            return 3;
        }
    }


    static Params getParams(Type type, const char *&c, const char *e)
    {
        Params params;
        int paramsLength = getParamsLength(type);
        for (int i = 0; i < paramsLength; i++)
        {
            params.push_back(getFloat(c, e));
            c++;
        }
        return params;
    }

    Frame(const char *c, FrameDescription &frameDescription)
    {
        int i = strlen(c);
        const char *e = c + i;
        for (auto &frameDescriptionElement : frameDescription)
        {
            auto part = frameDescriptionElement.first;
            auto type = frameDescriptionElement.second;
            model.push_back({part, type, getParams(type, c, e)});
        }
    }
    std::vector<FrameElement> model;

    std::string dump()
    {
        std::stringstream ss;
        for (auto &frameElement : model)
        {
            ss << frameElement.part << " "
                      << frameElement.type << " ";
            for (auto &x : frameElement.params)
            {
                ss << x << " ";
            }
            ss << "\n";
        }
        return ss.str();
    }

    void print()
    {
        std::cout << dump() << std::endl;
    }
};
