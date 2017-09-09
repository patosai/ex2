#ifndef _MATRIX_LEFT_H_
#define _MATRIX_LEFT_H_

#include <avr/io.h>

/* Row pin configuration
 * pins (top to bottom): F1 F4 F5 F6 F7
 */
#define ROW1_DDR_REG  DDRF
#define ROW1_DDR_PIN  DDF1
#define ROW1_PORT     PORTF
#define ROW1_PORT_PIN PF1

#define ROW2_DDR_REG  DDRF
#define ROW2_DDR_PIN  DDF4
#define ROW2_PORT     PORTF
#define ROW2_PORT_PIN PF4

#define ROW3_DDR_REG  DDRF
#define ROW3_DDR_PIN  DDF5
#define ROW3_PORT     PORTF
#define ROW3_PORT_PIN PF5

#define ROW4_DDR_REG  DDRF
#define ROW4_DDR_PIN  DDF6
#define ROW4_PORT     PORTF
#define ROW4_PORT_PIN PF6

#define ROW5_DDR_REG  DDRF
#define ROW5_DDR_PIN  DDF7
#define ROW5_PORT     PORTF
#define ROW5_PORT_PIN PF7

/* Column pin configuration
 * pins (left to right): D4 D6 D7 B4 B5 B6 F0
 */
#define COL1_DDR_REG  DDRD
#define COL1_DDR_PIN  DDD4
#define COL1_PORT     PORTD
#define COL1_PORT_PIN PD4
#define COL1_PIN      PIND
#define COL1_PIN_PIN  PIND4

#define COL2_DDR_REG  DDRD
#define COL2_DDR_PIN  DDD6
#define COL2_PORT     PORTD
#define COL2_PORT_PIN PD6
#define COL2_PIN      PIND
#define COL2_PIN_PIN  PIND6

#define COL3_DDR_REG  DDRD
#define COL3_DDR_PIN  DDD7
#define COL3_PORT     PORTD
#define COL3_PORT_PIN PD7
#define COL3_PIN      PIND
#define COL3_PIN_PIN  PIND7

#define COL4_DDR_REG  DDRB
#define COL4_DDR_PIN  DDB4
#define COL4_PORT     PORTB
#define COL4_PORT_PIN PB4
#define COL4_PIN      PINB
#define COL4_PIN_PIN  PINB4

#define COL5_DDR_REG  DDRB
#define COL5_DDR_PIN  DDB5
#define COL5_PORT     PORTB
#define COL5_PORT_PIN PB5
#define COL5_PIN      PINB
#define COL5_PIN_PIN  PINB5

#define COL6_DDR_REG  DDRB
#define COL6_DDR_PIN  DDB6
#define COL6_PORT     PORTB
#define COL6_PORT_PIN PB6
#define COL6_PIN      PINB
#define COL6_PIN_PIN  PINB6

#define COL7_DDR_REG  DDRF
#define COL7_DDR_PIN  DDF0
#define COL7_PORT     PORTF
#define COL7_PORT_PIN PF0
#define COL7_PIN      PINF
#define COL7_PIN_PIN  PINF0

#endif
