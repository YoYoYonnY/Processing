CC=gcc
CFLAGS=-Wall -std=c99 -Isrc/lib -L bin/lib
SHAREDLIB_EXT=.dll
LIBS=$(patsubst src/lib/%.c,%,$(wildcard src/lib/*.c))
LIBOBJ=$(patsubst %,bin/lib/%.o,$(LIBS))
LIBFLAGS=$(patsubst %,-l%,$(LIBS))

.PHONY: main all clean

all: main clean

clean:
	rm -f bin/lib/*.o
	rm -f bin/*.o

main: $(LIBOBJ) bin/main.o
	$(CC) -o bin/main $^ $(CFLAGS) $(LIBFLAGS)

# Directories

bin:
	mkdir -p bin
bin/lib:
	mkdir -p bin/lib

# Object files

bin/lib/%.o: src/lib/%.c | bin bin/lib
	$(CC) -c -o $@ $< $(CFLAGS)
	gcc -shared -Wl,-soname,bin/lib/lib$(patsubst bin/lib/%.o,%,$@)$(SHAREDLIB_EXT) -o bin/lib/lib$(patsubst bin/lib/%.o,%,$@)$(SHAREDLIB_EXT) $@
bin/%.o: src/%.c | bin
	$(CC) -c -o $@ $< $(CFLAGS)
