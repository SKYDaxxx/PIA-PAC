// MiniCryptTool.cpp
// Avances de cifrados simples (XOR y César).
// Si no se usa --in, el programa leerá la entrada estándar (stdin).

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

// ============================================================
// SECCIÓN 1: FUNCIONES DE UTILIDAD
// ============================================================

// Imprime un mensaje de error y termina el programa.
static void die(const std::string &msg) { 
    std::cerr << msg << "\n"; 
    std::exit(1); 
}

// Lee todo el contenido de un flujo de entrada (archivo o stdin) y lo devuelve como string.
// Se usa para cargar el texto que se va a cifrar o descifrar.
std::string read_all(std::istream &in) {
    std::string s, line;
    while (std::getline(in, line)) {
        s += line;
        if (!in.eof()) s += '\n';  // conserva los saltos de línea
    }
    return s;
}

// ============================================================
// SECCIÓN 2: CIFRADOS
// ============================================================

// --- XOR ---
// Cifra o descifra un texto aplicando XOR entre cada byte del texto y la clave.
// Si se usa la misma clave dos veces sobre el mismo texto, se recupera el original.
std::string xor_cipher(const std::string &input, const std::string &key) {
    if (key.empty()) return input; // sin cambio si no hay llave

    std::string out = input;
    for (size_t i = 0; i < out.size(); ++i) {
        // Se hace XOR con el carácter correspondiente de la clave (cíclicamente)
        out[i] = static_cast<char>(out[i] ^ key[i % key.size()]);
    }
    return out;
}

// --- Cifrado César ---
// Desplaza las letras del alfabeto una cantidad fija (shift).
// Solo afecta letras A-Z y a-z; los demás caracteres quedan igual.
std::string caesar_cipher(const std::string &input, int shift) {
    std::string out = input;
    for (char &c : out) {
        if (c >= 'a' && c <= 'z') {
            c = static_cast<char>((c - 'a' + shift + 26) % 26 + 'a');
        } else if (c >= 'A' && c <= 'Z') {
            c = static_cast<char>((c - 'A' + shift + 26) % 26 + 'A');
        }
        // otros caracteres (espacios, signos, números) no se modifican
    }
    return out;
}

// ============================================================
// SECCIÓN 3: INTERFAZ DE LÍNEA DE COMANDOS (CLI)
// ============================================================

int main(int argc, char **argv) {
    // Si no se pasan argumentos suficientes, muestra el uso.
    if (argc < 3) {
        std::cout << "Usage: " << argv[0]
                  << " --mode cipher --alg xor|caesar [--key KEY|--shift N] [--in file]\n";
        return 0;
    }

    // Variables para los parámetros del programa
    std::string mode, alg, key, infile;
    int shift = 0;

    // --- Parseo manual de argumentos ---
    // Se recorren los argumentos del programa para identificar opciones.
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "--mode") == 0 && i+1 < argc) { mode = argv[++i]; }
        else if (std::strcmp(argv[i], "--alg") == 0 && i+1 < argc) { alg = argv[++i]; }
        else if (std::strcmp(argv[i], "--key") == 0 && i+1 < argc) { key = argv[++i]; }
        else if (std::strcmp(argv[i], "--shift") == 0 && i+1 < argc) { shift = std::stoi(argv[++i]); }
        else if (std::strcmp(argv[i], "--in") == 0 && i+1 < argc) { infile = argv[++i]; }
        else if (std::strcmp(argv[i], "--help") == 0) {
            std::cout << "Options:\n"
                         "  --mode cipher            (único modo permitido por el momento)\n"
                         "  --alg xor|caesar         (elige el algoritmo)\n"
                         "  --key KEY                (clave para xor)\n"
                         "  --shift N                (desplazamiento para caesar, puede ser negativo)\n"
                         "  --in file                (archivo de entrada; por defecto usa stdin)\n";
            return 0;
        }
    }

    // Validaciones básicas de modo y algoritmo
    if (mode != "cipher") die("Only --mode cipher is supported for now. See --help");
    if (alg.empty()) die("--alg requerido. Use xor|caesar");

    // ============================================================
    // LECTURA DE DATOS DE ENTRADA
    // ============================================================
    std::string input;

    // Si se especificó un archivo, se lee desde él
    if (!infile.empty()) {
        std::ifstream f(infile, std::ios::binary);
        if (!f) die("Cannot open input file");
        input = read_all(f);
    } else {
        // Si no, se lee desde stdin (permite redirección o escritura directa)
        input = read_all(std::cin);
    }

    // ============================================================
    // EJECUCIÓN DEL CIFRADO SELECCIONADO
    // ============================================================

    if (alg == "xor") {
        if (key.empty()) die("xor requires --key");
        std::string out = xor_cipher(input, key);
        std::cout << out;  // imprime el resultado cifrado (o descifrado)
    } 
    else if (alg == "caesar") {
        std::string out = caesar_cipher(input, shift);
        std::cout << out;
    } 
    else {
        die("Unknown cipher algorithm (use xor|caesar)");
    }

    return 0;
}
