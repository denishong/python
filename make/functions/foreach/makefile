#!/bin/sh
header-y = asm-generic drm linux misc mtd rdma scsi sound video xen

#input-files2 := $(foreach hdr, $(header-y))
dirs := a b c d
files := $(foreach dir,$(dirs),$(wildcard $(dir)/*))

all : test
test:
	@echo $(files)
