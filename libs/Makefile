CC := g++
AR := ar
RM := rm
SRCDIR := src
INCLUDEDIR := include
BUILDDIR := build
FLAGS := -g -Wall -shared --std=c++11
TARGET := cclib.a

SOURCES := $(shell find $(SRCDIR) -type f -name "*.cpp")
OBJECTS := $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SOURCES:.cpp=.o))
INCDIR := -I include 


$(TARGET): $(OBJECTS)
	@echo "Building library..."
	@echo "$(AR) rcs $@ $^"; $(AR) rcs $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	@echo "$(CC) $(FLAGS) $(INCDIR) -c -o $@ $<"; $(CC) $(INCDIR) -c -o $@ $<
	
.PHONY: clean

clean:
	@echo "Limpiando..."
	$(RM) -r $(BUILDDIR) $(TARGET)
