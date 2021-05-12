#include "creaTablas.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define UPPER 54
#define LOWER 1
#define CARDS_NUM 16

int giveRngRand();
int *creaTabla(int *arreglo);
int giveUpDown();
int *tresTablas(int *array);

int giveRngRand()//Da un numero aleatorio dentro del rango de cartas (1-54)
{
	return ((rand() % (UPPER - LOWER + 1)) + LOWER);
}

int *creaTabla(int *arreglo)//Asigna un valor aleatorio no repetido dentro del rango 1-54 y repite los valores que estan o en la posicion 5,6 si doble es 0, y posicion 9,10 si doble es 1
{
	short carta;
	unsigned short doble = giveUpDown();
	for(unsigned short i = 0; i < CARDS_NUM;i++)	
	{
		do{
			
			carta = giveRngRand();
			
			for(unsigned short j =0; j<CARDS_NUM;j++)
			{
				if(arreglo[j] == carta)
				{
					carta = -1;
				}
			}
			
		}while(carta == -1);
		if((i == 5) && (doble == 0))
		{
			arreglo[5] = carta;
			arreglo[6] = carta;
			i++;
		}
		else if((i == 9) && (doble == 1))
		{
			arreglo[9] = carta;
			arreglo[10] = carta;
			i++;
		}
		else
		{
			arreglo[i] = carta;
		}
		
	}
	return arreglo;
}

int giveUpDown()//Da un valor aleatorio entre 0 y 1, para saber si el doble esta arriba o abajo
{
	return ((rand() % (1 - 0 + 1)));
}


int *tresTablas(int *array)
{
	short carta;
	unsigned short doble = giveUpDown();
	for(unsigned short i = 0; i < 48 ;i++)	
	{
		do{
			
			carta = giveRngRand();
			
			for(unsigned short j =0; j<48;j++)
			{
				if(array[j] == carta)
				{
					carta = -1;
				}
			}
			
		}while(carta == -1);
		if((i == 5) && (doble == 0))
		{
			array[5] = carta;
			array[6] = carta;
			i++;
		}
		else if((i == 9) && (doble == 1))
		{
			array[9] = carta;
			array[10] = carta;
			i++;
		}
		else if((i == 21) && (doble == 0))
		{
			array[21]=carta;
			array[22]=carta;
			i++;
		}
		else if((i == 25)&& (doble == 1))
		{
			array[25] =carta;
			array[26] =carta;
			i++;
		}
		else if((i==37)&&(doble == 0))
		{
			array[37] = carta;
			array[38] =carta;
			i++;
		}
		else if((i==41)&&(doble == 1))
		{
			array[41]=carta;
			array[42]=carta;
			i++;
		}
		else
		{
			array[i] = carta;
		}
		
	}
	return array;
}
