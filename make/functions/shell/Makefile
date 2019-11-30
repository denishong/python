# SHELL used by kbuild
CONFIG_SHELL := $(shell if [ -x "$$BASH" ]; then echo $$BASH; \
     else if [ -x /bin/bash ]; then echo /bin/bash; \
     else echo sh; fi ; fi)
KERNELRELEASE = $(shell cat ../../../../kernel/include/config/kernel.release 2>/dev/null)


ifeq ($(shell $(HOSTCC) -v 2>&1 | grep -c "clang version"), 1)
HOSTCFLAGS= his version
endif

test:
	@echo $(CONFIG_SHELL)
	@echo $(KERNELRELEASE)
	@echo $(HOSTCFLAGS)
