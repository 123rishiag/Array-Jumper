#pragma once
#include "BlockType.h"

namespace Level
{
    struct LevelData
    {
        static const int NUMBER_OF_BOXES = 10;

        BlockType level_boxes[NUMBER_OF_BOXES];
    };

    struct BoxDimensions
    {
        float box_width;
        float box_height;
        float box_spacing;

        float box_spacing_percentage = 0.3f;
        float bottom_offset = 200.f;
    };
}