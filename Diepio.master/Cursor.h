#pragma once
#include "CPadre.h"
ref class Ccursor : public CPadre {
	Bitmap^ diep;
	bool onOff;
	Direcciones lastKey;
	short cont;
public:
	Ccursor();
	Direcciones direccion;
	void mover();
	bool getOnOff();
	int getY();
protected:
	void dibujar(Graphics^ Graficador)override;
};