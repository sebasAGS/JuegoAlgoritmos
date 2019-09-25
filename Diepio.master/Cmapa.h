#pragma once
#include "CPadre.h"
ref class Cmapa : public CPadre {
	int x;
	int y;
	int dx;
	int dy;
	Bitmap^ mapa;
	int nivel;
	Direcciones ultimaTecla;
public:
	Cmapa(int nivel);
	~Cmapa() {
		delete mapa;
	}
	Direcciones direccion;
	void mover();
	void cambioNivel(int level);
protected:
	void dibujar(Graphics^ graficador)override;
};

