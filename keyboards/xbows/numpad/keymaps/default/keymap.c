/* Copyright 2021 Shulin Huang <mumu@x-bows.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "xbowscommon.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap VANILLA: (Base Layer) Default Layer
   *
   * |-------------------------------|
   * |  Esc  |  Tab  |   BS  |   Fn  |
   * |-------------------------------|
   * |  NUM  |   /   |   *   |   =   |
   * |-------------------------------|
   * |   7   |  8    |   9   |   -   |
   * |-------------------------------|
   * |   4   |   5   |   6   |   +   |
   * |-------------------------------|
   * |   1   |  2   |    3   | ENTER |
   * |-------------------------------|
   * |        0     |    .   |
   * |-----------------------|
   */
  [0] = LAYOUT(
    KC_ESC ,  KC_TAB,   KC_BSPC,  MO(1),
    KC_NLCK,  KC_PSLS,  KC_PAST,  KC_EQL,
    KC_P7,    KC_P8,    KC_P9,    KC_PMNS,
    KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
    KC_P1,    KC_P2,    KC_P3,    KC_PENT,
         KC_P0,       KC_PDOT),
  [1] = LAYOUT(
    MO(2),  KC_NO,   KC_NO,   KC_TRNS,
    KC_NO,  KC_NO,   KC_NO,   KC_NO,
    KC_NO,  RGB_VAI, KC_NO,   KC_NO,
    KC_NO,  KC_NO,   KC_NO,   KC_NO,
    KC_NO,  RGB_VAD, KC_NO,   KC_NO,
        KC_NO,          KC_NO),
  [2] = LAYOUT(
    KC_TRNS,  KC_NO,  KC_NO,  KC_TRNS,
    RESET,    KC_NO,  KC_NO,  KC_NO,
    EEP_RST,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,    KC_NO,  KC_NO,  KC_NO,
    KC_NO,    KC_NO,  KC_NO,  KC_NO,
        KC_NO,    KC_NO)
};

#ifdef RGB_MATRIX_ENABLE

int nummap[] = { 16, 17, 18, 12 };

int _layer_size = 3;

int _keyindices[][MATRIX_COLS] = {
     {  NO_LED, NO_LED, NO_LED, NO_LED},
     {  NO_LED, NO_LED, NO_LED, NO_LED},
     {  NO_LED, NO_LED, NO_LED, NO_LED},
     {  NO_LED, NO_LED, NO_LED, NO_LED},
     {  NO_LED, NO_LED, NO_LED, NO_LED},
     {  NO_LED, NO_LED, NO_LED, NO_LED}
 };

RgbColor _rgblayers[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = {
    { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_FN },
    { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF },
    { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF },
    { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF },
    { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF },
    { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF }
  },
  [1] = {
    { KRGB_FN,  KRGB_DEF, KRGB_DEF, KRGB_FN },
    { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF },
    { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF },
    { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF },
    { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF },
    { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF }
  },
  [2] = {
    { KRGB_FN,  KRGB_DEF, KRGB_DEF, KRGB_FN },
    { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF },
    { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF },
    { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF },
    { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF },
    { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF }
  },
};


void keyboard_post_init_user(void) {
  xbc_initialize_rgb_layers(_layer_size, MATRIX_ROWS, MATRIX_COLS, _rgblayers, _keyindices, g_led_config);
}


void rgb_matrix_indicators_user(void) {
  int alayer = biton32(layer_state);

  xbc_set_colors();
}

#endif