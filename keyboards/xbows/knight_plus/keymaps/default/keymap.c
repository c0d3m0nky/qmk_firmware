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

enum {
	M_LAMBDA = SAFE_RANGE,
	M_NEXTLED,
	M_PREVLED
};

// @formatter:off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap VANILLA: (Base Layer) Default Layer
   *
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | Esc |  F1  |  F2  |  F3  |  F4  |      F5  |  F6  |  F7  |  F8  |      F9  |  F10 |  F11 |  F12 |   Delete   |    Prtsc    |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * |  ~  |     1   |   2   |   3   |   4   |    5      |       6    |    7    |    8   |   9  |   0  |   -  |  =  |  Backspace  |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | Tab |   Q    |    W   |   E  |   R  |   T  |            |    Y   |    U   |    I  |   O  |   P  |   [  |  ]  |   \  | PgUp |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | Ctl |   A   |   S   |   D  |   F  |   G  |      Bksp      |    H  |    J   |   K  |   L  |   ;  |  '"  |    Enter   | PgDn |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * |Shift|   Z  |   X  |   C  |   V  |   B  |       Enter       |    N  |    M   |  ,  |   .  |  /?  | Shift|      |  Up |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * |Ctrl | GUI |     Alter   |    Space   |   Ctrl   |   Shift   |     Space     |    Alter   |  FN  | Ctrl | Lft  |  Dn |  Rig |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   */
	[0] = LAYOUT(
			KC_ESC,     KC_NO,      KC_F2,      KC_F3,  KC_F4,    KC_F5,      KC_F6,      KC_F7,    KC_F8,  KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_DEL,     KC_INS,
			KC_GRV,     KC_1,       KC_2,       KC_3,   KC_4,     KC_5,                   KC_6,     KC_7,   KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,
			KC_TAB,     KC_Q,       KC_W,       KC_E,   KC_R,     KC_T,       KC_Y,       KC_U,     KC_I,   KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,    KC_HOME,
			KC_LSFT,    KC_A,       KC_S,       KC_D,   KC_F,     KC_G,       KC_NO,      KC_H,     KC_J,   KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_ENT,     KC_END,
			KC_LSFT,    KC_Z,       KC_X,       KC_C,   KC_V,     KC_B,                   KC_NO,    KC_N,   KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,    KC_UP,
			KC_LCTL,    KC_LGUI,    KC_LALT,            KC_SPC,   KC_LCTL,    KC_LSFT,    KC_SPC,           KC_RALT,    MO(1),      KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RGHT
	),
	[1] = LAYOUT(
			KC_NO,      KC_MPLY,    KC_VOLD,    KC_VOLU,    KC_MUTE,    KC_F17,   KC_F18,   KC_F19,   KC_F20,   KC_F21,     KC_F22,   KC_F23,   KC_F24,     KC_NO,  KC_PSCR,
			KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,              KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_NO,    KC_NO,      KC_NO,  KC_NO,
			KC_NO,      KC_NO,      RGB_VAI,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_NO,    KC_NO,      KC_NO,  KC_PGUP,
			KC_CAPS,    KC_NO,      RGB_VAD,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_NO,    KC_NO,      KC_NO,  KC_PGDN,
			KC_NO,      KC_NO,      KC_CALC,    KC_NO,      KC_NO,      KC_NO,              MO(2),    KC_NO,    KC_NO,   	KC_NO,    M_LAMBDA, KC_NO,      KC_NO,  KC_NO,
			KC_NO,      KC_NO,      KC_NO,                  KC_NO,      KC_NO,    KC_NO,    KC_NO,              KC_MENU,    KC_TRNS,  KC_NO,    M_PREVLED,  KC_NO,  M_NEXTLED
//			KC_NO,      KC_NO,      KC_NO,                  KC_NO,      KC_NO,    KC_NO,    KC_NO,              KC_MENU,    KC_TRNS,  KC_NO,    KC_WBAK,    KC_NO,  KC_WFWD
	),
	[2] = LAYOUT(
			RESET,  EEP_RST,    KC_NO,  KC_NO,  KC_NO,  DEBUG,  KC_NO,  KC_NO,  	KC_NO,  KC_NO,  KC_NO,  	KC_NO,  KC_NO,  KC_NO,  KC_NO,
			KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,  	KC_NO,  KC_NO,  KC_NO,  	KC_NO,  KC_NO,  KC_NO,  KC_NO,
			KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  	KC_NO,  KC_NO,  KC_NO,  	KC_NO,  KC_NO,  KC_NO,  KC_NO,
			KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  	KC_NO,  KC_NO,  KC_NO,  	KC_NO,  KC_NO,  KC_NO,  KC_NO,
			KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  	KC_NO,  KC_NO,  KC_NO,  KC_NO,
			KC_NO,  KC_NO,      KC_NO,          KC_NO,  KC_NO,  KC_NO,  KC_NO,          	KC_NO,  KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO
	)

};

int _layer_size = 3;

int _keyindices[][MATRIX_COLS] = {
    {  0,      1,      2,      3,      4,      5,      6,      7,      8,      9,      10,     11,     12,     13,     14     },
    {  15,     16,     17,     18,     19,     20,     NO_LED, 21,     22,     23,     24,     25,     26,     27,     28     },
    {  29,     30,     31,     32,     33,     34,     35,     36,     37,     38,     39,     40,     41,     42,     43     },
    {  44,     45,     46,     47,     48,     49,     50,     51,     52,     53,     54,     55,     56,     57,     58     },
    {  59,     60,     61,     62,     63,     64,     65,     66,     67,     68,     69,     70,     71,     72,     NO_LED },
    {  73,     74,     75,     NO_LED, 76,     77,     78,     79,     NO_LED, 80,     81,     82,     83,     84,     85     }
 };


RgbColor _rgblayers[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = {
        { KRGB_DEF, KRGB_OFF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF  },
        { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF  },
        { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF  },
        { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_OFF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF  },
        { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_OFF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF  },
        { KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_FN,  KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF  }
        },
    [1] = {
        { KRGB_OFF, KRGB_DEF, KRGB_DEF,     KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_DEF, KRGB_OFF, KRGB_DEF  },
        { KRGB_OFF, KRGB_OFF, KRGB_OFF,     KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_DEF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF  },
        { KRGB_OFF, KRGB_OFF, KRGB_WHITE,   KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_DEF  },
        { KRGB_DEF, KRGB_OFF, KRGB_WHITE,   KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_DEF  },
        { KRGB_OFF, KRGB_OFF, KRGB_DEF,     KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_DEF, KRGB_FN,  KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF  },
        { KRGB_OFF, KRGB_OFF, KRGB_OFF,     KRGB_DEF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_DEF, KRGB_DEF, KRGB_FN,  KRGB_OFF, KRGB_DEF, KRGB_OFF, KRGB_DEF  }
        },
    [2] = {
        { KRGB_DANGER,    KRGB_DANGER,    KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_DEF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF  },
        { KRGB_OFF,       KRGB_OFF,       KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_DEF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF  },
        { KRGB_OFF,       KRGB_OFF,       KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF  },
        { KRGB_OFF,       KRGB_OFF,       KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF  },
        { KRGB_OFF,       KRGB_OFF,       KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_DEF, KRGB_FN,  KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF  },
        { KRGB_OFF,       KRGB_OFF,       KRGB_OFF, KRGB_DEF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_DEF, KRGB_OFF, KRGB_FN,  KRGB_OFF, KRGB_OFF, KRGB_OFF, KRGB_OFF  }
    }

  };
// @formatter:on


void keyboard_post_init_user(void) {
   xbc_initialize_rgb_layers(_layer_size);
}

RgbColor dev1 = KRGB_DEV1;
RgbColor dev2 = KRGB_DEV2;
RgbColor misn = KRGB_MISNAMED;
RgbColor por2 = KRGB_PORTAL2;
RgbColor fnk = KRGB_FN;

int ledPin = -1;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record -> event.pressed) {
		switch (keycode) {
			case M_LAMBDA:
				SEND_STRING(" => ");
				return false; break;
            case M_PREVLED:
                if (ledPin > 0) ledPin = 0;
                return false; break;
            case M_NEXTLED:
                if (ledPin < 85) ledPin = 1;
                return false; break;
			default:
				break;
		}
	}

	return true;
}


__attribute__ ((weak)) void rgb_matrix_indicators_user(void) {
    int alayer = biton32(layer_state);

    if (ledPin > 0) {
        xbc_set_colors(_rgblayers[alayer], _keyindices);
    }
    else {
        rgb_matrix_set_color(65, 0, 0, 0);
        rgb_matrix_set_color(50, 0, 0, 0);

        rgb_matrix_set_color(5, dev2.r, dev2.g, dev2.b);
        rgb_matrix_set_color(9, dev1.r, dev1.g, dev1.b);
        rgb_matrix_set_color(10, dev2.r, dev2.g, dev2.b);
        rgb_matrix_set_color(11, dev2.r, dev2.g, dev2.b);
        rgb_matrix_set_color(69, dev2.r, dev2.g, dev2.b);

        rgb_matrix_set_color(73, RGB_BLUE);
        rgb_matrix_set_color(82, por2.r, por2.g, por2.b);

        rgb_matrix_set_color(44, misn.r, misn.g, misn.b);
        rgb_matrix_set_color(43, misn.r, misn.g, misn.b);
        rgb_matrix_set_color(58, misn.r, misn.g, misn.b);

        rgb_matrix_set_color(81, fnk.r, fnk.g, fnk.b);

        rgb_matrix_set_color(45, RGB_CYAN);
        rgb_matrix_set_color(46, RGB_CYAN);
        rgb_matrix_set_color(47, RGB_CYAN);
        rgb_matrix_set_color(48, RGB_CYAN);
        rgb_matrix_set_color(51, RGB_CYAN);
        rgb_matrix_set_color(52, RGB_CYAN);
        rgb_matrix_set_color(53, RGB_CYAN);
        rgb_matrix_set_color(54, RGB_CYAN);

        rgb_matrix_set_color(1, RGB_MAGENTA);
        rgb_matrix_set_color(2, RGB_MAGENTA);
        rgb_matrix_set_color(3, RGB_MAGENTA);
        rgb_matrix_set_color(4, RGB_MAGENTA);
    }

//    rgb_matrix_set_color(ledPin, RGB_MAGENTA);

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(44, 0xFF, 0xFF, 0xFF);
    }
}
