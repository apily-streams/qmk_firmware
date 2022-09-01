#include QMK_KEYBOARD_H
#include "config.h"
#include "keycode.h"
#include <ergodox_ez/ergodox_ez.h>

enum LAYERS {
    BASE, // default qwerty layer
    MAC, // mac os overrides
    WIN,  // windows os overrides
    FUNC_ROW, // function key row
    SYMBOLS,  // symbols
    FUNC_PAD, // function key pad
    NUM_PAD,  // numbers
    SYS,  // settings and configuration
};

/*
 * special keys
 *
 * key : dbl tap    / tap an hold
 * TAB : alt+tab
 * ESC : Caps Lock
 * Z   : Left Control
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic QWERTY Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  \ |   |   1  |   2  |   3  |   4  |   5  |   -  |           |   +  |   6  |   7  |   8  |   9  |   0  |BACKSPCE|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |  ENTER |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ESC    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |  Z   |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |  `   |   '  | Left | Right|                                       |  Up  | Down |   [  |   ]  |        |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,---------------.      ,----------------.
 *                                       |       |       |      |       |        |
 *                                ,------|------ |-------|      |-------+--------+-------.
 *                                |      |       |       |      |       |        |       |
 *                                |      |       |-------|      |-------|        |       |
 *                                |      |       |       |      |       |        |       |
 *                                `----------------------'      `------------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand                                                                                            // right hand
  KC_NONUS_BSLASH, KC_1,     KC_2,     KC_3,         KC_4,           KC_5,     KC_MINUS,                  KC_PLUS,        KC_6,           KC_7,    KC_8,    KC_9,    KC_0,           KC_BACKSPACE,
  KC_TAB,          KC_Q,     KC_W,     KC_E,         KC_R,           KC_T,     KC_TRANSPARENT,            KC_TRANSPARENT, KC_Y,           KC_U,    KC_I,    KC_O,    KC_P,           KC_ENTER,
  KC_ESCAPE,       KC_A,     KC_S,     KC_D,         KC_F,           KC_G,                                                KC_H,           KC_J,    KC_K,    KC_L,    KC_SCOLON,      KC_QUOTE,
  KC_LSFT,         KC_Z,     KC_X,     KC_C,         KC_V,           KC_B,     KC_HYPER,                  KC_MEH,         KC_N,           KC_M,    KC_COMM, KC_DOT,  KC_SLSH,        KC_RSFT,
  KC_TRANSPARENT,  KC_GRAVE, KC_QUOTE, KC_LEFT,   KC_RGHT,                                                                KC_UP,          KC_DOWN, KC_LBRC, KC_RBRC, KC_TRANSPARENT,
                                                           KC_TRANSPARENT,     KC_TRANSPARENT,            KC_TRANSPARENT, KC_TRANSPARENT,
                                                                               KC_TRANSPARENT,            KC_TRANSPARENT,
                                           KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,            KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),
[MAC] = LAYOUT_ergodox_pretty(
  // left hand                                                       // right hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______,
                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
[WIN] = LAYOUT_ergodox_pretty(
  // left hand                                                       // right hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______,
                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
[FUNC_ROW] = LAYOUT_ergodox_pretty(
  // left hand                                                       // right hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______,
                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
[SYMBOLS] = LAYOUT_ergodox_pretty(
  // left hand                                                       // right hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______,
                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
[FUNC_PAD] = LAYOUT_ergodox_pretty(
  // left hand                                                       // right hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______,
                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
[NUM_PAD] = LAYOUT_ergodox_pretty(
  // left hand                                                       // right hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______,
                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
[SYS] = LAYOUT_ergodox_pretty(
  // left hand                                                       // right hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______,
                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
)
};