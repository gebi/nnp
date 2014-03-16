BIN=nnp

all: $(BIN)

nnp: nnp.c
	diet gcc -O2 -Wall -Werror -o $@ $^

clean:
	rm -f $(BIN)
