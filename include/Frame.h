// This file is a part of Treadmill project.
// Copyright 2018 Disco WTMH S.A.

#pragma once

#include <Part.h>
#include <Type.h>
#include <cstring>
#include <iostream>
#include <sstream>
#include <unordered_map>

#include "Parser.h"


using FrameDescription = std::vector<std::pair<Part, Type>>;

using Params = std::vector<float>;

using StaticDescription = std::vector<std::pair<Part, Params>>;

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

    static Params getInitialParams(Type type)
    {
        switch (type)
        {
            case Type::DISPLACEMENT:
                return {0.0F, 0.0F, 0.0F};
            case Type::ORIENTATION:
                return {0.0F, 0.0F, 0.0F};
            case Type::TRACKER:
                return {0.0F, 0.0F, 0.0F};
        }
        return {};
    }


    Frame() = default;
    Frame(const FrameDescription &frameDescription)
    {
        for (auto &frameDescriptionElement : frameDescription)
        {
            auto part = frameDescriptionElement.first;
            auto type = frameDescriptionElement.second;
            model.push_back({part, type, getInitialParams(type)});
        }
    }
    Frame(const char *c, FrameDescription &frameDescription)
    {
        size_t i = strlen(c);
        const char *e = c + i;
        for (auto &frameDescriptionElement : frameDescription)
        {
            auto part = frameDescriptionElement.first;
            auto type = frameDescriptionElement.second;
            model.push_back({part, type, getParams(type, c, e)});
            c++;
        }
    }
    std::vector<FrameElement> model;

    std::string dumpHuman()
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

    std::string dumpSerial()
    {
        std::stringstream ss;
        for (auto &frameElement : model)
        {
            for (auto &x : frameElement.params)
            {
                ss << x << " ";
            }
            ss << " ";
        }
        return ss.str();
    }

    std::vector<uint8_t> serialize()
    {
        auto serializedString = dumpSerial();
        return std::vector<uint8_t>(serializedString.begin(), serializedString.end());
    }

    void print()
    {
        std::cout << dumpHuman() << std::endl;
    }
};
