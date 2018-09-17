#include "deepModel/Treadmill.h"
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

const char* sampleFrame =
        "1 2 3 "
        "4 5 6 "
        "7 8 9 "
        ""
        "10 11 12 "
        "13 14 15 "
        ""
        "16 17 18 "
        "19 20 21 ";


int main()
{
    auto model = biomodel::deepModel::Treadmill().getModel();

    std::cout << model.root.dump() << std::endl;

    FrameDescription frameDescription = model.root.getFrameDescription();
    Frame frame(sampleFrame, frameDescription);
    frame.print();

    return 0;
}