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
	tempo = 0;
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
					if(maisPrio->getPeriodo() > aux->ObtemInfo()->getPeriodo()){

						maisPrio = aux->ObtemInfo();
						pos = i;
					}
					aux = aux->ObtemProximo();
				}
				pronto.RetiraDaPosicao(pos);
				cout << "tamanho atual" << tamanhoAtual << endl;
				cout << "tamanho total" << tamanho << endl;
				if(tamanho == tamanhoAtual){
					tempo++;
					executando.AdicionarNoFim(maisPrio);
					cout << "processo com periodo exec "<<maisPrio->getPeriodo() << endl;
					cout << "processo tem " << maisPrio->getExec() << endl;
					maisPrio->decremento();
					cout << "processo foi decrementado e tem " << maisPrio->getExec() << endl;
						if(maisPrio->getExec() == 0){
							cout << "processo acabou" << endl;
							terminado.AdicionarNoFim(maisPrio);
							executando.Retirar();
							tamanho--;

						}else{
							cout << "voltou para pronto" << endl;
							pronto.AdicionarNoFim(maisPrio);

						}

					//cout << "pos que vai ser tirada" << pos<< endl;

					//cout << maisPrio->getPeriodo();

				}

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

