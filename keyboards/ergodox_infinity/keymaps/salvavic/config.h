#pragma once

// place overrides here
// #define UNICODE_SELECTED_MODES UC_LNX, UC_OSX, UC_WIN, UC_WINC
// #define UNICODE_SELECTED_MODES UC_LNX
// #define UNICODE_KEY_LNX LCTL(LSFT(KC_U))
#undef TAPPING_TERM
// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 175
// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT
// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// #undef TAPPING_TOGGLE
// #define TAPPING_TOGGLE 1

#define EE_HANDS

