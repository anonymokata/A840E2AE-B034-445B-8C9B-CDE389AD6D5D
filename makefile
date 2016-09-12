CFLAGS = -O0
LFLAGS = `pkg-config --libs check`

NAME = romanCalc
TESTNAME = $(NAME)_check
SRC_DIR = src
TEST_DIR = tests

all: $(TESTNAME)

$(NAME).o: $(SRC_DIR)/$(NAME).c $(SRC_DIR)/$(NAME).h
	gcc $(CFLAGS) -c -o $(NAME).o $(SRC_DIR)/$(NAME).c

$(TESTNAME): $(NAME).o $(TEST_DIR)/$(TESTNAME).c
	gcc $(CFLAGS) -o $(TESTNAME) $(NAME).o $(TEST_DIR)/$(TESTNAME).c $(LFLAGS)

check: $(TESTNAME)
	./$(TESTNAME)

clean:
	rm $(TESTNAME) $(NAME).o
