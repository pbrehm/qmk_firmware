#include "matrix.h"
#include "rgblight.h"
#include "quantum.h"

#define COL_SHIFTER ((uint16_t)1)

static bool colABpressed = false;
static bool encoderPressed = false;
static uint16_t turns = 0;
static bool last_turn_clockwise;

void clicked(void) {
    tap_code(KC_MPLY);
}

void turned(bool clockwise) {
    if (clockwise != last_turn_clockwise) {
        // Switched way, reset counter
        last_turn_clockwise = clockwise;
        turns = 0;
    }
    turns++;
    if (!(turns%ENCODER_RESOLUTION == 0)) {
        return;
    }

    // if (IS_LAYER_ON(4)) {
    //     // clockwise ? rgb_matrix_decrease() : rgb_matrix_increase();
    // } else if (IS_LAYER_ON(3)) {
    //     tap_code(clockwise ? KC_VOLU : KC_VOLD);
    // } else if (IS_LAYER_ON(2)) {
    //     tap_code16(clockwise ? LCTL(KC_TAB) : LCTL(LSFT(KC_TAB)));
    // } else if (IS_LAYER_ON(1)) {
    //     tap_code(clockwise ? KC_PGDN : KC_PGUP);
    // } else {
    //     tap_code(clockwise ? KC_WH_D : KC_WH_U);
    // }
    tap_code16(clockwise ? KC_VOLU : KC_VOLD);
}

void blank_column(matrix_row_t current_matrix[], uint8_t col) {
    uint16_t column_index_bitmask = COL_SHIFTER << col;
    for (uint8_t row_index = 0; row_index < MATRIX_ROWS-1; row_index++) {
        current_matrix[row_index] &= ~column_index_bitmask;
    }
}

bool is_entire_column_held(matrix_row_t current_matrix[], uint8_t col) {
    uint16_t column_index_bitmask = COL_SHIFTER << col;
    for (uint8_t row_index = 0; row_index < MATRIX_ROWS-1; row_index++) {
        if (!(current_matrix[row_index] & column_index_bitmask)) return false;
    }
    return true;
}

// Because of a bug in the routing of the cheapino, encoder action
// triggers entire columns... fix it in software here, assumption is that
// you never press an entire column, sounds safe?
void fix_encoder_action(matrix_row_t current_matrix[]) {

    // 7th column means encoder was pressed
    if (is_entire_column_held(current_matrix, 7)) {
        encoderPressed = true;
        blank_column(current_matrix, 7);
        current_matrix[3] |= COL_SHIFTER;
    } else {
        current_matrix[3] &= ~COL_SHIFTER;
        // Only trigger click on release
        if (encoderPressed) {
            encoderPressed = false;
            clicked();
        }
    }

    // Now check rotary action:
    bool colA = is_entire_column_held(current_matrix, 9);
    bool colB = is_entire_column_held(current_matrix, 11);

    if (colA && colB) {
        colABpressed = true;
        blank_column(current_matrix, 9);
        blank_column(current_matrix, 11);
    } else if (colA) {
        if (colABpressed) {
            colABpressed = false;
            turned(true);
        }
        blank_column(current_matrix, 9);
    } else if (colB) {
        if (colABpressed) {
            colABpressed = false;
            turned(false);
        }
        blank_column(current_matrix, 11);
    }
}
