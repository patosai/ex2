#include <avr/pgmspace.h>

#include "keymap.h"
#include "matrix.h"

#ifdef KEYBOARD_LEFT
#include "keymap_left.h"
#else
#include "keymap_right.h"
#endif

static uint8_t layer = 0;

void keymap_set_current_layer(uint8_t new_layer) {
  if (new_layer < KEYMAP_LAYERS) {
    layer = new_layer;
  }
}

keycode_t keymap_key_at(matrix_row_t row, matrix_row_t col) {
  return (keycode_t)(pgm_read_byte(&(KEYMAP[layer][row][col])));
}
