/*
 * PCB.h
 *
 *  Created on: 21/04/2014
 *      Author: rodrigomello
 */
#include <string.h>
#ifndef PCB_H_
#define PCB_H_
#include <stdio.h>
#define EXECUTANDO 1
#define ESPERANDO 2
#define PRONTO 0
#define TERMINADO 3


class PCB{

char* nome;
int execucao;
int prioridade;
int periodo;
int estado;


public:
	PCB(char* n, int exec, int prior, int per, int est);
	virtual ~PCB();
	int getPrioridade();
	int getPeriodo();
	int getEstado();
	int getExec();
	void setPrioridade(int p);
	void setEstado(int p);
	void setExec(int exec);

};

#endif /* PCB_H_ */
