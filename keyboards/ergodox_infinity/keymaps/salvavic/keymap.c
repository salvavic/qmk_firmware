#include QMK_KEYBOARD_H
#include "version.h"
#include "layers.h"
#include "keymap_spanish.h"

#define _QWERTY     0  // default QWERTY base layer
#define _FN         1  // Capa Funciones
#define _SIMBOLOS   2  // Capa SIMBOLOS
#define _MOUSE      3  // Capa RATON

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
    /* BASE (QWERTY)
     *
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │ ESC  │  1 │  2 │  3 │  4 │  5 │ ESC│              │ESC │  6 │  7 │  8 │  9 │  0 │  '   │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │  ESC │  Q │  W │  E │  R │  T │MOUS│              │MOUS│  Y │  U │  I │  O │  P │  `   │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │ TAB  │  A │  S │  D │  F │  G ├────┤              ├────┤  H │  J │  K │  L │  Ñ │  ´   │
     * ├──────┼────┼────┼────┼────┼────┤  º │              │INS ├────┼────┼────┼────┼────┼──────┤
     * │MAYUS │  Z │  X │  C │  V │  B │    │              │    │  N │  M │  , │  . │  - │MAYUS │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │LCtl│LGUI|LAlt│ FN │SIMB│                                  │  ← │  → │  ↑ │  ↓ │SIMB│
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │BACK│ INS│    │RAlt│RCtl│
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │Home│    │    │    │    │
     *                            │BACK│ Del├────┤    ├────┤Entr│ [] │
     *                            │    │    │ End│    │MENU│    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */
    [_QWERTY] = LAYOUT_ergodox(  // QWERTY persistent layer
        // left hand
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5,    KC_ESC,
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,    TT(_MOUSE),
        KC_TAB, KC_A,    KC_S,    KC_D,    KC_F,      KC_G,
        LSFT_T(KC_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,    ES_MORD,
        KC_LCTL, KC_LGUI, KC_LALT, TT(_FN),  TT(_SIMBOLOS),
                                            KC_BSPC, KC_INS,
                                                       KC_HOME,
                                   KC_BSPC, KC_DEL,    KC_END,
        // right hand
        KC_ESC, KC_6,     KC_7,    KC_8,     KC_9,    KC_0,      ES_QUOT,
        TT(_MOUSE), KC_Y,     KC_U,    KC_I,     KC_O,    KC_P,     KC_LBRC,
                 KC_H,     KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
        KC_INS, KC_N,     KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  RSFT_T(KC_CAPS),
                           KC_LEFT, KC_RIGHT,  KC_UP,   KC_DOWN, TT(_SIMBOLOS),
        KC_RALT, KC_RCTRL,
        KC_INS,
        KC_APP, KC_ENT,   KC_SPC),

    /* FUNCTION LAYER: Function keys and interaction
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │PrtScr│ F1 │ F2 │ F3 │ F4 │ F5 │    │              │    │ F6 │ F7 │ F8 │ F9 │ F11│  F11 │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │CapPat│    │    │    │    │    │    │              │    │    │    │    │ScUp│ScRt│  F12 │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │C V │C C ├────┤              ├────┤    │Left│Down│ Up │Rght│      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │    │C X │    │              │    │    │Home│PgDn│PgUp│ End│      │
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
    [_FN] = LAYOUT_ergodox(
        // left hand
        KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
        SGUI(KC_S), _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, LCTL(KC_V), LCTL(KC_C),
        _______, _______, _______, _______, _______, LCTL(KC_X), _______,
        _______, _______, _______, _______, _______,
                                            KC_WBAK, KC_WFWD,  // Web forward/back
                                                     _______,
                                   _______, _______, _______,
        // right hand
        _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,
        _______, _______, _______, _______, KC_WH_U, KC_WH_R,  KC_F12,
                 _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,
        _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______,
                          _______,  _______,  _______,  _______,    _______,
        KC_MPRV, KC_MNXT,
        KC_VOLU,
        KC_VOLD, KC_MUTE, KC_MPLY),

/* SIMBOLOS : Simbolos
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │   ;  │  ( │  ) │  [ │ ]  │    │    │              │    │    │ BN │  / │  * │  - │ HOME │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │   *  │ {  │  } │  @ │ #  │    │    │              │    │    │  7 │  8 │  9 │  + │  END │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │   +  │ &  │  | │  / │ \  │    ├────┤              ├────┤    │  4 │  5 │  6 │  - │ PGUP │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │  ¿   │  ? │  ¡ │ !  │    │    │    │              │    │    │  1 │  2 │  3 │  = │ PGDW │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │ <  │ >  │    │    │    │                                  │  0 │  . │Entr│    │    │
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
        ES_SCLN, ES_LPRN,   ES_RPRN,   ES_LBRC,   ES_RBRC,   _______,   _______,
        ES_ASTR, ES_LCBR, ES_RCBR, ES_AT, ES_HASH, _______, _______,
        ES_PLUS, ES_AMPR, ES_PIPE, ES_SLSH, ES_BSLS, _______,
        ES_IQUE, ES_QUES, ES_IEXL, ES_EXLM, _______, _______, _______,
        ES_LABK, ES_RABK, _______, _______, _______,
                                            _______, _______,
                                                     _______,
                                   _______, _______, _______,
        // right hand
        _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_KP_MINUS, KC_HOME,
        _______, _______, KC_P7, KC_P8, KC_P9, KC_KP_PLUS,  KC_END,
                 _______, KC_P4, KC_P5, KC_P6, KC_KP_MINUS, KC_PGUP,
        _______, _______, KC_P1, KC_P2, KC_P3, KC_KP_EQUAL, KC_PGDN,
                          KC_P0, KC_KP_DOT, KC_PENT,  _______,    _______,
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
     *                                 │    │    │    │    │    │
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │    │    │    │    │    │
     *                            │    │    ├────┤    ├────┤    │    │
     *                            │    │    │    │    │    │    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */
    [_MOUSE] = LAYOUT_ergodox(
        // left hand
        RESET,   _______    , _______   , _______       , _______, _______, _______,
        _______, _______    , KC_MS_UP  , _______       ,  _______, KC_MS_ACCEL0, _______,
        _______, KC_MS_LEFT , KC_MS_DOWN, KC_MS_RIGHT   ,  _______, KC_MS_ACCEL1,
        _______, KC_WH_U    , KC_WH_D   , _______       ,  _______, KC_MS_ACCEL2, _______,
        _______, _______    , _______   , _______       ,  _______,
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
