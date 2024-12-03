#ifndef LINE_H
#define LINE_H

#include <stdbool.h>

#include "point.h"

/**
 * 表示一条线段的数据结构，包含多个点的信息。
 */
typedef struct
{
    point *data;       // 指向线段点数组的首地址
    uint16_t size;     // 当前线段包含的点数量
    uint16_t capacity; // 线段的最大点数量，确保不超过预分配的空间
} line;

/**
 * 初始化线段。
 *
 * @param self     指向需要初始化的 line 结构的指针。
 * @param capacity 要分配的最大点数量（容量）。
 * @return         初始化成功返回 true；如果失败（如内存不足）返回 false。
 *
 * @warning        调用者需要确保在初始化成功后再使用 line。
 */
bool line_init(line *self, uint16_t capacity);

/**
 * 清空线段。
 *
 * @param self 指向需要清空的 line 结构的指针。
 *
 * @warning 此函数不会释放内存，仅重置 `size`，以便重新使用。
 */
void line_clear(line *self);

#endif // LINE_H
