#include <iostream>


template <typename T>
class Campo2D {
public:
    Campo2D(int f, int c);
    ~Campo2D();
private:
    T **_datos;
    int _filas;
    int _columnas;

};

template <typename T>
Campo2D<T>::Campo2D(int f, int c) {

    // Guardar las dimensiones
    _filas = f;
    _columnas = c;

    // Crear el array de punteros a filas
    _datos = new T*[_filas];
    
    // Para cada puntero, crear una fila de datos
    for (int i = 0; i < _filas; i++) {
        _datos[i] = new T[_columnas];
        
        // Limpiar la fila (opcional pero recomendado)
        for (int j = 0; j < _columnas; j++) {
            _datos[i][j] = T();
        }
    }
    
    std::cout << "¡Campo2D de " << _filas << "x" << _columnas << " creado exitosamente!" << std::endl;
}

template <typename T>
Campo2D<T>::~Campo2D() {
    for (int i = 0; i < _filas - 1; i++)
    {
        delete[] _datos[i];
    }
    delete[] _datos;
}
bool seguirCorriendoPrograma = true;
int main() {
      std::cout << "--- Simulador Genérico de Campo 2D ---\n"; 
      std::cout << "Inicializando Campo Gravitatorio (Tipo FLOAT)\n";
std::cout << "Creando Grid (FLOAT) de 3x3...\n";
std::cout << "Estableciendo valores iniciales...\n";
int selectOption = 0;

    while (true)
    {

std::cout << "1) Calcular Gradiente Promedio\n";
std::cout << "2) Redimensionar\n";
std::cout << "3) Redimensionar (A una dimensión menor)\n";
std::cout << "4) Salir\n";
    std::cin >> selectOption;
switch (selectOption)
{
case 1:{

     /* code */
    break;
}
   
case 2:{

     /* code */
    break;
}

case 3:{

     /* code */
    break;
}

case 4:{
    seguirCorriendoPrograma = false;
    std::cout << "Destructor invocado. Liberando memoria de la Matriz 2D...\n";
std:: cout << "Sistema cerrado.";
    break;
}

default:
    break;
}

    }//BUCLE WHILE

    std::cout << "Creando un campo de enteros...\n" << std::endl;
    Campo2D<int> campoDeEnteros(3, 4);

    std::cout << "\nCreando un campo de flotantes..." << std::endl;
    Campo2D<float> campoDeFlotantes(5, 10);
    return 0;
}