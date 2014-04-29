/*
 * main.cpp
 *
 *  Created on: 27/04/2014
 *      Author: rodrigomello
 */
#include <stdlib.h>
#include <stdio.h>
#include "RMS.h"
#include "ListaEncadeada.h"




int main(void){
	char* v= "1111";

	PCB* p1 = new PCB(v,1,5,5,0);
	printf("ola1");
	ListaEncadeada<PCB>* l = new ListaEncadeada<PCB>();
	//printf("ola2");
	l->AdicionarNoFim(p1);
	RMS* t = new RMS(l);
	printf("teste");
	t->iniciarEscalonamento();



}



