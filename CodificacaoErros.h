/*
 * CodificacaoErros.h
 *
 *  Created on: 20/10/2013
 *      Author: cesar
 */

#ifndef CODIFICACAOERROS_H_
#define CODIFICACAOERROS_H_

const int ERROLISTAVAZIA = -1;
const int ERROLISTACHEIA = -2;
const int ERROPOSICAO = -3;
const int ERROELEMENTONAOENCONTRADO = -4;

class CodificacaoErros {
public:
	CodificacaoErros();
	virtual ~CodificacaoErros();
};

#endif /* CODIFICACAOERROS_H_ */
