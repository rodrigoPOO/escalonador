/*
 * IteradorListaEncadeada.cpp
 *
 *  Created on: 19/09/2013
 *      Author: cesar
 */
#ifndef ITERADORLISTAENCADEADA_HPP_
#define ITERADORLISTAENCADEADA_HPP_
#include "IteradorListaEncadeada.h"

template<class T>
IteradorListaEncadeada<T>::IteradorListaEncadeada(ListaEncadeada<T> *l) {

	iterador = l->obtemPrimeiro();

}
template<class T>
IteradorListaEncadeada<T>::~IteradorListaEncadeada() {
	// TODO Auto-generated destructor stub
}
template<class T>
bool IteradorListaEncadeada<T>::ExisteProximo(){
	if(iterador==NULL){
		return false;
	}else
		return true;
}
template<class T>
	NoDaListaSimples<T>* IteradorListaEncadeada<T>::Proximo(){
	NoDaListaSimples<T> *atual;
	atual = iterador;
	iterador = iterador->ObtemProximo();
	return atual;
}

#endif
