#include <avr/io.h>
#include <util/delay.h>

#include "matrix.h"

// debounce time in milliseconds
#ifdef DEBOUNCE_ENABLED
#define DEBOUNCE_AMOUNT 2
#endif

static void         init_cols(void);
static matrix_row_t read_cols(void);
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
  unselect_rows();
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
    _delay_ms(5);
    matrix_row_t row = read_cols();
    unselect_rows();
    _delay_ms(5);

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

/* Column pin configuration
 * pins (sorted): PB4 PB6 PF7 PF6 PF5 PF4 PF1
 */
static void init_cols(void) {
  // Input with pull-up(DDR:0, PORT:1)
  DDRB  &= ~(1<<DDB4 | 1<<DDB6);
  PORTB |=  (1<<PB4  | 1<<PB6);
  DDRF  &= ~(1<<DDF7 | 1<<DDF6 | 1<<DDF5 | 1<<DDF4 | 1<<DDF1);
  PORTF |=  (1<<PF7  | 1<<PF6  | 1<<PF5  | 1<<PF4  | 1<<PF1);
}

static matrix_row_t read_cols(void) {
  return
    (PINB&(1<<PINB4) ? 0 : (1<<0)) |
    (PINB&(1<<PINB6) ? 0 : (1<<1)) |
    (PINF&(1<<PINF7) ? 0 : (1<<2)) |
    (PINF&(1<<PINF6) ? 0 : (1<<3)) |
    (PINF&(1<<PINF5) ? 0 : (1<<4)) |
    (PINF&(1<<PINF4) ? 0 : (1<<5)) |
    (PINF&(1<<PINF1) ? 0 : (1<<6));
}

/* Row pin configuration
 * row: 0   1   2   3   4
 * pin: PD4 PD6 PD7 PB5 PF0
 */
static void select_row(uint8_t row) {
  // Output low(DDR:1, PORT:0) to select
  switch (row) {
    case 0:
      DDRD  |= (1<<4);
      PORTD &= ~(1<<4);
      break;
    case 1:
      DDRD  |= (1<<6);
      PORTD &= ~(1<<6);
      break;
    case 2:
      DDRD  |= (1<<7);
      PORTD &= ~(1<<7);
      break;
    case 3:
      DDRB  |= (1<<5);
      PORTB &= ~(1<<5);
      break;
    case 4:
      DDRF  |= (1<<0);
      PORTF &= ~(1<<0);
      break;
  }
}

static void unselect_rows(void) {
  // Hi-Z (DDR:0, PORT:0) to unselect
  DDRD  &= ~0b11010000;
  PORTD &= ~0b11010000;
  DDRB  &= ~0b00100000;
  PORTB &= ~0b00100000;
  DDRF  &= ~0b00000001;
  PORTF &= ~0b00000001;
}
