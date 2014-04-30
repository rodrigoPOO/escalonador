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
	int tamanho = pronto.ObtemTamanho()+1;
	NoDaListaSimples<PCB>* aux;
		while(tamanho > 0){
			PCB* maisPrio = pronto.obtemPrimeiro()->ObtemInfo();
			int pos = 0;
			aux = pronto.obtemPrimeiro();
			int tamanhoAtual = pronto.ObtemTamanho()+1;
				for(int i = 0; i < tamanhoAtual;i++){
					cout << maisPrio->getPeriodo()<<endl;
					cout << aux->ObtemInfo()->getPeriodo()<<endl;
					if(maisPrio->getPeriodo() > aux->ObtemInfo()->getPeriodo()){
						//cout << pos;
						maisPrio = aux->ObtemInfo();
						pos = i;
					}
					aux = aux->ObtemProximo();
				}
				pronto.RetiraDaPosicao(pos);
				executando.AdicionarNoFim(maisPrio);
				cout << "pos que vai ser tirada" << pos<< endl;
				cout << "processo com periodo exec "<<maisPrio->getPeriodo() << endl;
				cout << maisPrio->getPeriodo();
				terminado.AdicionarNoFim(maisPrio);
				executando.Retirar();
				tamanho--;

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

