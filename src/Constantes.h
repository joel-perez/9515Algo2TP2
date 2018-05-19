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
const int ACCION_COMPRAR_CAPACIDAD_ALMACEN = 8;
const int ACCION_COMPRAR_CAPACIDAD_TANQUE = 7;
const int ACCION_COMPRAR_TERRENO = 5;
const int ACCION_COSECHAR = 3;
const int ACCION_ENVIAR_A_DESTINO = 4;
const int ACCION_REGAR = 2;
const int ACCION_SEMBRAR = 1;
const int ACCION_SIGUIENTE_TURNO = 9;
const int ACCION_VENDER_TERRENO = 6;
const int CARAS_DADO = 6;
const int DIFICULTAD_DIFICIL = 3;
const int DIFICULTAD_FACIL = 1;
const int DIFICULTAD_MEDIA = 2;
const int MAX_TURNO = 6;
const int MIN_TURNO = 3;
const int MULTIPLICADOR_DADO = 8;
const int POTENCIADOR_AGUA = 5;
const int RENTABILIDAD_CULTIVO_VACIO = 0;
const int TERRENO_MAX_COLUMNAS = 10;
const int TERRENO_MAX_FILAS = 10;
const int TERRENO_MIN_COLUMNAS = 3;
const int TERRENO_MIN_FILAS = 3;
const std::string ARCHIVO_CULTIVOS = "cultivos.txt";
const std::string ARCHIVO_DESTINOS = "destinos.txt";
const std::string DIRECTORIO_CAPTURAS_PANTALLA = "screenshots";
const std::string DIRECTORIO_RECURSOS = "res";
const std::string NOMBRE_JUGADOR_DEFAULT = "Anonimo";

#endif
