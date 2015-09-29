#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#define ANCHO_PANTALLA 80


/*Progrmama para mostrar en pantalla y archivar el record y promedio de puntos de los jugadores de un equipo de baloncesto
Por: Kevin Santiago Ortiz*/

void main()
{
	int index, index1, opcion, conteo, sum, sum1, temp1=0;
	const int cantidad=2, temporada=2;
	int jugador[cantidad], intento_3[cantidad][temporada], intento_2[cantidad][temporada], intento_libre[cantidad][temporada];
	int asertado_3[cantidad][temporada], asertado_2[cantidad][temporada], asertado_libre[cantidad][temporada];
	float promedio_3[cantidad], promedio_2[cantidad], promedio_libre[cantidad], temp;
	FILE*record_de_puntos;

	printf("\n\n\n\n\n\n\n\n\n\n\n");
	printf("%*s\n", ANCHO_PANTALLA/2 + strlen("Programa para mostrar y archivar el record de puntos, mejor")/2, "Programa para mostrar y archivar el record de puntos, mejor");
	printf("%*s\n", ANCHO_PANTALLA/2 + strlen("promedio de tiros de tres, tiros de dos y tiros libres de los")/2, "promedio de tiros de tres, tiros de dos y tiros libres de los");
	printf("%*s\n", ANCHO_PANTALLA/2 + strlen("jugadores de baloncesto del equipo los Abejones de Monte Carlo")/2, "jugadores de baloncesto del equipo los Abejones de Monte Carlo.");
	_getch();
	system("cls");

	do
	{
	printf("%*s\n", ANCHO_PANTALLA/2 + strlen("Equipo de baloncesto los Abejones de Monte Carlo\n")/2, "Equipo de baloncesto los Abejones de Monte Carlo\n");
    printf("%*s\n", ANCHO_PANTALLA/2 + strlen("|Menu de opciones|\n")/2, "|Menu de opciones|\n");
	printf("	1.Entre los datos de los jugadores.\n\n");
	printf("	2.Ver el jugador con mejor promedio en tiros de tres, mejor\n	  promedio en tiros de dos y mejor promedio en tiros libres.\n");
	printf("\n	3.Ver los datos de todos los jugadores.\n");
	printf("\n	4.Guradar los datos de todos los jugadores en un archivo.\n");
	printf("\n	5.Salir\n");
	printf("\n\nOpci%cn deseada:\t",162);
	scanf("%d",&opcion);
	system("cls");

	switch(opcion)
	{
		case 1:
			printf("%*s\n", ANCHO_PANTALLA/2 + strlen("|Datos de los jugadores|\n\n")/2, "|Datos de los jugadores|\n");
			printf("Entre el numero de de cada uno de los jugadores del equipo.\nNOTA: El rango de numero de jugador va desde 0 hasta 99 y debe ser entero.\n\n");
				for(index=0;index<cantidad;index++)
				{
					switch (index)
						{
						case 0:case 2:
							printf("Entre el numero del %der jugador:\n",index+1);
							scanf("%d",&jugador[index]);
							break;
						case 1:
							printf("Entre el numero del 2do jugador:\n");
							scanf("%d",&jugador[index]);
							break;
						case 3:case 4:case 5:
							printf("Entre el numero del %dto jugador:\n",index+1);
							scanf("%d",&jugador[index]);
							break;
						case 6:case 9:case 10:case 11:
							printf("Entre el numero del %dmo jugador:\n",index+1);
							scanf("%d",&jugador[index]);
							break;
						case 7:
							printf("Entre el numero del 8vo jugador:\n");
							scanf("%d",&jugador[index]);
							break;
						case 8:
							printf("Entre el numero del 9no jugador:\n");
							scanf("%d",&jugador[index]);
							break;
						default:
							break;
						}
					while(jugador[index]>=100||jugador[index]<0)
						{
							printf("Recuerde que el numero del jugador debe ser mayor de 0 y menor de 100.\n");
							scanf("%d",&jugador[index]);
						}
						if(index>=1)
							for(conteo=0;conteo<index;conteo++)
							{
								while(jugador[index]==jugador[conteo])
								{
									printf("Ya hay un jugador con ese numero por favor entre otro:\n");
									scanf("%d",&jugador[index]);
								}
							}
				}
				system("cls");

				for(index=0;index<cantidad;index++)
				{
					printf("%*s\n", ANCHO_PANTALLA/2 + strlen("|Datos de los jugadores|\n\n")/2, "|Datos de los jugadores|\n");
					printf("Tiros de 3 puntos realizados por el jugador #%d en %d juegos\n",jugador[index], temporada);
					for(index1=0;index1<temporada;index1++)
					{
						printf("\nTiros intentados en el juego #%d:\n",index1+1);
						scanf("%d",&intento_3[index][index1]);
						printf("Tiros asertados en juego #%d:\n",index1+1);
						scanf("%d",&asertado_3[index][index1]);
					}

					system("cls");
					printf("%*s\n", ANCHO_PANTALLA/2 + strlen("|Datos de los jugadores|\n\n")/2, "|Datos de los jugadores|\n");
					printf("Tiros de 2 puntos realizados por el jugador #%d en %d juegos\n",jugador[index], temporada);
					for(index1=0;index1<temporada;index1++)
					{
						printf("\nTiros intentados en el juego #%d:\n",index1+1);
						scanf("%d",&intento_2[index][index1]);
						printf("Tiros asertados en juego #%d:\n",index1+1);
						scanf("%d",&asertado_2[index][index1]);
					}

					system("cls");
					printf("%*s\n", ANCHO_PANTALLA/2 + strlen("|Datos de los jugadores|\n\n")/2, "|Datos de los jugadores|\n");
					printf("Tiros libres realizados por el jugador #%d en %d juegos\n",jugador[index], temporada);
					for(index1=0;index1<temporada;index1++)
					{
						printf("\nTiros intentados en el juego #%d:\n",index1+1);
						scanf("%d",&intento_libre[index][index1]);
						printf("Tiros asertados en juego #%d:\n",index1+1);
						scanf("%d",&asertado_libre[index][index1]);
					}
					temp1=1;
					_getch();
					system("cls");
				}
			break;
		case 2:
			do
			{
			printf("%*s\n", ANCHO_PANTALLA/2 + strlen("|Mejores jugadores segun el promedio de tiros|\n")/2, "|Mejores jugadores segun el promedio de tiros|\n");
			for(index=0;index<cantidad;index++)
			{
				sum=0;
				sum1=0;
				for(index1=0;index1<temporada;index1++)
				{
					sum+=intento_3[index][index1];
					sum1+=asertado_3[index][index1];
				}
				promedio_3[index]=((float(sum1)/sum)*100);
				if(index==0)
					temp=promedio_3[index];
				if(index>=1)
					for(conteo=1;conteo<index;conteo++)
					{
						if(temp<promedio_3[conteo])
							temp=promedio_3[conteo];
						else
							temp=temp;
					}
			}
			for(index=0;index<cantidad;index++)
			{
				if(temp==promedio_3[index])
				{
					printf("Mejor promedio en tiros de 3 puntos:\n");
					printf("	Jugador #%d con promedio %.2f%c\n\n",jugador[index],temp, 37);
				}	
			}

			for(index=0;index<cantidad;index++)
			{
				sum=0;
				sum1=0;
				for(index1=0;index1<temporada;index1++)
				{
					sum+=intento_2[index][index1];
					sum1+=asertado_2[index][index1];
				}
				promedio_2[index]=(float(sum1)/sum)*100;
				if(index==0)
					temp=promedio_2[index];
				if(index>=1)
					for(conteo=1;conteo<index;conteo++)
						{
							if(temp<promedio_3[conteo])
								temp=promedio_3[index];
							else
								temp=temp;
						}
			}
			for(index=0;index<cantidad;index++)
			{
				if(temp==promedio_2[index])
				{
					printf("Mejor promedio en tiros de 2 puntos:\n");
					printf("	Jugador #%d con promedio %.2f%c\n\n",jugador[index],temp, 37);
				}	
			}
			for(index=0;index<cantidad;index++)
			{
				sum=0;
				sum1=0;
				for(index1=0;index1<temporada;index1++)
				{
					sum+=intento_libre[index][index1];
					sum1+=asertado_libre[index][index1];
				}
				promedio_libre[index]=((float(sum1)/sum)*100);
				if(index==0)
					temp=promedio_libre[index];
				if(index>=1)
					for(conteo=1;conteo<index;conteo++)
					{
						if(temp<promedio_libre[conteo])
							temp=promedio_libre[conteo];
						else
							temp=temp;
					}
			}
			for(index=0;index<cantidad;index++)
			{
				if(temp==promedio_libre[index])
				{
					printf("Mejor promedio en tiros libres:\n");
					printf("	Jugador #%d con promedio %.2f%c\n\n",jugador[index],temp, 37);
				}			
			}
			}
			while(temp1==0);
				printf("Para poder ver esta opcion primero debe entrar los datos de los jugadores.");
			printf("\n\nPresione ENTER para ir a menu");
			_getch();
			system("cls");
			break;
		case 3:
			{
				printf("%*s\n", ANCHO_PANTALLA/2 + strlen("|Tabla de record de todos los jugadores|\n")/2, "|Tabla de record de todos los jugadores|\n");
				printf("       _______________________________________________________________\n");
				printf("      |Jugador|Promedio 3 puntos|Promedio 2 puntos|Promedio tiro libre|\n");
				printf("      |_______|_________________|_________________|___________________|\n");
				for(index=0;index<cantidad;index++)
				{					
					printf("      |%7d|%15.2f %c|%16.2f%c|%18.2f%c|\n",jugador[index], promedio_3[index], 37, promedio_2[index], 37, promedio_libre[index], 37);
					printf("      |_______|_________________|_________________|___________________|\n");
				}
			}
			printf("\n\nPresione ENTER para ir a menu");
			_getch();
			system("cls");
			break;
		case 4:
			{
				if ((record_de_puntos=fopen("c:abejones.txt","w"))!=NULL)
				{
					fprintf(record_de_puntos,"%*s\n", ANCHO_PANTALLA/2 + strlen("|Tabla de record de todos los jugadores|\n")/2, "|Tabla de record de todos los jugadores|\n");
					fprintf(record_de_puntos,"       _______________________________________________________________\n");
					fprintf(record_de_puntos,"      |Jugador|Promedio 3 puntos|Promedio 2 puntos|Promedio tiro libre|\n");
					fprintf(record_de_puntos,"      |_______|_________________|_________________|___________________|\n");
					for(index=0;index<cantidad;index++)
					{
						fprintf(record_de_puntos,"      |%7d|%15.2f %c|%16.2f%c|%18.2f%c|\n",jugador[index], promedio_3[index], 37, promedio_2[index], 37, promedio_libre[index], 37);
						fprintf(record_de_puntos,"      |_______|_________________|_________________|___________________|\n");
					}
					printf("\nLos datos se han guardado satisfanctoriamente");
					fclose(record_de_puntos);
				}
				else
					printf("\nNo se pudo abrir el file");
			}
			printf("\n\nPresione ENTER para ir a menu");
			_getch();
			system("cls");
		}
	}
	while(opcion!=5);
	exit;
}