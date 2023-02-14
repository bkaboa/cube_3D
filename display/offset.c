#include "../includes/cube3D.h"

float playerOffset(float value)
{
    return (value * CELL_SIZE);
}

float minimapOffset(float value)
{
    return ((playerOffset(value) * MINIMAP_RATIO) / CELL_SIZE);
}