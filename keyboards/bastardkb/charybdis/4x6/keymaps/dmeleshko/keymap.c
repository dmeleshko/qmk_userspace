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

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_QWERTY,
    LAYER_GRAPHITE,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_POINTER,
    LAYER_SYMBOLS,
    LAYER_SYMBOLS_RU,
    LAYER_MACRO
};

#define LOWER LT(LAYER_LOWER, KC_BSPC)
#define RAISE LT(LAYER_RAISE, KC_SPC)
#define LW_BSPC LT(LAYER_LOWER, KC_BSPC)
#define LW_SPC LT(LAYER_LOWER, KC_SPC)
#define RS_ENT LT(LAYER_RAISE, KC_ENT)
#define RS_TAB LT(LAYER_RAISE, KC_TAB)
#define PT_Z LT(LAYER_POINTER, KC_Z)
#define PT_Q LT(LAYER_POINTER, KC_Q)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)
#define MACRO MO(LAYER_MACRO)
#define QWERTY MO(LAYER_QWERTY)
#define BASE MO(LAYER_GRAPHITE)

#define DF_GRPT DF(LAYER_BASE)
#define DF_QWRT DF(LAYER_QWERTY)

#define LC_N LCTL_T(KC_N)
#define LC_I LCTL_T(KC_I)
#define LC_A LCTL_T(KC_A)
#define LC_SCLN LCTL_T(KC_SCLN)
#define LC_COMM LCTL_T(KC_COMM)
#define LC_QUOT LCTL_T(KC_QUOT)

#define TMUX C(KC_B)

#define SYM_N LT(LAYER_SYMBOLS, KC_N)
#define SYM_I LT(LAYER_SYMBOLS, KC_I)
#define SYM_A LT(LAYER_SYMBOLS_RU, KC_A)
#define SYM_SCLN LT(LAYER_SYMBOLS_RU, KC_SCLN)

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

#define WM_BL C(S(G(KC_LEFT)))
#define WM_B A(G(KC_DOWN))
#define WM_BR C(S(G(KC_RIGHT)))
#define WM_L A(G(KC_LEFT))
#define WM_F A(G(KC_F))
#define WM_R A(G(KC_RIGHT))
#define WM_TL C(G(KC_LEFT))
#define WM_T A(G(KC_UP))
#define WM_TR C(G(KC_RIGHT))
#define WM_NDIS C(A(G(KC_RIGHT)))

#define MC_SCRN S(G(C(KC_4)))
#define MC_RCRD S(G(KC_5))
#define MC_SETRU SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_DOWN(X_LGUI) SS_LSFT("r") SS_UP(X_LCTL) SS_UP(X_LALT) SS_UP(X_LGUI)
#define MC_SETEN SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_DOWN(X_LGUI) SS_LSFT("e") SS_UP(X_LCTL) SS_UP(X_LALT) SS_UP(X_LGUI)

#define RUEN_DELAY 50
#define MC_RUEN(string) MC_SETEN SS_DELAY(RUEN_DELAY) string MC_SETRU

#define MC_UNDO G(KC_Z)
#define MC_REDO G(KC_Y)
#define MC_CUT G(KC_X)
#define MC_COPY G(KC_C)
#define MC_PASTE G(KC_V)
#define MC_LOCK G(C(KC_Q))

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

enum custom_keycodes {
    RU_TOGG = SAFE_RANGE,
    MC_CDUP,
    RU_PIPE,
    RU_GRV,
    RU_LT,
    RU_GT,
    RU_CIRC,
    RU_AMPR,
    RU_LBRC,
    RU_RBRC,
    RU_TILD,
    RU_DLR,
    RU_LCBR,
    RU_RCBR,
    RU_AT,
    RU_DOT,
    RU_COMM,
};

const custom_shift_key_t custom_shift_keys[] = {
  {KC_QUOT, KC_UNDS}, // Shift ' is _
  {LC_COMM, KC_QUES}, // Shift , is ?
  {KC_MINS, KC_DQUO}, // Shift - is "
  {PT_SLSH, KC_LT  }, // Shift / is <
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                       '*', '*', '*',  '*', '*',
                            '*', '*',  '*'
    );

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       CW_TOGG,    KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,    KC_QUOT,    KC_F,    KC_O,    KC_U,    KC_J, KC_SCLN,
       KC_LCTL,   SYM_N,    LA_R,    LG_T,    LS_S,    KC_G,       KC_Y,    LS_H,    LG_A,    LA_E,   SYM_I, LC_COMM,
       KC_UNDS,    PT_Q,    KC_X,    KC_M,    KC_C,    KC_V,       KC_K,    KC_P,  KC_DOT, KC_MINS, PT_SLSH, XXXXXXX,
                                    MACRO, LW_BSPC,  RS_ENT,     RS_TAB,  LW_SPC,
                                            QWERTY,    TMUX,     KC_ESC
  ),

  [LAYER_QWERTY] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       CW_TOGG,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
       KC_LCTL,   SYM_A,    LA_S,    LG_D,    LS_F,    KC_G,       KC_H,    LS_J,    LG_K,    LA_L,SYM_SCLN, LC_QUOT,
       KC_UNDS,    PT_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, PT_SLSH, KC_RBRC,
                                    MACRO, LW_BSPC,  RS_ENT,     RS_TAB,  LW_SPC,
                                              BASE,    TMUX,     KC_ESC
  ),

  [LAYER_GRAPHITE] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       CW_TOGG,    KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,    KC_QUOT,    KC_F,    KC_O,    KC_U,    KC_J, KC_SCLN,
       KC_LCTL,   SYM_N,    LA_R,    LG_T,    LS_S,    KC_G,       KC_Y,    LS_H,    LG_A,    LA_E,   SYM_I, LC_COMM,
       KC_UNDS,    PT_Q,    KC_X,    KC_M,    KC_C,    KC_V,       KC_K,    KC_P,  KC_DOT, KC_MINS, PT_SLSH, XXXXXXX,
                                    MACRO, LW_BSPC,  RS_ENT,     RS_TAB,  LW_SPC,
                                            QWERTY,    TMUX,     KC_ESC
  ),

  [LAYER_LOWER] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       RU_COMM,    KC_4,    KC_3,    KC_2,    KC_1,    KC_5,       KC_9,    KC_0,    KC_6,    KC_7,    KC_8, RU_COMM,
        RU_DOT, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,  KC_F11,     KC_F12, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL,  RU_DOT,
       KC_UNDS,   KC_F4,   KC_F3,   KC_F2,   KC_F1,   KC_F5,      KC_F9,  KC_F10,   KC_F6,   KC_F7,   KC_F8, KC_UNDS,
                                  XXXXXXX, _______, _______,    _______, _______,
                                           XXXXXXX,    TMUX,    XXXXXXX
  ),

  [LAYER_RAISE] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       KC_MNXT, KC_PGUP, KC_HOME,   KC_UP,  KC_END, KC_VOLU,    DF_QWRT, RU_TOGG, DF_GRPT, XXXXXXX, CG_TOGG, XXXXXXX,
       KC_MPLY, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_MUTE,    XXXXXXX, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, XXXXXXX,
       KC_MPRV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                  _______, _______, XXXXXXX,    _______, XXXXXXX,
                                           _______,    TMUX,    XXXXXXX
  ),

  [LAYER_POINTER] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, XXXXXXX,
       XXXXXXX, _______, DRGSCRL, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, DRGSCRL, _______, XXXXXXX,
                                  KC_BTN2, KC_BTN1, KC_BTN3,    KC_BTN3, KC_BTN1,
                                           XXXXXXX, KC_BTN2,    KC_BTN2
  ),

  [LAYER_SYMBOLS] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX,  KC_GRV,   KC_LT,   KC_GT, KC_DQUO,  KC_DOT,    KC_AMPR, KC_SCLN, KC_LBRC, KC_RBRC, KC_PERC, XXXXXXX,
       XXXXXXX, KC_EXLM, KC_MINS, KC_PLUS,  KC_EQL, KC_HASH,    KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES, XXXXXXX,
       XXXXXXX, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, MC_CDUP,    KC_TILD,  KC_DLR, KC_LCBR, KC_RCBR,   KC_AT, XXXXXXX,
                                  XXXXXXX, KC_BSPC,  KC_ENT,     KC_TAB,  KC_SPC,
                                           XXXXXXX,    TMUX,    XXXXXXX
  ),

  [LAYER_SYMBOLS_RU] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX,  RU_GRV,   RU_LT,   RU_GT,   KC_AT, KC_SLSH,    RU_AMPR,  KC_DLR, RU_LBRC, RU_RBRC, KC_PERC, XXXXXXX,
       XXXXXXX, KC_EXLM, KC_MINS, KC_PLUS,  KC_EQL, KC_HASH,    RU_PIPE, KC_CIRC, KC_LPRN, KC_RPRN, KC_AMPR, XXXXXXX,
       XXXXXXX, RU_CIRC, KC_PIPE, KC_ASTR, KC_BSLS, MC_CDUP,    RU_TILD,  RU_DLR, RU_LCBR, RU_RCBR,   RU_AT, XXXXXXX,
                                  XXXXXXX, KC_BSPC,  KC_ENT,     KC_TAB,  KC_SPC,
                                           XXXXXXX,    TMUX,    XXXXXXX
  ),

  [LAYER_MACRO] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX, MC_LOCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,   WM_TL,    WM_T,   WM_TR, MC_RCRD, XXXXXXX,
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    WM_NDIS,    WM_L,    WM_F,    WM_R, MC_SCRN, XXXXXXX,
       XXXXXXX, MC_UNDO, MC_CUT, MC_COPY, MC_PASTE, MC_REDO,    XXXXXXX,   WM_BL,    WM_B,   WM_BR, XXXXXXX, XXXXXXX,
                                  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,
                                           XXXXXXX, XXXXXXX,    XXXXXXX
  ),
};
// clang-format on
bool is_russian_enabled = false;

void set_russian_layer(void) {
    SEND_STRING(MC_SETRU);
    default_layer_set((layer_state_t)1 << LAYER_QWERTY);
}

void set_english_layer(void) {
    SEND_STRING(MC_SETEN);
    default_layer_set((layer_state_t)1 << LAYER_BASE);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!is_russian_enabled && !process_custom_shift_keys(keycode, record)) { return false; }
    switch (keycode) {
    case RU_TOGG:
        if (!record->event.pressed) {
            if (is_russian_enabled) {
                set_english_layer();
            } else {
                set_russian_layer();
            }
            is_russian_enabled = !is_russian_enabled;
        }
        break;
    case MC_CDUP:
        if (!record->event.pressed) {
            if(is_russian_enabled) {
                SEND_STRING("//|");
            } else {
                SEND_STRING("../");
            }
        }
        break;
    case RU_PIPE:
        if (!record->event.pressed) {
            SEND_STRING(MC_RUEN("|"));
        }
        break;
    case RU_GRV:
        if (!record->event.pressed) {
            SEND_STRING(MC_RUEN("`"));
        }
        break;
    case RU_LT:
        if (!record->event.pressed) {
            SEND_STRING(MC_RUEN("<"));
        }
        break;
    case RU_GT:
        if (!record->event.pressed) {
            SEND_STRING(MC_RUEN(">"));
        }
        break;
    case RU_CIRC:
        if (!record->event.pressed) {
            SEND_STRING(MC_RUEN("^"));
        }
        break;
    case RU_AMPR:
        if (!record->event.pressed) {
            SEND_STRING(MC_RUEN("&"));
        }
        break;
    case RU_LBRC:
        if (!record->event.pressed) {
            SEND_STRING(MC_RUEN("["));
        }
        break;
    case RU_RBRC:
        if (!record->event.pressed) {
            SEND_STRING(MC_RUEN("]"));
        }
        break;
    case RU_TILD:
        if (!record->event.pressed) {
            SEND_STRING(MC_RUEN("~"));
        }
        break;
    case RU_DLR:
        if (!record->event.pressed) {
            SEND_STRING(MC_RUEN("$"));
        }
        break;
    case RU_LCBR:
        if (!record->event.pressed) {
            SEND_STRING(MC_RUEN("{"));
        }
        break;
    case RU_RCBR:
        if (!record->event.pressed) {
            SEND_STRING(MC_RUEN("}"));
        }
        break;
    case RU_AT:
        if (!record->event.pressed) {
            SEND_STRING(MC_RUEN("@"));
        }
        break;
    case RU_DOT:
        if (!record->event.pressed) {
            if (is_russian_enabled) {
                SEND_STRING("/");
            } else {
                SEND_STRING(".");
            }
        }
        break;
    case RU_COMM:
        if (!record->event.pressed) {
            if (is_russian_enabled) {
                SEND_STRING("?");
            } else {
                SEND_STRING(",");
            }
        }
        break;
    }
    return true;
}
