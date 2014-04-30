/*
 * RMS.cpp
 *
 *  Created on: 25/04/2014
 *      Author: rodrigomello
 */

#include "RMS.h"
#include <iostream>

using namespace std;

RMS::RMS(ListaEncadeada<PCB>* processos) {
	listaPCB = processos;
	pronto = *(processos);
	//organizar a lista por prioridade
	//cout << pronto.obtemPrimeiro()->ObtemInfo()->getPeriodo()<<endl;

	iniciarEscalonamento();
}
void RMS::iniciarEscalonamento(){
	while(pronto.obtemPrimeiro() != NULL){
		//primeiro elemento seria o mais prioritario.
		PCB* executar = pronto.obtemPrimeiro()->ObtemInfo();
		int pos = 0;
		int posicaoProcessoPrioritario;
		NoDaListaSimples<PCB>* aux = pronto.obtemPrimeiro();
		printf("%d\n",aux->ObtemInfo()->getPeriodo());
		int quant = pronto.ObtemTamanho();
			while(quant > 0){

				if(executar->getPeriodo() > aux->ObtemInfo()->getPeriodo()){
					executar = aux->ObtemInfo();
					printf("%d\n",pos);
					posicaoProcessoPrioritario = pos;
					//printf("%d\n",posicaoProcessoPrioritario);


				}
				printf("sem if %d\n",pos);
				pos++;
				aux = aux->ObtemProximo();
				quant++;

			}
		pronto.RetiraDaPosicao(posicaoProcessoPrioritario);
		executando.AdicionarNoInicio(executar);
		//processo é executado
		//int periodo = executando.obtemPrimeiro()->ObtemInfo()->getPeriodo();
		//int quantProc = listaPCB->ObtemTamanho();
			//if(periodo >= executando.obtemPrimeiro()->ObtemInfo()->getExec()){
		printf("processo com periodo %d foi executado\n",executar->getPeriodo());
		terminado.AdicionarNoFim(executando.RetiraDoInicio());
				//}
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

