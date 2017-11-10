#ifndef _KEYMAP_LEFT_H_
#define _KEYMAP_LEFT_H_

#include <avr/pgmspace.h>

#include "keymap.h"

const keycode_t KEYMAP[KEYMAP_LAYERS][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
  // 0 - the regular
  {
    { KC_ESCAPE,    KC_1,     KC_2,     KC_3,    KC_4,      KC_5,      KC_LAYER_0 },
    { KC_TAB,       KC_Q,     KC_W,     KC_E,    KC_R,      KC_T,      KC_LAYER_1 },
    { KC_CAPSLOCK,  KC_A,     KC_S,     KC_D,    KC_F,      KC_G,      KC_LBRACKET },
    { KC_LSHIFT,    KC_Z,     KC_X,     KC_C,    KC_V,      KC_B,      KC_UP },
    { KC_LCTRL,     KC_LGUI,  KC_LALT,  KC_MUTE, KC_DELETE, KC_BSPACE, KC_DOWN }
  },
  // 1 - gaming
  {
    { KC_ESCAPE,    KC_1,     KC_2,     KC_3,    KC_4,      KC_5,      KC_LAYER_0 },
    { KC_TAB,       KC_Q,     KC_W,     KC_E,    KC_R,      KC_T,      KC_LAYER_1 },
    { KC_CAPSLOCK,  KC_A,     KC_S,     KC_D,    KC_F,      KC_G,      KC_LBRACKET },
    { KC_LSHIFT,    KC_Z,     KC_X,     KC_C,    KC_V,      KC_B,      KC_UP },
    { KC_LCTRL,     KC_LGUI,  KC_LALT,  KC_MUTE, KC_ENTER,  KC_SPACE,  KC_DOWN }
  }
};

#endif
