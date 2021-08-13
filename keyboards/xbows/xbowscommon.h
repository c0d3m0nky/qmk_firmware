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

#define RGBLAYOUT( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014,  \
    K100, K101, K102, K103, K104, K105,       K107, K108, K109, K110, K111, K112, K113, K114,  \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214,  \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314,  \
    K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413,        \
    K500, K501, K502,       K504, K505, K506, K507,       K509, K510, K511, K512, K513, K514   \
) \
{ \
    { K000, K001, K002, K003,       K004, K005, K006,       K007, K008,     K009, K010, K011, K012, K013, K014      }, \
    { K100, K101, K102, K103,       K104, K105, KRGB_DEF,   K107, K108,     K109, K110, K111, K112, K113, K114      }, \
    { K200, K201, K202, K203,       K204, K205, K206,       K207, K208,     K209, K210, K211, K212, K213, K214      }, \
    { K300, K301, K302, K303,       K304, K305, K306,       K307, K308,     K309, K310, K311, K312, K313, K314      }, \
    { K400, K401, K402, K403,       K404, K405, K406,       K407, K408,     K409, K410, K411, K412, K413, KRGB_DEF  }, \
    { K500, K501, K502, KRGB_DEF,   K504, K505, K506,       K507, KRGB_DEF, K509, K510, K511, K512, K513, K514      }  \
}
