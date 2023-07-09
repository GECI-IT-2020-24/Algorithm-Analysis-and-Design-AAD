CC = clang
CFLAGS = -Wall -Wextra -g
LDFLAGS=-fuse-ld=mold
UNITY= ./../unity/src/unity.c

SORT_SRC=./../dac/src/sort.c
SRC_DIR = ./src
SRC = $(wildcard $(SRC_DIR)/*.c)

TEST=./test/test.c
TEST_EXEC=greedy_test

all: $(TEST_EXEC)
	
# uses  Mold linker change LDFLAGS to use ld : )

$(TEST_EXEC):
	$(CC) $(CFLAGS) $(LDFLAGS) $(UNITY) $(SRC) $(SORT_SRC) $(TEST) -o $(TEST_EXEC)

clean:
	rm -f $(TEST_EXEC)

.PHONY: clean
