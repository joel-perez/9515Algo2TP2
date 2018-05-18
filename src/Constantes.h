#ifndef CONSTANTES_H_
#define CONSTANTES_H_

#include <string>

const char CULTIVO_A = 'A';
const char CULTIVO_B = 'B';
const char CULTIVO_C = 'C';
const char CULTIVO_PERDIDO_RECUPERADO = 'X';
const char PARCELA_LIBRE = '#';
const char SEPARADOR_DIRECTORIO_LINUX = '/';
const char SEPARADOR_DIRECTORIO_WINDOWS = '\\';
const std::string DIRECTORIO_RECURSOS = "res";
const std::string DIRECTORIO_CAPTURAS_PANTALLA = "screenshots";
const std::string NOMBRE_JUGADOR_DEFAULT = "Anonimo";

const int TERRENO_MAX_COLUMNAS = 10;
const int TERRENO_MAX_FILAS = 10;
const int TERRENO_MIN_COLUMNAS = 3;
const int TERRENO_MIN_FILAS = 3;

const int MAX_TURNO = 6;
const int MIN_TURNO = 3;

const int DIFICULTAD_FACIL = 1;
const int DIFICULTAD_MEDIA = 2;
const int DIFICULTAD_DIFICIL = 3;

const std::string ARCHIVO_CULTIVOS = "cultivos.txt";
const std::string ARCHIVO_DESTINOS = "destinos.txt";

const int RENTABILIDAD_CULTIVO_VACIO = 0;

#endif
