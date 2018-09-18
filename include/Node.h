// This file is a part of Treadmill project.
// Copyright 2018 Disco WTMH S.A.

#include <string>
#include <vector>
#include <stdexcept>
#include "Part.h"
#include "Type.h"
#include "Mode.h"
#include "Frame.h"


struct Node
{
    Node()
            : nodes(0)
    {
    }

    static int getWordLength(const char *c, const char *e)
    {
        int wordLength = 0;
        while ((c < e) && (*c != ' ') && (*c != '\n'))
        {
            c++;
            wordLength++;
        }
        return wordLength;
    }

    static int getLevel(const char *&c, const char *e)
    {
        int level = 0;
        while ((c < e) && (*c == ' '))
        {
            c++;
            level++;
        }
        return level;
    }

    template <typename EnumType>
    static EnumType getEnum(const std::vector<std::string> &pattern, const char *&c, const char *e)
    {
        int wordLength = getWordLength(c, e);
        for (int index = 0; index < pattern.size(); index++)
        {
            if (pattern[index].size() == wordLength)
            {
                if (pattern[index] == std::string(c, wordLength))
                {
                    c += wordLength;
                    return static_cast<EnumType>(index);
                }
            }
        }
        throw std::runtime_error("");
    };

    static float getFloat(const char *&c, const char *e)
    {
        float f;
        sscanf(c, "%f", &f);
        c += getWordLength(c, e);
        return f;
    }

    static Part getPart(const char *&c, const char *e)
    {
        return getEnum<Part>(PartString, c, e);
    }

    static Type getType(const char *&c, const char *e)
    {
        return getEnum<Type>(TypeString, c, e);
    }

    static Mode getMode(const char *&c, const char *e)
    {
        return getEnum<Mode>(ModeString, c, e);
    }

    static int getParamsLength(Mode mode, Type type)
    {
        if (mode == Mode::STATIC)
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
        else
        {
            return 0;
        }
    }

    static Params getParams(Type type, Mode mode, const char *&c, const char *e)
    {
        Params params;
        int paramsLength = getParamsLength(mode, type);
        for (int i = 0; i < paramsLength; i++)
        {
            params.push_back(getFloat(c, e));
            c++;
        }
        return params;
    }


    static Node getNode(const char *&c, const char *e)
    {
        Node node;
        node.level = getLevel(c, e);
        node.part = getPart(c, e);
        c++;
        node.type = getType(c, e);
        c++;
        node.mode = getMode(c, e);
        c++;
        node.params = getParams(node.type, node.mode, c, e);
        return node;
    }

    static std::vector<Node> getNodes(const char *c, const char *e)
    {
        std::vector<Node> nodes;
        int offset;
        while (c < e)
        {
            nodes.push_back(getNode(c, e));
        }
        return nodes;
    }

    template <typename T>
    static Node dispatch(T &startIt, T &endIt)
    {
        Node node = *startIt;
        auto &nextStartIt = startIt;
        int level = node.level;
        nextStartIt++;
        while (nextStartIt < endIt)
        {
            auto nextEndIt = nextStartIt;
            nextEndIt++;
            while ((nextEndIt < endIt) && (nextEndIt->level != level))
            {
                nextEndIt++;
            }
            node.nodes.push_back(dispatch(nextStartIt, nextEndIt));
        }
        return node;
    }

    Node(const char *c)
    {
        int i = strlen(c);
        std::vector<Node> treeFlat = getNodes(c, c + i);
        auto bit = treeFlat.begin();
        auto eit = treeFlat.end();
        *this = dispatch(bit, eit);


        for (auto &node : treeFlat)
        {
            if (node.mode == DYNAMIC)
            {
                frameDescription.push_back({node.part, node.type});
            }
        }
    }

    std::string dump()
    {
        static const char *spaces = "                                       ";
        std::stringstream ss;
        ss << std::string(spaces, level)
                  << part << " "
                  << type << " "
                  << mode << " ";
        for (auto &param : params)
        {
            ss << param << " ";
        }
        ss << '\n';
        for (auto &node : nodes)
        {
            ss << node.dump();
        }
        return ss.str();
    }

    FrameDescription getFrameDescription()
    {
        return frameDescription;
    }

    int level;
    Part part;
    Type type;
    Mode mode;
    Params params;
    std::vector<Node> nodes;
    FrameDescription frameDescription;
};
