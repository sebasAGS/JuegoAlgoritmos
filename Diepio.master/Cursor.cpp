#include "Cursor.h"



Ccursor::Ccursor() : CPadre(area)
{
	this->diep = gcnew Bitmap("Sprites\\Cursor.png");
	this->area = Rectangle(530, 425,diep->Width*0.05,diep->Height*0.05);
	this->onOff = true;
}
bool Ccursor::getOnOff() { return this->onOff; }
void Ccursor::mover()
{
	short x = area.Location.X;
	short y = area.Location.Y;
	if (direccion == Arriba && y == 525 )
	{
		y = area.Location.Y - 100;
		direccion = Ninguna;
	}
	if (direccion == Abajo && y == 425 )
	{
		y = area.Location.Y + 100;
		direccion = Ninguna;
	}
	area.Location = Point(x, y);
}
void Ccursor::dibujar(Graphics^ graficador)
{
	graficador->DrawImage(diep, area);
}
int Ccursor::getY() { return this->area.Location.Y; }
