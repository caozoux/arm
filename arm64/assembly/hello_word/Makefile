TARGET := obj
OBJ_START :=start.o
OBJS 	  :=main.o
BIN := $(TARGET).bin
LD_ADDR :=0x49000000

CROCESS_COMPILE=aarch64-linux-gnu-
CC :=$(CROCESS_COMPILE)gcc
AS :=$(CROCESS_COMPILE)as
LD :=$(CROCESS_COMPILE)ld
OBJCOPY :=$(CROCESS_COMPILE)objcopy
NM :=$(CROCESS_COMPILE)nm
CFLAGS = -lc
LINKSCRIPT=link.ld
#LFLAGS = -Ttext $(LD_ADDR)
LFLAGS = -T $(LINKSCRIPT)

all:$(TARGET)
	$(OBJCOPY) -O binary $^ $(BIN)
	$(CC) $(OBJS) $(OBJ_START) -lc  -nostartfiles -T $(LINKSCRIPT) -Wl,-Map=$(TARGET).map
	cp $(BIN) /var/lib/tftpboot/rootfs_altera

$(TARGET): $(OBJ_START) $(OBJS)
	$(LD) $^  -o $@  $(LFLAGS)
%.o:%.s
	$(AS) $< -o $@
%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm *.o

