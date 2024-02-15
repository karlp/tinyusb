MCU = MK64F12

CFLAGS += -DCPU_MK64FN1M0VLL12

# mcu driver cause following warnings
CFLAGS += -Wno-error=unused-parameter -Wno-error=redundant-decls  -ggdb3

# All source paths should be relative to the top level.
LD_FILE = $(MCU_DIR)/gcc/MK64FN1M0xxx12_flash.ld

#SRC_C += $(MCU_DIR)/project_template/clock_config.c
#SRC_C += $(TOP)/$(BOARD_PATH)/clock_config.c
SRC_C += $(BOARD_PATH)/clock_config.c

#INC += $(TOP)/$(SDK_DIR)/boards/frdmk64f

# For flash-jlink target
JLINK_DEVICE = MK64FN1M0xxx12

# For flash-pyocd target
PYOCD_TARGET = KMK64F # TBD?

# flash using pyocd
flash: flash-pyocd
