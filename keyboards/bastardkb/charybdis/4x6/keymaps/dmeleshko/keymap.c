/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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
#include <stdint.h>
#include QMK_KEYBOARD_H

#include "features/custom_shift_keys.h"

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
a
enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_QWERTY,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_POINTER,
    LAYER_SYMBOLS,
    LAYER_MACRO
};

/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define LOWER LT(LAYER_LOWER, KC_BSPC)
#define RAISE LT(LAYER_RAISE, KC_SPC)
#define PT_Z LT(LAYER_POINTER, KC_Z)
#define PT_Q LT(LAYER_POINTER, KC_Q)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)
#define SYMBOLS LT(LAYER_SYMBOLS, KC_ENT)
#define MACRO MO(LAYER_MACRO)

#define DF_GRPT DF(LAYER_BASE)
#define DF_QWRT DF(LAYER_QWERTY)

#define LC_N LCTL_T(KC_N)
#define LC_I LCTL_T(KC_I)
#define LC_A LCTL_T(KC_A)
#define LC_SCLN LCTL_T(KC_SCLN)

#define SYM_N LT(LAYER_SYMBOLS, KC_N)
#define SYM_I LT(LAYER_SYMBOLS, KC_I)
#define SYM_A LT(LAYER_SYMBOLS, KC_A)
#define SYM_SCLN LT(LAYER_SYMBOLS, KC_SCLN)

#define LA_R LALT_T(KC_R)
#define LA_E LALT_T(KC_E)
#define LA_S LALT_T(KC_S)
#define LA_L LALT_T(KC_L)

#define LG_T LGUI_T(KC_T)
#define LG_A LGUI_T(KC_A)
#define LG_D LGUI_T(KC_D)
#define LG_K LGUI_T(KC_K)

#define LS_S LSFT_T(KC_S)
#define LS_H LSFT_T(KC_H)
#define LS_F LSFT_T(KC_F)
#define LS_J LSFT_T(KC_J)

#define WM_BL HYPR(KC_1)
#define WM_B HYPR(KC_2)
#define WM_BR HYPR(KC_3)
#define WM_L HYPR(KC_4)
#define WM_F HYPR(KC_5)
#define WM_R HYPR(KC_6)
#define WM_TL HYPR(KC_7)
#define WM_T HYPR(KC_8)
#define WM_TR HYPR(KC_9)

#define MC_SCRN S(G(C(KC_4)))

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

enum custom_keycodes {
    RU_TOGG = SAFE_RANGE,
    MC_CDUP,
    MC_CLEQ,
};

const custom_shift_key_t custom_shift_keys[] = {
  {KC_QUOT, KC_UNDS}, // Shift ' is _
  {KC_COMM, KC_QUES}, // Shift , is ?
  {KC_MINS, KC_DQUO}, // Shift - is "
  {PT_SLSH, KC_LT  }, // Shift / is <
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_GRV,    KC_4,    KC_3,    KC_2,    KC_1,    KC_5,       KC_9,    KC_0,    KC_6,    KC_7,    KC_8, KC_MINS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       CW_TOGG,    KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,    KC_QUOT,    KC_F,    KC_O,    KC_U,    KC_J, KC_SCLN,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT,   SYM_N,    LA_R,    LG_T,    LS_S,    KC_G,       KC_Y,    LS_H,    LG_A,    LA_E,   SYM_I, KC_COMM,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LCTL,    PT_Q,    KC_X,    KC_M,    KC_C,    KC_V,       KC_K,    KC_P,  KC_DOT, KC_MINS, PT_SLSH, KC_LCTL,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                    KC_NO,   LOWER,  KC_ENT,     KC_TAB,   RAISE,
                                             MACRO,   KC_NO,     KC_ESC
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_QWERTY] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_GRV,    KC_4,    KC_3,    KC_2,    KC_1,    KC_5,       KC_9,    KC_0,    KC_6,    KC_7,    KC_8, KC_MINS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       CW_TOGG,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT,   SYM_A,    LA_S,    LG_D,    LS_F,    KC_G,       KC_H,    LS_J,    LG_K,    LA_L,SYM_SCLN, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LCTL,    PT_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, PT_SLSH, KC_LCTL,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                    KC_NO,   LOWER,  KC_ENT,     KC_TAB,   RAISE,
                                             MACRO,   KC_NO,     KC_ESC
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TILD, KC_DLR,  KC_HASH,   KC_AT, KC_EXLM, KC_PERC,    KC_LPRN, KC_RPRN, KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_LBRC,   KC_P7,   KC_P8,   KC_P9, KC_RBRC, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_TOG, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,    KC_PPLS,   KC_P4,   KC_P5,   KC_P6, KC_PMNS, KC_PEQL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_PAST,   KC_P1,   KC_P2,   KC_P3, KC_PSLS, KC_PDOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, _______,    XXXXXXX, _______,
                                           XXXXXXX, XXXXXXX,      KC_P0
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F4,   KC_F3,   KC_F2,   KC_F1,   KC_F5,      KC_F9,  KC_F10,   KC_F6,   KC_F7,  KC_F8,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MNXT, KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX,    DF_QWRT, RU_TOGG, DF_GRPT, XXXXXXX, XXXXXXX, KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPLY, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,    CW_TOGG, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPRV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, XXXXXXX,    _______, XXXXXXX,
                                           _______, _______,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       QK_BOOT,  EE_CLR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,  EE_CLR,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, _______, DRGSCRL, SNIPING, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, SNIPING, DRGSCRL, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN2, KC_BTN1, KC_BTN3,    KC_BTN3, KC_BTN1,
                                           XXXXXXX, KC_BTN2,    KC_BTN2
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_SYMBOLS] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,  KC_GRV,   KC_LT,   KC_GT, KC_DQUO,  KC_DOT,    KC_AMPR, MC_CLEQ, KC_LBRC, KC_RBRC, KC_PERC, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_EXLM, KC_MINS, KC_PLUS,  KC_EQL, KC_HASH,    KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, MC_CDUP,    KC_TILD,  KC_DLR, KC_LCBR, KC_RCBR,   KC_AT, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,
                                           XXXXXXX, XXXXXXX,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_MACRO] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    MC_SCRN,   WM_TL,    WM_T,   WM_TR, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    WM_L,    WM_F,    WM_R, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,   WM_BL,    WM_B,   WM_BR, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,
                                           XXXXXXX, XXXXXXX,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on
bool is_russian_enabled = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!is_russian_enabled && !process_custom_shift_keys(keycode, record)) { return false; }
    switch (keycode) {
    case RU_TOGG:
        if (!record->event.pressed) {
            if (is_russian_enabled) {
                SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_DOWN(X_LGUI) SS_LSFT("e") SS_UP(X_LCTL) SS_UP(X_LALT) SS_UP(X_LGUI));
                default_layer_set((layer_state_t)1 << LAYER_BASE);
                rgb_matrix_sethsv_noeeprom(MY_BASE_COLOR);
            } else {
                SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_DOWN(X_LGUI) SS_LSFT("r") SS_UP(X_LCTL) SS_UP(X_LALT) SS_UP(X_LGUI));
                default_layer_set((layer_state_t)1 << LAYER_QWERTY);
                rgb_matrix_sethsv_noeeprom(MY_SECONDARY_COLOR);
            }
            is_russian_enabled = !is_russian_enabled;
        }
        break;
    case MC_CDUP:
        if (!record->event.pressed) {
            SEND_STRING("../");
        }
        break;
    case MC_CLEQ:
        if (!record->event.pressed) {
            SEND_STRING(":=");
        }
        break;
    }
    return true;
}

#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

void keyboard_post_init_user(void) {
    rgb_matrix_sethsv_noeeprom(MY_BASE_COLOR);
}

layer_state_t layer_state_set_user(layer_state_t state) {
#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
  return state;
}

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif
