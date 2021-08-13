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
