#include QMK_KEYBOARD_H
#include "version.h"
#include "layers.h"
#include "keymap_spanish.h"

#define _QWERTY     0  // default QWERTY base layer
#define _COLEMAK    1  // default QWERTY base layer
#define _FN         2  // Capa Funciones
#define _SIMBOLOS   3  // Capa SIMBOLOS
#define _MOUSE      4  // Capa RATON
#define _NUMERICO   5  // Capa Teclado Numerico

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)


// Macros y combos:
#define M_CF4 LCTL(KC_F4)
#define M_WE G(KC_E)

// #define ES_MORD KC_GRV  // º
// #define ES_QUOT KC_MINS // '
// #define ES_IEXL KC_EQL  // ¡
// #define ES_GRV  KC_LBRC // ` (dead)
// #define ES_PLUS KC_RBRC // +
// #define ES_NTIL KC_SCLN // Ñ
// #define ES_ACUT KC_QUOT // ´ (dead)
// #define ES_CCED KC_NUHS // Ç
// #define ES_LABK KC_NUBS // <
// #define ES_COMM KC_COMM // ,
// #define ES_DOT  KC_DOT  // .
// #define ES_MINS KC_SLSH // -
// #define ES_EXLM S(ES_1)    // !
// #define ES_LPRN S(ES_8)    // (
// #define ES_RPRN S(ES_9)    // )
// #define ES_EQL  S(ES_0)    // =
// #define ES_QUES S(ES_QUOT) // ?
// #define ES_IQUE S(ES_IEXL) // ¿
// #define ES_CIRC S(ES_GRV)  // ^ (dead)
// #define ES_ASTR S(ES_PLUS) // *
// #define ES_RABK S(ES_LABK) // >
// #define ES_SCLN S(KC_COMM) // ;
// #define ES_COLN S(KC_DOT)  // :
// #define ES_UNDS S(ES_MINS) // _
// // Row 1
// #define ES_BSLS ALGR(ES_MORD) // (backslash)
// #define ES_PIPE ALGR(ES_1)    // |
// #define ES_AT   ALGR(ES_2)    // @
// #define ES_HASH ALGR(ES_3)    // #
// #define ES_TILD ALGR(ES_4)    // ~
// #define ES_EURO ALGR(ES_5)    // €
// #define ES_NOT  ALGR(ES_6)    // ¬
// // Row 2
// #define ES_LBRC ALGR(ES_GRV)  // [
// #define ES_RBRC ALGR(ES_PLUS) // ]
// // Row 3
// #define ES_LCBR ALGR(ES_ACUT) // {
// #define ES_RCBR ALGR(ES_CCED) // }
enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,  // can always be here
    EPRM,
    VRSN,
    RGB_SLD,
    QWERTY,
    COLEMAK
};
enum unicode_names {
    // LEFT HAND
    SQUARED, CUBED, PLUSMIN,
    // RIGHT HAND
    DEG, TIMES, ENDASH, EQISH, LEQ, GEQ, DIV, NEQ,
    LEFT, DOWN, UP, RIGHT
};
const uint32_t PROGMEM unicode_map[] = {
    // LEFT HAND
    [SQUARED] = 0x00B2,  // ²
    [CUBED]   = 0x00B3,  // ³
    [PLUSMIN] = 0x00B1,  // ±
    // RIGHT HAND
    [DEG]     = 0x00B0,  // °
    [TIMES]   = 0x00D7,  // ×
    [ENDASH]  = 0x2013,  // –
    [EQISH]   = 0x2248,  // ≈
    [LEQ]     = 0x2264,  // ≤
    [GEQ]     = 0x2265,  // ≥
    [DIV]     = 0x00F7,  // ÷
    [NEQ]     = 0x2260,  // ≠
    [LEFT]  = 0x2190,  // ←
    [DOWN]  = 0x2193,  // ↓
    [UP]    = 0x2191,  // ↑
    [RIGHT] = 0x2192,  // →
};

enum {
    //Teclas de Funcion
    TD_1 = 0,  TD_2, TD_3, TD_4, TD_5, TD_6, TD_7, TD_8, TD_9, TD_10, TD_11, TD_12,
    TD_PC, TD_ALT,
    TD_INT, TD_EXC, TD_ANG, TD_LLA, TD_PAR, TD_PAC
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
  [TD_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
  [TD_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
  [TD_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
  [TD_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5),
  [TD_6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6),
  [TD_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F7),
  [TD_8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F8),
  [TD_9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F9),
  [TD_10] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10),
  [TD_11] = ACTION_TAP_DANCE_DOUBLE(ES_QUOT, KC_F11),
  [TD_12] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_F12),
  [TD_PC] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, S(KC_COMM)),

  [TD_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, KC_LALT),

  [TD_INT] = ACTION_TAP_DANCE_DOUBLE(ES_IQUE, ES_QUES),
  [TD_EXC] = ACTION_TAP_DANCE_DOUBLE(ES_IEXL, ES_EXLM),
  [TD_ANG] = ACTION_TAP_DANCE_DOUBLE(ES_LABK, ES_RABK),
  [TD_LLA] = ACTION_TAP_DANCE_DOUBLE(ES_LCBR, ES_RCBR),
  [TD_PAR] = ACTION_TAP_DANCE_DOUBLE(ES_LPRN, ES_RPRN),
  [TD_PAC] = ACTION_TAP_DANCE_DOUBLE(ES_LBRC, ES_RBRC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* BASE (QWERTY)
     *
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │ ESC  │  1 │  2 │  3 │  4 │  5 │CLMK│              │TNUM│  6 │  7 │  8 │  9 │  0 │  '   │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │ TAB  │  Q │  W │  E │  R │  T │MOUS│              │MOUS│  Y │  U │  I │  O │  P │  `   │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │BLOQM │  A │  S │  D │  F │  G ├────┤              ├────┤  H │  J │  K │  L │  Ñ │  ´   │
     * ├──────┼────┼────┼────┼────┼────┤  º │              │FN  ├────┼────┼────┼────┼────┼──────┤
     * │MAYUS │  Z │  X │  C │  V │  B │    │              │    │  N │  M │  , │  . │  - │MAYUS │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │LCtl│LGUI|LAlt│ FN │SIMB│                                  │SIMB│ FN │    │    │    │
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │Home│ End│    │RAlt│RCtl│
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │PGUP│    │INS │    │    │
     *                            │BACK│ Del├────┤    ├────┤Entr│ [] │
     *                            │    │    │PGDO│    │MENU│    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */
    [_QWERTY] = LAYOUT_ergodox(  // QWERTY persistent layer
        // left hand
        KC_ESC,  TD(TD_1),    TD(TD_2),    TD(TD_3),    TD(TD_4),      TD(TD_5),    DF(_COLEMAK),
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,    TT(_MOUSE),
        KC_CAPS, (KC_A),    (KC_S),    (KC_D),    (KC_F),      KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,    ES_MORD,
        KC_LCTL, LALT_T(KC_LGUI), TT(_NUMERICO), TT(_FN),  TT(_SIMBOLOS),
                                            KC_HOME, KC_END,
                                                       KC_PGUP,
                                   KC_BSPC, KC_DEL,    KC_PGDN,
        // right hand
        TT(_NUMERICO), TD(TD_6), TD(TD_7), TD(TD_8), TD(TD_9),TD(TD_10), TD(TD_11),
        TT(_MOUSE), KC_Y, KC_U, KC_I, KC_O, KC_P, TD(TD_12),
                 KC_H, (KC_J), (KC_K), (KC_L), (KC_SCLN),  KC_QUOT,
        TT(_FN), KC_N, KC_M, TD(TD_PC), KC_DOT,  KC_SLSH,  KC_RSFT,
                            TT(_SIMBOLOS), TT(_FN), TT(_NUMERICO), KC_RALT, KC_RCTRL,
                                    KC_RALT, KC_RCTRL,
        KC_INS,
        KC_APP, KC_ENT,   KC_SPC),

     /* (COLEMAK)
     * https://forum.colemak.com/topic/2519-colemak-para-espanol-latino-win-colemak-for-spanish-la-win/
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │      │  1 │  2 │  3 │  4 │  5 │    │              │    │  6 │  7 │  8 │  9 │  0 │      │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │      │  Q │  W │  F │  P │  G │    │              │    │  J │  L │  U │  Y │  Ñ │      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │  A │  R │  S │  T │  D ├────┤              ├────┤  H │  N │  E │  I │  O │      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │  Z │  X │  C │  V │  B │    │              │    │  K │  M │    │    │    │      │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │    │    │    │    │    │                                  │    │    │    │    │    │
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │    │    │    │    │    │
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │    │    │    │    │    │
     *                            │    │    ├────┤    ├────┤    │    │
     *                            │    │    │    │    │    │    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */
    [_COLEMAK] = LAYOUT_ergodox(  // Colemak persistent layer (default)
        // left hand
        KC_ESC,  TD(TD_1),    TD(TD_2),    TD(TD_3),    TD(TD_4),      TD(TD_5),    DF(_QWERTY),
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,      KC_G, TT(_MOUSE),
        KC_CAPS, KC_A,    KC_R,    KC_S,    KC_T,      KC_D,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B, ES_MORD,
        KC_LCTL, LALT_T(KC_LGUI), TT(_NUMERICO), TT(_FN),  TT(_SIMBOLOS),
                                            KC_HOME, KC_END,
                                                       KC_PGUP,
                                   KC_BSPC, KC_DEL,    KC_PGDN,
        // right hand
        TT(_NUMERICO), TD(TD_6), TD(TD_7), TD(TD_8), TD(TD_9),TD(TD_10), TD(TD_11),
        TT(_MOUSE), KC_J,     KC_L,    KC_U,     KC_Y,    KC_SCLN,  TD(TD_12),
                 KC_H,     KC_N,    KC_E,     KC_I,    KC_O,     KC_QUOT,
        TT(_FN), KC_K,     KC_M,    KC_DOT,  KC_SLSH,  KC_SLSH,  KC_RSFT,
                            TT(_SIMBOLOS), TT(_FN), TT(_NUMERICO), KC_RALT, KC_RCTRL,
        KC_RALT, KC_RCTRL,
        KC_INS,
        KC_APP, KC_ENT,   KC_SPC),

/* SIMBOLOS : Simbolos2
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │      │    │  " │    │    │    │ [  │              │ ]  │    │    │    │    │    │      │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼─-──┼────┼──────┤
     * │      │ [] │  * │  + │  @ │  \ │ {  │              │ }  │    │    │    │    │    │      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │ {} │ () │  / │  & │  | ├────┤              ├────┤    │    │    │    │    │      │
     * ├──────┼────┼────┼────┼────┼────┤ (  │              │ )  ├────┼────┼────┼────┼────┼──────┤
     * │      │ ¿? │ ¡! │ <> │  - │  # │    │              │    │    │    │    │    │    │      │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │    │    │    │    │    │                                  │    │    │    │    │    │
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │    │    │    │    │    │
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │    │    │    │    │    │
     *                            │    │    ├────┤    ├────┤    │    │
     *                            │    │    │    │    │    │    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */

    [_SIMBOLOS] = LAYOUT_ergodox(
        // left hand
        _______, _______,   S(KC_2),   _______,   _______,   _______,   ES_LBRC,
        _______, TD(TD_PAC), ES_ASTR, ES_PLUS, ES_AT, ES_BSLS, ES_LCBR,
        _______, TD(TD_LLA), TD(TD_PAR), ES_SLSH, ES_AMPR, ES_PIPE,
        _______, TD(TD_INT), TD(TD_EXC), TD(TD_ANG), KC_SLSH, ES_HASH, ES_LPRN,
        _______, _______, _______, _______, _______,
                                            _______, _______,
                                                     _______,
                                   _______, _______, _______,
        // right hand
        ES_RBRC, _______, _______, _______, _______, _______, _______,
        ES_RCBR, _______, _______, _______, _______, _______,  _______,
                 _______, _______, _______, _______, _______, _______,
        ES_RPRN, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, _______),

/* Teclado Numérico
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │      │    │    │    │    │    │    │              │    │    │    │  / │  * │  - │ HOME │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │    │    │    │              │    │    │  7 │  8 │  9 │  + │  END │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │    │    ├────┤              ├────┤    │  4 │  5 │  6 │  - │ PGUP │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │    │    │    │              │    │    │  1 │  2 │  3 │  = │ PGDW │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │    │    │    │    │    │                                  │  0 │  . │Entr│    │    │
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │    │    │    │    │    │
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │    │    │    │    │    │
     *                            │    │    ├────┤    ├────┤    │    │
     *                            │    │    │    │    │    │    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */

    [_NUMERICO] = LAYOUT_ergodox(
        // left hand
        _______, _______,   _______,   _______,   _______,   _______,   _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                            _______, _______,
                                                     _______,
                                   _______, _______, _______,
        // right hand
        _______, _______, _______, KC_PSLS, KC_PAST, KC_KP_MINUS, KC_HOME,
        _______, _______, KC_7, KC_8, KC_9, KC_KP_PLUS,  KC_END,
                 _______, KC_4, KC_5, KC_6, KC_KP_MINUS, KC_PGUP,
        _______, _______, KC_1, KC_2, KC_3, KC_KP_EQUAL, KC_PGDN,
                          KC_0, KC_DOT, KC_ENT,  _______,    _______,
        _______, _______,
        _______,
        _______, _______, _______),


    /* FUNCTION LAYER: Function keys and interaction
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │      │ F1 │ F2 │ F3 │ F4 │ F5 │PrtS│              │    │ F6 │ F7 │ F8 │ F9 │ F11│  F11 │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │      │    │    │ GE │CF4 │    │CatP│              │PGUP│    │    │  ↑ │    │    │  F12 │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │C V │C C ├────┤              ├────┤HOME│  ← │  ↓ │  → │ END│      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │PGDW├────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │    │C X │    │              │    │    │    │    │    │    │      │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │    │    │    │    │    │                                  │    │    │    │    │    │
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │    │    │    │    │    │
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │    │    │    │    │    │
     *                            │    │    ├────┤    ├────┤    │    │
     *                            │    │    │    │    │    │    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */
    [_FN] = LAYOUT_ergodox(
        // left hand
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_PSCR,
        XXXXXXX, XXXXXXX, XXXXXXX, M_WE , M_CF4, XXXXXXX, SGUI(KC_S),
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LCTL(KC_V), LCTL(KC_C),
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LCTL(KC_X), XXXXXXX,
        _______, _______, _______, _______, _______,
                                            _______, _______,
                                                     _______,
                                   _______, _______, _______,
        // right hand
        XXXXXXX,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,
        KC_PGUP, XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX,  KC_F12,
                 KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, XXXXXXX,
        KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          _______, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, _______),

    /* MOUSE: Ratón
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │ FLASH│    │    │    │    │    │    │              │    │    │    │    │    │    │FLASH │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │      │    │ RA │    │    │ A0 │    │              │    │    │    │    │ScUp│ScRt│      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │ RL │ RB │ RR │    │ A1 ├────┤              ├────┤    │ B1 │ B2 │ B3 │    │      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │ScUp│ScDt│    │    │ A2 │    │              │    │    │    │    │    │    │      │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │    │    │    │    │    │                                  │    │    │    │    │    │
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │WbBk│WbFd│    │Prev│Next│
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │    │    │Vol+│    │    │
     *                            │    │    ├────┤    ├────┤Mute│Play│
     *                            │    │    │    │    │Vol-│    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */
    [_MOUSE] = LAYOUT_ergodox(
        // left hand
        RESET,   _______    , _______   , _______       , _______, _______, _______,
        _______, _______    , KC_MS_UP  , _______       ,  _______, KC_MS_ACCEL0, _______,
        _______, KC_MS_LEFT , KC_MS_DOWN, KC_MS_RIGHT   ,  _______, KC_MS_ACCEL1,
        _______, KC_WH_U    , KC_WH_D   , KC_MS_BTN1  ,  KC_MS_BTN2, KC_MS_ACCEL2, _______,
        _______, _______    , _______   , _______       ,  _______,
                                            KC_WBAK, KC_WFWD,  // Web forward/back
                                                         _______,
                                      _______,  _______, _______,
        // right hand
        _______, _______,  _______, _______, _______, _______, RESET,
        _______, _______, _______, _______,  KC_WH_U, KC_WH_R, _______,
                 _______, KC_MS_BTN1, KC_MS_BTN2,  KC_MS_BTN3, _______, _______,
        _______, _______, _______, _______,   _______,  _______,  _______,
                          _______, _______,  _______, _______,   _______,
        KC_MPRV, KC_MNXT,
        KC_VOLU,
        KC_VOLD, KC_MUTE, KC_MPLY),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // dynamically generate these.
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
            break;
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
        case RGB_SLD:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                rgblight_mode(1);
            #endif
            }
            return false;
            break;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void){
    // Start in Linux mode for unicode input
    set_unicode_input_mode(UC_LNX);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
            // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
};

//     /* Capa Vacia
//      * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
//      * │      │    │    │    │    │    │    │              │    │    │    │    │    │    │      │
//      * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
//      * │      │    │    │    │    │    │    │              │    │    │    │    │    │    │      │
//      * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
//      * │      │    │    │    │    │    ├────┤              ├────┤    │    │    │    │    │      │
//      * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
//      * │      │    │    │    │    │    │    │              │    │    │    │    │    │    │      │
//      * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
//      *   │    │    │    │    │    │                                  │    │    │    │    │    │
//      *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
//      *                                 │    │    │    │    │    │
//      *                            ┌────┼────┼────┤    ├────┼────┼────┐
//      *                            │    │    │    │    │    │    │    │
//      *                            │    │    ├────┤    ├────┤    │    │
//      *                            │    │    │    │    │    │    │    │
//      *                            └────┴────┴────┘    └────┴────┴────┘
//      */
//     [_MOUSE] = LAYOUT_ergodox(
//         // left hand
//         _______,   _______, _______, _______, _______, _______, _______,
//         _______, _______, _______,    _______,  _______, _______, _______,
//         _______, _______, _______,    _______,  _______, _______,
//         _______, _______, _______,    _______,  _______, _______, _______,
//         _______, _______, _______,    _______,  _______,
//                                                 _______, _______,
//                                                          _______,
//                                       _______,  _______, _______,
//         // right hand
//         _______, _______,  _______, _______, _______, _______, _______,
//         _______, _______, _______, _______,  _______, _______, _______,
//                  _______, _______, _______,  _______, _______, _______,
//         _______, _______, _______, _______,   _______,  _______,  _______,
//                           _______, _______,  _______, _______,   _______,
//         _______, _______,
//         _______,
//         _______, _______, _______),
