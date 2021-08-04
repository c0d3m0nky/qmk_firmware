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
#define KRGB_DEV1       (RgbColor){ 255, 52, 0, false }
#define KRGB_DEV2       (RgbColor){ RGB_ORANGE, false }
#define KRGB_FN         (RgbColor){ 0x99, 0x00, 0xCC, false }
#define KRGB_MISNAMED   (RgbColor){ 0x09, 0x00, 0x37, false }
#define KRGB_PORTAL1    (RgbColor){ RGB_BLUE, false }
#define KRGB_PORTAL2    (RgbColor){ RGB_ORANGE, false }
#define KRGB_OFF        (RgbColor){ 0x00, 0x00, 0x00, false }
#define KRGB_DANGER     (RgbColor){ 0xFF, 0x00, 0x00, false }
#define KRGB_WHITE      (RgbColor){ 0xFF, 0xFF, 0xFF, false }
#define KRGB_DEF        (RgbColor){ 0, 0, 0, true }

int _xbc_layerSize = 0;
int _xbc_rowSize = 0;
int _xbc_colSize = 0;


uint16_t xbc_get_keycode(int layer, int row, int col) {
  uint16_t kc = keymap_key_to_keycode(layer, (keypos_t){.row = row, .col = col});

  kc = keycode_config(kc);

  return (kc == KC_TRNS && layer > 0) ? xbc_get_keycode(layer - 1, row, col) : kc;
}

void xbc_initialize_rgb_layers(int layerSize, int rowSize, int colSize, RgbColor rgbLayers[layerSize][rowSize][colSize], int keyIndicies[rowSize][colSize], led_config_t ledConfig) {
	_xbc_layerSize = layerSize;
	_xbc_rowSize = rowSize;
	_xbc_colSize = colSize;

	for (int li = 0; li < _xbc_layerSize; li++) { 
	    for (int ri = 0; ri < _xbc_rowSize; ri++) { 
	      for (int ci = 0; ci < _xbc_colSize; ci++) {
	        switch (xbc_get_keycode(li, ri, ci)) {
	          case KC_NO:
	            rgbLayers[li][ri][ci] = KRGB_OFF;
	            break;
	          case RESET:
	          case EEP_RST:
	            rgbLayers[li][ri][ci] = KRGB_DANGER;
	            break;          
	          case RGB_VAI:
	          case RGB_VAD:
	            rgbLayers[li][ri][ci] = KRGB_WHITE;
	            break;
	          default:
	            break;
	        }

	              
	        if (li == 0) {
	          keyIndicies[ri][ci] = ledConfig.matrix_co[ri][ci];
	        }
	      }    
	    }
	}
}

void xbc_set_colors(RgbColor rgbLayer[_xbc_rowSize][_xbc_colSize], int keyIndicies[_xbc_rowSize][_xbc_colSize]) {
	for (int ri = 0; ri < _xbc_rowSize; ri++) { 
	    for (int ci = 0; ci < _xbc_colSize; ci++) { 
	      RgbColor c = rgbLayer[ri][ci];

	      if (!c.def) {
	        rgb_matrix_set_color(keyIndicies[ri][ci], c.r, c.g, c.b);
	      }
	    }    
	}
}