#include <iostream>
#include <array>

// Añadir std para fácil llamado de funciones
using namespace std;

//// Declaración de funciones
//Definimos un template (un tipo de dato) para nuestra matriz
template <typename matriz>
void LlenarMatriz(matriz & miMatriz);

template <typename matriz>
void ImprimirMatriz(matriz & miMatriz);

template <typename matriz>
void GaussJordan(matriz & miMatriz);

template <typename matriz>
void ImprimirSolucion(matriz & miMatriz);

template <typename matriz>
void multEscalar(matriz & miMatriz);

template <typename matriz>
void sumaRenglones(matriz & miMatriz);

template <typename matriz>
void Jordan(matriz & miMatriz);

template <typename matriz>
void cambioRenglones(matriz & miMatriz);

int main()
{
    // Definimos el número de variables de nuestro sistema
    const int variables = 3;
    // El número de columnas será el número de variables más su solición para cada ecuación
    const int columnas = variables + 1;

    // Inicializamos la matriz que vamos a ocupar
    array <array<float, columnas>, variables> miMatriz = { 0 };

    // Pedimos al usuario que llene la matriz
    LlenarMatriz(miMatriz);

    // Aplicamos el método de Gauss-Jordan sobre nuestra matriz
    GaussJordan(miMatriz);



    // Imprimimos la solución de la matriz
    ImprimirSolucion(miMatriz);

    return 0; // Indicamos que salimos del programa con éxito
}

/*
Llena 'miMatriz' con valores ingresados por el usuario para cada elemento.
No regresa ningún valor.
*/
template <typename matriz>
void LlenarMatriz(matriz & miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        for (int j = 0; j <= variables; j++) {
            cout << "Valor elemento [" << i << "][" << j << "]: ";
            cin >> miMatriz[i][j];
        }
    }
}

/*
Imprime cada elemento de 'miMatriz' emulando una matriz con corchetes cuadrados.
No regresa ningún valor.
*/
template <typename matriz>
void ImprimirMatriz(matriz & miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        cout << "[ ";
        for (int j = 0; j < variables + 1; j++)
            cout << miMatriz[i][j] << '\t';
        cout << "]\n";
    }
}

/*
Imprime en pantalla la solución para cada variable del sistema de ecuaciones correspondiente a los valores en 'miMatriz'.
No regresa ningún valor.
*/
template <typename matriz>
void ImprimirSolucion(matriz & miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        cout << "x" << i << " = " << miMatriz[i][variables] << "\n";
    }
}

/*
Implementa el algoritmo de Gauss-Jordan sobre 'miMatriz', finalizando en ella la solución del algoritmo.
No regresa ningún valor.
*/
template <typename matriz>
void GaussJordan(matriz & miMatriz)
{
    cambioRenglones(miMatriz);
    sumaRenglones(miMatriz);
    Jordan(miMatriz);
    multEscalar(miMatriz);
}

template <typename matriz>
void multEscalar(matriz & miMatriz){
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        for (int j = 0; j <= variables; j++) {
            if((i==j) & (miMatriz[i][j] !=1) ){
                float l=miMatriz[i][j];
                for(int k=j; k<= variables; k++)
                    miMatriz[i][k] *= (1/l);
            }
        }
    }
}

template <typename matriz>
void sumaRenglones(matriz & miMatriz){
    int variables = miMatriz.size();
    float m=0, n=0;
    for (int j = 0; j <= variables; j++) {
        for (int i = 0; i< variables; i++) {
            if(i==j){
                m= i;
                n= miMatriz[i][j];
            }
            if((i>j) & (miMatriz[i][j] !=0) ){
                float l= miMatriz[i][j];
                for(int k=0; k<= variables; k++)
                    miMatriz[i][k] = miMatriz[i][k] - ((miMatriz[m][k] * l)/n);
            }
        }
    }
}

template <typename matriz>
void cambioRenglones(matriz & miMatriz) {
    int variables = miMatriz.size();
    const int columnas= 4;
    array<float, columnas> C = {0};
    for (int i = 0; i < variables; i++) {
        int contador=0;
        for (int j = 0; j <= variables; j++) {
            if(miMatriz[i][j] == 0){
                contador++;
            }else {
                for(int k=0; k <= variables; k++){
                    C[k]= miMatriz[contador][k];
                    miMatriz[contador][k]=miMatriz[i][k];
                    miMatriz[i][k]=C[k];
                }
            }
        }
    }
}

template <typename matriz>
void Jordan(matriz & miMatriz){
    int variables = miMatriz.size();
    float m=0, n=0;
    for (int j = variables-1; j >= 0; j--) {
        for (int i = variables-1; i>=0; i--) {
            if(i==j){
                m= i;
                n= miMatriz[i][j];
            }
            if((i<j) & (miMatriz[i][j] !=0) ){
                float l= miMatriz[i][j];
                for(int k=0; k<= variables; k++)
                    miMatriz[i][k] = miMatriz[i][k] - ((miMatriz[m][k] * l)/n);
            }
        }
    }
}
