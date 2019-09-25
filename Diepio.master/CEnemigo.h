#pragma once
#include "CPadre.h"
#include "Cbalas.h"
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Collections;
using namespace System::Collections::Generic;

ref class CEnemigo : public CPadre
{
	SolidBrush^ brocha;
	FontFamily^ ff;
	System::Drawing::Font^ font;
	int vidas;
	int x, y, dx, dy, dx2, dy2;
	Bitmap^ enemigo;
	Direcciones direccion;
	int ancho, alto;
	List<Cbalas^>^ balas;

	int osilacion;
	int cont;
public:
	CEnemigo(int x, int y, int dx, int dy,String^ ruta);
	~CEnemigo() {
		delete enemigo;
		for (int i = 0; i < balas->Count; i++)
		{
			delete balas[i];
		}
		delete balas;
		delete brocha;
		delete ff;
		delete font;
	}
	List<Cbalas^>^ getBalas() { return this->balas; }
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	int getDX();
	int getDY();
	int getVidas() { return this->vidas; }
	void setVidas(int vidas) { this->vidas = vidas; }
	void setDX(int dx) { this->dx = dx; }
	void setDY(int dy){ this->dy = dy; }
	void mover(Graphics^ graficador);
	void moverCuadrados(Graphics^ graficador);
	void moverPentagono(Graphics^ graficador);
	void moverCuracion(Graphics ^ graficador);
	void moverUPC(Graphics ^ graficador);
	void addBalas();
	void lessBalas();
protected:
	void dibujar(Graphics^ graficador)override;
};

