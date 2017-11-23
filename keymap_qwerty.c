/*
Copyright 2016 Mathieu Bolla <mathieu.bolla@gmail.com>
*/

#include "keymap_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  KEYMAP(
      KC_M,       KC_G,      KC_F,      KC_V,  KC_HOME,    KC_UP,  KC_PGUP,     KC_A,     KC_B,     KC_H,  KC_COMM,    KC_NO,    KC_NO,
      KC_EQL,     KC_T,      KC_Q,      KC_E,  KC_LEFT,  KC_DOWN,  KC_RGHT,     KC_S,     KC_I,     KC_N,     KC_4,  KC_LALT,   KC_TAB,
      KC_Z,       KC_U,      KC_D,      KC_L,   KC_END,   KC_ESC,  KC_PGDN,     KC_O,     KC_C,  KC_SCLN,     KC_P,   KC_FN1,   KC_SPC,
      KC_0,     KC_FN2,      KC_Y,      KC_J,  KC_BSPC,  KC_LCTL,   KC_ENT,     KC_X,     KC_W,     KC_K,     KC_2,  KC_LGUI,  KC_LSFT),
  KEYMAP(
      KC_TRNS,   KC_FN7,   KC_FN8,    KC_FN6,    KC_P7,    KC_P8,    KC_P9,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_6,    KC_NO,    KC_NO,
      KC_NUBS,  KC_LBRC,  KC_QUOT,    KC_DOT,    KC_P4,    KC_P5,    KC_P6,     KC_5,  KC_RBRC,  KC_MINS,  KC_SLSH,  KC_TRNS,  KC_TRNS,
      KC_1,     KC_TRNS,     KC_3,    KC_GRV,    KC_P1,    KC_P2,    KC_P3,  KC_NUHS,     KC_9,  KC_TRNS,     KC_8,  KC_TRNS,  KC_TRNS,
      KC_7,     KC_MPRV,  KC_MNXT,   KC_MPLY,   KC_DEL,    KC_P0,  KC_MUTE,  KC_VOLD,  KC_VOLU,   KC_FN4,   KC_FN3,  KC_TRNS,  KC_TRNS),
  KEYMAP(
      KC_COMM,     KC_G,     KC_F,      KC_V,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_Q,     KC_B,     KC_H,  KC_SCLN,    KC_NO,    KC_NO,
      KC_MINS,     KC_T,     KC_A,      KC_E,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_S,     KC_I,     KC_N,  KC_QUOT,  KC_LALT,   KC_TAB,
         KC_W,     KC_U,     KC_D,      KC_L,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_O,     KC_C,     KC_M,     KC_P,   KC_FN5,   KC_SPC,
       KC_DOT,   KC_FN2,     KC_Y,      KC_J,  KC_BSPC,  KC_TRNS,   KC_ENT,     KC_X,     KC_Z,     KC_K,     KC_3,  KC_LGUI,  KC_LSFT),
  KEYMAP(
      KC_SLSH,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_P7,    KC_P8,    KC_P9,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_8,    KC_NO,    KC_NO,
      KC_BSLS,     KC_6,     KC_5,   KC_TRNS,    KC_P4,    KC_P5,    KC_P6,     KC_9,     KC_4,  KC_TRNS,   KC_EQL,  KC_TRNS,  KC_TRNS,
         KC_7,  KC_TRNS,  KC_LBRC,      KC_2,    KC_P1,    KC_P2,    KC_P3,   KC_GRV,  KC_RBRC,  KC_TRNS,     KC_1,  KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_P0,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_FN4,   KC_FN3,  KC_TRNS,  KC_TRNS),
  KEYMAP( // LAYER 4
      KC_FN0,   KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_F7,    KC_F8,    KC_F9,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_NO,    KC_NO,
      KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_F4,    KC_F5,    KC_F6,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_F1,    KC_F2,    KC_F3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_F10,   KC_F11,   KC_F12,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),
};

const action_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(BOOTLOADER), // FN_0
  [1] = ACTION_LAYER_MOMENTARY(1),
  [2] = ACTION_LAYER_TAP_KEY(4, KC_R),
  [3] = ACTION_MODS_KEY(MOD_LSFT|MOD_LCTL, KC_POWER),
  [4] = ACTION_LAYER_TOGGLE(2),
  [5] = ACTION_LAYER_MOMENTARY(3),
  [6] = ACTION_MODS_KEY(MOD_LGUI|MOD_LALT, KC_V),
  [7] = ACTION_MODS_KEY(MOD_LGUI|MOD_LALT, KC_SCLN),
  [8] = ACTION_MODS_KEY(MOD_LGUI|MOD_LALT, KC_F)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
