# 智能车图像处理相关数据结构-图片

```c
#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h>

typedef uint8_t pixel_t;

typedef struct
{
    pixel_t *data;   // 图像首地址
    uint16_t width;  // 图像宽度
    uint16_t height; // 图像高度
} image;

/**
 * 初始化图像对象。
 *
 * @param self   指向需要初始化的图像对象。
 * @param data   图像数据的首地址。
 * @param width  图像宽度。
 * @param height 图像高度。
 * @return       初始化成功返回 true。
 */
bool image_init(image *self, pixel_t *data, uint16_t width, uint16_t height);

#endif // IMAGE_H
```

为了统一图像处理算法的接口，防止算法函数参数过多且不统一，我们将图像进行一些简单的封装。其内部包含了图像的首地址，图像的宽度和高度。  

这里要注意图像的init不会为图像分配空间，我们需要在外面申请好空间（一般是一个二维的全局数组变量），然后一起传入init函数内进行使用。  

另外，一般来说大部分项目只需要用到8位深度的灰度图，所以并没有做泛型设计。如果项目中需要两种类型的pixel_t，那么请自行模仿以上代码写出另一个结构体来封装另一种图片。  

对于图片的参数传递，一般情况下结构体内部的值均在初始化后不会改变，所以进行简单的传值调用即可。

使用例：

```c

uint8_t image_memory[120][188];

void fn(image input_image) 
{
    //(input_image.data)[y][x]
}

int main() 
{
    image foo;
    image_init(&foo, &(image_memory[0][0]), 188, 120);

}

```