#pragma once

#include "CPadre.h"
#include"Cmapa.h"
#include"CDiep.h"
#include"ChordaPeque.h"
#include"HordaMayor.h"

ref class CMenu : public CPadre {
	Bitmap^ menu;
	Bitmap^ gameover;
	Bitmap^ win;
	Pen^ pencil;
	SolidBrush^ brocha;
	FontFamily^ ff;
	System::Drawing::Font^ font;
	String^ Nivel;
	bool onMenu;
	bool onPlay;
	Cmapa^ mapa;
	CDiep^ diep;
	int nivel;
	ChordaPeque^ pequesTriangulo;
	ChordaPeque^ pequesCuadrado;
	ChordaPeque^ pequesPentagono;
	ChordaPeque^ curacion;
	ChordaPeque^ upc;
	CHordaMayor^ rojos;
	int vidas;
public:
	CMenu(Rectangle area);
	~CMenu()
	{
		delete menu;
		delete gameover;
		delete pencil;
		delete brocha;
		delete ff;
		delete font;
		delete Nivel;
		delete mapa;
		delete diep;
		delete pequesTriangulo;
		delete pequesCuadrado;
		delete pequesPentagono;
		delete upc;
		delete curacion;
		delete rojos;
	}
	bool getOnPlay() { return this->onPlay; }
	bool getOnMenu() { return this->onMenu; }
	void setOnPlay(bool OnPlay) { this->onPlay = OnPlay; }
	void setOnMenu(bool OnMenu) { this->onMenu = OnMenu; }
	void obMouse(int x, int y) {}
	CDiep^ getDiep() { return this->diep; }
	Cmapa^ getMapa() { return this->mapa; }
	void Animar(Graphics^ graficador, int xMouse, int yMouse) override;
	void setNivel(int nivel) { this->nivel = nivel; }
	int getNivel() { return this->nivel; }
	void movPeques(Graphics^ graficador);
	void movHordaMayor(Graphics^ graficador);
	void colision(List<Cbalas^>^ bala,Rectangle getAreaBalas);

protected:
	void dibujar(Graphics^ graficador, int xMouse, int yMouse) override;
};


//auto getOnPlay = [=](bool onPlay)-> bool {return onPlay; };
//auto SetNivel = [=](int nivel) -> int {return nivel};
