#include "../includes/cube3D.h"


float Offset(t_cube cube, float value)
{
    return (value * cube.mlx.minimap_ratio);
}
