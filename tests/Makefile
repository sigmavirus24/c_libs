Q := @
RM := rm -f
CC := gcc
CFLAGS := -ggdb3 -Werror -Wall -pedantic-errors -L../lib

# liblist specifics
LIST_SRC := test_list.c
LIST_OBJ := $(LIST_SRC:%c=%o)
LIST_FLAGS := $(CFLAGS) -llist

# libstrsearch specifics
SEARCH_SRC := test_string_search.c
SEARCH_OBJ := $(STRING_SRC:%c=%o)
SEARCH_FLAGS := $(CFLAGS) -lstrsearch

# everything
OBJ := $(LIST_OBJ) $(SEARCH_OBJ)

default := test_list test_search

test_list: $(LIST_OBJ)
	@echo " [BUILD] $@"
	$(Q)$(CC) $(LIST_OBJ) $(LIST_FLAGS) -o $@

test_search: $(SEARCH_OBJ)
	@echo " [BUILD] $@"
	$(Q)$(CC) $(SEARCH_OBJ) $(SEARCH_FLAGS) -o $@

verbose: verbose_list

verbose_list: $(LIST_SRC)
	@echo " [BUILD] $@"
	$(Q)$(CC) -DVERBOSE $(LIST_FLAGS) $(LIST_SRC) -o $@

clean:
	$(Q)$(RM) $(OBJ) test_list

%o: %c
	@echo " [CC] $@"
	$(Q)$(COMPILE.c) $(OUTPUT_OPTION) $<
