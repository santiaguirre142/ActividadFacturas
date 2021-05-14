
#include <iostream>
#include <ctime>

using namespace std;

class Vendedor {
    public:
        string Cve_vendedor;
        string Nombre;
};

class Inventario {
    public:
        string Cve_Articulo;
        string Descripcion;
        double Precio;
};

class Factura {
    public:
        string NoFactura;
        string Cve_Vendedor;
        string Cve_Articulo;
        int Cantidad;
};

std::string GETDATE() {

    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%Y%m%d%H%S",timeinfo);
    std::string str(buffer);

    // std::cout << str;

    return str;

};

void GenerarFactura(int i, Factura arregloF[], Vendedor v1, Inventario i2, int Cant ) {

    Factura f1;
    f1.Cve_Vendedor = v1.Cve_vendedor;
    f1.Cve_Articulo = i2.Cve_Articulo;
    f1.Cantidad = Cant;
    f1.NoFactura = "F" + GETDATE();
    //arregloF[i];

};

void datosVendedor(Vendedor vend) {

    Vendedor v1;

    string CVE;
    string Nombre;

    cout << "---- CVE del vendedor: ----" << endl;
    cin >> CVE;
    cout << "---- Nombre del vendedor: ----" << endl;
    cin >> CVE;

    v1.Cve_vendedor = CVE;
    v1.Nombre = Nombre;

}

void datosProducto(Inventario prod) {

    Inventario p1;

    string CVE;
    string Descripcion;
    double Precio;
    int Cantidad;

    cout << "---- CVE del producto: ----" << endl;
    cin >> CVE;
    cout << "---- Descripcion del producto: ----" << endl;
    cin >> Descripcion;
    cout << "---- Precio del producto: ----" << endl;
    cin >> Precio;
    cout << "---- Cantidad: ----" << endl;
    cin >> Cantidad;

    p1.Cve_Articulo = CVE;
    p1.Descripcion = Descripcion;
    p1.Precio = Precio;

}

int main() {

    int facturas;
    int cantidad;
    string opcion;
    Factura arregloFact[facturas];

    // Input Usuario
    cout << "" << endl;
    cout << "Super 'Doña Maria'" << endl << endl;
    cout << "-----------------" << endl << endl;
    cout << "Escriba 'G para generar factura" << "\t" << "\t" << "Escriba 'F' para imprimir facturas" << endl << endl; 
    cin >> opcion;
    cout << "" << endl;

    // Opcion Generar Factura
    if (opcion == "G") {   

        // 1.- Se pide el numero de facturas
        cout << "Cuantos facturas desea agregar?" << endl;
        cin >> facturas;

        // 2.- Loop que genera el numero de facturas pedidas
        for (int i = 0; i < facturas; i = i + 1) {
            Vendedor v1;
            Inventario p1;

            // 2.- Se piden los datos del vendedor
            datosVendedor(v1);

            // 3.- Se piden los datos del producto
            datosProducto(p1);

            // 4.- Se pide la cantidad de productos
            cout << "---- Cantidad: ----" << endl;
            cin >> cantidad;

            // 5.- Se genera la factura 
            //GenerarFactura(i, arregloFact, v1, p1, cantidad);

        }

    } else if (opcion == "F") {

    } else {

        cout << "Opcion Invalida. Apagando Programa . . . " << endl;
        cout << "" << endl;
        return 0;
        
    }

    return 0;

}

