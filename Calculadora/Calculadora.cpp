//Author: Jorge Antonio Montes Ríos
//Montes.24@comunidad.unam.mx
//28 sept, 2022

#include <iostream>

using namespace std;

int main(){
    float primernumero=0;
    float segundonumero=0;
    int primnum;
    int segnum;
    char operacion;
    char i= '1';

    cout << "--Calculadora--"<< "\n"<< "Resuleve operaciones basicas"<< endl;

    while(i == '1'){

        cout << "Ingrese la operacion\n" << endl;
        cout << "Primer numero:";
        cin >> primernumero;
        cout << "Operacion:";
        cin >> operacion;
        cout << "segundo numero:";
        cin >> segundonumero;

        switch(operacion){
            case '+':
                cout  << "\nResultado:\n" << primernumero << " + " << segundonumero << " = " << primernumero + segundonumero << endl;
                break;
            case '-':
                cout << "\nResultado:\n" << primernumero << " - " << segundonumero << " = " << primernumero - segundonumero << endl;
                break;
            case '*' :
                cout << "\nResultado:\n" << primernumero << " * " << segundonumero << " = " << primernumero * segundonumero << endl;
                break;
            case '/':
                if(segundonumero != 0){
                    cout << "\nResultado:\n" << primernumero << " / " << segundonumero << " = " << primernumero / segundonumero << endl;
                    break;
                }
                else{
                    cout << "Math Error" << endl;
                    break;
                }

            case '%':
                primnum= int(primernumero);
                segnum= int(segundonumero);
                //cout << "si los numeros ingresados son reales, fueron transformados a enteros para realizar la operacion"<<endl;
                cout << "\nResultado:\n" << primnum << " % " << segnum << " = " << primnum % segnum << endl;
                break;

            default:
                cout << "La operacion no es valida"<< endl;
                break;
        }

        cout << "\nPresione 1 para repetir o cualquier tecla para salir"<< endl;
        cin >> i;
    }
}
