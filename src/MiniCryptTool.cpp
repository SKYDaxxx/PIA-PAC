// MiniCryptTool
// Ejecutable didáctico: cifrados simples (xor, caesar) + hashes (djb2, fnv1a).
// Uso general:
//   ./minicrypttool --mode cipher|hash --alg xor|caesar|djb2|fnv1a [--key KEY] [--shift N] [--in file]

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdint>
#include <iomanip>
#include <sstream>
#include <cstdlib>

// ---------------------------------------------------------------------------
// Utilidades generales
// ---------------------------------------------------------------------------

// Imprime un mensaje de error en stderr y termina el programa con código 1.
static void die(const std::string &msg) {
    std::cerr << "[ERROR] " << msg << "\n";
    std::exit(1);
}

// Muestra la ayuda/uso del programa.
void print_usage(const char *progname) {
    std::cout
        << "Uso:\n  " << progname
        << " --mode cipher|hash --alg xor|caesar|djb2|fnv1a"
        << " [--key KEY] [--shift N] [--in file]\n\n"
        << "Opciones:\n"
        << "  --mode cipher|hash       Modo de operación: cifrado o hash.\n"
        << "  --alg xor|caesar|djb2|fnv1a\n"
        << "                           Algoritmo a utilizar.\n"
        << "  --key KEY                Llave para cifrado XOR.\n"
        << "  --shift N                Desplazamiento (entero, puede ser negativo) para Caesar.\n"
        << "  --in file                Archivo de entrada (por defecto stdin).\n"
        << "  --help                   Muestra esta ayuda.\n\n"
        << "Ejemplos:\n"
        << "  echo \"hola\" | " << progname << " --mode cipher --alg xor --key secreto\n"
        << "  echo \"hola\" | " << progname << " --mode cipher --alg caesar --shift 3\n"
        << "  echo \"hola\" | " << progname << " --mode hash   --alg djb2\n";
}

// Lee todo el contenido de un std::istream y lo devuelve como std::string.
// Este patrón permite leer tanto de archivos como de stdin de forma genérica.
std::string read_all(std::istream &in) {
    std::string s;
    std::string line;
    while (std::getline(in, line)) {
        s += line;
        if (!in.eof()) s += '\n';
    }
    return s;
}

// Convierte un std::string en un vector de bytes (uint8_t).
std::vector<uint8_t> to_bytes(const std::string &s) {
    return std::vector<uint8_t>(s.begin(), s.end());
}

// Convierte un vector de bytes a una cadena en hexadecimal (ej: "486f6c61" para "Hola").
std::string bytes_to_hex(const std::vector<uint8_t> &b) {
    std::ostringstream oss;
    oss << std::hex << std::setfill('0');
    for (uint8_t x : b) {
        oss << std::setw(2) << static_cast<int>(x);
    }
    return oss.str();
}

// ---------------------------------------------------------------------------
// Cifrados
// ---------------------------------------------------------------------------

// Cifrado (o descifrado) XOR simple.
// - Recorre cada carácter de 'input' y lo XORea con la llave (repitiéndola si es más corta).
// - Si la llave está vacía, devuelve el texto original sin cambios.
std::string xor_cipher(const std::string &input, const std::string &key) {
    if (key.empty()) return input; // sin cambio si no hay llave

    std::string out = input;
    const size_t key_len = key.size();

    for (size_t i = 0; i < out.size(); ++i) {
        out[i] = static_cast<char>(out[i] ^ key[i % key_len]);
    }
    return out;
}

// Cifrado César (solo letras A-Z / a-z).
// - Desplaza las letras dentro del rango alfabético (26 letras).
// - No modifica otros caracteres (espacios, signos, números, etc.).
std::string caesar_cipher(const std::string &input, int shift) {
    std::string out = input;

    // Normalizamos el shift para que esté en el rango [-25, 25]
    // (no es estrictamente necesario, pero evita dar más vueltas).
    shift %= 26;

    for (char &c : out) {
        if (c >= 'a' && c <= 'z') {
            c = static_cast<char>((c - 'a' + shift + 26) % 26 + 'a');
        } else if (c >= 'A' && c <= 'Z') {
            c = static_cast<char>((c - 'A' + shift + 26) % 26 + 'A');
        }
        // otros caracteres no se cambian
    }
    return out;
}

// ---------------------------------------------------------------------------
// Hashes educativos
// ---------------------------------------------------------------------------

// Hash DJB2 (versión simple, didáctica).
// No debe usarse para seguridad real, solo fines educativos.
uint64_t djb2_hash(const std::string &s) {
    uint64_t hash = 5381;
    for (unsigned char c : s) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}

// Hash FNV-1a 64-bit (didáctico).
// Igual que con DJB2, solo para fines de aprendizaje.
uint64_t fnv1a_hash(const std::string &s) {
    const uint64_t FNV_OFFSET = 14695981039346656037ULL;
    const uint64_t FNV_PRIME  = 1099511628211ULL;

    uint64_t hash = FNV_OFFSET;
    for (unsigned char c : s) {
        hash ^= c;
        hash *= FNV_PRIME;
    }
    return hash;
}

// ---------------------------------------------------------------------------
// Punto de entrada (main)
// ---------------------------------------------------------------------------

int main(int argc, char **argv) {
    // Validación mínima: si no hay suficientes argumentos, mostramos ayuda.
    if (argc < 3) {
        print_usage(argv[0]);
        return 0;
    }

    std::string mode;     // "cipher" o "hash"
    std::string alg;      // "xor", "caesar", "djb2", "fnv1a"
    std::string key;      // llave para xor
    std::string infile;   // nombre de archivo de entrada
    int shift = 0;        // desplazamiento para caesar

    // -----------------------------------------------------------------------
    // Parseo simple de argumentos de línea de comandos (sin librerías extra)
    // -----------------------------------------------------------------------
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "--mode") == 0 && i+1 < argc) {
            mode = argv[++i];
        } else if (std::strcmp(argv[i], "--alg") == 0 && i+1 < argc) {
            alg = argv[++i];
        } else if (std::strcmp(argv[i], "--key") == 0 && i+1 < argc) {
            key = argv[++i];
        } else if (std::strcmp(argv[i], "--shift") == 0 && i+1 < argc) {
            // std::stoi lanza excepción si es inválido, podríamos capturarla,
            // pero para mantenerlo simple asumimos entrada correcta.
            shift = std::stoi(argv[++i]);
        } else if (std::strcmp(argv[i], "--in") == 0 && i+1 < argc) {
            infile = argv[++i];
        } else if (std::strcmp(argv[i], "--help") == 0) {
            print_usage(argv[0]);
            return 0;
        } else {
            // Argumento desconocido: lo reportamos pero no abortamos de inmediato
            // para no ser tan agresivos. En un programa real, podríamos hacer die().
            std::cerr << "[ADVERTENCIA] Opción desconocida: " << argv[i] << "\n";
        }
    }

    // Validaciones básicas de los parámetros obligatorios
    if (mode.empty() || alg.empty()) {
        die("Se requieren --mode y --alg. Usa --help para más información.");
    }

    // -----------------------------------------------------------------------
    // Lectura de entrada: desde archivo (--in) o stdin por defecto.
    // -----------------------------------------------------------------------
    std::string input;

    if (!infile.empty()) {
        std::ifstream f(infile, std::ios::binary);
        if (!f) {
            die("No se pudo abrir el archivo de entrada: " + infile);
        }
        input = read_all(f);
    } else {
        // Si no se especifica archivo, leemos desde stdin.
        // Ejemplo: echo "hola" | ./minicrypttool --mode hash --alg fnv1a
        input = read_all(std::cin);
    }

    // -----------------------------------------------------------------------
    // Ejecución lógica según el modo: cipher o hash
    // -----------------------------------------------------------------------
    if (mode == "cipher") {
        // ---------------------- MODO CIFRADO -------------------------------
        if (alg == "xor") {
            if (key.empty()) {
                die("El cifrado xor requiere una llave (--key).");
            }
            std::string out = xor_cipher(input, key);

            // Opcional: si quisieras ver el resultado en hex, podrías descomentar:
            // auto bytes = to_bytes(out);
            // std::cout << bytes_to_hex(bytes) << "\n";

            // Por ahora, escribimos el resultado tal cual (texto/bytes crudos).
            std::cout << out;

        } else if (alg == "caesar") {
            std::string out = caesar_cipher(input, shift);
            std::cout << out;

        } else {
            die("Algoritmo de cifrado desconocido: " + alg);
        }

    } else if (mode == "hash") {
        // ---------------------- MODO HASH ----------------------------------
        uint64_t h = 0;

        if (alg == "djb2") {
            h = djb2_hash(input);
        } else if (alg == "fnv1a") {
            h = fnv1a_hash(input);
        } else {
            die("Algoritmo de hash desconocido: " + alg);
        }

        // Mostramos el hash en hexadecimal.
        std::cout << std::hex << h << "\n";

    } else {
        die("Modo desconocido: " + mode + " (usa 'cipher' o 'hash').");
    }

    return 0;
}