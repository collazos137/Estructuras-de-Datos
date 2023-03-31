#ifndef ARRAYLIST
#define ARRAYLIST

#include <stdio.h>
#include <stdlib.h>
#define CAP 100

typedef struct List List;


struct List{
	int a[CAP], n;
	int (*creanteList);
	int (*sum) (List *);
} 

int sum(List * x);

int sum(List * x){
	int i;
	int cont;
	for(i = 0; i < x->n - 1; i++){
		cont +=  x ->a[i];
	}
	return cont;
}