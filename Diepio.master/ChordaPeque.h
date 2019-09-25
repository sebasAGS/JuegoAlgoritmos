#pragma once
#include"CEnemigo.h"
#include"CDiep.h"
ref class ChordaPeque {
	List<CEnemigo^>^ hordapeques;
	Bitmap^ enemigo;
public:
	ChordaPeque(String^ Ruta) {
		
		hordapeques = gcnew List<CEnemigo^>;
		Random r;

		for (int i = 0; i < r.Next(4,6); i++)
		{
			hordapeques->Add(gcnew CEnemigo(r.Next(50,1300),r.Next(50,700), r.Next(1,4), r.Next(1, 4),Ruta));
		}
		
	}
	~ChordaPeque() {
		delete enemigo;
		for (int i = 0; i < hordapeques->Count; i++)
		{
			delete hordapeques[i];
		}
		delete hordapeques;
	}
	void mover(Graphics^ graficador)
	{

		for (int i = 0; i < hordapeques->Count; i++)
		{
			hordapeques[i]->mover(graficador);
		}
	}
	void moverCuadrado(Graphics^ graficador)
	{
		for (int i = 0; i < hordapeques->Count; i++)
		{
			hordapeques[i]->moverCuadrados(graficador);
		}
	}
	void moverPentagono(Graphics^ graficador)
	{
		for (int i = 0; i < hordapeques->Count; i++)
		{
			hordapeques[i]->moverPentagono(graficador);
		}
	}
	void moverCuracion(Graphics^ graficador)
	{
		for (int i = 0; i < hordapeques->Count; i++)
		{
			hordapeques[i]->moverCuracion(graficador);
		}
	}

	void moverUPC(Graphics^ graficador)
	{
		for (int i = 0; i < hordapeques->Count; i++)
		{
			hordapeques[i]->moverCuracion(graficador);
		}
	}
	void morir(List<CbalasBuenas^>^ balas2)
	{
		int vidas = 11;
		for (int i = 0; i < balas2->Count; i++)
		{
			for (int j = 0; j < hordapeques->Count; j++)
			{
				if (hordapeques[j]->getArea().IntersectsWith(balas2[i]->getArea()))
				{
					vidas--;
					if (vidas < 10)
					{
						hordapeques->RemoveAt(j);
					}
					else if(hordapeques[j]!=nullptr)
					{
						hordapeques[j]->setVidas(1);
					}

				}
			}
		}
	}
	List<CEnemigo^>^ getPeques()
	{
		return this->hordapeques;
	}
		

};

