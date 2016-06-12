#pragma once
#include <pebble.h>

// Initialize the lazy font system.
void lazy_fonts_init(void);

// Deinitialize the lazy font system. Loaded fonts will be unloaded and
// memory structures freed.
void lazy_fonts_deinit(void);

// Return the GFont with the specified resource_id. If the GFont is not yet
// loaded it will be loaded, otherwise the already loaded GFont will be
// returned.
GFont lazy_fonts_get(uint32_t resource_id);
