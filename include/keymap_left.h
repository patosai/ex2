#ifndef _KEYMAP_LEFT_H_
#define _KEYMAP_LEFT_H_

#include <avr/pgmspace.h>

#include "keymap.h"

const keycode_t KEYMAP[KEYMAP_LAYERS][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
  // 0 - the regular
  {
    { KC_ESCAPE,    KC_1,     KC_2,     KC_3,    KC_4,      KC_5,      KC_NONE },
    { KC_NONE,      KC_Q,     KC_W,     KC_E,    KC_R,      KC_T,      KC_NONE },
    { KC_CAPSLOCK,  KC_A,     KC_S,     KC_D,    KC_F,      KC_G,      KC_NONE },
    { KC_LSHIFT,    KC_Z,     KC_X,     KC_C,    KC_V,      KC_B,      KC_NONE },
    { KC_LCTRL,     KC_LGUI,  KC_LALT,  KC_LEFT, KC_DOWN,   KC_BSPACE, KC_RIGHT }
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
