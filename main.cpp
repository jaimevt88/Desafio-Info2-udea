#include <iostream>
#include <fstream>

int main() {
    const int MAX_FILAS = 50;
    const int NUM_DIAS = 8;
    int ventas_leidas[MAX_FILAS][NUM_DIAS];
    int fila_actual = 0;

    const char* nombre_archivo = "ventas.csv";
    std::ifstream archivo_csv(nombre_archivo);

    if (!archivo_csv.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << nombre_archivo << std::endl;
        return 1;
    }

    // Saltar la línea de encabezados
    char caracter;
    while (archivo_csv.get(caracter) && caracter != '\n') {
        // Ignorar hasta el final de la primera línea
    }

    // Leer los datos del archivo
    while (fila_actual < MAX_FILAS && archivo_csv) {
        for (int col_actual = 0; col_actual < NUM_DIAS; ++col_actual) {
            if (!(archivo_csv >> ventas_leidas[fila_actual][col_actual])) {
                break; // Detener si la lectura falla
            }
            // el operador de extracción >> para leer un tipo de dato numérico
            // busca y lee los carácteres que forman ese número.
            //La lectura se detiene cuando encuentra un carácter que no es parte del número.
            if (col_actual < NUM_DIAS - 1) {
                archivo_csv.get(); // Leer y descartar la coma
            }
        }
        fila_actual++;
    }

    archivo_csv.close();

    // Imprimir el contenido del arreglo para verificar
    std::cout << "Datos leidos y guardados en el arreglo:" << std::endl;
    for (int i = 0; i < fila_actual-1; ++i) {
        for (int j = 0; j < NUM_DIAS; ++j) {
            std::cout << ventas_leidas[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    //Esto es una prueba
    //Esto es una segunda prueba

    return 0;
}
