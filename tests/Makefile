Q := @
RM := rm -f
CC := gcc
CFLAGS := -ggdb3 -Werror -Wall -pedantic-errors -L../lib
SRC :=  test_list.c
OBJ := $(SRC:%c=%o)

default := test_list

test_list: $(OBJ)
	@echo " [BUILD] $@"
	$(Q)$(CC) $(OBJ) $(CFLAGS) -llist -o $@

clean:
	$(Q)$(RM) $(OBJ) test_list

%o: %c
	@echo " [CC] $@"
	$(Q)$(COMPILE.c) $(OUTPUT_OPTION) $<
