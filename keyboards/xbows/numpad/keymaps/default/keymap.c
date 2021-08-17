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
			KC_ESC,     KC_TAB,     KC_BSPC,    MO(1),
			KC_NLCK,    KC_PSLS,    KC_PAST,    KC_EQL,
			KC_P7,      KC_P8,      KC_P9,      KC_PMNS,
			KC_P4,      KC_P5,      KC_P6,      KC_PPLS,
			KC_P1,      KC_P2,      KC_P3,      KC_PENT,
			KC_P0,                  KC_PDOT
	),
	[1] = LAYOUT(
			MO(2),  KC_NO,      KC_NO,  MO(1),
			KC_NO,  KC_NO,      KC_NO,  KC_NO,
			KC_NO,  RGB_VAI,    KC_NO,  KC_NO,
			KC_NO,  KC_NO,      KC_NO,  KC_NO,
			KC_NO,  RGB_VAD,    KC_NO,  KC_NO,
			KC_NO,              KC_NO
	),
	[2] = LAYOUT(
			MO(2),      KC_NO,  KC_NO,  MO(1),
			RESET,      KC_NO,  KC_NO,  KC_NO,
			EEP_RST,    KC_NO,  KC_NO,  KC_NO,
			KC_NO,      KC_NO,  KC_NO,  KC_NO,
			KC_NO,      KC_NO,  KC_NO,  KC_NO,
			KC_NO,              KC_NO
	)

};

int _keyindices[][MATRIX_COLS] = {
     {  0,      1,      2,      3     },
     {  4,      5,      6,      7     },
     {  8,      9,      10,     11    },
     {  12,     13,     14,     15    },
     {  16,     17,     18,     19    },
     {  20,     NO_LED, 21,     NO_LED}
 };


const KeyColor PROGMEM _rgblayers[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = RGBLAYOUT(
			KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_FN,
			KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF,
			KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF,
			KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF,
			KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF,
			KRGB_DEF,           KRGB_DEF
	),
	[1] = RGBLAYOUT(
			KRGB_FN,  KRGB_OFF,     KRGB_OFF, KRGB_FN,
			KRGB_OFF, KRGB_OFF,     KRGB_OFF, KRGB_OFF,
			KRGB_OFF, KRGB_VAL,   KRGB_OFF, KRGB_OFF,
			KRGB_OFF, KRGB_OFF,     KRGB_OFF, KRGB_OFF,
			KRGB_OFF, KRGB_VAL,   KRGB_OFF, KRGB_OFF,
			KRGB_OFF,               KRGB_OFF
	),
	[2] = RGBLAYOUT(
			KRGB_FN,        KRGB_OFF, KRGB_OFF, KRGB_FN,
			KRGB_DANGER,    KRGB_OFF, KRGB_OFF, KRGB_OFF,
			KRGB_DANGER,    KRGB_OFF, KRGB_OFF, KRGB_OFF,
			KRGB_OFF,       KRGB_OFF, KRGB_OFF, KRGB_OFF,
			KRGB_OFF,       KRGB_OFF, KRGB_OFF, KRGB_OFF,
			KRGB_OFF,                 KRGB_OFF
	)

};


int nummap[] = { 16, 17, 18, 12 };


void keyboard_post_init_user(void) {
    xbc_initialize_rgb_layers(3, _rgblayers, _keyindices);
}


__attribute__ ((weak)) void rgb_matrix_indicators_user(void) {
    int li = biton32(layer_state);

    xbc_set_colors(li);

    if (li == 0 && host_keyboard_led_state().num_lock) {
        KeyColor_s c = xbc_getKeyColor(KRGB_WHITE);

        rgb_matrix_set_color(4, c.r, c.g, c.b);
    }
}

#ifdef RGBLIGHT_SLEEP

void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}


void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}

#endif
