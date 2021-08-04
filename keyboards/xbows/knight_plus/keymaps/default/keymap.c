#include QMK_KEYBOARD_H
#include "xbowscommon.h"

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

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
        KC_ESC,     KC_NO,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_DEL,     KC_INS, 
        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC, 
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,    KC_HOME, 
        KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_NO,      KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_ENT,     KC_END, 
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_NO,      KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,    KC_UP, 
        KC_LCTL,    KC_LGUI,    KC_LALT,    KC_SPC,     KC_LCTL,    KC_LSFT,    KC_SPC,     KC_RALT,    MO(1),      KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RGHT
    ),
	[1] = LAYOUT(
        KC_NO,      KC_MPLY,    KC_VOLD,    KC_VOLU,    KC_MUTE,    KC_F17,     KC_F18,     KC_F19,     KC_F20,     KC_F21,     KC_F22,     KC_F23,     KC_F24,     KC_NO,      KC_PSCR, 
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO, 
        KC_NO,      KC_NO,      RGB_VAI,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_PGUP, 
        KC_CAPS,    KC_NO,      RGB_VAD,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_PGDN, 
        KC_NO,      KC_NO,      KC_CALC,    KC_NO,      KC_NO,      KC_NO,      MO(2),      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO, 
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_MENU,    KC_NO,      KC_NO,      KC_WBAK,    KC_NO,      KC_WFWD
    ),
	[2] = LAYOUT(
        RESET,      EEP_RST,    KC_NO,      KC_NO,      KC_NO,      DEBUG,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO, 
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO, 
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO, 
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO, 
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO, 
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO
    )
};


int nummap[] = { 16, 17, 18, 19 };

int _layer_size = 3;

int _keyindices[][MATRIX_COLS] = {
     {  NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED     },
     {  NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED     },
     {  NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED     },
     {  NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED     },
     {  NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED     },
     {  NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED,     NO_LED     }
 };

RgbColor _rgblayers[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = {
        KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF, 
        KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF, 
        KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF, 
        KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF, 
        KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF, 
        KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_FN,    KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF
    },
    [1] = {
        KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF, 
        KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF, 
        KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF, 
        KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF, 
        KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_FN,    KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF, 
        KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_FN,    KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF
    },
    [2] = {
        KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF, 
        KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF, 
        KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF, 
        KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF, 
        KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_FN,    KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF, 
        KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_FN,    KRGB_DEF,   KRGB_DEF,   KRGB_DEF,   KRGB_DEF
    }
};


void keyboard_post_init_user(void) {
  xbc_initialize_rgb_layers(_layer_size, MATRIX_ROWS, MATRIX_COLS, _rgblayers, _keyindices, g_led_config);
}


void rgb_matrix_indicators_user(void) {
  int alayer = biton32(layer_state);

  xbc_set_colors(_rgblayers[alayer], _keyindices);

  rgb_matrix_set_color(nummap[alayer], 0xFF, 0xFF, 0xFF);
}
