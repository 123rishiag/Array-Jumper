#pragma once
#include "BlockType.h"

namespace Level
{
    struct LevelData
    {
        static const int NUMBER_OF_BOXES = 10;

        BlockType level_boxes[NUMBER_OF_BOXES] = {
            BlockType::ONE,
            BlockType::TWO,
            BlockType::OBSTACLE_ONE,
            BlockType::TWO,
            BlockType::THREE,
            BlockType::ONE,
            BlockType::OBSTACLE_TWO,
            BlockType::TWO,
            BlockType::ONE,
            BlockType::TARGET };
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