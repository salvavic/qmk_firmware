#include QMK_KEYBOARD_H
#include "version.h"
#include "layers.h"
#include "keymap_spanish.h"

#define TAPPING_TOGGLE 2

#define _QWERTY 0 // default QWERTY base layer
#define _FN 1     // Capa Funciones
#define _MOUSE 2  // Capa RATON

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
    COLEMAK,
    QWERTY,
    ES_LSPO,
    ES_RSPC
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* BASE LAYER (QWERTY)
     *
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │  ESC │  1 │  2 │  3 │  4 │  5 │HOME│              │END │  6 │  7 │  8 │  9 │  0 │  '   │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │  TAB │  Q │  W │  E │  R │  T │PGUP│              │PGDO│  Y │  U │  I │  O │  P │  `   │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │ CAPS │  A │  S │  D │  F │  G ├────┤              ├────┤  H │  J │  K │  L │  Ñ │  ´   │
     * ├──────┼────┼────┼────┼────┼────┤TT 1│              │TT 1├────┼────┼────┼────┼────┼──────┤
     * │MAYUS │  Z │  X │  C │  V │  B │    │              │    │  N │  M │  , │  . │ -  │MAYUS │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │LCtl│LAlt│LGUI│ º  │ <> │                                  │Left│Down│ Up │Rght│TT 2│
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │    │TT 2│    │RAlt│RCtl│
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │Home│    │INS │    │    │
     *                            │BACK│ Del├────┤    ├────┤Entr│ [] │
     *                            │    │    │ End│    │MENU│    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */
    [_QWERTY] = LAYOUT_ergodox(  // QWERTY persistent layer
        // left hand
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5,    KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,    KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,      KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,    TT(_FN),
        KC_LCTL, KC_LALT, KC_LGUI, ES_MORD,  ES_LABK,
                                            _______, TT(_MOUSE),
                                                       KC_HOME,
                                   KC_BSPC, KC_DEL,    KC_END,
        // right hand
        KC_END, KC_6,     KC_7,    KC_8,     KC_9,    KC_0,      ES_QUOT,
        KC_PGDN, KC_Y,     KC_U,    KC_I,     KC_O,    KC_P,     KC_LBRC,
                 KC_H,     KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
        TT(_FN), KC_N,     KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
                           KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, TT(_MOUSE),
        KC_RALT, KC_RCTRL,
        KC_INS,
        KC_APP, KC_ENT,   KC_SPC),

    /* FUNCTION LAYER: Function keys and interaction
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │PrtScr│ F1 │ F2 │ F3 │ F4 │ F5 │    │              │ F6 │ F7 │ F8 │ F9 │ F10│ F11│  F12 │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │CapPat│  ( │  ) │ [  │  ] │    │TT 2│              │TT 2│    │    │    │ScUp│ScRt│      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │   ;  │  { │  } │    │C V │C C ├────┤              ├────┤    │Left│Down│ Up │Rght│      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │  ¿   │  ? │  ¡ │ !  │    │C X │    │              │    │    │Home│PgDn│PgUp│ End│      │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │    │    │    │    │    │                                  │LOff│LED-│LED+│ LOn│    │
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │WbBk│WbFd│    │Prev│Next│
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │TabL│    │Vol+│    │    │
     *                            │    │    ├────┤    ├────┤Mute│Play│
     *                            │    │    │TabR│    │Vol-│    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */
    [_FN] = LAYOUT_ergodox(
        // left hand
        KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
        SGUI(KC_S), ES_LPRN, ES_RPRN, ES_LBRC, ES_RBRC, _______, TT(_MOUSE),
        ES_SCLN, ES_LCBR, ES_RCBR, _______, LCTL(KC_V), LCTL(KC_C),
        ES_IQUE, ES_QUES, ES_IEXL, ES_EXLM, _______, LCTL(KC_X), _______,
        _______, _______, _______, _______, _______,
                                            KC_WBAK, KC_WFWD,  // Web forward/back
                                                     C(KC_PGUP),
                                   _______, _______, C(KC_PGDN),
        // right hand
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11, KC_F12,
        TT(_MOUSE), _______, _______, _______, KC_WH_U, KC_WH_R,  _______,
                 _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,
        _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______,
                          BL_OFF,  BL_DEC,  BL_INC,  BL_ON,    _______,
        KC_MPRV, KC_MNXT,
        KC_VOLU,
        KC_VOLD, KC_MUTE, KC_MPLY),

    /* MOUSE: Ratón
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │ FLASH│    │    │    │    │    │    │              │    │    │    │    │    │    │FLASH │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │      │    │ RA │    │    │    │    │              │    │    │    │    │ScUp│ScRt│      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │ RL │ RB │ RR │    │    ├────┤              ├────┤    │ B1 │ B2 │ B3 │    │      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │    │    │    │              │    │    │    │    │    │    │      │
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
    [_MOUSE] = LAYOUT_ergodox(
        // left hand
        RESET,   _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MS_UP,    _______,  _______, _______, _______,
        _______, KC_MS_LEFT, KC_MS_DOWN,    KC_MS_RIGHT,  _______, _______,
        _______, _______, _______,    _______,  _______, _______, _______,
        _______, _______, _______,    _______,  _______,
                                                _______, _______,
                                                         _______,
                                      _______,  _______, _______,
        // right hand
        _______, _______,  _______, _______, _______, _______, RESET,
        _______, _______, _______, _______,  KC_WH_U, KC_WH_R, _______,
                 _______, KC_MS_BTN1, KC_MS_BTN2,  KC_MS_BTN3, _______, _______,
        _______, _______, _______, _______,   _______,  _______,  _______,
                          _______, _______,  _______, _______,   _______,
        _______, _______,
        _______,
        _______, _______, _______),

};

//     /* MOUSE: Ratón
//      * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
//      * │ FLASH│    │    │    │    │    │    │              │    │    │    │    │    │    │FLASH │
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
//         RESET,   _______, _______, _______, _______, _______, _______,
//         _______, _______, _______,    _______,  _______, _______, _______,
//         _______, _______, _______,    _______,  _______, _______,
//         _______, _______, _______,    _______,  _______, _______, _______,
//         _______, _______, _______,    _______,  _______,
//                                                 _______, _______,
//                                                          _______,
//                                       _______,  _______, _______,
//         // right hand
//         _______, _______,  _______, _______, _______, _______, RESET,
//         _______, _______, _______, _______,  _______, _______, _______,
//                  _______, _______, _______,  _______, _______, _______,
//         _______, _______, _______, _______,   _______,  _______,  _______,
//                           _______, _______,  _______, _______,   _______,
//         _______, _______,
//         _______,
//         _______, _______, _______),

// };

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
        // case COLEMAK:
        //     if (record->event.pressed) {
        //         set_single_persistent_default_layer(_COLEMAK);
        //     }
        //     return false;
        //     break;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
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

// BLANK LAYER

// ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
// │      │    │    │    │    │    │    │              │    │    │    │    │    │    │      │
// ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
// │      │    │    │    │    │    │    │              │    │    │    │    │    │    │      │
// ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
// │      │    │    │    │    │    ├────┤              ├────┤    │    │    │    │    │      │
// ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
// │      │    │    │    │    │    │    │              │    │    │    │    │    │    │      │
// └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
//   │    │    │    │    │    │                                  │    │    │    │    │    │
//   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
//                                 │    │    │    │    │    │
//                            ┌────┼────┼────┤    ├────┼────┼────┐
//                            │    │    │    │    │    │    │    │
//                            │    │    ├────┤    ├────┤    │    │
//                            │    │    │    │    │    │    │    │
//                            └────┴────┴────┘    └────┴────┴────┘
