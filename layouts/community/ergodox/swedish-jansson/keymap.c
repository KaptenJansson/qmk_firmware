/* Copyright 2017 Christoffer Jansson
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "debug.h"
#include "version.h"
#include "keymap_swedish.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols layer
#define GAME 2 // gaming layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Default layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * | Esc    |   !  |  "   |  #   |  #   |  %   | LEFT |           | RIGHT|   &  |  /   |  (   |  )   |  =   |  ?     |
   * |        |   1  |  2 @ |  3 £ |  4 $ |  5   |      |           |      |   6  |  7 { |  8 [ |  9 ] |  0 } |  + \   |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Del    |   Q  |   W  |   E  |   R  |   T  | ~L2  |           |      |   Y  |   U  |   I  |   O  |   P  |   Å    |
   * |        |      |      |      |      |      |      |           | Del  |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |Ö / L2|Ä / Cmd |
   * | CTRL   |      |      |      |      |      | Hyper|           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           | Alt  |------+------+------+------+------+--------|
   * | Left   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ;  |   :  |_/Ctrl| RShift |
   * | Shift  |      |      |      |      |      |      |           |      |      |      |   ,  |   .  |-     |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   | '/L1 |  `   |AltShf| Left | Right|                                       |  Up  | Down |  ^   |  *   | ~L1  |
   *   |      |  '   |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | App  | LGui |       | AltGr| Esc  |
   *                                 ,------|------|------|       |------|------|------,
   *                                 |      |      | Home |       | PgUp |      |      |
   *                                 | Space|Back- |------|       |------| Tab  |Enter |
   *                                 |      |space | End  |       | PgDn |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [BASE] = LAYOUT_ergodox(
    // left hand
    KC_ESC,            KC_1,    KC_2,          KC_3,    KC_4,    KC_5, KC_LEFT,
    KC_DELT,           KC_Q,    KC_W,          KC_E,    KC_R,    KC_T, KC_FN2,
    KC_LCTL,           KC_A,    KC_S,          KC_D,    KC_F,    KC_G,
    KC_LSFT,           KC_Z,    KC_X,          KC_C,    KC_V,    KC_B, ALL_T(KC_NO),
    LT(SYMB, NO_APOS), NO_ACUT, LALT(KC_LSFT), KC_LEFT, KC_RGHT,
                                                                 ALT_T(KC_APP),   KC_LGUI,
                                                                                  KC_HOME,
                                                                 KC_SPC, KC_BSPC, KC_END,
    // right hand
    KC_RGHT, KC_6,   KC_7,   KC_8,    KC_9,    KC_0,              NO_PLUS,
    KC_DELT, KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,              NO_AA,
             KC_H,   KC_J,   KC_K,    KC_L,    LT(GAME, NO_OSLH), GUI_T(NO_AE),
    KC_LALT, KC_N,   KC_M,   KC_COMM, KC_DOT,  CTL_T(NO_MINS),    KC_RSFT,
                     KC_UP,  KC_DOWN, NO_CIRC, NO_ASTR,           KC_FN1,
    NO_ALGR, KC_ESC,
    KC_PGUP,
    KC_PGDN, KC_TAB, KC_ENT
  ),

  /* Keymap 1: Symbol Layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |  ½ §   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |   !  |   @  |   {  |   }  |   |  |   \  |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      | Play |       | Mute |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      | Next |       | VolUp|      |      |
   *                                 |   <  |      |------|       |------|      |  >   |
   *                                 |      |      | Prev |       | Voldn|      |      |
   *                                 `--------------------'       `--------------------'
   */
  [SYMB] = LAYOUT_ergodox(
    // left hand
    NO_HALF, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
    KC_TRNS, KC_EXLM, NO_AT,   NO_LCBR, NO_RCBR, NO_PIPE, RALT(NO_PLUS),
    KC_LCTL, KC_HASH, NO_DLR,  NO_LPRN, NO_RPRN, NO_GRV,
    KC_LSFT, KC_PERC, NO_CIRC, NO_LBRC, NO_RBRC, NO_TILD, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 KC_TRNS, KC_MPLY,
                                                          KC_MNXT,
                                        KC_NUBS, KC_TRNS, KC_MPRV,
    // right hand
    KC_TRNS, KC_F6,   KC_F7,   KC_F8,  KC_F9, KC_F10,  KC_F11,
    KC_TRNS, KC_UP,   KC_7,    KC_8,   KC_9,  NO_ASTR, KC_F12,
             KC_DOWN, KC_4,    KC_5,   KC_6,  NO_PLUS, KC_TRNS,
    KC_TRNS, NO_AMPR, KC_1,    KC_2,   KC_3,  KC_NUBS, KC_TRNS,
                      KC_TRNS, KC_DOT, KC_0,  NO_EQL,  KC_TRNS,
    KC_MUTE, KC_TRNS,
    KC_VOLU,
    KC_VOLD, KC_TRNS, LSFT(KC_NUBS)
  ),

  /* Keymap 2: Gaming Layer
   * Left side is changed to accomedate most games, right side is untouched so typing in chat is still possible.
   * Scrl lock is used for push to talk in voice chat apps.
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * | Esc    |   !  |  "   |  #   |  #   |  %   |  &   |           | RIGHT|   &  |  /   |  (   |  )   |  =   |  ?     |
   * |        |   1  |  2 @ |  3 £ |  4 $ |  5   |  6   |           |      |   6  |  7 { |  8 [ |  9 ] |  0 } |  + \   |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Tab    |   Q  |   W  |   E  |   R  |   T  |  M   |           |      |   Y  |   U  |   I  |   O  |   P  |   Å    |
   * |        |      |      |      |      |      |      |           | Del  |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |Ö / L2|Ä / Cmd |
   * | CTRL   |      |      |      |      |      |  I   |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           | Alt  |------+------+------+------+------+--------|
   * | Left   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ;  |   :  |_/Ctrl| RShift |
   * | Shift  |      |      |      |      |      |      |           |      |      |      |   ,  |   .  |-     |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   | Scrl |  Alt | Enter| Left | Right|                                       |  Up  | Down |  '   |  *   | ~L1  |
   *   | Lock |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |  F1  |  F2  |       | AltGr| Esc  |
   *                                 ,------|------|------|       |------|------|------.
   *                                 |      |      |  F3  |       | PgUp |      |      |
   *                                 | Space|Back- |------|       |------| Tab  | Enter|
   *                                 |      |space |  F4  |       | PgDn |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [GAME] = LAYOUT_ergodox(
    // left hand
    KC_ESC,  KC_1,    KC_2,          KC_3,    KC_4,    KC_5, KC_6,
    KC_TAB,  KC_Q,    KC_W,          KC_E,    KC_R,    KC_T, KC_M,
    KC_LCTL, KC_A,    KC_S,          KC_D,    KC_F,    KC_G,
    KC_LSFT, KC_Z,    KC_X,          KC_C,    KC_V,    KC_B, KC_I,
    KC_SLCK, KC_LALT, KC_ENT,        KC_LEFT, KC_RGHT,
                                                               KC_F1,   KC_F2,
                                                                        KC_F3,
                                                       KC_SPC, KC_BSPC, KC_F4,
    // right hand
    KC_RGHT, KC_6,   KC_7,  KC_8,    KC_9,    KC_0,              NO_PLUS,
    KC_DELT, KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,              NO_AA,
             KC_H,   KC_J,  KC_K,    KC_L,    LT(GAME, NO_OSLH), GUI_T(NO_AE),
    KC_LALT, KC_N,   KC_M,  KC_COMM, KC_DOT,  CTL_T(NO_MINS),    KC_RSFT,
                     KC_UP, KC_DOWN, NO_APOS, NO_ASTR,           KC_FN1,
    NO_ALGR, KC_ESC,
    KC_PGUP,
    KC_PGDN, KC_TAB, KC_ENT
  ),
};

// Toggle layers.
const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),  // FN1 - Momentary Layer 1 (Symbols)
  [2] = ACTION_LAYER_TAP_TOGGLE(GAME),  // FN2 - Momentary Layer 2 (Game)
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);
  ergodox_board_led_off();
  ergodox_right_led_1_off(); // Red
  ergodox_right_led_2_off(); // Green
  ergodox_right_led_3_off(); // Blue
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      // Changed this to the blue led since it's less bright after using a permament marker.
      ergodox_right_led_3_on();
      break;
    default:
      // none
      break;
  }
};


