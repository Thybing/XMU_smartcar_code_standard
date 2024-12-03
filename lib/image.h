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