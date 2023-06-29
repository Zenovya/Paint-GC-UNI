#include <graphics.h>

typedef enum {TRUE, FALSE} bool; /*Se crea tipo de dato bool*/
typedef char* String; /*Se crea tipo de dato string*/

void clear(int);
void mlimitMax(void);

void clear(int color){
	/*Limpiar pantalla completa según el color especificado
	para el fondo*/
	setfillstyle(1, color);
	bar(0, 0, 639, 480);
}

void mlimitMax(){
	mlimit(1,1,1,639,475);
}