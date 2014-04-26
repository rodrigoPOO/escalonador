/*
 * NoDaLista.cpp
 *
 *  Created on: 15/09/2013
 *      Author: rodrigomello
 */


#ifndef NODALISTASIMPLES_HPP_
#define NODALISTASIMPLES_HPP_
#include "NoDaListaSimples.h"
template <class T>
NoDaListaSimples<T>::NoDaListaSimples() {
	proximo = NULL;
	info = NULL;
}
template <class T>
NoDaListaSimples<T>::~NoDaListaSimples() {

}

template <class T>
T* NoDaListaSimples<T>::ObtemInfo() {
	return info;
}

template <class T>
NoDaListaSimples<T>* NoDaListaSimples<T>::ObtemProximo() {
	return proximo;
}

template <class T>
void NoDaListaSimples<T>::DefinirInfo(T* arg) {
	info = arg;
}

template <class T>
void NoDaListaSimples<T>::DefinirProximo(NoDaListaSimples * prox){
	proximo = prox;
}
template <class T>
void NoDaListaSimples<T>::LimparInfo(){
    delete(info);
}
#endif
