/*
 * RMS.cpp
 *
 *  Created on: 25/04/2014
 *      Author: rodrigomello
 */

#include "RMS.h"

RMS::RMS() {
	// TODO Auto-generated constructor stub

}

RMS::~RMS() {
	// TODO Auto-generated destructor stub
}
void RMS::decrementarProcesso(PCB p){
	int v = p.getPrioridade();
	p.setPrioridade(--v);
	//aaaaaa
}

