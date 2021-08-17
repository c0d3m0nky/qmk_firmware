#pragma once

#include QMK_KEYBOARD_H

typedef struct {
  uint8_t h;
  uint8_t s;
  uint8_t v;
  uint8_t r;
  uint8_t g;
  uint8_t b;
} KeyColor_s;

enum KeyColor_e {
    KRGB_DEF = -1,
    KRGB_OFF,
    KRGB_VAL,   // Special value for the keys that control brightness so they don't fully turn off
    KRGB_HOME,
    KRGB_MEDIA,
    KRGB_DEV1,
    KRGB_DEV2,
    KRGB_FN,
    KRGB_MISNAMED,
    KRGB_PORTAL1,
    KRGB_PORTAL2,
    KRGB_DANGER,
    KRGB_WHITE
};

typedef enum KeyColor_e KeyColor;

KeyColor_s _xbc_colors[] = {
    [KRGB_OFF] = 		{},
    [KRGB_VAL] = 		{0, 0, 255, 255, 255, 255},
    [KRGB_HOME] = 		{128, 255, 255, 0, 255, 255},
    [KRGB_MEDIA] = 		{213, 255, 255, 255, 0, 255},
    [KRGB_DEV1] = 		{4, 255, 255, 255, 25, 0},
    [KRGB_DEV2] = 		{21, 255, 255, 255, 128, 0},
    [KRGB_FN] = 		{202, 255, 204, 153, 0, 204},
    [KRGB_MISNAMED] = 	{177, 255, 55, 9, 0, 55},
    [KRGB_PORTAL1] = 	{170, 255, 255, 0, 0, 255},
    [KRGB_PORTAL2] = 	{14, 255, 255, 255, 85, 0},
    [KRGB_DANGER] = 	{0, 255, 255, 255, 0, 0},
    [KRGB_WHITE] = 		{0, 0, 255, 255, 255, 255}
};

size_t _xbc_layerMemSize = sizeof(KeyColor) * MATRIX_ROWS * MATRIX_COLS;
uint8_t _xbc_KRGB_VAL_min = 33;

int (*_xbc_keyindices_ptr)[MATRIX_COLS];
const KeyColor (*_xbc_rgblayers_ptr)[MATRIX_ROWS][MATRIX_COLS];

KeyColor _xbc_currLayer[MATRIX_ROWS][MATRIX_COLS];
int _xbc_currLayerIndex = -1;
uint8_t _xbc_currHsVal = 0;


void xbc_initialize_rgb_layers(int layerSize, const KeyColor rgblayers[layerSize][MATRIX_ROWS][MATRIX_COLS], int keyindices[MATRIX_ROWS][MATRIX_COLS]) {
    _xbc_keyindices_ptr = keyindices;
    _xbc_rgblayers_ptr = rgblayers;
}


KeyColor_s xbc_getKeyColor(KeyColor kc) {
    KeyColor_s c = _xbc_colors[kc];

    if (kc == KRGB_OFF) return c;

    // Update RGB if brightness value has changed, but not if it would set brightness control keys to 0
    if (_xbc_currHsVal != c.v && !(_xbc_currHsVal < _xbc_KRGB_VAL_min && kc == KRGB_VAL)) {
        RGB rgb = hsv_to_rgb((HSV){c.h, c.s, _xbc_currHsVal});
        c = (KeyColor_s){ c.h, c.s, _xbc_currHsVal, rgb.r, rgb.g, rgb.b };
        _xbc_colors[kc] = c;
    }

    return c;
}


void xbc_set_colors(int li) {
    if (li != _xbc_currLayerIndex) {
        _xbc_currLayerIndex = li;
        memcpy_P(_xbc_currLayer, _xbc_rgblayers_ptr[li], _xbc_layerMemSize);
    }
    _xbc_currHsVal = rgb_matrix_get_val();

    for (int ri = 0; ri < MATRIX_ROWS; ri++) {
        for (int ci = 0; ci < MATRIX_COLS; ci++) {
            KeyColor kc = _xbc_currLayer[ri][ci];

            if (kc != KRGB_DEF) {
                KeyColor_s c = xbc_getKeyColor(kc);
                rgb_matrix_set_color(_xbc_keyindices_ptr[ri][ci], c.r, c.g, c.b);
            }
        }
    }
}
