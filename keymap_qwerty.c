/*
Copyright 2016 Mathieu Bolla <mathieu.bolla@gmail.com>
*/

#include "keymap_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  KEYMAP(
      KC_M,     KC_G, KC_F, KC_V, KC_P7,    KC_P8,  KC_P9,  KC_A, KC_B, KC_H,   KC_COMM,KC_NO,    KC_NO,
      KC_R,     KC_T, KC_Q, KC_E, KC_P4,    KC_P5,  KC_P6,  KC_S, KC_I, KC_N,   KC_U,   KC_BSPC,  KC_TAB,
      KC_EQL,   KC_P, KC_D, KC_L, KC_P1,    KC_P2,  KC_P3,  KC_O, KC_C, KC_SCLN,KC_SLSH, KC_LGUI,  KC_LSFT,
      KC_LCTL,  KC_Z, KC_Y, KC_J, KC_LALT,  KC_P0,  KC_ENT, KC_X, KC_W, KC_K,   KC_ESC, KC_FN1,   KC_FN2),
  KEYMAP(
      KC_FN0,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_HOME, KC_UP,   KC_PGUP, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_NO,    KC_NO,
      KC_NUBS,  KC_LBRC,   KC_QUOT,   KC_DOT,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NUHS,  KC_RBRC,  KC_MINS,  KC_TRNS, KC_TRNS,  KC_TRNS,
      KC_1,     KC_2,      KC_3,      KC_4,     KC_END,  KC_TRNS, KC_PGDN, KC_5,     KC_6,     KC_7,     KC_8,    KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,   KC_GRV,    KC_9,     KC_TRNS, KC_TRNS, KC_TRNS, KC_0,     KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS),
  KEYMAP(
      KC_FN0,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_F7,    KC_F8,   KC_F9,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO,
      KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_F4,    KC_F5,   KC_F6,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_F1,    KC_F2,   KC_F3,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_F10,   KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(BOOTLOADER),
  [1] = ACTION_LAYER_TAP_KEY(1, KC_SPC),
  [2] = ACTION_LAYER_TAP_KEY(2, KC_SPC)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
