CC = gcc
# Added -I. so it can find headers if they are in the root or lib
CFLAGS = -Wall -I. -I./lib

BIN_DIR = bin
# The central object directory for main and lib files
OBJ_DIR = obj
TARGET = $(BIN_DIR)/main.out

# 1. Module Files (The 171925_dilon_YPK_chapter* folders)
MODULE_SRCS := $(wildcard 171925_dilon_YPK_chapter*/src/*.c)
MODULE_OBJS := $(subst /src/,/obj/,$(MODULE_SRCS:.c=.o))

# 2. Root and Lib Files
MAIN_SRC = src/main.c
LIB_SRC  = lib/main_switch.c lib/common_func.c

MAIN_OBJ = $(OBJ_DIR)/main.o
LIB_OBJ  = $(OBJ_DIR)/main_switch.o
COMMON_OBJ = $(OBJ_DIR)/common_func.o   # added

ALL_OBJS = $(MAIN_OBJ) $(LIB_OBJ) $(COMMON_OBJ) $(MODULE_OBJS)  # added common object

all: $(TARGET)
	@echo "\n--- Compilation Complete ---"
	@echo "Executable is at: $(TARGET)"

# Link the final executable
$(TARGET): $(ALL_OBJS)
	@mkdir -p $(BIN_DIR)
	@$(CC) $(ALL_OBJS) -lm -o $(TARGET)   # added -lm

# Rule for main.o and common.o into the central ./obj folder
$(OBJ_DIR)/%.o: **/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

execute:
	./$(TARGET)
# Loop to handle module-specific object placement (src/ -> obj/)
define COMPILE_RULE
$(subst /src/,/obj/,$(1:.c=.o)): $(1)
	@mkdir -p $$(dir $$@)
	$(CC) $(CFLAGS) -c $$< -o $$@
endef

$(foreach src,$(MODULE_SRCS),$(eval $(call COMPILE_RULE,$(src))))

clean:
	rm -rf $(BIN_DIR)
	# Cleans all .o files within the directory structure
	find . -name "*.o" -type f -delete
	@echo "Cleaned up all binaries and objects."
debug:
	@echo "Source files found: $(MODULE_SRCS)"
	@echo "Object files to link: $(ALL_OBJS)"
