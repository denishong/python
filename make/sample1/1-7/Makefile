CC = gcc
MKDIR = mkdir
RM = rm
.SUFFIX = .c .o
VPATH = src include
CPPFLAGS = -I include
#vpath %.c src
#vpath %.h include
OBJS_DIR = output
TARGET = test
DEPEND_FILE = depend_file

TARGET_SRCS = main.c write.c read.c
TARGET_OBJS = $(TARGET_SRCS:%.c=$(OBJS_DIR)/%.o)
TARGET_NAMES = $(TARGET_SRCS:%.c=$(OBJS_DIR)/%)

all : $(TARGET_NAMES)

.SECONDEXPANSION:
$(TARGET_NAMES): $$@.o
	$(CC) -o $@ $< 

$(OBJS_DIR)/%.o : %.c
	@echo "=============================="
	@echo "== Compiling $@ "
	@echo "=============================="
#	@'[ -d $(OBJS_DIR) ] || $(MKDIR) $(OBJS_DIR)'
	$(CC) -c $< -o $@	

depend: 
	@'[ -d $(OBJS_DIR) ] || $(MKDIR) $(OBJS_DIR)'
	@$(RM) -f $(DEPEND_FILE)
	@for FILE in $(TARGET_SRCS:%.c=%); do \
		$(CC) -MM $(OBJS_DIR)/$$FILE.o $$FILE.c >> $(DEPEND_FILE); \
	done
	#gccmakedep $(SRCS)

clean:
	rm -rf $(OBJS_DIR)
