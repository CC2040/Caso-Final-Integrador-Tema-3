#include "Funciones.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <stdexcept>


using namespace std;

ConsoleBox *consoleBox = new ConsoleBox; // suponemos que ya está inicializado

const char* base_path = "../"; //Puntero donde se guardara la ruta del directorio actual con ../

void load_script(const char* filename, bool show_script ){
    string script;
    FILE* f = nullptr;
    try
    {
        f = fopen(filename, "rb");
        if (!f)
        {
            cerr << "El achivo " << filename <<" no existe."<< endl; //primera excepcion
            return;
        }

        int c;
        char buf[4001];
        while ((c = fread(buf, 1, 4000, f)) > 0)
        {
            buf[c] = 0;
            script.append(buf);
        }
        fclose(f);
        f = nullptr;

        if (show_script)
        {
            cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            cout << script << endl;
        }
        consoleBox->new_text();
        consoleBox->set_text(script);
    }
    catch (...)
    {
        cerr << "error durante la lectura del archivo" << endl;  //segunda excepcion
        if(f)
            fclose(f);
    }
}

void load_script2()
{
    char filename[500];
    printf("Archivo: ");
    scanf("%499s", filename);
    string fullfilename=string(base_path)+filename; //Concatenacion del directorio padre con el archivo a buscar ademas de transformar a base_path en un string
    load_script(fullfilename.c_str(), true); //llamada de la funcion con la conversion de fullfilename en una cadena de tipo puntero
}