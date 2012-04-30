Q := @
RM := rm -f
CC := gcc
AR := ar
RL := ranlib
MV := mv
CFLAGS := -ggdb3 -Werror -Wall -pedantic-errors
TARGET := liblist
SRC := add_elem.c add_node.c add_node_at.c append.c \
	count_nodes.c elem_at.c empty_list.c new_node.c \
	node_at.c remove_node.c remove_node_at.c remove_last.c \
	traverse_list.c
OBJ := $(SRC:%c=%o)

default := liblist

liblist: $(OBJ)
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
