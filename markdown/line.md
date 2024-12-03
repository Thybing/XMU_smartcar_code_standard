# 智能车图像处理相关数据结构-线

```c
#ifndef LINE_H
#define LINE_H

#include <stdbool.h>

#include "point.h"

/**
 * 表示一条线段的数据结构，包含多个点的信息。
 */
typedef struct 
{
    point *data;        // 指向线段点数组的首地址
    uint16_t size;      // 当前线段包含的点数量
    uint16_t capacity;  // 线段的最大点数量，确保不超过预分配的空间
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
```

在图像处理中经常需要使用一系列相关的点构成的集合，如一条连续的线或一条折线。我们使用line来描述这样的一个点的集合。  
其类似一个具有长度等其它信息的“胖”指针，在其当作只读的参数时我们只需要进行传值即可，在需要对其进行改变时需要传入地址，如:

```c

void fn(const line input_line) {
    //(input_line.data)[index]获取第index个点
}

void fn2(line * p_input_line) {
    //(input_line->data)[index]获取第index个点
    //(input_line->size)获取线的长度
}

int main() 
{
    line foo;
    line_init(&foo);
    fn(foo);
    fn2(&foo);
}

```
