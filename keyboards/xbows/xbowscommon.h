#pragma once

#include QMK_KEYBOARD_H

#ifdef XBC_DEF_RGB_PIN
const uint8_t _xbc_defRgbPin = XBC_DEF_RGB_PIN;
#else
const uint8_t _xbc_defRgbPin = 255;
#endif

// This is a cheat to not have to deal with dynamically allocating memory
// Setting XBC_DEF_LAYER_MAX_LENGTH allows for a minor optimization
#ifdef XBC_LAYER_MAX_LENGTH
const uint8_t _xbc_layerArrayLength = XBC_DEF_LAYER_MAX_LENGTH;
#else
const uint8_t _xbc_layerArrayLength = MATRIX_ROWS * MATRIX_COLS;
#endif

typedef struct {
  uint8_t h;
  uint8_t s;
  uint8_t v;
  uint8_t r;
  uint8_t g;
  uint8_t b;
} KeyColor_s;

typedef enum {
    KRGB_DEF = 0,
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
} KeyColor;

typedef struct {
    uint8_t pin;
    uint8_t h;
    uint8_t s;
} KeyColorSetHs;

typedef struct {
    uint8_t pin;
    KeyColor keyColor;
} KeyColorSetPreset;

typedef struct {
    uint8_t length;
    KeyColorSetHs arr[_xbc_layerArrayLength];
} KeyColorSetHsArray;

typedef struct {
    uint8_t length;
    KeyColorSetPreset arr[_xbc_layerArrayLength];
} KeyColorSetPresetArr;

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

#ifdef XBC_KRGB_VAL_MIN
uint8_t _xbc_KRGB_VAL_min = XBC_KRGB_VAL_MIN;
#else
uint8_t _xbc_KRGB_VAL_min = 33;
#endif

uint8_t (*_xbc_keyindices_ptr)[MATRIX_COLS];
const KeyColorSetPresetArr (*_xbc_rgblayers_ptr)[_xbc_layerMaxArray];

KeyColorSetPresetArr _xbc_currLayer;
KeyColorSetHsArray _xbc_currStreamedLayer;
int _xbc_currLayerIndex = -1;
uint8_t _xbc_currHsVal = 0;


void xbc_initialize_rgb_layers(int layerSize, const KeyColorSetPresetArr rgblayers[layerSize], uint8_t keyindices[MATRIX_ROWS][MATRIX_COLS]) {
    _xbc_keyindices_ptr = keyindices;
    _xbc_rgblayers_ptr = rgblayers;
}

RGB _xbc_HsToRgb(uint8_t h, uint8_t s) {
    return hsv_to_rgb((HSV){h, s, _xbc_currHsVal});
}

KeyColor_s xbc_getKeyColor(KeyColor kc) {
    KeyColor_s c = _xbc_colors[kc];

    if (kc == KRGB_OFF) return c;

    // Update RGB if brightness value has changed, but not if it would set brightness control keys to 0
    if (_xbc_currHsVal != c.v && !(_xbc_currHsVal < _xbc_KRGB_VAL_min && kc == KRGB_VAL)) {
        RGB rgb = xbc_HsToRgb(c.h, c.s);
        c = (KeyColor_s){ c.h, c.s, _xbc_currHsVal, rgb.r, rgb.g, rgb.b };
        _xbc_colors[kc] = c;
    }

    return c;
}


void _xbc_setDefaultColor(uint8_t h, uint8_t s) {

}

void xbc_setLayerColors(int li) {
    if (li != _xbc_currLayerIndex) {
        _xbc_currLayerIndex = li;
        memcpy_P(_xbc_currLayer, _xbc_rgblayers_ptr[li], _xbc_layerMemSize);
    }
    _xbc_currHsVal = rgb_matrix_get_val();
    int si = 0;

    if (_xbc_currLayer.arr[si].pin == _xbc_defRgbPin) {
        KeyColor_s c = xbc_getKeyColor(_xbc_currLayer.arr[si].keyColor);

        _xbc_setDefaultColor(c.h, c.s);
        si++;
    }

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
