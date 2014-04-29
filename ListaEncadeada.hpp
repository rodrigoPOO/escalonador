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
		return Retirar();
	}

	IteradorListaEncadeada<T> it = IteradorListaEncadeada<T>(this);
	for (int i = 1; i <= pos; i++) {
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
T* ListaEncadeada<T>::Retirar(){
	//remove o ultimo nó
			if(tamanho == 0){
				return this->RetiraDoInicio();
			}
		//adicionar caso possua só um elemento!
		NoDaListaSimples<T>* aux = new NoDaListaSimples<T>();
		aux = primeiro;
			while(aux->ObtemProximo() != NULL){
				aux = aux->ObtemProximo();
			}
		NoDaListaSimples<T>* penultimo = new NoDaListaSimples<T>();

		penultimo->DefinirProximo(NULL);
		T* dado = aux->ObtemInfo();
		delete (aux);
		tamanho--;
		return dado;

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
    int valor = tamanho;
    T* inf;
    NoDaListaSimples<T>* aux = primeiro;
    	for (int i = 0; i < tamanho; i++) {
			//std::cout << (*(aux->ObtemInfo()));
		}
    std::cout << (aux->ObtemInfo());
}

#endif
