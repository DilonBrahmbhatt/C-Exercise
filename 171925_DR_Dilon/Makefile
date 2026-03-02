CC = gcc
CFLAGS = -Wall -I./header -I./lib -I.

BIN_DIR = bin
TARGET = $(BIN_DIR)/main.out

# --- 1. Define Core Files (Top-level obj/) ---
CORE_OBJ_DIR = obj
CORE_SRCS = src/main.c lib/common.c
CORE_OBJS = $(addprefix $(CORE_OBJ_DIR)/, $(notdir $(CORE_SRCS:.c=.o)))

# --- 2. Define Module Files ---
M1_DIR = 171925_dilon_DR_M1_t006
M2_DIR = 171925_dilon_DR_M2_t006
M3_DIR = 171925_dilon_DR_M3_t006
M4_DIR = 171925_dilon_DR_M4_t006

M1_SRCS = $(wildcard $(M1_DIR)/src/*.c)
M2_SRCS = $(wildcard $(M2_DIR)/src/*.c)
M3_SRCS = $(wildcard $(M3_DIR)/src/*.c)
M4_SRCS = $(wildcard $(M4_DIR)/src/*.c)

# Maps src/*.c to obj/*.o within the module folders
M1_OBJS = $(patsubst $(M1_DIR)/src/%.c, $(M1_DIR)/obj/%.o, $(M1_SRCS))
M2_OBJS = $(patsubst $(M2_DIR)/src/%.c, $(M2_DIR)/obj/%.o, $(M2_SRCS))
M3_OBJS = $(patsubst $(M3_DIR)/src/%.c, $(M3_DIR)/obj/%.o, $(M3_SRCS))
M4_OBJS = $(patsubst $(M4_DIR)/src/%.c, $(M4_DIR)/obj/%.o, $(M4_SRCS))

ALL_OBJS = $(CORE_OBJS) $(M1_OBJS) $(M2_OBJS) $(M3_OBJS) $(M4_OBJS)

# --- 3. Build Rules ---

all: $(TARGET)

# This links the ALREADY COMPILED .o files. 
# It no longer tries to compile .c files in this step.
$(TARGET): $(ALL_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(ALL_OBJS) -o $(TARGET)

# Rule for Core Files
$(CORE_OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(CORE_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(CORE_OBJ_DIR)/%.o: lib/%.c
	@mkdir -p $(CORE_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for M1 Files (Crucial: This now uses CFLAGS so it finds header.h)
$(M1_DIR)/obj/%.o: $(M1_DIR)/src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for M2 Files
$(M2_DIR)/obj/%.o: $(M2_DIR)/src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
# Rule for M3 Files
$(M3_DIR)/obj/%.o: $(M3_DIR)/src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
# Rule for M4 Files
$(M4_DIR)/obj/%.o: $(M4_DIR)/src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN_DIR)/*.out $(CORE_OBJ_DIR)/*.o
	rm -rf $(M1_DIR)/obj/*.o $(M2_DIR)/obj/*.o $(M3_DIR)/obj/*.o $(M4_DIR)/obj/*.o
