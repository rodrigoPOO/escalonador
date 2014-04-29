/*
 * PCB.cpp
 *
 *  Created on: 21/04/2014
 *      Author: rodrigomello
 */

#include "PCB.h"

PCB::PCB(char* n, int exec, int prior, int per, int est) {
	nome = n;
	execucao = exec;
	prioridade = prior;
	periodo = per;
	estado = est;

}

PCB::~PCB() {
	// TODO Auto-generated destructor stub
}
int PCB::getExec(){
	 return execucao;
}
int PCB::getPeriodo(){
	 return periodo;
}



