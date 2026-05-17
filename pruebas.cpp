#include <iostream>
#include<string>
using namespace std;

void registrardatos (string productos[], float precios[], int &cantidad)
{
    int i=0;
    cout<<"Ingrese la cantidad de productos"<<endl;
    cin>>cantidad;
    while (cantidad<1 || cantidad>10)
        {
            cout<<"Error, ingrese un valor entre 1 y 10"<<endl;
            cin>>cantidad;
        }
    cout<<"Ingrese sus productos"<<endl;
        for(i=0;i<cantidad;i++)
        {
            cout<<"Producto "<<i+1<<endl;
            cin>>productos[i];

            cout<<"Precio"<<endl;
            cin>>precios[i];
            while(precios[i]<0)
            {
                cout<<"Error, ingrese un numero positivo"<<endl;
                cin>>precios[i];
            }
        }       
}






 int main ()
 {
    string productos[10];
    float precios[10];
    int cantidad;

    registrardatos (productos, precios, cantidad);

    return 0;

 }
