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
    ~Campo2D(); // Destructor (No es el que destruye xd)
    void redimensionar(int nuevaF, int nuevaC);
    void setValor(int f, int c, T valor);
    T getValor(int f, int c);
    T calcularGradientePromedio(int inicioF, int finF, int inicioC, int finC);
    void mostrarGrid();
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
Campo2D<T>::~Campo2D() {
    for (int i = 0; i < _filas; i++) {
        delete[] _datos[i];
    }
    delete[] _datos;
}

template <typename T>
void Campo2D<T>::setValor(int f, int c, T valor) {
    if (f >= 0 && f < _filas && c >= 0 && c < _columnas) {
        _datos[f][c] = valor;
    } else {
        std::cout << "Error: Índices fuera de rango." << std::endl;
    }
}

template <typename T>
T Campo2D<T>::getValor(int f, int c) {
    if (f >= 0 && f < _filas && c >= 0 && c < _columnas) {
        return _datos[f][c];
    } else {
        std::cout << "Error: Índices fuera de rango. Retornando 0." << std::endl;
        return T();
    }
}

template <typename T>
void Campo2D<T>::redimensionar(int nuevaF, int nuevaC) {
    // Creaando mis auxiliares de tipo matrices bidimension
    T **nuevosDatos = new T*[nuevaF];
    for (int i = 0; i < nuevaF; i++) {
        nuevosDatos[i] = new T[nuevaC];
        for (int j = 0; j < nuevaC; j++) {
            nuevosDatos[i][j] = T();
        }
    }
    
    // Copiar datos existentes para pasarlos al auxiliar
    
    int minFilas = (_filas < nuevaF) ? _filas : nuevaF;
    int minColumnas = (_columnas < nuevaC) ? _columnas : nuevaC;
    
    for (int i = 0; i < minFilas; i++) {
        for (int j = 0; j < minColumnas; j++) {
            nuevosDatos[i][j] = _datos[i][j];
        }
    }
    
    // Liberar memoria antigua
    for (int i = 0; i < _filas; i++) {
        delete[] _datos[i];
    }
    delete[] _datos;
    
    // Asignar nueva matriz
    _datos = nuevosDatos;
    _filas = nuevaF;
    _columnas = nuevaC;
    
    std::cout << "Datos copiados. Memoria antigua liberada." << std::endl;
}

template <typename T>
T Campo2D<T>::calcularGradientePromedio(int inicioF, int finF, int inicioC, int finC) {
    // Validar límites
    if (inicioF < 0 || finF >= _filas || inicioC < 0 || finC >= _columnas ||
        inicioF > finF || inicioC > finC) {
        std::cout << "Error: Límites de submatriz inválidos." << std::endl;
        return T();
    }
    
    T sumaGradientes = T();
    int contadorPuntos = 0;
    
    // Recorrer cada celda
    for (int i = inicioF; i <= finF; i++) {
        for (int j = inicioC; j <= finC; j++) {
            T gradienteLocal = T();
            int vecinosContados = 0;
            
            // Calcular diferencia con vecino derecho
            if (j + 1 <= finF && j + 1 < _columnas) {
                T diferencia = _datos[i][j + 1] - _datos[i][j];
                gradienteLocal += (diferencia < 0) ? -diferencia : diferencia;
                vecinosContados++;
            }
            
            // Calcular diferencia con vecino inferior
            if (i + 1 <= finF && i + 1 < _filas) {
                T diferencia = _datos[i + 1][j] - _datos[i][j];
                gradienteLocal += (diferencia < 0) ? -diferencia : diferencia;
                vecinosContados++;
            }
            
            // Si hay vecinos, calcular el promedio
            if (vecinosContados > 0) {
                sumaGradientes += gradienteLocal / vecinosContados;
                contadorPuntos++;
            }
        }
    }
    
  



    
    if (contadorPuntos > 0) {
        return sumaGradientes / contadorPuntos;
    }
    return T();
}

template <typename T>
void Campo2D<T>::mostrarGrid() {
    std::cout << "\nGrid Actual:\n";
    for (int i = 0; i < _filas; i++) {
        std::cout << "|";
        for (int j = 0; j < _columnas; j++) {
            std::cout << " " << _datos[i][j] << " |";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "--- Simulador Genérico de Campo 2D ---\n";
    std::cout << "Inicializando Campo Gravitatorio (Tipo FLOAT)\n";
    std::cout << "Creando Grid (FLOAT) de 3x3...\n";

    Campo2D<float> campo(3, 3);

    std::cout << "Estableciendo valores iniciales...\n";
    campo.setValor(0, 0, 10.0f); campo.setValor(0, 1, 8.0f); campo.setValor(0, 2, 5.0f);
    campo.setValor(1, 0, 12.0f); campo.setValor(1, 1, 9.0f); campo.setValor(1, 2, 6.0f);
    campo.setValor(2, 0, 15.0f); campo.setValor(2, 1, 11.0f); campo.setValor(2, 2, 7.0f);

    campo.mostrarGrid();

    bool seguirCorriendoPrograma = true;
    int selectOption = 0;

    while (seguirCorriendoPrograma) {
        std::cout << "\n1) Calcular Gradiente Promedio\n";
        std::cout << "2) Redimensionar\n";
        std::cout << "3) Mostrar Grid\n";
        std::cout << "4) Salir\n";
        std::cout << "Seleccione opción: ";
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
                std::cout << "\n";

                std::cout << "Calculando Gradiente Promedio en la región [" << iF << "," << fF << "]x[" << iC << "," << fC << "]...\n";
                
                float gradiente = campo.calcularGradientePromedio(iF, fF, iC, fC);
                
                std::cout << "Gradiente Promedio calculado: " << gradiente << " unidades/metro.\n";
                break;
            }
            case 2: {
                int nuevaF, nuevaC;
                std::cout << "Ingrese nuevas dimensiones (filas columnas): ";
                std::cin >> nuevaF >> nuevaC;
                
                if (nuevaF > 0 && nuevaC > 0) {
                    std::cout << "Redimensionando Grid a " << nuevaF << "x" << nuevaC << "...\n";
                    campo.redimensionar(nuevaF, nuevaC);
                    campo.mostrarGrid();
                } else {
                    std::cout << "Error: Las dimensiones deben ser positivas.\n";
                }
                break;
            }
            case 3: {
                campo.mostrarGrid();
                break;
            }
            case 4: {
                seguirCorriendoPrograma = false;
                std::cout << "Destructor invocado. Liberando memoria de la Matriz 2D...\n";
                std::cout << "Sistema cerrado.\n";
                break;
            }
            default:
                std::cout << "ERROR: Opcion no valida compadre.\n";
                break;
        }
    }

    return 0;
}