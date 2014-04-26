/*
 * NoDaLista.h
 *
 *  Created on: 15/09/2013
 *      Author: rodrigomello
 */

#ifndef NODALISTASIMPLES_H_
#define NODALISTASIMPLES_H_
#include <stdlib.h>
template<class T>
class NoDaListaSimples {
	T* info;
	NoDaListaSimples<T>* proximo;
public:

	NoDaListaSimples();
	virtual ~NoDaListaSimples();
	T* ObtemInfo();
	NoDaListaSimples* ObtemProximo();
	void DefinirInfo(T* info);
	void DefinirProximo(NoDaListaSimples* proximo);
	void LimparInfo();

};

#include "NoDaListaSimples.hpp"
#endif /* NODALISTASIMPLES_H_ */
