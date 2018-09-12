#include "sample.h"
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>


enum Part
{
    CRANE,
    DISTANCE,
    BACKPACK,
    LEFT_LEG_OFFSET,
    LEFT_LEG_UPPER,
    LEFT_LEG_LOWER,
    RIGHT_LEG_OFFSET,
    RIGHT_LEG_UPPER,
    RIGHT_LEG_LOWER
};


enum Type
{
    DISPLACEMENT,
    ORIENTATION,
    TRACKER
};

enum Mode
{
    STATIC,
    DYNAMIC
};

using FrameDescription = std::vector<std::pair<Part, Type>>;
using Params = std::vector<float>;

std::vector<std::string> PartString =
    {
        "CRANE",
        "DISTANCE",
        "BACKPACK",
        "LEFT_LEG_OFFSET",
        "LEFT_LEG_UPPER",
        "LEFT_LEG_LOWER",
        "RIGHT_LEG_OFFSET",
        "RIGHT_LEG_UPPER",
        "RIGHT_LEG_LOWER"};

std::vector<std::string> TypeString{
    "DISPLACEMENT",
    "ORIENTATION",
    "TRACKER"};

std::vector<std::string> ModeString{
    "STATIC",
    "DYNAMIC"};


std::ostream &operator<<(std::ostream &os, Part &part)
{
    os << PartString[static_cast<int>(part)];
    return os;
}

std::ostream &operator<<(std::ostream &os, Type &type)
{
    os << TypeString[static_cast<int>(type)];
    return os;
}

std::ostream &operator<<(std::ostream &os, Mode &mode)
{
    os << ModeString[static_cast<int>(mode)];
    return os;
}


struct FrameElement
{
    Part part;
    Type type;
    Params params;
};

int getWordLength(const char *c, const char *e)
{
    int wordLength = 0;
    while ((c < e) && (*c != ' ') && (*c != '\n'))
    {
        c++;
        wordLength++;
    }
    return wordLength;
}

float getFloat(const char *&c, const char *e)
{
    float f;
    sscanf(c, "%f", &f);
    c += getWordLength(c, e);
    return f;
}

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

    void print()
    {
        for (auto &frameElement : model)
        {
            std::cout << frameElement.part << " "
                      << frameElement.type << " ";
            for (auto &x : frameElement.params)
            {
                std::cout << x << " ";
            }
            std::cout << std::endl;
        }
    }
};

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

    void print()
    {
        static const char *spaces = "                                       ";
        std::cout << std::string(spaces, level)
                  << part << " "
                  << type << " "
                  << mode << " ";
        for (auto &param : params)
        {
            std::cout << param << " ";
        }
        std::cout << std::endl;
        for (auto &node : nodes)
        {
            node.print();
        }
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


int main()
{
    Node node(sample);
    node.print();

    std::cout << std::endl;

    FrameDescription frameDescription = node.getFrameDescription();
    Frame frame(sampleFrame, frameDescription);
    frame.print();

    return 0;
}