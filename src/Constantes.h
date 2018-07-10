#ifndef CONSTANTES_H_
#define CONSTANTES_H_

#include <string>

const char SEPARADOR_DIRECTORIO_LINUX = '/';
const char SEPARADOR_DIRECTORIO_WINDOWS = '\\';
const float PROPORCIONAL_COMPRA_TERRENO = 1.3;
const float PROPORCIONAL_VENTA_TERRENO = 0.5;
const float TIEMPO_RECUPERACION_PROPORCIONAL_CULTIVO_PODRIDO = 0.5;
const int ACCION_ABANDONAR = 11;
const int ACCION_CAMBIAR_TERRENO = 9;
const int ACCION_COMPRAR_CAPACIDAD_ALMACEN = 8;
const int ACCION_COMPRAR_CAPACIDAD_TANQUE = 7;
const int ACCION_COMPRAR_TERRENO = 5;
const int ACCION_COSECHAR = 3;
const int ACCION_ENVIAR_A_DESTINO = 4;
const int ACCION_REGAR = 2;
const int ACCION_SEMBRAR = 1;
const int ACCION_SIGUIENTE_TURNO = 10;
const int ACCION_VENDER_TERRENO = 6;
const int CANTIDAD_MAXIMA_JUGADORES = 10;
const int CARAS_DADO = 6;
const int DIFICULTAD_DIFICIL = 3;
const int DIFICULTAD_FACIL = 1;
const int DIFICULTAD_MEDIA = 2;
const int MARGEN_COLUMNA = 0;
const int MARGEN_FILA = 0;
const int MAX_TURNO = 6;
const int MIN_TURNO = 3;
const int MULTIPLICADOR_DADO = 8;
const int POTENCIADOR_AGUA = 5;
const int RENTABILIDAD_CULTIVO_PODRIDO = 0;
const int RENTABILIDAD_CULTIVO_RECUPERACION = 0;
const int RENTABILIDAD_CULTIVO_SECO = 0;
const int RENTABILIDAD_CULTIVO_VACIO = 0;
const int TERRENO_MAX_COLUMNAS = 10;
const int TERRENO_MAX_FILAS = 10;
const int TERRENO_MIN_COLUMNAS = 3;
const int TERRENO_MIN_FILAS = 3;
const int TIEMPO_COSECHA_CULTIVO_PODRIDO = 0;
const int TIEMPO_COSECHA_CULTIVO_RECUPERACION = 0;
const int TIEMPO_COSECHA_CULTIVO_SECO = 0;
const int TIEMPO_RECUPERACION_CULTIVO_PODRIDO = 0;
const int TIEMPO_RECUPERACION_CULTIVO_RECUPERACION = 0;
const int TIEMPO_RECUPERACION_CULTIVO_SECO = 1;
const std::string ARCHIVO_CULTIVOS = "cultivos.txt";
const std::string ARCHIVO_DESTINOS = "destinos.txt";
const std::string ARCHIVO_DESTINOS_DOS = "destinos2.txt";
const std::string DIRECTORIO_ARCHIVOS_DATOS = "datos";
const std::string DIRECTORIO_CAPTURAS_PANTALLA = "screenshots";
const std::string DIRECTORIO_RECURSOS = "res";
const std::string EXTENSION_IMAGEN = ".bmp";
const std::string NOMBRE_JUGADOR_DEFAULT = "Anonimo";
const std::string PARCELA_EN_RECUPERACION = "R";
const std::string PARCELA_PODRIDA = "P";
const std::string PARCELA_SECA = "S";
const std::string PARCELA_VACIA = "#";
const unsigned int PRECIO_BASE_TANQUE = 5;
const unsigned int TIEMPO_COSECHA_CULTIVO_COSECHADO = 0;
const unsigned int VALOR_GRANDE = 99999999;

#endif
