# Compilador
CXX = g++
CXXFLAGS = -std=c++17 -g -O0

# Directorios
SRC_DIR = src
BIN_DIR = bin

# Nombre del binario (único)
TARGET = MiniCryptTool-completo.exe

# Archivo fuente
SRC = $(SRC_DIR)/MiniCryptTool.cpp

# Ruta de salida
OUT = $(BIN_DIR)/$(TARGET)

# Regla por defecto: compilar el único binario
all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)
	@echo ">>> Compilado: $(OUT)"

# Limpiar binarios
clean:
	rm -f $(BIN_DIR)/$(TARGET)
	@echo ">>> Binario eliminado"
