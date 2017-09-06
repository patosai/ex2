#include <avr/pgmspace.h>

#include "keymap.h"
#include "matrix.h"

static uint8_t layer = 0;

const keycode_t KEYMAP[KEYMAP_LAYERS][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
  // 0 - the regular
  {
    { KC_NONE,      KC_6,     KC_7,     KC_8,    KC_9,      KC_0,      KC_BSLASH },
    { KC_NONE,      KC_Y,     KC_U,     KC_I,    KC_O,      KC_P,      KC_NONE },
    { KC_NONE,      KC_H,     KC_J,     KC_K,    KC_L,      KC_SCOLON, KC_SCOLON },
    { KC_PGUP,      KC_B,     KC_N,     KC_M,    KC_COMMA,  KC_DOT,    KC_COMMA },
    { KC_PGDOWN,    KC_SPACE, KC_TAB,   KC_LEFT, KC_DOWN,   KC_UP,     KC_RIGHT }
  },
  // 1 - arrows and media
  {
    { KC_NONE,  KC_SPACE, KC_NONE,  KC_NONE, KC_NONE,   KC_NONE,   KC_NONE },
    { KC_NONE,  KC_SPACE, KC_NONE,  KC_NONE, KC_NONE,   KC_NONE,   KC_NONE },
    { KC_NONE,  KC_SPACE, KC_NONE,  KC_NONE, KC_NONE,   KC_NONE,   KC_NONE },
    { KC_NONE,  KC_SPACE, KC_NONE,  KC_NONE, KC_NONE,   KC_NONE,   KC_NONE },
    { KC_NONE,  KC_SPACE, KC_NONE,  KC_NONE, KC_NONE,   KC_NONE,   KC_NONE },
  }
};

void keymap_set_current_layer(uint8_t new_layer) {
  if (new_layer < KEYMAP_LAYERS) {
    layer = new_layer;
  }
}

keycode_t keymap_key_at(matrix_row_t row, matrix_row_t col) {
  return (keycode_t)(pgm_read_byte(&(KEYMAP[layer][row][col])));
}
