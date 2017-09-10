# EX2

An ergonomic, split mechanical keyboard

## Editing the keymap
See the files `include/keymap_left.h` and `include/keymap_right.h`. Available keycodes are in `include/keycodes.h`.

## Building
To make the firmware for a left or right half, first `make clean`. Then

`make left`

or

`make right`

Due to the Makefile not registering changes between making the left and right firmware sides, you will need clean the repo first. This will be fixed soon.

## Flashing
The firmware assumes the LUFA DFU bootloader is being used. If you have a programmer you can use `make bootloader` to flash it.

Once the firmware is built, run

`make flash`
