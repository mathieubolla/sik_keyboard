# Set to /dev/cu.usbmodem1421 or whatever on Macs
USB ?= /dev/ttyACM0

# Target file name (without extension).
TARGET = sik

# Directory common source filess exist
TMK_DIR = ./tmk_core/tmk_core

# Directory keyboard dependent files exist
TARGET_DIR = .

# project specific files
SRC =	keymap_common.c \
	matrix.c \
	led.c

KEYMAP ?= qwerty
SRC := keymap_$(KEYMAP).c $(SRC)
CONFIG_H = config.h

# MCU name
MCU = at90usb1286

F_CPU = 16000000
F_USB = $(F_CPU)

# Interrupt driven control endpoint task(+60)
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT

# Boot Section Size in *bytes*
#   Teensy halfKay   512
#   Teensy++ halfKay 1024
#   Atmel DFU loader 4096
#   LUFA bootloader  4096
#   USBaspLoader     2048
OPT_DEFS += -DBOOTLOADER_SIZE=1024

# Build Options
#   comment out to disable the options.
#
# BOOTMAGIC_ENABLE = yes	# Virtual DIP switch configuration(+1000)
# MOUSEKEY_ENABLE = yes	# Mouse keys(+4700)
EXTRAKEY_ENABLE = yes	# Audio control and System control(+450)
# CONSOLE_ENABLE = yes	# Console for debug(+400)
# COMMAND_ENABLE = yes    # Commands for debug and configuration
# SLEEP_LED_ENABLE = yes  # Breathing sleep LED during USB suspend
NKRO_ENABLE = yes	# USB Nkey Rollover - not yet supported in LUFA

# Causes trouble on low voltage chipsets.
#OPT_DEFS += -DNO_SUSPEND_POWER_DOWN

# Optimize size but this may cause error "relocation truncated to fit"
EXTRALDFLAGS = -Wl,--relax

# Search Path
VPATH += $(TARGET_DIR)
VPATH += $(TMK_DIR)

include $(TMK_DIR)/protocol/pjrc.mk
include $(TMK_DIR)/common.mk
include $(TMK_DIR)/rules.mk
