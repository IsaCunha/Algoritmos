# Define as variáveis do compilador
CPP = g++
STD = -std=c++11

# Define as flags obrigatórias para o TP
CFLAGS = -Wall -Wextra -Wpedantic -Wformat-security -Wconversion -Werror 

# Define o diretório de inclusão para os arquivos de cabeçalho (.hpp)
IDIR = -I include

# Define os arquivos de código fonte e objeto
SRCS = src/main.cpp src/natal.cpp
OBJS = obj/main.o obj/natal.o

# Define o nome do executável final (tp2.out, conforme a especificação)
TARGET = tp3.out 

# --------------------------------------------------------------------------
# 1. Regra Padrão (all): Cria o executável
# Cria a pasta obj se ela não existir antes de compilar
.PHONY: all
all: | obj $(TARGET)

# --------------------------------------------------------------------------
# 2. Regra do Executável: Linkagem
# O executável depende dos arquivos objeto.
$(TARGET): $(OBJS)
	$(CPP) $(CFLAGS) $(STD) $(IDIR) $^ -o $(TARGET)
	@echo "----------------------------------------------"
	@echo "Compilação concluída: Arquivo '$(TARGET)' criado."

# --------------------------------------------------------------------------
# 3. Regras de Compilação (Gerando os .o)
# Compila os arquivos de implementação (.cpp) e coloca os objetos na pasta obj/

# Regra genérica para compilar qualquer arquivo .cpp e gerar o .o
obj/%.o: src/%.cpp include/natal.hpp
	$(CPP) $(CFLAGS) $(STD) $(IDIR) -c $< -o $@

# --------------------------------------------------------------------------
# 4. Regras de Limpeza (clean)
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
	@echo "Arquivos objeto e executável removidos."

# 5. Criação do diretório obj (se necessário)
obj:
	mkdir -p obj