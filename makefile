APP_NAME = main
LIB_NAME = lib
TEST_NAME = main_test

TESTFLAGS = -I thirdparty
CFLAGS = -Wall -Werror -I src
DEPSFLAGS = -MMD
CC = gcc

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
TEST_PATH = $(BIN_DIR)/$(TEST_NAME)

APP_SOURCES = $(wildcard $(SRC_DIR)/$(APP_NAME)/*.c)
APP_OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(APP_SOURCES))

LIB_SOURCES = $(wildcard $(SRC_DIR)/$(LIB_NAME)/*.c)
LIB_OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(LIB_SOURCES))

TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(TEST_SOURCES))

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d) $(TEST_OBJECTS:.o=.d)

.PHONY: all test clean
all: $(APP_PATH)

-include $(DEPS)


$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) -o $@ $^ -lm

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(DEPSFLAGS) -c -o $@ $< -lm

run: all
	$(APP_PATH) $(BIN_DIR)/geommi.txt

clean:
	$(RM) $(APP_PATH) $(TEST_PATH) $(OBJ_DIR)/*/*/*.[aod] $(OBJ_DIR)/test/*.[aod]