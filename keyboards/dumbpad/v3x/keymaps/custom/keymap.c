/*
Copyright 2022 imchipwood && deveth0

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
            BASE LAYER - Num Pad
    /-----------------------------------------------------`
    |             |    7    |    8    |    9    |    -    |
    |             |---------|---------|---------|---------|
    |             |    4    |    5    |    6    |    +    |
    |             |---------|---------|---------|---------|
    |             |    1    |    2    |    3    |    *    |
    |-------------|---------|---------|---------|---------|
    |    Mute     |  TT(1)  |    0    |    .    |  Enter  |
    \-----------------------------------------------------'
    */
    [0] = LAYOUT(
                    KC_P7,      KC_P8,    KC_P9,             KC_PMNS,
                    KC_P4,      KC_P5,    KC_P6,             KC_PPLS,
                    KC_P1,      KC_P2,    KC_P3,             KC_PAST,
        KC_MUTE,    TT(1),      KC_P0,    KC_KP_DOT,         KC_ENTER
    ),
    /*
            SUB LAYER  - RGB controls, Modes on encoder
    /-----------------------------------------------------`
    |             | On/Off  | Bright- | Bright+ |  Reset  |
    |             |---------|---------|---------|---------|
    |             |         | Hue-    | Hue+    |         |
    |             |---------|---------|---------|---------|
    |             |         | Sat-    | Sat+    |         |
    |-------------|---------|---------|---------|---------|
    |             |  TT(1)  | Effect- | Effect+ |         |
    \-----------------------------------------------------'
    */
    [1] = LAYOUT(
                    RM_TOGG,    RM_VALD,     RM_VALU,      QK_BOOT,
                    KC_NO,      RM_HUED,     RM_HUEU,      KC_NO,
                    KC_NO,      RM_SATD,     RM_SATU,      KC_NO,
        KC_NO,      _______,    RM_SPDD,     RM_SPDU,      KC_NO
    ),
};
// clang-format on

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case 0:
            // main layer, volume
            if (clockwise) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_VOLU);
            }
            break;
        default:
            // rgb control layer, effects
            if (clockwise) {
                rgblight_step();
            } else {
                rgblight_step_reverse();
            }
            break;
    }
    return false;

    // }
    // enum combos {
    //     C1_DEL,
    //     C2_END,
    //     C3_PGDN,
    //     C4_INSERT,
    //     C5_HOME,
    //     C6_PGUP,
    //     C7_PRTSC,
    //     C8_SCROLL,
    //     C9_PAUSE
    // };
    // //Combos
    // const uint16_t PROGMEM del[] = {KC_LCTL, KC_P1, COMBO_END};
    // const uint16_t PROGMEM end[] = {KC_LCTL, KC_P2, COMBO_END};
    // const uint16_t PROGMEM pgdn[] = {KC_LCTL, KC_P3, COMBO_END};
    // const uint16_t PROGMEM insert[] = {KC_LCTL, KC_P4, COMBO_END};
    // const uint16_t PROGMEM home[] = {KC_LCTL, KC_P5, COMBO_END};
    // const uint16_t PROGMEM pgup[] = {KC_LCTL, KC_P6, COMBO_END};
    // const uint16_t PROGMEM prtsc[] = {KC_LCTL, KC_P7, COMBO_END};
    // const uint16_t PROGMEM scroll[] = {KC_LCTL, KC_P8, COMBO_END};
    // const uint16_t PROGMEM pause[] = {KC_LCTL, KC_P9, COMBO_END};

    // combo_t key_combos[] = {
    //     [C1_DEL] = COMBO(del, KC_DEL),
    //     [C2_END] = COMBO(end, KC_END),
    //     [C3_PGDN] = COMBO(pgdn, KC_PGDN),
    //     [C4_INSERT] = COMBO(insert, KC_INS),
    //     [C5_HOME] = COMBO(home, KC_HOME),
    //     [C6_PGUP] = COMBO(pgup, KC_PGUP),
    //     [C7_PRTSC] = COMBO(prtsc, KC_PSCR),
    //     [C8_SCROLL] = COMBO(scroll, KC_SCRL),
    //     [C9_PAUSE] = COMBO(pause, KC_PAUSE)
    // };