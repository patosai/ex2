#include <avr/io.h>
#include <util/delay.h>

#include "matrix.h"

#ifdef KEYBOARD_LEFT
#include "matrix_left.h"
#else
#include "matrix_right.h"
#endif

// debounce time in milliseconds
#ifdef DEBOUNCE_ENABLED
#define DEBOUNCE_AMOUNT 2
#endif

static void         init_cols(void);
static matrix_row_t read_cols(void);
static void         init_rows(void);
static void         select_row(uint8_t row);
static void         unselect_rows(void);

/*
 * 1: pressed
 * 0: unpressed
 */
static matrix_row_t matrix_state[MATRIX_ROWS];

#ifdef DEBOUNCE_ENABLED
static matrix_row_t matrix_debounced_state[MATRIX_ROWS];
static uint8_t matrix_debounce_counter;
#endif

void matrix_initialize(void) {
  init_rows();
  init_cols();

  uint8_t i;
  for (i = 0; i < MATRIX_ROWS; ++i) {
    matrix_state[i] = 0;
#ifdef DEBOUNCE_ENABLED
    matrix_debounced_state[i] = 0;
    matrix_debounce_counter = DEBOUNCE_AMOUNT;
#endif
  }
}

matrix_row_t matrix_get_row(uint8_t row_num) {
#ifdef DEBOUNCE_ENABLED
  return matrix_debounced_state[row_num];
#else
  return matrix_state[row_num];
#endif
}

bool matrix_switch_pressed_at(uint8_t row_num, uint8_t col_num) {
  return matrix_get_row(row_num) & (1 << col_num);
}

void matrix_scan(void) {
  uint8_t i;

  for (i = 0; i < MATRIX_ROWS; ++i) {
    select_row(i);
    _delay_ms(1);
    matrix_row_t row = read_cols();
    unselect_rows();

#ifdef DEBOUNCE_ENABLED
    if (matrix_state[i] != row) {
      matrix_debounce_counter = DEBOUNCE_AMOUNT;
    }
#endif

    matrix_state[i] = row;
  }

#ifdef DEBOUNCE_ENABLED
  if (matrix_debounce_counter) {
    --matrix_debounce_counter;
  } else {
    for (i = 0; i < MATRIX_ROWS; ++i) {
      matrix_debounced_state[i] = matrix_state[i];
    }
  }
#endif
}

static void init_cols(void) {
  // Input with pull-up (DDR:0, PORT:1)
  COL1_DDR_REG &= ~(1<<COL1_DDR_PIN);
  COL1_PORT    |=  (1<<COL1_PORT_PIN);

  COL2_DDR_REG &= ~(1<<COL2_DDR_PIN);
  COL2_PORT    |=  (1<<COL2_PORT_PIN);

  COL3_DDR_REG &= ~(1<<COL3_DDR_PIN);
  COL3_PORT    |=  (1<<COL3_PORT_PIN);

  COL4_DDR_REG &= ~(1<<COL4_DDR_PIN);
  COL4_PORT    |=  (1<<COL4_PORT_PIN);

  COL5_DDR_REG &= ~(1<<COL5_DDR_PIN);
  COL5_PORT    |=  (1<<COL5_PORT_PIN);

  COL6_DDR_REG &= ~(1<<COL6_DDR_PIN);
  COL6_PORT    |=  (1<<COL6_PORT_PIN);

  COL7_DDR_REG &= ~(1<<COL7_DDR_PIN);
  COL7_PORT    |=  (1<<COL7_PORT_PIN);
}

static matrix_row_t read_cols(void) {
  return
    (COL1_PIN&(1<<COL1_PIN_PIN) ? 0 : (1<<0)) |
    (COL2_PIN&(1<<COL2_PIN_PIN) ? 0 : (1<<1)) |
    (COL3_PIN&(1<<COL3_PIN_PIN) ? 0 : (1<<2)) |
    (COL4_PIN&(1<<COL4_PIN_PIN) ? 0 : (1<<3)) |
    (COL5_PIN&(1<<COL5_PIN_PIN) ? 0 : (1<<4)) |
    (COL6_PIN&(1<<COL6_PIN_PIN) ? 0 : (1<<5)) |
    (COL7_PIN&(1<<COL7_PIN_PIN) ? 0 : (1<<6));
}

static void select_row(uint8_t row) {
  // Output low (DDR:1, PORT:0) to select
  switch (row) {
    case 0:
      ROW1_DDR_REG |=  (1<<ROW1_DDR_PIN);
      ROW1_PORT    &= ~(1<<ROW1_PORT_PIN);
      break;
    case 1:
      ROW2_DDR_REG |=  (1<<ROW2_DDR_PIN);
      ROW2_PORT    &= ~(1<<ROW2_PORT_PIN);
      break;
    case 2:
      ROW3_DDR_REG |=  (1<<ROW3_DDR_PIN);
      ROW3_PORT    &= ~(1<<ROW3_PORT_PIN);
      break;
    case 3:
      ROW4_DDR_REG |=  (1<<ROW4_DDR_PIN);
      ROW4_PORT    &= ~(1<<ROW4_PORT_PIN);
      break;
    case 4:
      ROW5_DDR_REG |=  (1<<ROW5_DDR_PIN);
      ROW5_PORT    &= ~(1<<ROW5_PORT_PIN);
      break;
  }
}

static void init_rows(void) {
  // High-Z (DDR:0, PORT:0) to unselect
  ROW1_DDR_REG &= ~(1<<ROW1_DDR_PIN);
  ROW1_PORT    &= ~(1<<ROW1_PORT_PIN);

  ROW2_DDR_REG &= ~(1<<ROW2_DDR_PIN);
  ROW2_PORT    &= ~(1<<ROW2_PORT_PIN);

  ROW3_DDR_REG &= ~(1<<ROW3_DDR_PIN);
  ROW3_PORT    &= ~(1<<ROW3_PORT_PIN);

  ROW4_DDR_REG &= ~(1<<ROW4_DDR_PIN);
  ROW4_PORT    &= ~(1<<ROW4_PORT_PIN);

  ROW5_DDR_REG &= ~(1<<ROW5_DDR_PIN);
  ROW5_PORT    &= ~(1<<ROW5_PORT_PIN);
}

static void unselect_rows(void) {
  init_rows();
}
