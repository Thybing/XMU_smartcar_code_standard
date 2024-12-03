#include "image.h"

bool image_init(image *const self, pixel_t *const data, const uint16_t width, const uint16_t height)
{
    if (!self || !data)
    {
        return false;
    }
    self->data = data;
    self->width = width;
    self->height = height;
    return true;
}
