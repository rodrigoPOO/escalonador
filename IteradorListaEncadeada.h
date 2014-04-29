/*
 * IteradorListaEncadeada.h
 *
 *  Created on: 19/09/2013
 *      Author: cesar
 */

#ifndef ITERADORLISTAENCADEADA_H_
#define ITERADORLISTAENCADEADA_H_
#include <stdlib.h>
#include "ListaEncadeada.h"

template<class T>
class IteradorListaEncadeada {
	NoDaListaSimples<T>* iterador;

public:
	IteradorListaEncadeada(ListaEncadeada<T>* l);
	virtual ~IteradorListaEncadeada();
	bool ExisteProximo();
	NoDaListaSimples<T>* Proximo();
};

#include "IteradorListaEncadeada.hpp"
#endif /* ITERADORLISTAENCADEADA_H_ */
