#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0  // default layer
#define SYMB 1  // symbols
#define MDIA 2  // media keys

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |  `   |           |   :  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   [    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |    ]   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | RAlt   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | RAlt   |
 * |--------+------+------+------+------+------|  L2  |           |  L2  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl |   "  |  (   |  )   |   $  |                                       |   \  |  <   |  >   |  '   | RCtrl|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | MEH  |       | HYPR |  Esc |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | LGUI |       | RGUI |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | LAlt |       | LAlt |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_GRV,
  KC_LBRACKET,     KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    OSL(SYMB),
  OSM(MOD_RALT),   KC_A,        KC_S,          KC_D,    KC_F,    KC_G,
  OSM(MOD_LSFT),   KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    OSL(MDIA),
  OSM(MOD_LCTL),   KC_DQT,   KC_LPRN,         KC_RPRN,  KC_DOLLAR,
                                                                     KC_NO, KC_MEH,
                                                                    OSM(MOD_LGUI),
                                                   KC_SPC, KC_BSPC, OSM(MOD_LALT),
  // right hand
  KC_COLON,     KC_6,    KC_7,    KC_8,    KC_9,         KC_0,            KC_MINS,
  OSL(SYMB),    KC_Y,    KC_U,    KC_I,    KC_O,         KC_P,            KC_RBRACKET,
                KC_H,    KC_J,    KC_K,    KC_L,         KC_SCLN,         OSM(MOD_RALT),
  OSL(MDIA),    KC_N,    KC_M,    KC_COMM, KC_DOT,       KC_SLSH,         OSM(MOD_RSFT),
                      KC_BSLS,    KC_LT,   KC_GT,        KC_QUOTE,        OSM(MOD_RCTL),
  KC_HYPR, KC_ESC,
  OSM(MOD_RGUI),
  OSM(MOD_LALT), KC_TAB, KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           | F12  |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |      |      |      |  _   |   -  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------|  ^   |  &   |  *   |  '   |   "  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |      |   [  |   ]  |   ~  |      |           |      |      |      |      |      |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  // left hand
  KC_NO,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
  KC_NO, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
  KC_NO, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
  KC_NO, KC_PERC, KC_NO, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                               KC_NO, KC_NO,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_NO,
  KC_TRNS, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_MINS, KC_NO,
           KC_CIRC, KC_AMPR, KC_ASTR, KC_QUOT, KC_DQT,  KC_NO,
  KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSLS, KC_NO,
                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |  INS   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |Lclck | MsUp |Rclck |      |      |           |      | HOME | PgDn | PgUp | END  |      |  DEL   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------| Left | Down |  Up  | Rght |      |  PSCR  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | Prev | Mute | Play | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
  // left hand
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_BTN1, KC_MS_U, KC_BTN2, KC_NO, KC_TRNS,
  KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
  KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_INS,
  KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO, KC_DEL,
           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO, KC_PSCR,
  KC_TRNS, KC_MPRV, KC_MUTE, KC_MPLY, KC_MNXT, KC_NO, KC_NO,
                    KC_VOLU, KC_VOLD, KC_NO, KC_NO, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case EPRM:
                eeconfig_init();
                return false;
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
#ifdef RGBLIGHT_ENABLE
            case RGB_SLD:
                rgblight_mode(1);
                return false;
#endif
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = biton32(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#else
#    ifdef RGBLIGHT_ENABLE
            rgblight_init();
#    endif
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
