#include "quantum.h"

enum combos {
    BSPC_SPACE
};

const uint16_t PROGMEM test_combo[] = {LT(1,KC_SPC), LT(4,KC_BSPC), COMBO_END};

combo_t key_combos[] = {
    [BSPC_SPACE] = COMBO(test_combo, LCTL(KC_SPACE)),
};
