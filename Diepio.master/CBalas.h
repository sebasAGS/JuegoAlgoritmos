#pragma once
#include "CPadre.h"
#include<math.h>

ref class Cbalas : public CPadre {
	int x, dx, y, dy;
	int indiceX;
	int indiceY;
	Bitmap^ bala;
	Direcciones direccion;
	int ancho;
	int alto;
	double angle;	
public:
	Cbalas(Direcciones direccion, int x, int y, int mouseX, int mouseY);
	~Cbalas() {
		delete bala;
	}
	/*int getX() { return this->x; }
	int getY() { return this->y; }*/
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	int getDX() { return this->dx; }
	int getDY() { return this->dy; }
	void mover(Graphics^ graficador);
	Rectangle get_rectangle();
	/*Rectangle getAreaBalas() 
	{ 
		return Rectangle(x, y, ancho, alto); 
	}*/
protected:
	void dibujar(Graphics^ graficador)override;
};

auto getX = [=](int x) -> int {return x; };
auto getY = [=](int y) -> int {return y; };
auto gerAreaBalas = [=](int x, int y, int ancho, int alto) ->Rectangle
{
	return Rectangle(x, y, ancho, alto);
};

	