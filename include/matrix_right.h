#ifndef _MATRIX_RIGHT_H_
#define _MATRIX_RIGHT_H_

#include <avr/io.h>

/* Row pin configuration
 * pins (top to bottom): D4 D6 D7 B5 F0
 */
#define ROW1_DDR_REG  DDRD
#define ROW1_DDR_PIN  DDD4
#define ROW1_PORT     PORTD
#define ROW1_PORT_PIN PD4

#define ROW2_DDR_REG  DDRD
#define ROW2_DDR_PIN  DDD6
#define ROW2_PORT     PORTD
#define ROW2_PORT_PIN PD7

#define ROW3_DDR_REG  DDRD
#define ROW3_DDR_PIN  DDD7
#define ROW3_PORT     PORTD
#define ROW3_PORT_PIN PD7

#define ROW4_DDR_REG  DDRB
#define ROW4_DDR_PIN  DDB5
#define ROW4_PORT     PORTB
#define ROW4_PORT_PIN PB5

#define ROW5_DDR_REG  DDRF
#define ROW5_DDR_PIN  DDF0
#define ROW5_PORT     PORTF
#define ROW5_PORT_PIN PF0

/* Column pin configuration
 * pins (left to right): B4 B6 F7 F6 F5 F4 F1
 */
#define COL1_DDR_REG  DDRB
#define COL1_DDR_PIN  DDB4
#define COL1_PORT     PORTB
#define COL1_PORT_PIN PB4
#define COL1_PIN      PINB
#define COL1_PIN_PIN  PINB4

#define COL2_DDR_REG  DDRB
#define COL2_DDR_PIN  DDB6
#define COL2_PORT     PORTB
#define COL2_PORT_PIN PB6
#define COL2_PIN      PINB
#define COL2_PIN_PIN  PINB6

#define COL3_DDR_REG  DDRF
#define COL3_DDR_PIN  DDF7
#define COL3_PORT     PORTF
#define COL3_PORT_PIN PF7
#define COL3_PIN      PINF
#define COL3_PIN_PIN  PINF7

#define COL4_DDR_REG  DDRF
#define COL4_DDR_PIN  DDF6
#define COL4_PORT     PORTF
#define COL4_PORT_PIN PF6
#define COL4_PIN      PINF
#define COL4_PIN_PIN  PINF6

#define COL5_DDR_REG  DDRF
#define COL5_DDR_PIN  DDF5
#define COL5_PORT     PORTF
#define COL5_PORT_PIN PF5
#define COL5_PIN      PINF
#define COL5_PIN_PIN  PINF5

#define COL6_DDR_REG  DDRF
#define COL6_DDR_PIN  DDF4
#define COL6_PORT     PORTF
#define COL6_PORT_PIN PF4
#define COL6_PIN      PINF
#define COL6_PIN_PIN  PINF4

#define COL7_DDR_REG  DDRF
#define COL7_DDR_PIN  DDF1
#define COL7_PORT     PORTF
#define COL7_PORT_PIN PF1
#define COL7_PIN      PINF
#define COL7_PIN_PIN  PINF1

#endif
