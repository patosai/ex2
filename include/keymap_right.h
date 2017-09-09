#ifndef _KEYMAP_RIGHT_H_
#define _KEYMAP_RIGHT_H_

#include <avr/pgmspace.h>

#include "keymap.h"

const keycode_t KEYMAP[KEYMAP_LAYERS][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
  // 0 - the regular
  {
    { KC_NONE,      KC_6,     KC_7,     KC_8,    KC_9,      KC_0,      KC_BSPACE },
    { KC_NONE,      KC_Y,     KC_U,     KC_I,    KC_O,      KC_P,      KC_BSLASH },
    { KC_NONE,      KC_H,     KC_J,     KC_K,    KC_L,      KC_SCOLON, KC_ENTER },
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

#endif
