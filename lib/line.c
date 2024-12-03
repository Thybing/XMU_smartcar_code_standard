#include "line.h"

//所有的线的可申请的总长度
#define LINES_POOL_SIZE (1024)

static point lines_pool[LINES_POOL_SIZE] = {0};
static uint16_t pool_used_index = 0;

static bool allocate_points(point **const p_points_ptr, const uint16_t size)
{
    if (!p_points_ptr)
    {
        return false;
    }
    if (pool_used_index + size > LINES_POOL_SIZE)
    {
        *p_points_ptr = NULL;
        return false;
    }
    *p_points_ptr = &lines_pool[pool_used_index];
    pool_used_index += size;
    return true;
}

bool line_init(line *const self, const uint16_t capacity)
{
    if (!self)
    {
        return false;
    }
    self->size = 0;
    self->capacity = capacity;
    return allocate_points(&(self->data), capacity);
}

void line_clear(line *const self)
{
    self->size = 0;
}