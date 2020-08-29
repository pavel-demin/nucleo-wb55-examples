NAME = led_blinker

PART = STM32WB55xx

OBJECTS = main.o startup.o

vpath %.c common $(NAME)

CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy

CFLAGS = -Wall -Os -mthumb -march=armv7-m -mtune=cortex-m4 \
  -fdata-sections -ffunction-sections -D$(PART) -ICMSIS

LDFLAGS = --script ldscript.ld --gc-sections

all: $(NAME).bin

install: $(NAME).elf
	openocd -f openocd.cfg -c "program $< verify reset exit"

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

%.elf: $(OBJECTS)
	$(LD) $(LDFLAGS) $^ -o $@

%.bin: %.elf
	$(OBJCOPY) -O binary -S $< $@

clean:
	rm -rf *.o *.elf *.bin
