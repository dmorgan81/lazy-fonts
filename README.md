lazy-fonts
=============

lazy-fonts lets Pebble app components load fonts without having to worry
about unloading or coordinating use with other components. Fonts are loaded
once and only once so the same font is shared among components automatically.

Installation
------------

```
pebble package install lazy-fonts
```

You must be using a new-style project; install the latest pebble tool and SDK
and run `pebble convert-project` on your app if you aren't.

Usage
-----

```c
// This is not a complete example, but should demonstrate the basic usage of
// the Linked List library.

#include <lazy-fonts/lazy-fonts.h>

static void window_load(Window *window) {
    TextLayer *text_layer = text_layer_create(GRectZero);
    text_layer_set_font(text_layer, lazy_fonts_get(RESOURCE_ID_MY_COOL_FONT_42);
}

static void init(void) {
  lazy_fonts_init();
  ...
}

static void deinit(void) {
  lazy_fonts_deinit();
  ...
}
```

You must call `lazy_fonts_init()` first, preferably in your app's init function. Before you app
quits, you must call `lazy_fonts_deinit()` to unload any loaded fonts and free memory.

`lazy_fonts_get(resource_id)` returns a [GFont](https://developer.pebble.com/docs/c/Graphics/Fonts/#GFont).
The GFont will be loaded if it is not already, otherwise the already loaded GFont will be returned.
