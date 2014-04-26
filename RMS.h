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

class RMS {
ListaEncadeada<PCB> listaPCB;
ListaEncadeada<PCB> pronto;
ListaEncadeada<PCB> executando;
ListaEncadeada<PCB> bloqueado;
ListaEncadeada<PCB> terminado;


public:
	RMS();
	virtual ~RMS();
	void moverProcessos();
	void prontoParaexecutando(PCB p);
	void executandoParaterminado(PCB p);
	void executandoParabloqueado(PCB p);
	void executandoParaterminado(PCB p);
	void bloqueadoParaexecutando(PCB p);
	void decrementarProcesso(PCB p);


};

#endif /* RMS_H_ */
