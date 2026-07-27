// Copyright 2026 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

// Shared RGB color palette for X-BOWS keyboards.
//
// Named colors used by per-key/per-layer lighting overrides. Values are stored
// as plain R, G, B triplets because that is what rgb_matrix_set_color() expects.
//
// Two indices are special:
//   KRGB_DEF (-1) -> no override; the key keeps the default solid color.
//   KRGB_OFF ( 0) -> the LED is turned off (0, 0, 0).
#pragma once

#include <stdint.h>
#include <avr/pgmspace.h>
#include "quantum.h"

enum xbows_key_color {
    KRGB_DEF = -1, // keep the default solid color
    KRGB_OFF = 0,  // off
    KRGB_VAL,      // white; for brightness keys so they stay lit
    KRGB_HOME,
    KRGB_MEDIA,
    KRGB_DEV1,
    KRGB_DEV2,
    KRGB_FN,
    KRGB_MISNAMED,
    KRGB_PORTAL1,
    KRGB_PORTAL2,
    KRGB_DANGER,
    KRGB_WHITE,
    KRGB_COUNT
};

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} xbows_rgb_t;

// Indexed by the non-negative values of enum xbows_key_color.
static const xbows_rgb_t PROGMEM xbows_palette[KRGB_COUNT] = {
    [KRGB_OFF]      = {  0,   0,   0},
    [KRGB_VAL]      = {255, 255, 255},
    [KRGB_HOME]     = {  0, 255, 255},
    [KRGB_MEDIA]    = {255,   0, 255},
    [KRGB_DEV1]     = {255,  25,   0},
    [KRGB_DEV2]     = {255, 128,   0},
    [KRGB_FN]       = {153,   0, 204},
    [KRGB_MISNAMED] = {  9,   0,  55},
    [KRGB_PORTAL1]  = {  0,   0, 255},
    [KRGB_PORTAL2]  = {255,  85,   0},
    [KRGB_DANGER]   = {255,   0,   0},
    [KRGB_WHITE]    = {255, 255, 255},
};

#ifdef RGB_MATRIX_ENABLE

// Shared per-key indicator renderer for X-BOWS RGB Matrix boards.
//
// For the current highest active layer it paints:
//   * caps_lock_led white while Caps Lock is on,
//   * any KC_NO / KC_TRNS key off,
//   * every other key its per-layer override color (KRGB_DEF keeps the default).
//
// layer_colors is a [num_layers][MATRIX_ROWS][MATRIX_COLS] table of
// enum xbows_key_color values. Call this from rgb_matrix_indicators_advanced_kb().
static inline void xbows_render_rgb_layers(uint8_t led_min, uint8_t led_max, const int8_t (*layer_colors)[MATRIX_ROWS][MATRIX_COLS], uint8_t num_layers, uint8_t caps_lock_led) {
    uint8_t layer   = get_highest_layer(layer_state);
    bool    caps_on = host_keyboard_led_state().caps_lock;

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t led = g_led_config.matrix_co[row][col];
            if (led == NO_LED || led < led_min || led >= led_max) {
                continue;
            }

            // Caps Lock: force the Caps key white on every layer while active.
            if (caps_on && led == caps_lock_led) {
                rgb_matrix_set_color(led, 0xFF, 0xFF, 0xFF);
                continue;
            }

            // Unassigned / transparent keys on this layer are turned off.
            keypos_t pos     = (keypos_t){.col = col, .row = row};
            uint16_t keycode = keymap_key_to_keycode(layer, pos);
            if (keycode == KC_NO || keycode == KC_TRNS) {
                rgb_matrix_set_color(led, 0x00, 0x00, 0x00);
                continue;
            }

            // Per-key override for this layer; KRGB_DEF keeps the default color.
            if (layer < num_layers) {
                int8_t color = (int8_t)pgm_read_byte(&layer_colors[layer][row][col]);
                if (color != KRGB_DEF) {
                    uint8_t r = pgm_read_byte(&xbows_palette[color].r);
                    uint8_t g = pgm_read_byte(&xbows_palette[color].g);
                    uint8_t b = pgm_read_byte(&xbows_palette[color].b);
                    rgb_matrix_set_color(led, r, g, b);
                }
            }
        }
    }
}

#endif // RGB_MATRIX_ENABLE
