Q := @
RM := rm -f
CC := gcc
AR := ar
RL := ranlib
MV := mv
CFLAGS := -ggdb3 -Werror -Wall -pedantic-errors
TARGET := liblist
SRC := find_char.c rfind_char.c find_string.c
OBJ := $(SRC:%c=%o)

default := libstrsearch

libstrsearch: $(OBJ)
	$(Q)$(CC) -c $(CFLAGS) $(SRC)
	$(Q)$(AR) -rc $@.a $(OBJ)
	$(Q)$(RL) $@.a
	$(Q)$(MV) $@.a ../lib/
	@echo " [BUILD] $@.a"

clean:
	$(Q)$(RM) $(OBJ) ../lib/$(TARGET).a

%o: %c
	@echo " [CC] $@"
	$(Q)$(COMPILE.c) $(OUTPUT_OPTION) $<
