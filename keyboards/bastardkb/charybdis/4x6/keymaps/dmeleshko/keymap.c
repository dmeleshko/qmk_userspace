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

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_QWERTY,
    LAYER_GRAPHITE,
    LAYER_POINTER,
    LAYER_NUMBERS,
    LAYER_NAVIGATION,
    LAYER_SYMBOLS,
    LAYER_SYMBOLS_RU,
    LAYER_EXTRA
};

#define PT_MINS LT(LAYER_POINTER, KC_MINS)
#define PT_QUOT LT(LAYER_POINTER, KC_QUOT)
#define QWERTY MO(LAYER_QWERTY)
#define BASE MO(LAYER_GRAPHITE)
#define POINTER MO(LAYER_POINTER)
#define EXTRA MO(LAYER_EXTRA)

#define DF_GRPT DF(LAYER_BASE)
#define DF_QWRT DF(LAYER_QWERTY)

#define SYM_N LT(LAYER_SYMBOLS, KC_N)
#define SYM_I LT(LAYER_SYMBOLS, KC_I)
#define SYM_A LT(LAYER_SYMBOLS_RU, KC_A)
#define SYM_SCLN LT(LAYER_SYMBOLS_RU, KC_SCLN)

#define NUM_H LT(LAYER_NUMBERS, KC_H)
#define NUM_J LT(LAYER_NUMBERS, KC_J)

#define NAV_S LT(LAYER_NAVIGATION, KC_S)
#define NAV_F LT(LAYER_NAVIGATION, KC_F)

#define LC_Q LCTL_T(KC_Q)
#define LC_SLSH LCTL_T(KC_SLSH)
#define LC_Z LCTL_T(KC_Z)

#define LA_R LALT_T(KC_R)
#define LA_E LALT_T(KC_E)
#define LA_S LALT_T(KC_S)
#define LA_L LALT_T(KC_L)

#define LG_P LGUI_T(KC_P)
#define LG_C LGUI_T(KC_C)
#define LG_M LGUI_T(KC_M)
#define LG_V LGUI_T(KC_V)

#define LS_A LSFT_T(KC_A)
#define LS_T LSFT_T(KC_T)
#define LS_D LSFT_T(KC_D)
#define LS_K LSFT_T(KC_K)

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
#define MC_RFSH G(KC_R)

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
       CW_TOGG,    KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,    KC_QUOT,    KC_F,    KC_O,    KC_U,    KC_J, KC_DQUO,
       POINTER,   SYM_N,    LA_R,    LS_T,   NAV_S,    KC_G,       KC_Y,   NUM_H,    LS_A,    LA_E,   SYM_I, PT_MINS,
         EXTRA,    LC_Q,    KC_X,    KC_M,    LG_C,    KC_V,       KC_K,    LG_P,  KC_DOT, KC_COMM, LC_SLSH,   EXTRA,
                                  KC_LSFT, KC_BSPC,  KC_ENT,     KC_TAB,  KC_SPC,
                                            QWERTY, XXXXXXX,     KC_ESC
  ),

  [LAYER_QWERTY] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       CW_TOGG,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
       POINTER,   SYM_A,    LA_S,    LS_D,   NAV_F,    KC_G,       KC_H,   NUM_J,    LS_K,    LA_L,SYM_SCLN, PT_QUOT,
         EXTRA,    LC_Z,    KC_X,    KC_C,    LG_V,    KC_B,       KC_N,    LG_M, KC_COMM,  KC_DOT, LC_SLSH, KC_RBRC,
                                  KC_LSFT, KC_BSPC,  KC_ENT,     KC_TAB,  KC_SPC,
                                              BASE, XXXXXXX,     KC_ESC
  ),

  [LAYER_GRAPHITE] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       CW_TOGG,    KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,    KC_QUOT,    KC_F,    KC_O,    KC_U,    KC_J, KC_DQUO,
       POINTER,   SYM_N,    LA_R,    LS_T,   NAV_S,    KC_G,       KC_Y,   NUM_H,    LS_A,    LA_E,   SYM_I, PT_MINS,
         EXTRA,    LC_Q,    KC_X,    KC_M,    LG_C,    KC_V,       KC_K,    LG_P,  KC_DOT, KC_COMM, LC_SLSH,   EXTRA,
                                  KC_LSFT, KC_BSPC,  KC_ENT,     KC_TAB,  KC_SPC,
                                            QWERTY, XXXXXXX,     KC_ESC
  ),

  [LAYER_NUMBERS] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX, XXXXXXX,    KC_9,    KC_8,    KC_7, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX,  RU_DOT,    KC_3,    KC_2,    KC_1,    KC_0,    XXXXXXX, XXXXXXX, KC_RSFT, KC_RALT, KC_RCTL, XXXXXXX,
       XXXXXXX, KC_COMM,    KC_6,    KC_5,    KC_4, XXXXXXX,    XXXXXXX, KC_RGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                  XXXXXXX, _______, XXXXXXX,    _______, _______,
                                           XXXXXXX, XXXXXXX,    QK_LLCK
  ),

  [LAYER_NAVIGATION] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX, MC_RFSH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_PGUP, KC_HOME,   KC_UP,  KC_END, KC_VOLU, KC_MNXT,
       XXXXXXX, XXXXXXX, KC_LALT, KC_LSFT, XXXXXXX, XXXXXXX,    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_MPRV,
       XXXXXXX, KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MPLY,
                                  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,
                                           XXXXXXX, XXXXXXX,    QK_LLCK
  ),

  [LAYER_POINTER] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, XXXXXXX,
       DRGSCRL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DRGSCRL,
                                  KC_BTN2, KC_BTN1, KC_BTN3,    KC_BTN3, KC_BTN1,
                                           XXXXXXX, KC_BTN2,    KC_BTN2
  ),

  [LAYER_SYMBOLS] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX,  KC_GRV,   KC_LT,   KC_GT, KC_DQUO,  KC_DOT,    KC_AMPR, KC_SCLN, KC_LBRC, KC_RBRC, KC_PERC, XXXXXXX,
       XXXXXXX, KC_EXLM, KC_MINS, KC_PLUS,  KC_EQL, KC_HASH,    KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES, XXXXXXX,
       XXXXXXX, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, MC_CDUP,    KC_TILD,  KC_DLR, KC_LCBR, KC_RCBR,   KC_AT, XXXXXXX,
                                  XXXXXXX, KC_BSPC,  KC_ENT,     KC_TAB,  KC_SPC,
                                           XXXXXXX, XXXXXXX,    QK_LLCK
  ),

  [LAYER_SYMBOLS_RU] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX,  RU_GRV,   RU_LT,   RU_GT,   KC_AT, KC_SLSH,    RU_AMPR,  KC_DLR, RU_LBRC, RU_RBRC, KC_PERC, XXXXXXX,
       XXXXXXX, KC_EXLM, KC_MINS, KC_PLUS,  KC_EQL, KC_HASH,    RU_PIPE, KC_CIRC, KC_LPRN, KC_RPRN, KC_AMPR, XXXXXXX,
       XXXXXXX, RU_CIRC, KC_PIPE, KC_ASTR, KC_BSLS, MC_CDUP,    RU_TILD,  RU_DLR, RU_LCBR, RU_RCBR,   RU_AT, XXXXXXX,
                                  XXXXXXX, KC_BSPC,  KC_ENT,     KC_TAB,  KC_SPC,
                                           XXXXXXX, XXXXXXX,    QK_LLCK
  ),

  [LAYER_EXTRA] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX, MC_LOCK, XXXXXXX, XXXXXXX, XXXXXXX, MC_RCRD,    DF_QWRT, RU_TOGG, DF_GRPT, XXXXXXX, CG_TOGG, XXXXXXX,
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MC_SCRN,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX, XXXXXXX,MC_PASTE, XXXXXXX, MC_COPY,  MC_CUT,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,
                                           XXXXXXX, XXXXXXX,    QK_LLCK
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

const uint16_t PROGMEM semicolon_combo[] = {KC_DOT, KC_COMM, COMBO_END};
combo_t key_combos[] = {
    COMBO(semicolon_combo, KC_SCLN),
};
