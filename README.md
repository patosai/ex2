# EX2

An ergonomic, split mechanical keyboard

## How to use
1. Plug in the keyboard
2. Edit the keymap if you wish
3. Build and flash the firmware, see below.
4. Run!

## Editing the keymap
See the files `include/keymap_left.h` and `include/keymap_right.h`. Available keycodes are in `include/keycodes.h`.

## Building
To make the firmware for a left or right half, first `make clean`. Then

`make left`

or

`make right`

Due to the Makefile not registering changes between making the left and right firmware sides, you will need clean the repo first. This will be fixed soon.

## Flashing
The firmware assumes the LUFA DFU bootloader is being used, it should already be there so you don't need to flash it again. Otherwise, `make bootloader`.

To flash the firmware that you built, first put the board into DFU mode by pressing the reset button a couple of times, or by plugging in the board with the reset button held. Then run

`make flash`

Once flashed, you can start the application using `make launch` or by plugging in the keyboard in again.
