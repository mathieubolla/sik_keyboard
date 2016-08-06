/*
Copyright 2016 Mathieu Bolla <mathieu.bolla@gmail.com>
*/

#include "keymap_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  KEYMAP(
      KC_BSPC, KC_E, KC_I, KC_M, KC_Q, KC_U, KC_A, KC_Y, KC_U, KC_I, KC_O, KC_NO, KC_E,
      KC_FN0, KC_F, KC_J, KC_N, KC_R, KC_V, KC_B, KC_G, KC_H, KC_J, KC_K, KC_L, KC_F,
      KC_LGUI, KC_G, KC_K, KC_O, KC_S, KC_W, KC_C, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC, KC_G,
      KC_LSFT, GUI(KC_TAB), KC_L, KC_P, KC_T, KC_X, KC_D, KC_NO, KC_MINS, KC_QUOT, KC_NO, KC_NO, KC_H)
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(BOOTLOADER),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
