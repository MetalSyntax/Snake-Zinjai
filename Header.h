#ifndef HEADER_H
#define HEADER_H
//Librerias a utilizar
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <direct.h>
#include <ctime>   
// NUMEROS ASOCIADOS A LAS FLECHAS DEL TECLADO
#define ARRIBA     72      
#define IZQUIERDA  75
#define DERECHA    77
#define ABAJO      80
#define ESC        27

int body[200][2]; //Cuerpo
int n = 1; // Variable para controlar los índices del cuerpo
int tam = 3; // Tamaño del cuerpo
int dir = 3; // Variable control de la dirección de la serpiente
int xc = 30, yc = 15; //Coordenadas de la comida
//coordenadas de la serpiente
int x = 10, y = 12;
int h = 1;// control para la velocidad 
int speed = 100; //Velocidad
int score = 0; //Record
char key; //Tecla

#endif
