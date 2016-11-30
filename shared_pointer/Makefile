CC := g++
RM := rm
SRCDIR := src
INCLUDEDIR := include
BINDIR := bin
TARGET := app
FLAGS := -g -Wall

INC := -Iinclude -I../libs/include -I../libs/include/mal
LIBS := ../libs/cclib.a

archivo:
	@echo "Coders Cantabria Rulez" > $(BINDIR)/archivo.txt

directorios: directorios
	@mkdir -p $(BINDIR)

solucion: directorios archivo
	@echo " Compilando solucion shared pointer"
	@echo " $(CC) $(FLAGS) $(INC) $(LDFLAGS) $(LIBS) main.cpp -o $(BINDIR)/solucion"
	        $(CC) $(FLAGS) $(INC) $(LDFLAGS) $(LIBS) main.cpp -o $(BINDIR)/solucion

problema: directorios archivo
	@echo " Compilando problema para shared pointer"
	@echo " $(CC) $(FLAGS) $(INC) $(LDFLAGS) $(LIBS) main_problema.cpp -o $(BINDIR)/problema"
	        $(CC) $(FLAGS) $(INC) $(LDFLAGS) $(LIBS) main_problema.cpp -o $(BINDIR)/problema

all: problema solucion

clean:
	@echo "Limpiando..."
	$(RM) -r $(BUILDDIR) $(TARGET)
