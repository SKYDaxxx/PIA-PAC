## Notas de Análisis Estático — Observaciones del Comportamiento de Ghidra

Al analizar el binario con Ghidra, la función main no se muestra exactamente igual que en el código fuente original, debido al proceso de compilación.
El compilador transforma las estructuras de alto nivel (for, if, nombres de variables como mode, alg, etc.) en instrucciones de máquina sin nombres ni comentarios.
Ghidra, a partir de ese ensamblador, intenta reconstruir una representación en C++, pero:

Asigna nombres genéricos a las variables locales (local_1d8, local_238) porque los nombres originales no están en el binario.

Expande las llamadas a constructores y destructores de std::string y std::ifstream, mostrando explícitamente las funciones internas de la librería estándar.

Reorganiza los bucles y condiciones (por ejemplo, mostrando un do-while donde en el código original había un for, o expresando la condición mode.empty() || alg.empty() de forma lógica equivalente pero distinta).

Incluye detalles del ABI de C++ (std::__cxx11, __main, __new_allocator) que normalmente no se observan en el código fuente.

A pesar de estas diferencias sintácticas, la lógica reconstruida por Ghidra es equivalente a la del código fuente: valida argc, inicializa las cadenas mode, alg, key, infile, procesa los argumentos de línea de comandos y, finalmente, comprueba que mode y alg no estén vacíos antes de continuar.

---

## Código Reconstruido por Ghidra (Función main)

```cpp
int __cdecl main(int _Argc,char **_Argv,char **_Env)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  ostream *poVar5;
  istream local_448 [224];
  ios aiStack_368 [272];
  string local_258 [32];
  string local_238 [32];
  string local_218 [32];
  string local_1f8 [32];
  string local_1d8 [32];
  string local_1b8 [47];
  undefined1 local_189;
  string local_188 [47];
  undefined1 local_159;
  string local_158 [32];
  string local_138 [32];
  string local_118 [32];
  string local_f8 [47];
  undefined1 local_c9;
  string local_c8 [32];
  string local_a8 [32];
  string local_88 [32];
  string local_68 [40];
  undefined1 *local_40;
  undefined1 *local_38;
  undefined1 *local_30;
  ulonglong local_28;
  int local_20;
  int local_1c;
  
  __main();
  if (_Argc < 3) {
    print_usage(*_Argv);
    return 0;
  }
  std::__cxx11::string::string(local_1d8);
  std::__cxx11::string::string(local_1f8);
  std::__cxx11::string::string(local_218);
  std::__cxx11::string::string(local_238);
  local_1c = 0;
  local_20 = 1;
  do {
    if (_Argc <= local_20) {
      uVar4 = std::__cxx11::string::empty(local_1d8);
      if (((char)uVar4 == '\0') &&
         (uVar4 = std::__cxx11::string::empty(local_1f8), (char)uVar4 == '\0')) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        local_38 = &local_159;
        std::__cxx11::string::string<>(local_188,&DAT_140008300);
        die(local_188);
        std::__cxx11::string::~string(local_188);
        std::__new_allocator<char>::~__new_allocator();
      }
      std::__cxx11::string::string(local_258);
      uVar4 = std::__cxx11::string::empty(local_238);
      if ((char)uVar4 == '\x01') {
        read_all[abi:cxx11](local_118,(istream *)&_ZSt3cin);
        std::__cxx11::string::operator=(local_258,local_118);
        std::__cxx11::string::~string(local_118);
      }
      else {
        std::ifstream::ifstream();
        cVar2 = std::ios::operator!(aiStack_368);
        if (cVar2 != '\0') {
          std::operator+(local_158,"No se pudo abrir el archivo de entrada: ",local_238);
          die(local_158);
          std::__cxx11::string::~string(local_158);
        }
        read_all[abi:cxx11](local_138,local_448);
        std::__cxx11::string::operator=(local_258,local_138);
        std::__cxx11::string::~string(local_138);
        std::ifstream::~ifstream((ifstream *)local_448);
      }
      uVar4 = std::operator==(local_1d8,"cipher");
      if ((char)uVar4 == '\0') {
        uVar4 = std::operator==(local_1d8,"hash");
        if ((char)uVar4 == '\0') {
          std::operator+(local_68,"Modo desconocido: ",local_1d8);
          std::operator+(local_88,local_68," (usa \'cipher\' o \'hash\').");
          die(local_88);
          std::__cxx11::string::~string(local_88);
          std::__cxx11::string::~string(local_68);
        }
        else {
          local_28 = 0;
          uVar4 = std::operator==(local_1f8,"djb2");
          if ((char)uVar4 == '\0') {
            uVar4 = std::operator==(local_1f8,"fnv1a");
            if ((char)uVar4 == '\0') {
              std::operator+(local_a8,"Algoritmo de hash desconocido: ",local_1f8);
              die(local_a8);
              std::__cxx11::string::~string(local_a8);
            }
            else {
              local_28 = fnv1a_hash(local_258);
            }
          }
          else {
            local_28 = djb2_hash(local_258);
          }
          poVar5 = (ostream *)std::ostream::operator<<((ostream *)&_ZSt4cout,std::hex);
          poVar5 = (ostream *)std::ostream::operator<<(poVar5,local_28);
          std::operator<<(poVar5,"\n");
        }
      }
      else {
        uVar4 = std::operator==(local_1f8,"xor");
        if ((char)uVar4 == '\0') {
          uVar4 = std::operator==(local_1f8,"caesar");
          if ((char)uVar4 == '\0') {
            std::__operator+(local_c8,"Algoritmo de cifrado desconocido: ",local_1f8);
            die(local_c8);
            std::__cxx11::string::~string(local_c8);
          }
          else {
            caesar_cipher((string *)local_448,local_258,local_1c);
            std::operator<<((ostream *)&_ZSt4cout,(string *)local_448);
            std::__cxx11::string::~string((string *)local_448);
          }
        }
        else {
          uVar4 = std::__cxx11::string::empty(local_218);
          if ((char)uVar4 != '\0') {
            local_40 = &local_c9;
            std::__cxx11::string::string<>(local_f8,"El cifrado xor requiere una llave (--key).");
            die(local_f8);
            std::__cxx11::string::~string(local_f8);
            std::__new_allocator<char>::~__new_allocator();
          }
          xor_cipher((string *)local_448,local_258,local_218);
          std::operator<<((ostream *)&_ZSt4cout,(string *)local_448);
          std::__cxx11::string::~string((string *)local_448);
        }
      }
      std::__cxx11::string::~string(local_258);
LAB_140002582:
      std::__cxx11::string::~string(local_238);
      std::__cxx11::string::~string(local_218);
      std::__cxx11::string::~string(local_1f8);
      std::__cxx11::string::~string(local_1d8);
      return 0;
    }
    iVar3 = strcmp(_Argv[local_20],"--mode");
    if ((iVar3 == 0) && (local_20 + 1 < _Argc)) {
      local_20 = local_20 + 1;
      std::__cxx11::string::operator=(local_1d8,_Argv[local_20]);
    }
    else {
      iVar3 = strcmp(_Argv[local_20],"--alg");
      if ((iVar3 == 0) && (local_20 + 1 < _Argc)) {
        local_20 = local_20 + 1;
        std::__cxx11::string::operator=(local_1f8,_Argv[local_20]);
      }
      else {
        iVar3 = strcmp(_Argv[local_20],"--key");
        if ((iVar3 == 0) && (local_20 + 1 < _Argc)) {
          local_20 = local_20 + 1;
          std::__cxx11::string::operator=(local_218,_Argv[local_20]);
        }
        else {
          iVar3 = strcmp(_Argv[local_20],"--shift");
          if ((iVar3 == 0) && (local_20 + 1 < _Argc)) {
            local_30 = &local_189;
            local_20 = local_20 + 1;
            std::__cxx11::string::string<>(local_1b8,_Argv[local_20]);
            local_1c = std::__cxx11::stoi(local_1b8,(longlong *)0x0,10);
            std::__cxx11::string::~string(local_1b8);
            std::__new_allocator<char>::~__new_allocator();
          }
          else {
            iVar3 = strcmp(_Argv[local_20],"--in");
            if ((iVar3 == 0) && (local_20 + 1 < _Argc)) {
              local_20 = local_20 + 1;
              std::__cxx11::string::operator=(local_238,_Argv[local_20]);
            }
            else {
              iVar3 = strcmp(_Argv[local_20],"--help");
              if (iVar3 == 0) {
                print_usage(*_Argv);
                goto LAB_140002582;
              }
              poVar5 = std::operator<<((ostream *)&_ZSt4cerr,&DAT_1400082d8);
              poVar5 = std::operator<<(poVar5,_Argv[local_20]);
              std::operator<<(poVar5,"\n");
            }
          }
        }
      }
    }
    local_20 = local_20 + 1;
  } while( true );
}