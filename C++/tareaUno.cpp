
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

void GenerarFactura(int i, Factura arreglof[], Vendedor v1, Inventario i2, int Cant ) {

    Factura f1;
    f1.Cve_Vendedor = v1.Cve_vendedor;
    f1.Cve_Articulo = i2.Cve_Articulo;
    f1.Cantidad = Cant;
    f1.NoFactura = "F" + GETDATE();
    // arreglof[i];

};

void inputUsuario() {

    string opcion;

    cout << "" << endl;
    cout << "Super 'Doña Maria'" << endl << endl;
    cout << "-----------------" << endl << endl;
    cout << "Que desea agregar?" << endl << endl;
    cout << "Escriba 'P' para producto" << "\t" << "Escriba 'V' para vendedor" << endl << endl; 
    cin >> opcion;
    cout << "" << endl;

    if (opcion == "P") {
        cout << "Opcion Producto" << endl << endl;
    } else if (opcion == "V") {
        cout << "Opcion Vendedor" << endl << endl;
    } else {
        cout << "Opcion Invalida. Reiniciando Programa . . . " << endl;
        inputUsuario();
    }

}

void agregarProducto() {

}

void agregarVendedor() {
    
}

int main() {

    inputUsuario();

    Vendedor arreglov[4];
    Inventario arregloi[4];
    Factura arreglof[5];

    // Variable v1
    Vendedor v1 = {"v100", "Don Julio"};
    Vendedor v2 = {"v200", "Dona Esperanza"};
    arreglov[0] = v1;
    arreglov[1] = v2;

    // Variable i1, i2
    Inventario i1 = {"i500", "Tornillo sin fin", 10.0};
    Inventario i2 = {"i100", "Angulo de Ackerman", 20.0};
    Inventario i3 = {"i500", "Piñon cremallera", 15.0};
    arregloi[0] = i1;
    arregloi[1] = i2;
    arregloi[2] = i3;

    int contadorFactura = 0;

    GenerarFactura(contadorFactura, arreglof, v1, i2, 32);

    return 0;

}

