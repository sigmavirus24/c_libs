Q := @
PWD := $(shell pwd)
MAKE := make -C
MAKECLEAN := make clean
CD := cd

LIBDIRS := list
DIRS := $(LIBDIRS) tests

default := all

all:
	for i in $(DIRS) ; do \
		$(MAKE) $$i ; \
	done

tests:
	$(MAKE) tests/

libs:
	for i in $(LIBDIRS) ; do \
		$(MAKE) $$i ; \
	done

.SILENT:
clean:
	for i in $(DIRS) ; do \
		$(CD) $(PWD)/$$i && $(MAKECLEAN) ; \
	done

