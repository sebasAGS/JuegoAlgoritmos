#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace System::Media;
enum Direcciones {Arriba,Abajo,Derecha,Izquierda,Ninguna};
ref class CPadre{
protected:
	Rectangle area;
public:
	CPadre(Rectangle area) : area(area) {}
	~CPadre() {	}
	virtual void Animar(Graphics^ graficador) { dibujar(graficador); }
	bool colision(CPadre^ hijo) { return this->area.IntersectsWith(hijo->getArea()); }
	Rectangle getArea() { return this->area; }
protected:
	virtual void dibujar(Graphics^ graficador) {}
};

//auto getArea = [=](Rectangle area) -> Rectangle {return area; };