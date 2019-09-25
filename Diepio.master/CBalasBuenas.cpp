#include "CBalasBuenas.h"




CbalasBuenas::CbalasBuenas(Direcciones direccion, int x, int y, int mouseX, int mouseY) : CPadre(area)
{
	this->direccion = direccion;
	this->balas2 = gcnew Bitmap("Sprites//BalasHero.png");
	this->balas2->MakeTransparent(balas2->GetPixel(2, 2));
	this->dx = 0;
	this->dy = 0;
	this->x = x;
	this->y = y;
	this->ancho = balas2->Width;
	this->alto = balas2->Height;
	area.Size = Size(4, 4);
	angle = atan2(mouseY - (y + 40), mouseX - (x + 40));
	dx = cos(angle) * 24;
	dy = sin(angle) * 24;
}

Rectangle CbalasBuenas::get_rectangle()
{
	return Rectangle(this->indiceX*this->ancho, this->indiceY*this->alto, balas2->Width, balas2->Height);
}
void CbalasBuenas::mover(Graphics ^ graficador)
{
	for (short j = 0;j < abs(dx); j++) x += Math::Sign(dx);
	for (short j = 0; j < abs(dy); j++) y += Math::Sign(dy);
	dibujar(graficador);
}

void CbalasBuenas::dibujar(Graphics ^ graficador)
{
	Rectangle region = get_rectangle();
	this->area = Rectangle(x + 40, y + 40, ancho*0.25, alto*0.25);
	graficador->DrawImage(this->balas2, area);
	this->indiceY = 0;
}