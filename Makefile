# Top-level Makefile - delegates the real work to src/Makefile

.PHONY: all clean run

all:
	$(MAKE) -C src

clean:
	$(MAKE) -C src clean
	rm -f bin/*

run:
	./bin/client
