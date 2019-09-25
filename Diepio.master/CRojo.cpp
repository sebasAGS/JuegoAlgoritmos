#include "CRojo.h"
#include<math.h>


CRojo::CRojo(int x, int y, int dx, int dy) : CPadre(area)
{
	this->rojo = gcnew Bitmap("Sprites//enemigosRojo.png");
	rojo->MakeTransparent(rojo->GetPixel(2, 2));
	this->dx = dx;
	this->dy = dy;
	this->angle = 0;
	indiceX = 0;
	indiceY = 0;
	this->nroSubimagenesAlto = 10;
	this->nroSubimagenesLargo = 10;
	this->ancho = (rojo->Width) / this->nroSubimagenesLargo;
	this->alto = (rojo->Height) / this->nroSubimagenesAlto;
	this->balas = gcnew List<Cbalas^>;
	ultimaTecla = Abajo;
	direccion   = Ninguna;
	this->xRojo = x;
	this->yRojo = y;
	Random r;
	this->osilacion = r.Next(0, 30);
	System::Threading::Thread::Sleep(10);
	this->cont = r.Next(60, 100);
	System::Threading::Thread::Sleep(10);
	this->dx = r.Next(10, 25);
	System::Threading::Thread::Sleep(10);
	this->dy = r.Next(10, 25);
	this->disparos = 0;
}

void CRojo::mover(Graphics^ graficador,CDiep^ diep)
{
	if (xRojo + this->dx < 0 || xRojo + this->dx > 1300)
	{
		this->dx *= -1;
	}
	else
	{
		if (osilacion >= cont)
		{
			this->dx *= -1;
			this->osilacion = 0;
		}
	}
	if (yRojo + this->dy < 0 || yRojo + this->dy > 700)
	{
		this->dy *= -1;
	}
	else
	{
		if (osilacion >= cont)
		{
			this->dy *= -1;
			this->osilacion= 0;
		}
	}
	osilacion++;
	xRojo = xRojo + dx;
	yRojo = yRojo + dy;
	dibujar(graficador,diep->getX(),diep->getY());
	if (disparos > 25)
	{
		disparar(diep->getX(),diep->getY());
		disparos = 0;
	}
	disparos++;
}
Rectangle CRojo::obtenerRegion()
{
	return Rectangle(indiceX*ancho, indiceY*alto, ancho, alto);
}
void CRojo::obtAngulo(int xDiep, int yDiep)
{
	double y = 0;
	double x = 0;
	int cuadrante = 0;
	if (xDiep > (xRojo + 40) && yDiep < (yRojo + 40))
	{
		cuadrante = 1;
		y = (yDiep - (yRojo + 40))*(-1);
		x = xDiep - (xRojo + 40);
	}
	if (xDiep < (xRojo + 60) && yDiep < (yRojo + 60))
	{
		cuadrante = 2;
		y = (yDiep - (yRojo + 60));
		x = (xDiep - (xRojo + 60));
	}
	if (xDiep < (xRojo + 60) && yDiep >(yRojo + 60))
	{
		cuadrante = 3;
		y = (yDiep - (yRojo + 60))*(-1);
		x = (xDiep - (xRojo + 60));
	}
	if (xDiep > (xRojo + 60) && yDiep > (yRojo + 60))
	{
		cuadrante = 4;
		y = (yDiep - (yRojo + 60));
		x = (xDiep - (xRojo + 60));
	}
	double radianes = atan((y / x));
	angle = radianes * (180 / Math::PI);

	switch (cuadrante)
	{
	case 1:
		angle = angle;
		if (angle == NAN)
		{
			angle = 90;
		}
		break;
	case 2:
		angle = 90 + (90 - angle);
		if (angle == NAN)
		{
			angle = 180;
		}
		break;
	case 3:
		angle = 180 + angle;
		if (angle == NAN)
		{
			angle = 270;
		}
		break;
	case 4:
		angle = 270 + (90 - angle);
		if (angle == NAN)
		{
			angle = 360;
		}
		break;

	}

}
void CRojo::Animar(Graphics ^ graficador, int xMouse, int yMouse)
{
	dibujar(graficador, xMouse, yMouse);
}
void CRojo::dibujar(Graphics^ graficador, int xDiep, int yDiep)
{
	Rectangle region = obtenerRegion();
	this->area = Rectangle(xRojo, yRojo, 60, 60);
	graficador->DrawImage(this->rojo, area, region, GraphicsUnit::Pixel);
	obtAngulo(xDiep, yDiep);

	int cont = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (angle >= cont * 3.6 && angle <= (cont + 1) * 3.6)
			{
				indiceX = j;
				if (cont > i * 10 && cont < (i + 1)*(10)) indiceY = i;
			}
			cont++;
		}
	}

	for (short i = 0; i < balas->Count; i++)
	{
		if (balas[i]->getX() > xRojo + 40 || balas[i]->getX() < xRojo - 40 || balas[i]->getY() > yRojo + 40 || balas[i]->getY() > yRojo - 40)
		{
			balas[i]->mover(graficador);
		}
		if (i > 0)
		{
			if ((balas[i]->getX()) < 0 || (balas[i]->getY()) < 0 || (balas[i]->getX()) > 1300 || (balas[i]->getY()) > 700)
			{
				balas->RemoveAt(i);
			}
		}
	}
}


void CRojo::disparar(int xDiep, int yDiep)
{
	this->balas->Add(gcnew Cbalas(ultimaTecla, xRojo, yRojo, xDiep, yDiep));
}


