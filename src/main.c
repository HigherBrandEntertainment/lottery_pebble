#include <pebble.h>
  
static Window *s_main_window;
static TextLayer *s_text_layer;
static GFont s_text_font;


static void main_window_load(Window *window) {
  
  // Create time TextLayer
  s_text_layer = text_layer_create(GRect(0, 55, 144, 50));
  text_layer_set_background_color(s_text_layer, GColorClear);
  text_layer_set_text_color(s_text_layer, GColorBlack);
  text_layer_set_text(s_text_layer, "Lottery Report");

  text_layer_set_font(s_text_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
  text_layer_set_text_alignment(s_text_layer, GTextAlignmentCenter);

  // Add it as a child layer to the Window's root layer
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_text_layer));
}

static void main_window_unload(Window *window) {
  // Unload GFont
  fonts_unload_custom_font(s_text_font);

  // Destroy TextLayer
  text_layer_destroy(s_text_layer);
}
  
static void init() {
  // Create main Window element and assign to pointer
  s_main_window = window_create();

  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true);
}

static void deinit() {
  // Destroy Window
  window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
