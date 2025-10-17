#include <iostream>
#include <cmath>

template <typename T>
class Campo2D {
private:
    T **_datos;
    int _filas;
    int _columnas;

public:
    Campo2D(int f, int c); // Constructor
    ~Campo2D(); // Destructor (no destruye literalmente xd)
    void redimensionar(int nuevaF, int nuevaC);
    void setValor(int f, int c, T valor);
    T calcularGradientePromedio(int inicioF, int finF, int inicioC, int finC){
        
    };
    // ... otros métodos

    
};

template <typename T>
Campo2D<T>::Campo2D(int f, int c) {

    _filas = f;
    _columnas = c;

    _datos = new T*[_filas];
    
    for (int i = 0; i < _filas; i++) {
        _datos[i] = new T[_columnas];
        
        for (int j = 0; j < _columnas; j++) {
            _datos[i][j] = T();
        }
    }
    
    std::cout << "¡Campo2D de " << _filas << "x" << _columnas << " creado exitosamente!" << std::endl;
}

template <typename T>
Campo2D<T>::~Campo2D() { //No sea flojo y empieze a destruir (librerar memoria) jsk
    for (int i = 0; i < _filas; i++)
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

    Campo2D<float> campo(3, 3);

    std::cout << "Estableciendo valores iniciales...\n";
    campo.setValor(0, 0, 10.0f); campo.setValor(0, 1, 8.0f); campo.setValor(0, 2, 5.0f);
    campo.setValor(1, 0, 12.0f); campo.setValor(1, 1, 9.0f); campo.setValor(1, 2, 6.0f);
    campo.setValor(2, 0, 15.0f); campo.setValor(2, 1, 11.0f); campo.setValor(2, 2, 7.0f);

    bool seguirCorriendoPrograma = true;
    int selectOption = 0;

    while (seguirCorriendoPrograma) {
        std::cout << "\n1) Calcular Gradiente Promedio\n";
        std::cout << "2) Redimensionar\n";
        std::cout << "3) Salir\n";
        std::cin >> selectOption;

        switch (selectOption) {
            case 1: {
                int iF, fF, iC, fC;
                std::cout << "Ingrese Fila Inicial: ";
                std::cin >> iF;
                std::cout << "Ingrese Fila Final: ";
                std::cin >> fF;
                std::cout << "Ingrese Columna Inicial: ";
                std::cin >> iC;
                std::cout << "Ingrese Columna Final: ";
                std::cin >> fC;

                std::cout << "Calculando Gradiente Promedio en la región [" << iF << "," << fF << "]x[" << iC << "," << fC << "]...\n";
                
                double gradiente = campo.calcularGradientePromedio(iF, fF, iC, fC);
                
                std::cout << "Gradiente Promedio calculado: " << gradiente << " unidades/metro.\n";
                break;
            }
            case 2: {
                std::cout << "Opción de redimensionar aún no implementada.\n";
                break;
            }
            case 3: {
                seguirCorriendoPrograma = false;
                std::cout << "Destructor invocado. Liberando memoria de la Matriz 2D...\n";
                std::cout << "Sistema cerrado.\n";
                break;
            }
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
                break;
        }
    } // FIN DEL BUCLE WHILE

    return 0;
}