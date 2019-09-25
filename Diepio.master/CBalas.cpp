#include "Cbalas.h"

Cbalas::Cbalas(Direcciones direccion,int x,int y,int mouseX,int mouseY) : CPadre(area)
{
	this->direccion = direccion;
	this->bala = gcnew Bitmap("Sprites//Balas.png");
	this->bala->MakeTransparent(bala->GetPixel(2, 2));
	this->dx = 0;
	this->dy = 0;
	this->x = x;
	this->y = y;
	this->ancho = bala->Width;
	this->alto = bala->Height;
	area.Size = Size(4, 4);
	angle = atan2(mouseY-(y+40), mouseX-(x+40));
	dx = cos(angle) * 24;
	dy = sin(angle) * 24;
}

Rectangle Cbalas::get_rectangle()
{
	return Rectangle(this->indiceX*this->ancho, this->indiceY*this->alto, bala->Width, bala->Height);
}
void Cbalas::mover(Graphics ^ graficador)
{
	for (short j = 0;j < abs(dx); j++) x += Math::Sign(dx);
	for (short j = 0; j < abs(dy); j++) y += Math::Sign(dy);
	dibujar(graficador);
}

void Cbalas::dibujar(Graphics ^ graficador)
{
	Rectangle region = get_rectangle();
	this->area = Rectangle(x+40, y+40, ancho*0.25, alto*0.25);
	graficador->DrawImage(this->bala, area);
	this->indiceY = 0;
}
