#pragma once
#include <pebble.h>

void lazy_fonts_init(void);
void lazy_fonts_deinit(void);
GFont lazy_fonts_get(uint32_t resource_id);
