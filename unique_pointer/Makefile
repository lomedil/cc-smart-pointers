CC := g++
RM := rm
SRCDIR := src
INCLUDEDIR := include
TARGET := app
BINDIR := bin
FLAGS := -g -Wall -std=c++11

INC := -Iinclude -I../libs/include
LIBS := ../libs/cclib.a

directorios:
	@mkdir -p $(BINDIR)

archivo: directorios
	@echo "Coders Cantabria Rulez" > $(BINDIR)/archivo.txt

cuenta_con_excepciones: directorios archivo
	@echo " Compilando problema con excepciones"
	@echo " $(CC) $(FLAGS) $(INC) $(LDFLAGS) $(LIBS) main_cuenta_con_excep.cpp -o $(BINDIR)/cuenta_con_excepciones"
	        $(CC) $(FLAGS) $(INC) $(LDFLAGS) $(LIBS) main_cuenta_con_excep.cpp -o $(BINDIR)/cuenta_con_excepciones

cuenta_sin_excepciones: directorios archivo
	@echo " Compilando problema sin excepciones"
	@echo " $(CC) $(FLAGS) $(INC) $(LDFLAGS) $(LIBS) main_cuenta_sin_excep.cpp -o $(BINDIR)/cuenta_sin_excepciones"
	        $(CC) $(FLAGS) $(INC) $(LDFLAGS) $(LIBS) main_cuenta_sin_excep.cpp -o $(BINDIR)/cuenta_sin_excepciones

cuenta_unique_pointer: directorios archivo
	@echo " Compilando problema sin excepciones"
	@echo " $(CC) $(FLAGS) $(INC) $(LDFLAGS) $(LIBS) main_cuenta_unique_pointer.cpp -o $(BINDIR)/cuenta_unique_pointer"
	        $(CC) $(FLAGS) $(INC) $(LDFLAGS) $(LIBS) main_cuenta_unique_pointer.cpp -o $(BINDIR)/cuenta_unique_pointer	        

all: cuenta_sin_excepciones cuenta_con_excepciones cuenta_unique_pointer

clean:
	@echo "Limpiando..."
	$(RM) -r $(BUILDDIR) $(BINDIR)
