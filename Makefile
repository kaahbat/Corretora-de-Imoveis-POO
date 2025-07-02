# Definição de variáveis
CXX = g++
CXXFLAGS = -Wall -Iinclude
SRCDIR = src
OBJDIR = obj
BINDIR = bin
SOURCES = imovel.cpp apartamento.cpp casa.cpp chacara.cpp menu.cpp funcoes.cpp main.cpp 
OBJECTS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SOURCES))
EXECUTABLE = corretora

# Regra padrão para compilação de objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para construir o executável
$(BINDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

# Regra para limpar arquivos gerados
.PHONY: clean
clean:
ifeq ($(OS),Windows_NT)
	@if exist $(OBJDIR)\*.o del /Q $(OBJDIR)\*.o
	@if exist $(SRCDIR)\$(EXECUTABLE).exe del /Q $(SRCDIR)\$(EXECUTABLE).exe
else
	rm -f $(OBJDIR)/*.o $(SRCDIR)/$(EXECUTABLE)
endif

# Regra padrão que constrói o executável
all: $(SRCDIR)/$(EXECUTABLE)

# Comando padrão ao executar "make" no terminal
.DEFAULT_GOAL := all