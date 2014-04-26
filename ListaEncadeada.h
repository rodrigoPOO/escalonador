/*
 * CabecaDaLista.h
 *
 *  Created on: 15/09/2013
 *      Author: rodrigomello
 */

#ifndef LISTAENCADEADA_H_
#define LISTAENCADEADA_H_
#include "NoDaListaSimples.h"
#include <stdlib.h>
#include <iostream>
#include "CodificacaoErros.h"


using namespace std;
template <class T>
class ListaEncadeada {
int tamanho;
NoDaListaSimples<T>* primeiro;

public:
	ListaEncadeada();
	virtual ~ListaEncadeada();
	int AdicionarNoFim(T* elemento);
	int AdicionarNoInicio(T* elemento);
	int AdicionarNaPosicao(int posicao, T* elemento);
	T* RetiraDoInicio();
	T* obtemNo(int pos);
	NoDaListaSimples<T>* obtemPrimeiro();
	T* RetiraDaPosicao(int pos);
	T* RetiraDoFim();
	bool EstaVazia();
	int ObtemTamanho();
	void mostrar();

	void DestroiLista();



};

#include "ListaEncadeada.hpp"
#endif /* CABECADALISTA_H_ */
