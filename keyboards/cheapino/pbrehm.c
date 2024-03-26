#include "quantum.h"

enum combos {
    BSPC_SPACE,
    CTRL_Q,
    CTRL_W,
    CTRL_E,
    CTRL_R,
    CTRL_T,
    CTRL_A,
    CTRL_S,
    CTRL_D,
    CTRL_F,
    CTRL_G,
    CTRL_Z,
    CTRL_X,
    CTRL_C,
    CTRL_V,
    CTRL_B,
};

const uint16_t PROGMEM test_combo[] = {LT(1,KC_SPC), LT(4,KC_BSPC), COMBO_END};
const uint16_t PROGMEM q_combo[] = {LT(3,KC_ESC), KC_Q, COMBO_END};
const uint16_t PROGMEM w_combo[] = {LT(3,KC_ESC), KC_W, COMBO_END};
const uint16_t PROGMEM e_combo[] = {LT(3,KC_ESC), KC_E, COMBO_END};
const uint16_t PROGMEM r_combo[] = {LT(3,KC_ESC), KC_R, COMBO_END};
const uint16_t PROGMEM t_combo[] = {LT(3,KC_ESC), KC_T, COMBO_END};
const uint16_t PROGMEM a_combo[] = {LT(3,KC_ESC), KC_A, COMBO_END};
const uint16_t PROGMEM s_combo[] = {LT(3,KC_ESC), KC_S, COMBO_END};
const uint16_t PROGMEM d_combo[] = {LT(3,KC_ESC), KC_D, COMBO_END};
const uint16_t PROGMEM f_combo[] = {LT(3,KC_ESC), KC_F, COMBO_END};
const uint16_t PROGMEM g_combo[] = {LT(3,KC_ESC), KC_G, COMBO_END};
const uint16_t PROGMEM z_combo[] = {LT(3,KC_ESC), KC_Z, COMBO_END};
const uint16_t PROGMEM x_combo[] = {LT(3,KC_ESC), KC_X, COMBO_END};
const uint16_t PROGMEM c_combo[] = {LT(3,KC_ESC), KC_C, COMBO_END};
const uint16_t PROGMEM v_combo[] = {LT(3,KC_ESC), KC_V, COMBO_END};
const uint16_t PROGMEM b_combo[] = {LT(3,KC_ESC), KC_B, COMBO_END};

combo_t key_combos[] = {
    [BSPC_SPACE] = COMBO(test_combo, LCTL(KC_SPACE)),
    [CTRL_Q] = COMBO(q_combo, LCTL(KC_Q)),
    [CTRL_W] = COMBO(w_combo, LCTL(KC_W)),
    [CTRL_E] = COMBO(e_combo, LCTL(KC_E)),
    [CTRL_R] = COMBO(r_combo, LCTL(KC_R)),
    [CTRL_T] = COMBO(t_combo, LCTL(KC_T)),
    [CTRL_A] = COMBO(a_combo, LCTL(KC_A)),
    [CTRL_S] = COMBO(s_combo, LCTL(KC_S)),
    [CTRL_D] = COMBO(d_combo, LCTL(KC_D)),
    [CTRL_F] = COMBO(f_combo, LCTL(KC_F)),
    [CTRL_G] = COMBO(g_combo, LCTL(KC_G)),
    [CTRL_Z] = COMBO(z_combo, LCTL(KC_Z)),
    [CTRL_X] = COMBO(x_combo, LCTL(KC_X)),
    [CTRL_C] = COMBO(c_combo, LCTL(KC_C)),
    [CTRL_V] = COMBO(v_combo, LCTL(KC_V)),
    [CTRL_B] = COMBO(b_combo, LCTL(KC_B)),
};
