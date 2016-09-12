CFLAGS = -O2
LFLAGS = `pkg-config --libs check`

NAME = romanCalc
TESTNAME = $(NAME)_check
SRC_DIR = src
TEST_DIR = tests

all: $(TESTNAME)

$(TESTNAME): $(SRC_DIR)/$(NAME).c $(TEST_DIR)/$(TESTNAME).c
	gcc $(CFLAGS) -o $(TESTNAME) $(SRC_DIR)/$(NAME).c $(TEST_DIR)/$(TESTNAME).c $(LFLAGS)
