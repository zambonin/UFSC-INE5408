//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a pista.
/*! Classe que gerencia uma fila encadeada de carros.
 * \author Gustavo Zambonin, Lucas Ribeiro Neis
 * \since 09/10/14
 * \version 1.1
 */

#ifndef PISTA_H_
#define PISTA_H_
#include "Carro.h"
#include "FilaEnc.hpp"

class Pista : public FilaEnc<Carro *> {
private:
  //! Identificador de tamanho.
  /*! Descreve o tamanho da fila encadeada de carros. */
  int tamanho;

  //! Contador de carros que passaram por semáforos.
  /*! Descreve a quantidade de carros que trocaram de pista. */
  int carrosQuePassaram;

  //! Contador de carros que entraram no sistema.
  /*! Descreve a quantidade de carros que foram criados. */
  int carrosQueEntraram;

  //! Identificador de espaço ocupado.
  /*! Descreve o espaço ocupado por carros na pista. */
  int espacoOcupado;

  //! Identificador de velocidade média.
  /*! Descreve a velocidade média da pista. */
  int velocidadeMedia;

  //! Identificador de tempo de chegada.
  /*! Descreve o tempo necessário para chegar ao final da pista. */
  int tempoChegada;

  //! Identificador de tempo de criação positivo.
  /*! Descreve o máximo tempo do evento para ser criado um carro na pista. */
  int tempoCriacaoPos;

  //! Identificador de tempo de criação negativo.
  /*! Descreve o mínimo tempo do evento para ser criado um carro na pista. */
  int tempoCriacaoNeg;

  //! Identificador de pista fonte.
  /*! Descreve a habilidade de criação de carros da pista. */
  bool fonte;

  //! Identificador de pista sumidouro.
  /*! Descreve a habilidade de deleção de carros da pista. */
  bool sumidouro;

public:
  //! Construtor.
  /*! Define as características intrínsecas da pista, fornecidas previamente. */
  Pista(int _tamanho, int _velocidadeMedia, int _intervaloCriacao,
        int _tempoCriacao);

  // Método que adiciona um carro na fila encadeada.
  /*!
   * \param carro o ponteiro do carro a ser adicionado.
   * \sa removeCarro()
   */
  void adicionaCarro(Carro *carro);

  //! Método que remove um carro da fila encadeada.
  /*!
   * \sa adicionaCarro()
   */
  void removeCarro();

  //! Método que calcula o próximo evento da pista.
  /*!
   * \param tempoAtual descreve o tempo do evento atual, necessário para o
   * cálculo.
   * \return um inteiro.
   * \sa tempoDeChegada()
   */
  int calculeProximoEvento(int tempoAtual);

  //! Método que calcula o tempo de chegada necessário para o carro completar
  //! seu trajeto.
  /*!
   * \param tempoNasceu tempo do evento que o carro foi criado.
   * \return um inteiro.
   * \sa calculeProximoEvento()
   */
  int tempoDeChegada(int tempoNasceu);

  //! Método que retorna quantos carros passaram por semáforos.
  /*!
   * \return um inteiro.
   * \sa retornaCarrosQueEntraram()
   */
  int retornaCarrosQuePassaram();

  //! Método que retorna quantos carros foram criados pelo sistema.
  /*!
   * \return um inteiro.
   * \sa retornaCarrosQuePassaram()
   */
  int retornaCarrosQueEntraram();

  //! Método que verifica se a pista está cheia.
  /*!
   * \param carro o objeto a ser adicionado ao tamanho atual da pista.
   * \return um boolean.
   */
  bool estaCheia(Carro *carro);

  //! Método que retorna se a pista cria carros.
  /*!
   * \return um boolean.
   * \sa eSumidouro()
   */
  bool eFonte();

  //! Método que retorna se a pista deleta carros.
  /*!
   * \return um boolean.
   * \sa eFonte()
   */
  bool eSumidouro();
};

#endif
