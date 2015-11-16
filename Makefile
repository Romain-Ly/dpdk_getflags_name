ifeq ($(RTE_SDK),)
$(error "Please define RTE_SDK environment variable")
endif

# Default target, can be overriden by command line or environment
RTE_TARGET ?= x86_64-native-linuxapp-gcc
RTE_OUTPUT = bin
RTE_TOOLCHAIN = gcc


include $(RTE_SDK)/mk/rte.vars.mk

# binary name
APP = getflags_test

# all source are stored in SRCS-y
SRCS-y := src/getflags_name.c

CFLAGS_src/getflags_name.o += -DGETFLAGS_NAME_MAIN


#CFLAGS += -I/home/rly/stage-ddos/DPDK/getflags_name/include
CFLAGS += -I$(RTE_SRCDIR)/include
#CFLAGS += -v
CFLAGS += -O0
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -std=gnu11
CFLAGS += $(WERROR_FLAGS)




include $(RTE_SDK)/mk/rte.extapp.mk
