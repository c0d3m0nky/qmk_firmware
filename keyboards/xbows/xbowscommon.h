#pragma once

#include QMK_KEYBOARD_H

typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
  bool def;
} RgbColor;


#define KRGB_HOME       (RgbColor){ RGB_CYAN, false }
#define KRGB_MEDIA      (RgbColor){ RGB_MAGENTA, false }
#define KRGB_DEV1       (RgbColor){ 255, 25, 0, false }
#define KRGB_DEV2       (RgbColor){ RGB_ORANGE, false }
#define KRGB_FN         (RgbColor){ 0x99, 0x00, 0xCC, false }
#define KRGB_MISNAMED   (RgbColor){ 0x09, 0x00, 0x37, false }
#define KRGB_PORTAL1    (RgbColor){ RGB_BLUE, false }
#define KRGB_PORTAL2    (RgbColor){ 255, 85, 0, false }
#define KRGB_OFF        (RgbColor){ 0x00, 0x00, 0x00, false }
#define KRGB_DANGER     (RgbColor){ 0xFF, 0x00, 0x00, false }
#define KRGB_WHITE      (RgbColor){ 0xFF, 0xFF, 0xFF, false }
#define KRGB_DEF        (RgbColor){ 0, 0, 0, true }

size_t _xbc_layerMemSize = sizeof(KRGB_FN) * MATRIX_ROWS * MATRIX_COLS;

int (*_xbc_keyindices_ptr)[MATRIX_COLS];
const RgbColor (*_xbc_rgblayers_ptr)[MATRIX_ROWS][MATRIX_COLS];

RgbColor _xbc_lastLayer[MATRIX_ROWS][MATRIX_COLS];
int _xbc_lastLayerIndex = -1;


void xbc_initialize_rgb_layers(int layerSize, const RgbColor rgblayers[layerSize][MATRIX_ROWS][MATRIX_COLS], int keyindices[MATRIX_ROWS][MATRIX_COLS]) {
    _xbc_keyindices_ptr = keyindices;
    _xbc_rgblayers_ptr = rgblayers;
}


void xbc_set_colors(int li) {
    if (li != _xbc_lastLayerIndex) {
        _xbc_lastLayerIndex = li;
        memcpy_P(_xbc_lastLayer, _xbc_rgblayers_ptr[li], _xbc_layerMemSize);
    }

    for (int ri = 0; ri < MATRIX_ROWS; ri++) {
        for (int ci = 0; ci < MATRIX_COLS; ci++) {
            RgbColor c = _xbc_lastLayer[ri][ci];

            if (!c.def) {
                rgb_matrix_set_color(_xbc_keyindices_ptr[ri][ci], c.r, c.g, c.b);
            }
        }
    }
}
