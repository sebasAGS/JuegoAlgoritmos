#pragma once
#include "CPadre.h"
#include"CDiep.h"
#include"CBalas.h"
ref class CRojo : public CPadre {
	Bitmap^ rojo;
	int xRojo, yRojo;
	int dy;
	int dx;
	double angle;
	int nroSubimagenesLargo, nroSubimagenesAlto;
	double ancho, alto;
	int indiceX, indiceY;
	Direcciones ultimaTecla;
	List<Cbalas^>^ balas;
	int osilacion;
	int cont;
	int vidas;
	int disparos;
public:
	CRojo(int x, int y , int dx, int dy);
	~CRojo()
	{
		delete rojo;
		delete balas;
	}
	void mover(Graphics^ graficador,CDiep^ diep);
	void setX(int x) { this->xRojo = x; }
	void setY(int y) { this->yRojo = y; }
	int getX() { return this->xRojo; };
	int getY() { return this->yRojo; };
	int getVidas() { return this->vidas; }
	void setVidas(int vidas) { this->vidas = vidas; }
	Rectangle obtenerRegion();
	Direcciones direccion;
	void obtAngulo(int xMouse, int yMouse);
	void Animar(Graphics^ graficador, int xMouse, int yMouse) override;
	double getAngle() { return this->angle; }
	void disparar(int xDiep, int yDiep);
	List<Cbalas^>^ getdisparos() { return this->balas; }
protected:
	void dibujar(Graphics^ graficador, int xMouse, int yMouse)override;
};

//auto SetX = [=](int x, int xRojo) -> int { xRojo = x; };
//auto SetY = [=](int y, int yRojo) -> int { yRojo = y; };
//auto getAngle = [=](int angle)->double {return angle; };