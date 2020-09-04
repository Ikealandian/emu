# ONLY BUILDS SRC/X11/

BUILD := build/
OBJ := $(BUILD)obj/

LIB := $(BUILD)libemu.a
LEMU := -L $(BUILD) -lemu

EXAMPLES := examples/

INC := include/
SRC := src/

CC := cc
CFLAGS := -Wall -Wextra -I $(INC)
CLIBS := -lX11 -lvulkan

X11PATH := $(SRC)x11/
X11SRC := $(wildcard $(X11PATH)*.c)
X11OBJ := $(X11SRC:$(X11PATH)%.c=$(OBJ)%.o)

EMUSRC := $(wildcard $(SRC)*.c)
EMUOBJ := $(EMUSRC:$(SRC)%.c=$(OBJ)%.o)

EXMSRC := $(wildcard $(EXAMPLES)*.c)
EXMOBJ := $(EXMSRC:$(EXAMPLES)%.c=$(BUILD)%.o)

all: $(OBJ) $(EMUOBJ) $(X11OBJ) $(LIB) $(EXMOBJ)

$(OBJ):
	mkdir -p $(OBJ)

$(EMUOBJ): $(OBJ)%.o: $(SRC)%.c
	$(CC) $(CFLAGS) $(CLIBS) -c $< -o $@

$(X11OBJ): $(OBJ)%.o: $(X11PATH)%.c
	$(CC) $(CFLAGS) $(CLIBS) -c $< -o $@

$(EXMOBJ): $(BUILD)%.o: $(EXAMPLES)%.c
	$(CC) $(CFLAGS) $(CLIBS) $< $(LEMU) -o $@

$(LIB):
	ar rs $(LIB) $(EMUOBJ) $(X11OBJ)

clean:
	$(RM) $(EMUOBJ) $(X11OBJ) $(WAYOBJ) $(LIB) $(EXMOBJ)