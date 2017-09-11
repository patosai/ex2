#ifndef _KEYMAP_RIGHT_H_
#define _KEYMAP_RIGHT_H_

#include <avr/pgmspace.h>

#include "keymap.h"

const keycode_t KEYMAP[KEYMAP_LAYERS][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
  // 0 - the regular
  {
    { KC_LAYER_0,  KC_6,     KC_7,     KC_8,     KC_9,      KC_0,       KC_GRAVE },
    { KC_LAYER_1,  KC_Y,     KC_U,     KC_I,     KC_O,      KC_P,       KC_BSLASH },
    { KC_RBRACKET, KC_H,     KC_J,     KC_K,     KC_L,      KC_SCOLON,  KC_QUOTE },
    { KC_PGUP,     KC_N,     KC_M,     KC_COMMA, KC_DOT,    KC_SLASH,   KC_MINUS },
    { KC_PGDOWN,   KC_SPACE, KC_ENTER, KC_LEFT,  KC_RIGHT,  KC_PSCREEN, KC_EQUAL }
  },
  // 1 - numpad
  {
    { KC_LAYER_0,  KC_NONE,  KC_NONE,    KC_TAB,   KC_KP_SLASH, KC_KP_ASTERISK,   KC_KP_MINUS },
    { KC_LAYER_1,  KC_NONE,  KC_NONE,    KC_KP_7,  KC_KP_8,     KC_KP_9,          KC_KP_PLUS },
    { KC_NONE,     KC_NONE,  KC_NONE,    KC_KP_4,  KC_KP_5,     KC_KP_6,          KC_KP_EQUAL },
    { KC_NONE,     KC_NONE,  KC_NONE,    KC_KP_1,  KC_KP_2,     KC_KP_3,          KC_KP_ENTER },
    { KC_NONE,     KC_SPACE, KC_NUMLOCK, KC_KP_0,  KC_COMMA,    KC_KP_DOT,        KC_BSPACE },
  }
};

#endif
