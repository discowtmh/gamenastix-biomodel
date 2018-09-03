// This file is a part of treadmill-t2-biomodel project.
// Copyright 2018 Disco WTMH S.A.

#include <glm/glm.hpp>
#include <segment/BodySegment.h>
#include <layout/Joint.h>


namespace biomodel {
namespace deepModel {

struct Bone
{
    segment::Enum segmentEnum;
    Joint joint;
    glm::vec4 orientation;
};
}
}