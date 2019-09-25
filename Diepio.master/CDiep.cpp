#include "CDiep.h"
#include<math.h>


CDiep::CDiep(int nivel) : CPadre(area)
{
	this->nivel = nivel;
	diep = gcnew Bitmap("Sprites//Matriz3.png");
	diep->MakeTransparent(diep->GetPixel(2, 2));
	this->xDiep = 500;
	this->yDiep = 300;
	this->dx = 0;
	this->dy = 0;
	this->angle = 0;
	indiceX = 0;
	indiceY = 0;
	this->nroSubimagenesAlto = 10;
	this->nroSubimagenesLargo = 10;
	this->ancho = (diep->Width)/this->nroSubimagenesLargo;
	this->alto = (diep->Height)/this->nroSubimagenesAlto;
	this->balas2 = gcnew List<CbalasBuenas^>;
	ultimaTecla = Abajo;
	direccion = Ninguna;
	this->vidas = 100;
}

void CDiep::mover()
{

	if (direccion == Ninguna)
	{
		dx = 0;
		dy = 0;
	}
	if (direccion == Abajo)
	{
		if (yDiep < 700)
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
		if (yDiep > 0) {
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
		if (xDiep > 0)
		{
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
		if (xDiep < 1300)
		{
			dx = 10;
			dy = 0;
		}
		else
		{
			dx = 0;
			dy = 0;
		}

	}

	yDiep = yDiep + dy;
	xDiep = xDiep + dx;	
}
Rectangle CDiep::obtenerRegion()
{
	return Rectangle(indiceX*ancho, indiceY*alto, ancho , alto);
}
void CDiep::obtAngulo(int xMouse, int yMouse)
{
	double y = 0;
	double x = 0;
	int cuadrante = 0;
	if (xMouse> (xDiep + 40) && yMouse< (yDiep + 40))
	{
		cuadrante = 1;
		y = (yMouse - (yDiep + 40))*(-1);
		x = xMouse - (xDiep + 40);
	}
	if (xMouse< (xDiep + 60) && yMouse< (yDiep + 60))
	{
		cuadrante = 2;
		y = (yMouse - (yDiep + 60));
		x = (xMouse - (xDiep + 60));
	}
	if (xMouse < (xDiep + 60) && yMouse > (yDiep + 60))
	{
		cuadrante = 3;
		y = (yMouse - (yDiep + 60))*(-1);
		x = (xMouse - (xDiep + 60));
	}
	if (xMouse > (xDiep + 60) && yMouse > (yDiep + 60))
	{
		cuadrante = 4;
		y = (yMouse - (yDiep + 60));
		x = (xMouse - (xDiep + 60));
	}
	double radianes = atan((y/x));
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
void CDiep::Animar(Graphics ^ graficador, int xMouse, int yMouse)
{
	dibujar(graficador, xMouse, yMouse);
}
void CDiep::cambNivel(int nivel)
{
	switch (nivel)
	{
	case 1:
		diep = gcnew Bitmap("Sprites//Matriz3.png");
		break;
	case 2:
		diep = gcnew Bitmap("Sprites//personaje2SPRITE.png");
		break;
	case 3:
		diep = gcnew Bitmap("Sprites//personaje3SPRITE.png");
		break;
	case 4:
		diep = gcnew Bitmap("Sprites//personaje4SPRITE.png");
		break;
	case 5:
		diep = gcnew Bitmap("Sprites//personaje5SPRITE.png");
		break;
	}
}
void CDiep::dibujar(Graphics^ graficador, int xMouse, int yMouse)
{
	Rectangle region = obtenerRegion();
	this->area = Rectangle(xDiep, yDiep, 80, 80);
	graficador->DrawImage(this->diep, area, region, GraphicsUnit::Pixel);
	obtAngulo(xMouse, yMouse);

	int cont = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (angle >= cont * 3.6 && angle <= (cont+1) * 3.6)
			{
				indiceX = j;
				if (cont > i*10 && cont < (i+1)*(10)) indiceY = i;
			}
			cont++;
		}
	}

	for (short i = 0; i < balas2->Count; i++)
	{
		if (balas2[i]->getX() > xDiep+40|| balas2[i]->getX() < xDiep - 40 || balas2[i]->getY() > yDiep + 40|| balas2[i]->getY() > yDiep - 40)
		{
			balas2[i]->mover(graficador);
		}
		if (i>0)
		{
			if ((balas2[i]->getX()) < 0 || (balas2[i]->getY()) < 0|| (balas2[i]->getX()) > 1300 || (balas2[i]->getY()) > 700)
			{
				balas2->RemoveAt(i);
			}
		}

	}
}


void CDiep::disparar(int mouseX,int mouseY)
{
	this->balas2->Add(gcnew CbalasBuenas(ultimaTecla,xDiep,yDiep,mouseX,mouseY));
}