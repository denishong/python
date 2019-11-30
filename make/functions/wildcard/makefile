#!/bin/sh
.PHONY:all

VPATH = ./a
c_source = *.c 
c_source_wildcard ?= $(wildcard *.c) 
KBUILD_OUTPUT ?= $(patsubst %.c,%.o,$(wildcard *.c)) 

all : test
test:$(c_source) 
	@echo $(c_source) 
	@echo $(c_source_wildcard) 
	@echo $(KBUILD_OUTPUT) $< $@ $% $? $^ $+
