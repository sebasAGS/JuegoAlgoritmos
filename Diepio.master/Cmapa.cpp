#include "Cmapa.h"
#include "CDiep.h"


Cmapa::Cmapa(int nivel) : CPadre(area)
{
	this->mapa = gcnew Bitmap("Sprites\\espacio1.jpg");
	this->x = 0;
	this->y = 0;
	this->dx = 0;
	this->dy = 0;
	this->nivel = nivel;
	ultimaTecla = Ninguna;
	direccion = Ninguna;
}

void Cmapa::mover()
{
	if (direccion == Ninguna)
	{
		dx = 0;
		dy = 0;
	}
	if (direccion == Abajo)
	{
		if (y < 800)
		{
			dx = 0;
			dy = 10;
		}
		else
		{
			dx = 0;
			dy = 0;
		}
	}
	if (direccion == Arriba)
	{
		if (y > 0) {
			dx = 0;
			dy = -10;
		}
		else
		{
			dx = 0;
			dy = 0;
		}
	}
	if (direccion == Izquierda)
	{
		if (x > 0) {
			dx = -10;
			dy = 0;
		}
		else
		{
			dx = 0;
			dy = 0;
		}
	}
	if (direccion == Derecha)
	{
		if (x < 1000) {
			dx = 10;
			dy = 0;
		}
		else
		{
			dx = 0;
			dy = 0;
		}

	}
	y = y + dy;
	x = x + dx;
}

void Cmapa::dibujar(Graphics ^ graficador)
{
	Rectangle areaDibujar = Rectangle(x = x + dx , y = y + dy,500,500);
	this->area = Rectangle(area.Location.X, area.Location.Y, 1400,1450);
	graficador->DrawImage(mapa, area, areaDibujar, GraphicsUnit::Pixel);
}

void Cmapa::cambioNivel(int level)
{
	switch (level)
	{
	case 1 :

		mapa = gcnew Bitmap("Sprites\\espacio1.jpg");
		
		break;
	case 2:
		mapa = gcnew Bitmap("Sprites\\espacio2.jpg");
		break;
	case 3:
		mapa = gcnew Bitmap("Sprites\\espacio3.jpg");
		break;
	case 4:
		mapa = gcnew Bitmap("Sprites\\espacio4.jpg");
		break;
	case 5:
		mapa = gcnew Bitmap("Sprites\\espacio5.png");
		break;

	}
}
