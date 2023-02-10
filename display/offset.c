#include "../includes/cube3D.h"

float playerOffset(float value)
{
    return (value * CELL_SIZE + CELL_SIZE / 2);
}

float minimapOffset(float value)
{
    return ((playerOffset(value) * MINIMAP_RATIO) / CELL_SIZE);
}