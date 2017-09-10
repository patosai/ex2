MCU          = atmega32u4
ARCH         = AVR8
BOARD        = USBKEY
F_CPU        = 16000000
F_USB        = $(F_CPU)
OPTIMIZATION = s
TARGET       = keyboard
SRC          = $(TARGET).c \
               $(shell find src -name '*.c') \
               $(LUFA_SRC_USB) \
               $(LUFA_SRC_USBCLASS)
LUFA_PATH    = ./LUFA
CC_FLAGS     = -DUSE_LUFA_CONFIG_HEADER \
							 -DDEBOUNCE_ENABLED \
							 -Iinclude
LD_FLAGS     =

DFU          = dfu-programmer $(MCU)

default: hex

left: CC_FLAGS += -DKEYBOARD_LEFT
left: hex

right: hex

all-left: left flash launch
all-right: right flash launch

flash:
	$(DFU) erase; $(DFU) flash $(TARGET).hex

bootloader:
	avrdude -p m32u4 -c usbasp -e -U flash:w:bootloader/BootloaderDFU.hex

launch:
	$(DFU) reset

.PHONY: bootloader

# Include LUFA build script makefiles
include $(LUFA_PATH)/Build/lufa_sources.mk
include $(LUFA_PATH)/Build/lufa_build.mk
include $(LUFA_PATH)/Build/lufa_cppcheck.mk
include $(LUFA_PATH)/Build/lufa_dfu.mk
