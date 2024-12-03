# 智能车图像处理相关数据结构-点

```c
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
```

点是图像处理中最基本的要素，我们在此统一一下点的定义，方面后续统一算法接口。  
按照图像处理的一贯定义习惯，我们一般将图像的左上角定义为(0,0)，将水平向右定义为x轴正方向，垂直向下为y轴正方向。通俗的讲，x代表图像从左到右的列数，y代表从上到下的行数。  

在参数传递的过程中，由于此结构体仅占2个字节，所以我们在传入只读参数时可以直接进行传值调用。但是如果函数内部对其进行了修改并且需要传出，我们可以通过取地址的方式来进行传递。如下
```c
void fn(const point input_point) 
{
    //使用input_point做出一些计算
}

void fn2(point *const p_input_point)
{
    //使用p_input_point->x、p_input_point->y来读取或更改
}

void main() {
    point foo = {0, 0};
    fn(foo);
    fn2(&foo);
}

```