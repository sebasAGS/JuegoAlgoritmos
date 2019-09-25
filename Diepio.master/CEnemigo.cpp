#include "CEnemigo.h"

CEnemigo::CEnemigo(int x, int y, int dx, int dy,String^ Ruta) : CPadre(area)
{
	this->ff       = gcnew FontFamily("Arial");
	this->font     = gcnew System::Drawing::Font("Arial", 15);
	this->brocha   = gcnew SolidBrush(Color::DarkMagenta);
	this->balas    = gcnew List<Cbalas^>;
	this->vidas    = 3;
	this->enemigo  = gcnew Bitmap(Ruta);
	this->x   = x;
	this->y   = y;
	this->dx  = dx;
	this->dy  = dy;
	this->ancho = this->enemigo->Width;
	this->alto  = this->enemigo->Height;
	this->enemigo->MakeTransparent(enemigo->GetPixel(2, 2));
	Random r;
	this->osilacion = r.Next(0, 30);
	System::Threading::Thread::Sleep(10);
	this->cont = r.Next(60, 100);
	System::Threading::Thread::Sleep(10);
	this->dx2 = r.Next(10, 25);
	System::Threading::Thread::Sleep(10);
	this->dy2 = r.Next(10, 25);

}
void CEnemigo::addBalas()
{
	if (getDX() > 0)
	{
		direccion = Derecha;
	}
	if (getDX() < 0)
	{
		direccion = Izquierda;
	}
	if (getDY() > 0)
	{
		direccion = Abajo;
	}
	if (getDY() < 0)
	{
		direccion = Arriba;
	}
	
}

void CEnemigo::lessBalas()
{
	for (short i = 0; i < balas->Count; i++)
	{
		if (balas[i]->getX() + balas[i]->getDX() < 24 * 3 || (balas[i]->getX() + ancho + balas[i]->getDX()) > 1005 || balas[i]->getY() + balas[i]->getDY() < 24 * 3 || (balas[i]->getY() + alto + balas[i]->getDY()) > 24 * 28)
		{
			balas->RemoveAt(i);
		}
	}
}


void CEnemigo::dibujar(Graphics^ graficador)
{
	this->area = Rectangle(x, y, ancho, alto);
	graficador->DrawImage(enemigo,area);
	graficador->DrawString(Convert::ToString(vidas), font, brocha, x + (ancho / 3), y + (alto / 3));
}
int CEnemigo::getX() { return this->x; }
int  CEnemigo::getY() { return this->y; }
void  CEnemigo::setX(int x) { this->x = x; }
void  CEnemigo::setY(int y) { this->y = y; }
int CEnemigo::getDX() { return this->dx; }
int CEnemigo::getDY() { return this->dy; }

void CEnemigo::mover(Graphics^ graficador)
{
	if (x + this->dx < 0 || x + this->dx  > 1300)
	{
		this->dx *= -1;
	}
	if (y + this->dy < 0 || y + this->dy  > 700)
	{
		this->dy *= -1;
	}
	x = x + dx;
	y = y + dy;

	for (short i = 0; i < balas->Count; i++)
	{
		balas[i]->mover(graficador);
	}
	lessBalas();
	dibujar(graficador);
}
void CEnemigo::moverCuadrados(Graphics^ graficador)
{
	if (x + this->dx < 0 || x + this->dx  > 1300)
	{
		this->dx *= -1;
	}
	if (y + this->dy < 0 || y + this->dy  > 700)
	{
		this->dy *= -1;
	}
	Random r;

	if (r.Next(-10, 10) > 0)
	{
		dx *= -1;
	}
	else if (r.Next(-10, 10) < 0)
	{
		this->dy *= -1;
	}
	x = x + dx;
	y = y + dy;

	for (short i = 0; i < balas->Count; i++)
	{
		balas[i]->mover(graficador);
	}
	lessBalas();
	dibujar(graficador);
}

void CEnemigo::moverPentagono(Graphics ^ graficador)
{
	if (x + this->dx2 < 0 || x + this->dx2 > 1300)
	{
		this->dx2 *= -1;
	}
	else
	{
		if (osilacion >= cont)
		{
			this->dx2 *= -1;
			this->osilacion = 0;
		}
	}
	if (y + this->dy < 0 || y + this->dy2 > 700)
	{
		this->dy2 *= -1;
	}
	else
	{
		if (osilacion >= cont)
		{
			this->dy2 *= -1;
			this->osilacion= 0;
		}
	}
	osilacion++;
	x = x + dx2;
	y = y + dy2;
	dibujar(graficador);
}

void CEnemigo::moverCuracion(Graphics ^ graficador)
{
	if (x + this->dx2 < 0 || x + this->dx2 > 1300)
	{
		this->dx2 *= -1;
	}
	else
	{
		if (osilacion >= cont)
		{
			this->dx2 *= -1;
			this->osilacion = 0;
		}
	}
	if (y + this->dy < 0 || y + this->dy2 > 700)
	{
		this->dy2 *= -1;
	}
	else
	{
		if (osilacion >= cont)
		{
			this->dy2 *= -1;
			this->osilacion = 0;
		}
	}
	osilacion++;
	x = x + dx2;
	y = y + dy2;
	dibujar(graficador);
}

void CEnemigo::moverUPC(Graphics ^ graficador)
{
	if (x + this->dx2 < 0 || x + this->dx2 > 1300)
	{
		this->dx2 *= -1;
	}
	else
	{
		if (osilacion >= cont)
		{
			this->dx2 *= -1;
			this->osilacion = 0;
		}
	}
	if (y + this->dy < 0 || y + this->dy2 > 700)
	{
		this->dy2 *= -1;
	}
	else
	{
		if (osilacion >= cont)
		{
			this->dy2 *= -1;
			this->osilacion = 0;
		}
	}
	osilacion++;
	x = x + dx2;
	y = y + dy2;
	dibujar(graficador);
}

