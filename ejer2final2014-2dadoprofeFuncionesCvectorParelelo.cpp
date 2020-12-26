// ConsoleApplication5.cpp : main project file.
#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include <Windows.h>
#include <iomanip>
#include<string.h>
using namespace std;
using namespace System;

void genera_arreglos(int presupuestado[], int avance[], int montogastado[], int codigo[])
{
	Random r;
	for (int i = 0; i < 24; i++)
	{
		presupuestado[i] = r.Next(1000, 10001);
		avance[i] = r.Next(0, 101);
		montogastado[i] = r.Next(1000, 10001);
		codigo[i] = i;
	}
}

void imprimir_arreglos(int presupuestado[], int avance[], int montogastado[], int codigo[])
{
	cout << " cod \t presupuesto \t %avance \t monto gastado " << endl << endl;
	for (int i = 0; i < 24; i++)
		cout << codigo[i] << "\t" << presupuestado[i] << "\t\t" << avance[i] << "\t\t" << montogastado[i] << endl;

}

void obtiene_mayor_gastado(int montogastado[])
{
	int mayor = montogastado[0], codigo;
	for (int i = 0; i < 24; i++)
		if (mayor < montogastado[i])
		{
			mayor = montogastado[i];
			codigo = i;
		}
	cout << "mayor monto gastado en la partida de codigo: " << codigo << endl;
}

void obtiene_promedio_presupuestado(int presupuestado[], int montogastado[])
{
	float suma = 0, promedio; int contador = 0;
	for (int i = 0; i < 24; i++)
		if (presupuestado[i] < montogastado[i])
		{
			suma = suma + presupuestado[i];
			contador++;
		}
	promedio = suma / contador;
	cout << "promedio montos presupuestados (gasto>presupues): " << promedio << endl;
}

void partida_finalizada_ok(int presupuestado[], int avance[], int montogastado[])
{
	cout << "finalizada correctamente: " << endl << endl;
	for (int i = 0; i < 24; i++)
		if ((presupuestado[i] == montogastado[i]) && avance[i] == 100)
			cout << "partida: " << i << montogastado[i];
		
}

void ordena_arreglo(int presupuestado[], int avance[], int montogastado[], int codigo[])
{
	cout << "ordenado ascendente en base al porcentaje de avance" << endl<<endl;
	int temppres, tempavanc, tempgastado, tempcodigo;
	for (int i = 0; i < 23; i++)
		for (int j = i + 1; j < 24; j++)
			if (avance[i] > avance[j])
			{
				temppres = avance[i];
				avance[i] = avance[j];
				avance[j] = temppres;

				tempavanc = presupuestado[i];
				presupuestado[i] = presupuestado[j];
				presupuestado[j] = tempavanc;

				tempgastado = montogastado[i];
				montogastado[i] = montogastado[j];
				montogastado[j] = tempgastado;

				tempcodigo = codigo[i];
				codigo[i] = codigo[j];
				codigo[j] = tempcodigo;
			}
}
int main()
{

	int *presupuestado = new int[24];
	int *avance = new int[24];
	int *montogastado = new int[24];
	int*codigo = new int[24];
	genera_arreglos(presupuestado, avance, montogastado,codigo);
	imprimir_arreglos(presupuestado, avance, montogastado,codigo);
	obtiene_mayor_gastado(montogastado);
	obtiene_promedio_presupuestado(presupuestado, montogastado);
	partida_finalizada_ok(presupuestado, avance, montogastado);
	ordena_arreglo(presupuestado, avance, montogastado,codigo);
	imprimir_arreglos(presupuestado, avance, montogastado, codigo);

	delete[]presupuestado;
	delete[]avance;
	delete[]montogastado;
	delete[]codigo;

	system("pause");
}