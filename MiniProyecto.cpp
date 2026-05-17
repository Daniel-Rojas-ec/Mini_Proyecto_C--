//Creamos nuestras funciones
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

void mostrardatos(string productos[], float precios[], int &cantidad)
{
    int i=0;
    for(i=0;i<cantidad;i++)
    {
        cout<<productos[i]<<" - "<<" Precio: "<<"$"<<precios[i]<<endl;
    }
}

float sumatotal(float precios[], int &cantidad)
{
    int i=0;
    float suma=0;
    for(i=0;i<cantidad;i++)
    {
        suma=suma+precios[i];
    }

    return suma;
}

float promedio (float precios[], int &cantidad)
{
    int i=0;
    float suma;

        suma=sumatotal(precios,cantidad);

    return suma/cantidad;
}

void buscarproducto(string productos[], float precios[], int &cantidad)
{
    int i =0;
    bool encontrado =false;
    string nombre;

    cout<<"Ingrese producto que desea buscar"<<endl;
    cin>>nombre;
    for(i=0;i<cantidad;i++)
    {
        if( nombre == productos[i])
        {
            encontrado=true;
            cout<<"Producto encontrado"<<endl;
            cout<<nombre<<endl;
            cout<<"Precio: "<<"$"<<precios[i]<<endl;
        }
    }
    if (encontrado==false)
    {
        cout<<"Producto no encontrado"<<endl;
    } 
}

void productocaroybarato(string productos[], float precios[], int &cantidad)
{
    int i=0;
    float caro= precios[0];
    float barato =precios[0];
    int carop=0;
    int baratop=0;

    for(i=0;i<cantidad;i++)
    {
        if(caro<precios[i])
        {
            caro=precios[i]; 
            carop=i; 
        }
    }

    for(i=0;i<cantidad;i++)
    {
        if(barato>precios[i])
        {
            barato=precios[i];
            baratop=i;
        }
    }

    cout<<"Producto mas caro: "<<productos[carop]<<" - Precio: "<<"$"<<precios[carop]<<endl;
    cout<<"Producto mas barato: "<<productos[baratop]<<" - Precio: "<<"$"<<precios[baratop]<<endl;
}

void factura(string productos[], float precios[], int &cantidad)
{
    int i=0;
    int repetir;
    float suma=0;
    do
    {
        cout<<"=====FACTURA====="<<endl;
        for(i=0;i<cantidad;i++)
        {
            cout<<productos[i]<<" ** "<<"$"<<precios[i]<<endl;
        }
        suma=sumatotal(precios, cantidad);
            cout<<"TOTAL: "<<suma<<endl;

        cout<<"1.Mostrar nuevamente"<<endl;
        cout<<"2.Salir"<<endl;
        cin>>repetir;
        
    } while(repetir==1);
}

void menu(string productos[], float precios[], int &cantidad)
{
    int opcion;

    do
    {
        cout << "===== MENU =====" << endl;

        cout << "1. Registrar productos" << endl;

        cout << "2. Mostrar productos" << endl;

        cout << "3. Suma total" << endl;

        cout << "4. Promedio general" << endl;

        cout << "5. Buscar producto" << endl;

        cout << "6. Producto mas caro y mas barato" << endl;

        cout << "7. Factura" << endl;

        cout << "8. Salir" << endl;

        cout<<"Ingrese una opcion"<<endl;
        cin>>opcion;

        switch (opcion)
        {
            case 1:
                registrardatos (productos, precios, cantidad);
                break;
            case 2:
                mostrardatos (productos, precios, cantidad);
                break;
            case 3:
                cout<<"Suma total: "<<"$"<<sumatotal(precios, cantidad)<<endl;
                break;
            case 4:
                cout<<"Promedio: "<<promedio (precios, cantidad)<<endl;
                break;
            case 5:
                buscarproducto(productos, precios, cantidad);
                break;
            case 6:
                productocaroybarato(productos, precios, cantidad);
                break;
            case 7:
                factura(productos, precios, cantidad);
                break;
            case 8:
                cout<<"Saliendo del programa......."<<endl;
                break;
            default:
                cout<<"Opcion invalida"<<endl;
        }
    } while (opcion!=8);
}

int main()
{
    string productos[10];
    float precios[10];
    int cantidad;
    
    menu( productos, precios, cantidad);

    return 0;

}