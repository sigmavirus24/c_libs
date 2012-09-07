Q := @
PWD := $(shell pwd)
MAKE := make -C
MAKECLEAN := make clean
MAKEVERB := make verbose
RUNTESTS := /bin/bash run_tests.sh
CD := cd

LIBDIRS := list
DIRS := $(LIBDIRS) tests

default := all

all:
	for i in $(DIRS) ; do \
		$(MAKE) $$i ; \
	done

travis: all
	$(RUNTESTS)

verbose: libs
	$(CD) $(PWD)/tests && $(MAKEVERB)

test: verbose
	$(RUNTESTS)

libs:
	for i in $(LIBDIRS) ; do \
		$(MAKE) $$i ; \
	done

.SILENT:
clean:
	for i in $(DIRS) ; do \
		$(CD) $(PWD)/$$i && $(MAKECLEAN) ; \
	done

