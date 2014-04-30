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
#include <iostream>


using namespace std;

int main(void){
	char* v= "1111";
	PCB* p1 = new PCB("p1",1,0,8,0);
	PCB* p2 = new PCB("p2",1,0,10,0);
	PCB* p3 = new PCB("p3",2,0,12,0);
	//printf("ola1");
	ListaEncadeada<PCB>* l = new ListaEncadeada<PCB>();
	//printf("ola2");
	l->AdicionarNoInicio(p1);
	l->AdicionarNoInicio(p2);
	l->AdicionarNoInicio(p3);
	/*l->RetiraDaPosicao(3);

		for(int i = 0; i <= l->ObtemTamanho();i++){
			cout << l->obtemNo(i)->getExec() << endl;
		}
	*/
	RMS* t = new RMS(l);

	//printf("teste");
	//t->iniciarEscalonamento();



}



