#UF2_FAMILY_ID = 0x7f83e793
SDK_DIR = hw/mcu/nxp/mcux-sdk
DEPS_SUBMODULES += $(SDK_DIR) lib/CMSIS_5
MCU_DIR = $(SDK_DIR)/devices/$(MCU)

include $(TOP)/$(BOARD_PATH)/board.mk
CPU_CORE ?= cortex-m4

CFLAGS += \
	-DCFG_TUSB_MCU=OPT_MCU_KINETIS_K

LDFLAGS_GCC += -specs=nosys.specs -specs=nano.specs

SRC_C += src/portable/nxp/khci/dcd_khci.c
SRC_C += src/portable/nxp/khci/hcd_khci.c
SRC_C += $(MCU_DIR)/system_$(MCU).c
SRC_C += $(MCU_DIR)/drivers/fsl_clock.c
SRC_C += $(SDK_DIR)/drivers/gpio/fsl_gpio.c
#SRC_C += $(SDK_DIR)/drivers/lpuart/fsl_lpuart.c
SRC_C += $(SDK_DIR)/drivers/uart/fsl_uart.c

INC += $(TOP)/$(BOARD_PATH)
INC += $(TOP)/lib/CMSIS_5/CMSIS/Core/Include
INC += $(TOP)/$(MCU_DIR)
#INC += $(TOP)/$(MCU_DIR)/project_template
INC += $(TOP)/$(MCU_DIR)/drivers
INC += $(TOP)/$(SDK_DIR)/drivers/smc
INC += $(TOP)/$(SDK_DIR)/drivers/common
INC += $(TOP)/$(SDK_DIR)/drivers/gpio
INC += $(TOP)/$(SDK_DIR)/drivers/port
INC += $(TOP)/$(SDK_DIR)/drivers/lpuart
INC += $(TOP)/$(SDK_DIR)/drivers/uart

SRC_S += $(MCU_DIR)/gcc/startup_$(MCU).S
