CC := g++
RM := rm
SRCDIR := src
INCLUDEDIR := include
FLAGS := -g -Wall --std=c++11
FOLDERS := problema unique_pointer shared_pointer
DEMOLIBPATH := libs/cclib.a

$(DEMOLIBPATH):
	$(MAKE) -C libs

all: $(FOLDERS)
	true

$(FOLDERS): $(DEMOLIBPATH)
	@echo "Making $@..."
	$(MAKE) -C $@

.PHONY: clean

clean:
	@echo "Limpiando..."
	$(MAKE) clean -C libs
	$(MAKE) clean -C unique_pointer
	$(MAKE) clean -C shared_pointer
