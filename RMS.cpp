/*
 * RMS.cpp
 *
 *  Created on: 25/04/2014
 *      Author: rodrigomello
 */

#include "RMS.h"

RMS::RMS(ListaEncadeada<PCB>* processos) {
	listaPCB = processos;
	//listaPCB->mostrar();
	//organizar a lista por prioridade
}
void RMS::iniciarEscalonamento(){
	//primeiro elemento seria o mais prioritario.
	PCB* executar = listaPCB->RetiraDoInicio();
	executando.AdicionarNoInicio(executar);
	int periodo = executando.obtemPrimeiro()->ObtemInfo()->getPeriodo();
	//int quantProc = listaPCB->ObtemTamanho();
		if(periodo >= executando.obtemPrimeiro()->ObtemInfo()->getExec()){
				terminado.AdicionarNoFim(executando.RetiraDoInicio());
			}

}

RMS::~RMS() {
	// TODO Auto-generated destructor stub
}
/*void RMS::decrementarProcesso(PCB p){
	p.setExec(--p.getExec());
}
void RMS::executandoParabloqueado(PCB p){
	//processo vai do estado executando para bloqueado quando o seu periodo acaba mas ele nao termina sua execução
	executando.RetiraDoInicio();
	bloqueado.AdicionarNoFim((PCB *)p);
}*/
void RMS::mostrarL(){
	//terminado.mostrar();
}

