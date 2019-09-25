#include "CMenu.h"
#include "CBalas.h"


CMenu::CMenu(Rectangle area) : CPadre(area)
{
	this->menu  = gcnew Bitmap("Menu2.png");
	this->nivel = 1;
	this->mapa  = gcnew Cmapa(nivel);
	this->pequesTriangulo = gcnew ChordaPeque("Sprites//subenemigo2.png");
	this->pequesCuadrado  = gcnew ChordaPeque("Sprites//subenemigo1.png");
	this->pequesPentagono  = gcnew ChordaPeque("Sprites//subenemigo3.png");
	this->curacion = gcnew ChordaPeque("Sprites//CURACION.png");
	this->upc = gcnew ChordaPeque("Sprites//upc.png");
	this->gameover = gcnew Bitmap("Sprites//gameover.jpg");
	this->win = gcnew Bitmap("Sprites//win.png");
	if (nivel<2)
	{
		this->rojos = gcnew CHordaMayor(1);
	}
	else
	{
		this->rojos = gcnew CHordaMayor(3);
	}
	ff     = gcnew FontFamily("Arial");
	font   = gcnew System::Drawing::Font("Arial", 30);
	brocha = gcnew SolidBrush(Color::WhiteSmoke);
	onMenu = true;
	onPlay = false;
	diep   = gcnew CDiep(nivel);
	this->vidas = 10; 
}

void CMenu::Animar(Graphics ^ graficador, int xMouse, int yMouse)
{
	dibujar(graficador, xMouse, yMouse);
}

void CMenu::movPeques(Graphics^ graficador)
{
	for (int i = 0; i < pequesTriangulo->getPeques()->Count; i++)
	{
		if (diep->getX() < pequesTriangulo->getPeques()[i]->getX())
		{
			pequesTriangulo->getPeques()[i]->setDX(-2);
		}
		if (diep->getX() > pequesTriangulo->getPeques()[i]->getX())
		{
			pequesTriangulo->getPeques()[i]->setDX(2);
		}
		if (diep->getY() < pequesTriangulo->getPeques()[i]->getY())
		{
			pequesTriangulo->getPeques()[i]->setDY(-2);
		}
		if (diep->getY() > pequesTriangulo->getPeques()[i]->getY())
		{
			pequesTriangulo->getPeques()[i]->setDY(2);
		}
	}
	if (nivel==1 || nivel == 5||nivel==2|| nivel == 3 || nivel == 4)
	{
		pequesTriangulo->mover(graficador);
		pequesTriangulo->morir(diep->getdisparos());
	}
	if (nivel==2 || nivel == 5|| nivel == 3 || nivel == 4)
	{
		pequesCuadrado->moverCuadrado(graficador);
		pequesCuadrado->morir(diep->getdisparos());
	}
	if (nivel==3|| nivel==5 || nivel == 4)
	{
		pequesPentagono->moverPentagono(graficador);
		pequesPentagono->morir(diep->getdisparos());
	}
	if (nivel == 4 || nivel == 5)
	{
		curacion->moverCuracion(graficador);
		curacion->morir(diep->getdisparos());
	}

	if (nivel == 5)
	{
		upc->moverUPC(graficador);
	}


	for (int i = 0; i < pequesTriangulo->getPeques()->Count; i++)
	{
		if (diep->getArea().IntersectsWith(pequesTriangulo->getPeques()[i]->getArea()))
		{
			pequesTriangulo->getPeques()->RemoveAt(i);
			vidas--;
		}
	}
	for (int i = 0; i < pequesCuadrado->getPeques()->Count; i++)
	{
		if (diep->getArea().IntersectsWith(pequesCuadrado->getPeques()[i]->getArea()))
		{
			pequesCuadrado->getPeques()->RemoveAt(i);
			vidas--;

		}
	}
	for (int i = 0; i < pequesPentagono->getPeques()->Count; i++)
	{
		if (diep->getArea().IntersectsWith(pequesPentagono->getPeques()[i]->getArea()))
		{
			pequesPentagono->getPeques()->RemoveAt(i);
			vidas--;

		}
	}

	for (int i = 0; i < curacion->getPeques()->Count; i++)
	{
		if (diep->getArea().IntersectsWith(curacion->getPeques()[i]->getArea()))
		{
			curacion->getPeques()->RemoveAt(i);
			vidas++;

		}
	}

	for (int i = 0; i < upc->getPeques()->Count; i++)
	{
		if (diep->getArea().IntersectsWith(upc->getPeques()[i]->getArea()))
		{
			curacion->getPeques()->RemoveAt(i);
			vidas = vidas + 5;

		}
	}

}
void CMenu::colision(List<Cbalas^>^ bala,Rectangle getAreaBalas)
{
	for (int i = 0; i < bala->Count; i++)
	{

		if (diep->getArea().IntersectsWith(bala[i]->getAreaBalas()))
		{
			vidas--;
		}
	}
}



void CMenu::movHordaMayor(Graphics ^ graficador)
{
	rojos->mover(graficador, diep);
	rojos->morir(diep->getdisparos());
	rojos->balasLess(diep);
	
	for (int i = 0; i < rojos->getHordaMayor()->Count; i++)
	{
		if (rojos->getHordaMayor()[i]->colision(diep))
		{
			vidas--;
		}
	}
	//rojos->matar(diep);
}

void CMenu::dibujar(Graphics^ graficador, int xMouse, int yMouse)
{
	Nivel = gcnew String("Nivel : " + Convert::ToString(nivel));
	if (onMenu)
	{
		graficador->DrawImage(menu, area);
		graficador->DrawString(Nivel, font, brocha, 950, 650);
	}
	else if(onPlay)
	{
		mapa->Animar(graficador);
		diep->Animar(graficador,xMouse,yMouse);
		mapa->cambioNivel(nivel); 
		//graficador->DrawString(Convert::ToString(diep->getAngle()), font, brocha, 50, 50); 
		graficador->DrawString(Convert::ToString(diep->getVidas()), font, brocha, 1, 1);
		movPeques(graficador);
		diep->mover();
		mapa->mover();
		
		movHordaMayor(graficador);
		
		diep->setVidas(vidas);
		if (vidas<=0)
		{
			graficador->DrawImage(gameover,Rectangle(0,0,area.Width,area.Height));
		}
		else if (vidas > 15)
		{
			graficador->DrawImage(win, Rectangle(0, 0, area.Width, area.Height));
		}
	}
}
