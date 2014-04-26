#ifndef LISTAENCADEADA_HPP_
#define LISTAENCADEADA_HPP_
#include "ListaEncadeada.h"
#include "IteradorListaEncadeada.h"

template<class T>
ListaEncadeada<T>::ListaEncadeada() {
	tamanho = -1;
	primeiro = NULL;
}
template<class T>
ListaEncadeada<T>::~ListaEncadeada() {
	DestroiLista();
}
template<class T>
void ListaEncadeada<T>::DestroiLista() {
	while(tamanho >= 0){
        delete(RetiraDoInicio());
	}
}
template<class T>
int ListaEncadeada<T>::ObtemTamanho() {
	return tamanho;
}

template<class T>
NoDaListaSimples<T>* ListaEncadeada<T>::obtemPrimeiro(){
	return primeiro;
}

template<class T>
int ListaEncadeada<T>::AdicionarNoFim(T* el) {

	if (primeiro == NULL) {
		return AdicionarNoInicio(el);
	} else {
		NoDaListaSimples<T> *novo;
		novo = new NoDaListaSimples<T>();
		if (novo == NULL) {
			throw ERROLISTACHEIA;
		}

		IteradorListaEncadeada<T> it = IteradorListaEncadeada<T>(this);

		NoDaListaSimples<T> *ultimo;

		while (it.ExisteProximo()) {

			ultimo = it.Proximo();
		}
		ultimo->DefinirProximo(novo);
		novo->DefinirInfo(el);
		tamanho++;
	}

	return 1;
}

template<class T>
int ListaEncadeada<T>::AdicionarNoInicio(T* el) {
	NoDaListaSimples<T> *novo;
	novo = new NoDaListaSimples<T>();
	if (novo == NULL) {
		throw ERROLISTACHEIA;

	}
	novo->DefinirProximo(primeiro);
	primeiro = novo;
	novo->DefinirInfo(el);
	tamanho++;
	return 1;
}

template<class T>
T* ListaEncadeada<T>::RetiraDoInicio() {
	if (EstaVazia()) {
		throw ERROLISTAVAZIA;
	}

	T *saiu;
	NoDaListaSimples<T> *volta;
	tamanho--;
	saiu = primeiro->ObtemInfo();
	volta = primeiro;
	primeiro = volta->ObtemProximo();
	delete volta;
	return saiu;
}
template<class T>
T* ListaEncadeada<T>::RetiraDaPosicao(int pos) {
	NoDaListaSimples<T>* antecessor;
	NoDaListaSimples<T>* noSaida;

	if (pos > tamanho) {
		throw ERROLISTAVAZIA;
	}
	if (pos == 0) {
		return RetiraDoInicio();
	}
	if (pos == tamanho) {
		return RetiraDoFim();
	}

	IteradorListaEncadeada<T> it = IteradorListaEncadeada<T>(this);
	for (int i = 1; i <= pos - 1; i++) {
		antecessor = it.Proximo();
	}
	noSaida = it.Proximo();
	antecessor->DefinirProximo(noSaida->ObtemProximo());
	tamanho--;
	T* dado = noSaida->ObtemInfo();
	delete (noSaida);
	return dado;
}

template<class T>
T* ListaEncadeada<T>::RetiraDoFim() {

	NoDaListaSimples<T>* antecessor;
	NoDaListaSimples<T>* ultimo;
	T* dadoSaida;

	if (EstaVazia()) {
		throw ERROLISTAVAZIA;
	}

	IteradorListaEncadeada<T> it = IteradorListaEncadeada<T>(this);

	while (it.ExisteProximo()) {
		antecessor = it.Proximo();

	}
	ultimo = it.Proximo();
	dadoSaida = ultimo->ObtemInfo();
	antecessor->DefinirProximo(NULL);
	tamanho--;

	delete ultimo;
	return dadoSaida;

}
template<class T>
bool ListaEncadeada<T>::EstaVazia() {
	return tamanho == -1;
}
template<class T>
T* ListaEncadeada<T>::obtemNo(int pos){
    if(pos < -1 || pos > tamanho){
        throw ERROPOSICAO;
    }
    NoDaListaSimples<T>* aux = primeiro;
        for(int i = 0; i < pos;i++){
            aux = aux->ObtemProximo();
        }
    return aux->ObtemInfo();
}
template<class T>
void ListaEncadeada<T>::mostrar(){
    std::cout << primeiro->ObtemInfo();
}

#endif
