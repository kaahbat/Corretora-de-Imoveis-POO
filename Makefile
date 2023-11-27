# Definição de variáveis
CXX = g++
CXXFLAGS = -Wall
SRCDIR = src
OBJDIR = obj
BINDIR = bin
SOURCES = imovel.cpp apartamento.cpp casa.cpp chacara.cpp menu.cpp funcoes.cpp main.cpp 
OBJECTS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SOURCES))
EXECUTABLE = programa

# Regra padrão para compilação de objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para construir o executável
$(SRCDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

# Regra para limpar arquivos gerados
.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o $(SRCDIR)/$(EXECUTABLE)

# Regra padrão que constrói o executável
all: $(SRCDIR)/$(EXECUTABLE)

# Comando padrão ao executar "make" no terminal
.DEFAULT_GOAL := all