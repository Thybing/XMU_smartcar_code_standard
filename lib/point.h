#ifndef POINT_H
#define POINT_H

#include <stdint.h>

// 定义坐标数据的类型。这里使用 uint8_t，可自行调整
typedef uint8_t coordinate_data_t;

typedef struct
{
    coordinate_data_t x; // 横坐标
    coordinate_data_t y; // 纵坐标
} point;

#endif // POINT_H