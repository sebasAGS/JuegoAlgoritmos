#pragma once
#include "CPadre.h"
#include"CBalasBuenas.h"
#include"CBalas.h"
ref class CDiep : public CPadre {
	Bitmap^ diep;
	int xDiep, yDiep;
	int dy;
	int dx;
	double angle;
	int nroSubimagenesLargo, nroSubimagenesAlto;
	double ancho, alto;
	int indiceX, indiceY;
	Direcciones ultimaTecla;
	List<CbalasBuenas^>^ balas2;
	int vidas;
	int nivel;
public:
	CDiep(int nivel);
	~CDiep() {
		delete diep;
		for (int i = 0; i < balas2->Count; i++)
		{
			delete balas2[i];
		}
		delete balas2;
	}

	void mover();
	void setX(int x) { this->xDiep = x; }
	void setY(int y) { this->yDiep = y; }
	int getX() { return this->xDiep; };
	int getY() { return this->yDiep; };
	Rectangle obtenerRegion();
	Direcciones direccion;
	void obtAngulo(int xMouse,int yMouse);
	void Animar(Graphics^ graficador, int xMouse, int yMouse) override;
	double getAngle() { return this->angle; }
	void disparar(int mouseX, int mouseY);
	List<CbalasBuenas^>^ getdisparos() { return this->balas2; }
	void setVidas(int vidas) { this->vidas = vidas; }
	int getVidas() { return this->vidas; }
	void cambNivel(int nivel);
	
protected:
	void dibujar(Graphics^ graficador, int xMouse, int yMouse)override;
};

//auto SetX = [=](int x, int xDiep) -> void {xDiep = x; };
//auto SetY = [=](int y, int yDiep) -> void {yDiep = y;};
//auto getX = [=](int xDiep) -> int {return xDiep; };
