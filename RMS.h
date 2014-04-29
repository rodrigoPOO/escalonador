/*
 * RMS.h
 *
 *  Created on: 25/04/2014
 *      Author: rodrigomello
 */

#ifndef RMS_H_
#define RMS_H_
#include "ListaEncadeada.h"
#include "PCB.h"
#include <stdio.h>


class RMS {
ListaEncadeada<PCB>* listaPCB;
ListaEncadeada<PCB> pronto;
ListaEncadeada<PCB> executando;
ListaEncadeada<PCB> bloqueado;
ListaEncadeada<PCB> terminado;


public:
	RMS();
	RMS(ListaEncadeada<PCB>* processos);
	virtual ~RMS();
	void moverProcessos();
	void prontoParaexecutando(PCB p);
	//void executandoParaterminado(PCB p);
	void executandoParabloqueado(PCB p);
	//void executandoParaterminado(PCB p);
	void decrementarProcesso(PCB p);
	void iniciarEscalonamento();
	void mostrarL();


};

#endif /* RMS_H_ */
