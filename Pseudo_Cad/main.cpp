#include <iostream>

using namespace std;

void presentacion(){
    cout << "    __^__                                      __^__\n";
    cout << "   ( ___ )------------------------------------( ___ )\n";
    cout << "    | | |  USAC                                | | |\n";
    cout << "    | | |  Estructura de Datos                 | | |\n";
    cout << "    | | |  Seccion A                           | | |\n";
    cout << "    | | |  Kevin Jose Sandoval Catalan         | | |\n";
    cout << "    |___|  201807265                           |___|\n";
    cout << "   (_____)------------------------------------(_____)\n\n";

    system("pause");
    system("cls");
}

int main()
{
    int opcionMenu = 0;

    presentacion();

    do
    {
        cout << "          _______________________________\n";
        cout << " ________|            PSEUDO-CAD         |_______\n";
        cout << "|        | 1. Ver proyectos              |      |\n";
        cout << "|        | 2. Editar proyectos           |      |\n";
        cout << "|        | 3. Cargar proyectos           |      |\n";
        cout << "|        | 4. Graficar proyectos         |      |\n";
        cout << "|        | 5. Guardar proyectos          |      |\n";
        cout << "|        | 6. Cargar librerias           |      |\n";
        cout << "|        | 7. Salir                      |      |\n";
        cout << "|        |_______________________________|      |\n";
        cout << "|__________)                        (___________|\n";


        cout << "\n\nEliga una opcion: ";
        cin >> opcionMenu;

        switch(opcionMenu){
        case 1:
            system("cls");
            cout << "\n VER PROYECTOS \n";
            break;

        case 2:
            system("cls");
            cout << "\n EDITAR PROYECTOS \n";
            break;

        case 3:
            system("cls");
            cout << "\n CARGAR PROYECTOS \n";
            break;

        case 4:
            system("cls");
            cout << "\n GRAFICAR PROYECTOS \n";
            break;

        case 5:
            system("cls");
            cout << "\n GUARDAR PROYECTOS \n";
            break;

        case 6:
            system("cls");
            cout << "\n CARGAR PROYECTOS \n";
            break;

        case 7:
            system("cls");
            cout << "\n Programa finalizado \n";
            break;

        default:
            system("cls");
            cout << "\n Opcion NO valida \n";
        }
    } while (opcionMenu != 7);

    return 0;
}
