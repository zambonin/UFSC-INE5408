//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a lista encadeada circular dupla.
/*! Classe que trata das operações relacionadas a listas circulares duplas. 
* \author Gustavo Zambonin, Lucas Ribeiro Neis
* \since 30/09/14
* \version 1.0
*/

#ifndef LISTADUPLACIRC_HPP_
#define LISTADUPLACIRC_HPP_
#include "ListaDupla.hpp"

template<typename T>
class ListaDuplaCirc : public ListaDupla<T> {
 private:
 	//! Sentinela da lista encadeada circular dupla.
	/*! Elemento que descreve o primeiro nó da lista circular dupla. */
	ElementoDuplo<T>* sentinela;

 public:
 	//! Construtor.
    /*! Construtor básico para a classe, sem parâmetros. */
	ListaDuplaCirc();

	//! Destrutor.
	/*! Destrutor que deleta todos os nós. */
	~ListaDuplaCirc();

	//! Método para adicionar um dado no fim da lista circular dupla.
	/*!
	* \param dado o endereço do objeto genérico a ser adicionado.
	* \sa adicionaNoInicioDuplo(), retiraDoInicioDuplo()
	*/
	void adicionaDuplo(const T& dado);

	//! Método para adicionar um dado no início da lista encadeada dupla.
	/*!
	* \param dado o endereço do objeto genérico a ser adicionado.
	* \sa adicionaDuplo(), retiraDoInicioDuplo()
	*/
	void adicionaNoInicioDuplo(const T& dado);

	//! Método para eliminar iterativamente cada elemento da lista circular.
	/*!
	* \sa ~eliminaDoInicioDuplo()
	*/
	void destroiListaDuplo();

	//! Método para eliminar o primeiro nó da lista circular dupla.
	/*!
	* \sa ~destroiListaDuplo()
	*/
	void eliminaDoInicioDuplo();

	//! Método para retirar o primeiro dado da lista.
 	/*!
 	* \return um objeto genérico que era o primeiro da lista.
	* \sa adicionaDuplo(), adicionaNoInicioDuplo()
 	*/	
	T retiraDoInicioDuplo();
};

template <typename T>
ListaDuplaCirc<T>::ListaDuplaCirc() : ListaDupla<T>() {
	ElementoDuplo<T>* sentinel = new ElementoDuplo<T>(0, 0, 0);
    this->cabeca = sentinel;
    sentinel->setProximo(this->cabeca);
    sentinel->setAnterior(this->cabeca);
    sentinela = sentinel;
}

template <typename T>
ListaDuplaCirc<T>::~ListaDuplaCirc() {
	this->destroiListaDuplo();
}

template <typename T>
ListaDuplaCirc<T>::adicionaDuplo(const T& dado) {
    if (ListaDupla<T>::listaVazia()) {
        return adicionaNoInicioDuplo(dado);
    }
    ElementoDuplo<T>* novo = new ElementoDuplo<T>(dado, 0, 0);
	ElementoDuplo<T>* anterior = sentinela->getAnterior();
	if (novo == 0) {
	    throw ExcecaoListaCheia();
    }
	anterior->setProximo(novo);
	novo->setProximo(sentinela);
	sentinela->setAnterior(novo);
	novo->setAnterior(anterior);
	this->tamanho++;
}

template <typename T>
ListaDuplaCirc<T>::adicionaNoInicioDuplo(const T& dado) {
	ElementoDuplo<T>* novo = new ElementoDuplo<T>(dado, 0, 0);
	if (novo == 0) {
		throw ExcecaoListaCheia();
	}
	novo->setProximo(this->cabeca);
	novo->setAnterior(sentinela);
	this->cabeca = novo;
	novo->getProximo()->setAnterior(novo);
	sentinela->setProximo(novo);
	this->tamanho++;
}

template <typename T>
ListaDuplaCirc<T>::destroiListaDuplo() {
   	ElementoDuplo<T>* atual;
	for (int i = 0; i < this->tamanho; i++) {
		atual = this->cabeca;
		this->cabeca = this->cabeca->getProximo();
		delete atual;
	}
    this->tamanho = 0;
}

template <typename T>
ListaDuplaCirc<T>::eliminaDoInicioDuplo() {
	ListaDupla<T>::eliminaDoInicioDuplo();
	sentinela->setProximo(this->cabeca);
	this->cabeca->setAnterior(sentinela);
}

template <typename T>
ListaDuplaCirc<T>::retiraDoInicioDuplo() {
   	T volta = ListaDupla<T>::retiraDoInicioDuplo();
	sentinela->setProximo(this->cabeca);
	this->cabeca->setAnterior(sentinela);
	return volta;
}

#endif
