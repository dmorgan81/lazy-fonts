#include <pebble.h>
#include <@smallstoneapps/linked-list/linked-list.h>
#include "lazy-fonts.h"

typedef struct {
    uint32_t resource_id;
    GFont font;
} Data;

static LinkedRoot *s_root;

void lazy_fonts_init(void) {
    s_root = linked_list_create_root();
}

static bool list_destroy_callback(void *object, void *context) {
    Data *data = (Data *) object;
    fonts_unload_custom_font(data->font);
    free(data);
    return true;
}

void lazy_fonts_deinit(void) {
    linked_list_foreach(s_root, list_destroy_callback, NULL);
    linked_list_clear(s_root);
    free(s_root);
}

static bool list_find_compare(void *object1, void *object2) {
    return ((uint32_t) object1) == ((Data *) object2)->resource_id;
}

GFont lazy_fonts_get(uint32_t resource_id) {
    int16_t index = linked_list_find_compare(s_root, (void *) resource_id, list_find_compare);
    if (index == -1) {
        Data *data = malloc(sizeof(Data));
        data->resource_id = resource_id;
        data->font = fonts_load_custom_font(resource_get_handle(resource_id));
        linked_list_append(s_root, data);
        return data->font;
    } else {
        return ((Data *) linked_list_get(s_root, index))->font;
    }
}
