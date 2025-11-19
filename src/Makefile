# Nombre del ejecutable final
TARGET = MiniCryptTool

# Carpeta donde se guardará el ejecutable
BINDIR = bin

# Compilador
CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

# Archivos fuente (nombre EXACTO del archivo)
SRCS = MiniCryptTool.cpp
OBJS = $(SRCS:.cpp=.o)

# Regla principal
all: $(BINDIR)/$(TARGET)

# Crear bin/ y compilar
$(BINDIR)/$(TARGET): $(OBJS)
	mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$(TARGET) $(OBJS)

# Limpiar objetos y binarios
clean:
	rm -f $(OBJS)
	rm -rf $(BINDIR)

# Limpieza total
distclean: clean

.PHONY: all clean distclean
