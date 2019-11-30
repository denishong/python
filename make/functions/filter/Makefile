#!/bin/sh
core-y      += kernel/ certs/ mm/ fs/ ipc/ security/ crypto/ block/
vmlinux-dirs = $(filter /%,$(core-y)) 
pattern_vmlinux-dirs = $(patsubst %/,%,$(filter %/,$(core-y))) 
core-yx      := $(patsubst %/, %/built-in.o, $(core-y))
test:
	@echo $(core-y)	
	@echo $(vmlinux-dirs)
	@echo $(pattern_vmlinux-dirs)
	@echo $(core-yx)	
