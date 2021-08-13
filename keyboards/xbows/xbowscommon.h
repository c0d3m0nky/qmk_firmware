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

int _xbc_layerSize = 0;

void xbc_initialize_rgb_layers(int layerSize) {
	_xbc_layerSize = layerSize;
}

void xbc_set_colors(RgbColor rgbLayer[MATRIX_ROWS][MATRIX_COLS], int keyIndicies[MATRIX_ROWS][MATRIX_COLS]) {
    for (int ri = 0; ri < MATRIX_ROWS; ri++) {
        for (int ci = 0; ci < MATRIX_COLS; ci++) {
	    	// if((ri == 1 && ci == 6) || (ri == 4 && ci == 14) || (ri == 5 && ci == 3) || (ri == 5 && ci == 8)) continue;

	       RgbColor c = rgbLayer[ri][ci];

	       if (!c.def) {
	           int ki = keyIndicies[ri][ci];

               if (ki != NO_LED) rgb_matrix_set_color(ki, c.r, c.g, c.b);
	       }
	    }    
	}
}