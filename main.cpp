#include "creaTablas.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <graphics.h>
#include <winuser.h>

#define CARDS_NUM 16

#define DIVISION 16

size_t width = ((size_t)GetSystemMetrics(SM_CXSCREEN)*1.2)/1.5;
size_t height = (((size_t)GetSystemMetrics(SM_CYSCREEN))*4)/1.2;

int *creaTabla(int *arreglo);
void mostrarTabla(int arrayFiguras[], float x = 0, float y = 0, float u = width/DIVISION, float v = height/DIVISION,unsigned int numTabla = 0);
int *tresTablas(int *array);

int main() {

	srand(time(NULL));

	int todoTabla[48];
	int tabla1[CARDS_NUM];
	int tabla2[CARDS_NUM];
	int tabla3[CARDS_NUM];
	int tabla4[CARDS_NUM];

	
	
	for(unsigned short i =0; i<48; i++)//Inicializa todos los valores de tablas en cero
	{
		todoTabla[i] = 0;
	}
	tresTablas(todoTabla);
	
	for(unsigned short i =0,j=0; i<16; i++,j++)
	{	
	 	
		tabla1[j]=todoTabla[i];
	}
	
	
	for(unsigned short i =16,j=0; i<32; i++,j++)
	{
		
		tabla2[j]=todoTabla[i];
	}
	
	for(unsigned short i =32,j=0; i<48; i++,j++)
	{
		tabla3[j]=todoTabla[i];
	}
	
	for(unsigned short i =0; i<16; i++)//Inicializa todos los valores de tablas en cero
	{
		tabla4[i] = 0;
	}
	creaTabla(tabla4);
	
	
	initwindow(width,height/4,"Tabla de loteria");
	
	mostrarTabla(tabla1);

	mostrarTabla(tabla2, width/4, 0, width/4+width/DIVISION, height/DIVISION, 1);

	mostrarTabla(tabla3, width/2, 0, width/2+width/DIVISION, height/DIVISION, 2);
	
	mostrarTabla(tabla4, width/1.333, 0, width/1.333+width/DIVISION, height/DIVISION, 3);
	
	system("pause");
	return 0;
}

void mostrarTabla(int arrayFiguras[], float x,float y,  float u, float v, unsigned int numTabla)
{
	unsigned short figura;
	unsigned int counter = 0;
	int figureS_x = width/DIVISION;
	int figureS_y = height/DIVISION;
	
	for(unsigned short i = 0; i<16; i++ ,counter++, x += width/DIVISION, u += width/DIVISION)
	{
		figura = arrayFiguras[i];
		if(counter == 4 && numTabla == 0)//Esto sirve para saltar a la siguiente fila de la tabla
		{
			y += height/DIVISION;
			v += height/DIVISION;
			x = 0;
			u = width/DIVISION;
			counter = 0;
		}
		else if(counter == 4 && numTabla == 1)//Esto sirve para saltar a la siguiente fila de la tabla
		{
			y += height/DIVISION;
			v += height/DIVISION;
			x = width/4;
			u = width/4+figureS_x;
			counter = 0;
		}
		else if(counter == 4 && numTabla == 2)//Esto sirve para saltar a la siguiente fila de la tabla
		{
			y += height/DIVISION;
			v += height/DIVISION;
			x = width/2;
			u = width/2+figureS_x;
			counter = 0;
		}
		else if(counter == 4 && numTabla == 3)//Esto sirve para saltar a la siguiente fila de la tabla
		{
			y += height/DIVISION;
			v += height/DIVISION;
			x = width/(1.33333);
			u = width/(1.33333)+ figureS_x;
			counter = 0;
		}
		

		switch(figura)
		{
		case 1:
			readimagefile("1_gallo.jpg",x,y,u,v);break;
		case 2:
			readimagefile("2_diablo.jpg",x,y,u,v);break;
		case 3:
			readimagefile("3_dama.jpg",x,y,u,v);break;
		case 4:
			readimagefile("4_catrin.jpg",x,y,u,v);break;
		case 5:
			readimagefile("5_paraguas.jpg",x,y,u,v);break;
		case 6:
			readimagefile("6_sirena.jpg",x,y,u,v);break;
		case 7:
			readimagefile("7_escalera.jpg",x,y,u,v);break;
		case 8:
			readimagefile("8_botella.jpg",x,y,u,v);break;
		case 9:
			readimagefile("9_barril.jpg",x,y,u,v);break;
		case 10:
			readimagefile("10_arbol.jpg",x,y,u,v);break;
		case 11:
			readimagefile("11_melon.jpg",x,y,u,v);break;
		case 12:
			readimagefile("12_valiente.jpg",x,y,u,v);break;
		case 13:
			readimagefile("13_gorrito.jpg",x,y,u,v);break;
		case 14:
			readimagefile("14_muerte.jpg",x,y,u,v);break;
		case 15:
			readimagefile("15_pera.jpg",x,y,u,v);break;
		case 16:
			readimagefile("16_bandera.jpg",x,y,u,v);break;
		case 17:
			readimagefile("17_bandolon.jpg",x,y,u,v);break;
		case 18:
			readimagefile("18_violoncello.jpg",x,y,u,v);break;
		case 19:
			readimagefile("19_garza.jpg",x,y,u,v);break;
		case 20:
			readimagefile("20_pajaro.jpg",x,y,u,v);break;
		case 21:
			readimagefile("21_mano.jpg",x,y,u,v);break;
		case 22:
			readimagefile("22_bota.jpg",x,y,u,v);break;
		case 23:
			readimagefile("23_luna.jpg",x,y,u,v);break;
		case 24:
			readimagefile("24_cotorro.jpg",x,y,u,v);break;
		case 25:
			readimagefile("25_borracho.jpg",x,y,u,v);break;
		case 26:
			readimagefile("26_negrito.jpg",x,y,u,v);break;
		case 27:
			readimagefile("27_corazon.jpg",x,y,u,v);break;	
		case 28:
			readimagefile("28_sandia.jpg",x,y,u,v);break;
		case 29:
			readimagefile("29_tambor.jpg",x,y,u,v);break;
		case 30:
			readimagefile("30_camaron.jpg",x,y,u,v);break;
		case 31:
			readimagefile("31_jaras.jpg",x,y,u,v);break;
		case 32:
			readimagefile("32_musico.jpg",x,y,u,v);break;
		case 33:
			readimagefile("33_arana.jpg",x,y,u,v);break;
		case 34:
			readimagefile("34_soldado.jpg",x,y,u,v);break;
		case 35:
			readimagefile("35_estrella.jpg",x,y,u,v);break;
		case 36:
			readimagefile("36_cazo.jpg",x,y,u,v);break;
		case 37:
			readimagefile("37_mundo.jpg",x,y,u,v);break;
		case 38:
			readimagefile("38_apache.jpg",x,y,u,v);break;
		case 39:
			readimagefile("39_nopal.jpg",x,y,u,v);break;
		case 40:
			readimagefile("40_alacran.jpg",x,y,u,v);break;
		case 41:
			readimagefile("41_rosa.jpg",x,y,u,v);break;
		case 42:
			readimagefile("42_calavera.jpg",x,y,u,v);break;
		case 43:
			readimagefile("43_campana.jpg",x,y,u,v);break;
		case 44:
			readimagefile("44_cantarito.jpg",x,y,u,v);break;
		case 45:
			readimagefile("45_venado.jpg",x,y,u,v);break;
		case 46:
			readimagefile("46_sol.jpg",x,y,u,v);break;
		case 47:
			readimagefile("47_corona.jpg",x,y,u,v);break;
		case 48:
			readimagefile("48_chalupa.jpg",x,y,u,v);break;
		case 49:
			readimagefile("49_pino.jpg",x,y,u,v);break;
		case 50:
			readimagefile("50_pescado.jpg",x,y,u,v);break;
		case 51:
			readimagefile("51_palma.jpg",x,y,u,v);break;
		case 52:
			readimagefile("52_maceta.jpg",x,y,u,v);break;
		case 53:
			readimagefile("53_arpa.jpg",x,y,u,v);break;
		case 54:
			readimagefile("54_rana.jpg",x,y,u,v);break;
		default:
			printf("ERROR");
		}
	}
}

