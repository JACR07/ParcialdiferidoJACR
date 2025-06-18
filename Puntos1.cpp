#include <iostream>
using namespace std;

const int MAX_LIBROS = 100;
char librosPrestados[MAX_LIBROS][50]; 
int cantidadLibros = 0;

char *prestarLibro()
{
    if (cantidadLibros >= MAX_LIBROS)
    {
        return (char *)"No puedes prestar más libros.";
    }
    cout << "Ingrese el titulo del libro a prestar (una palabra, max. 49 caracteres): ";
    cin >> librosPrestados[cantidadLibros];
    cantidadLibros++;
    return (char *)"Prestamo exitoso.";
}

char *devolverLibro()
{
    if (cantidadLibros == 0)
    {
        return (char *)"No hay libros prestados para devolver.";
    }

    cout << "Libros prestados:\n";
    for (int i = 0; i < cantidadLibros; i++)
    {
        cout << i + 1 << ". " << librosPrestados[i] << endl;
    }

    int indice;
    cout << "Seleccione el numero del libro a devolver: ";
    cin >> indice;

    if (indice < 1 || indice > cantidadLibros)
    {
        return (char *)"Selección invalida.";
    }

    cout << "Devolucion exitosa: \"" << librosPrestados[indice - 1] << "\" ha sido eliminado de su lista.\n";

    for (int i = indice - 1; i < cantidadLibros - 1; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            librosPrestados[i][j] = librosPrestados[i + 1][j];
        }
    }
    cantidadLibros--;

    return (char *)"Libro eliminado correctamente.";
}

int mostrarMenu()
{
    cout << "\nMenu\n";
    cout << "1. Prestar libro\n";
    cout << "2. Devolver libro\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opcion: ";
    int opcion;
    cin >> opcion;
    return opcion;
}

int main()
{
    char nombreUsuario[50], numeroCarnet[9];

    cout << "Ingrese su nombre (una palabra, max. 49 caracteres): ";
    cin >> nombreUsuario;

    do
    {
        cout << "Ingrese su numero de carnet (8 digitos): ";
        cin >> numeroCarnet;
        bool esvalido = true;
        for (int i = 0; i < 8; i++)
        {
            if (numeroCarnet[i] < '0' || numeroCarnet[i] > '9')
            {
                esvalido = false;
                break;
            }
        }
        if (!esvalido || numeroCarnet[8] != '\0')
        {
            cout << "Numero de carnet inválido. debe tener cabal 8 digitos.\n";
        }
    } while (numeroCarnet[8] != '\0');

    int opcion;
    do
    {
        opcion = mostrarMenu();
        if (opcion == 1)
        {
            cout << prestarLibro() << endl;
        }
        else if (opcion == 2)
        {
            cout << devolverLibro() << endl;
        }
        else if (opcion == 3)
        {
            cout << "Saliendo del sistema...\n";
        }
        else
        {
            cout << "Opción invalida, intente nuevamente.\n";
        }
    } while (opcion != 3);

    return 0;
}
