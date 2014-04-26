/*
 * PCB.h
 *
 *  Created on: 21/04/2014
 *      Author: rodrigomello
 */

#ifndef PCB_H_
#define PCB_H_

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
	PCB(char* nome, int exec, int prior, int periodo, int estado);
	virtual ~PCB();
	int getPrioridade();
	int getPeriodo();
	int getEstado();
	void setPrioridade(int p);
	void setEstado(int p);


};

#endif /* PCB_H_ */
