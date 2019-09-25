#pragma once
#include"CRojo.h"
#include"CDiep.h"
ref class CHordaMayor {
	List<CRojo^>^ hordaMayor;
	Bitmap^ enemigo;
public:
	CHordaMayor(int cantidad) {

		hordaMayor = gcnew List<CRojo^>;
		Random r;
		for (int i = 0; i < r.Next(cantidad, cantidad + r.Next(2,4)); i++)
		{
			hordaMayor->Add(gcnew CRojo(r.Next(50, 1300), r.Next(50, 700), r.Next(1, 4), r.Next(1, 4)));
		}

	}
	~CHordaMayor() {
		delete enemigo;
		for (int i = 0; i < hordaMayor->Count; i++)
		{
			delete hordaMayor[i];
		}
		delete hordaMayor;
	}
	void mover(Graphics^ graficador,CDiep^ diep)
	{
		for (int i = 0; i < hordaMayor->Count; i++)
		{
			hordaMayor[i]->mover(graficador,diep);
		}
	}

	void morir(List<CbalasBuenas^>^ balas2)
	{
		int vidas = 11;
		for (int i = 0; i < balas2->Count; i++)
		{
			for (int j = 0; j < hordaMayor->Count; j++)
			{
				if (hordaMayor[j]->getArea().IntersectsWith(balas2[i]->getArea()))
				{
					vidas--;
					if (vidas < 10)
					{
						hordaMayor->RemoveAt(j);
					}
					else if (hordaMayor[j] != nullptr)
					{
						hordaMayor[j]->setVidas(1);
					}
				}
			}
		}
	}
	

	void balasLess(CDiep ^ diep)
	{
		for (int i = 0; i < hordaMayor->Count; i++)
		{
			for (int j = 0; j < hordaMayor[i]->getdisparos()->Count; j++)
			{
				for (int z = 0; z < diep->getdisparos()->Count; z++)
				{
					//aveces aparece un error, es porque se generan muy rapido las balas y el contador no pasa por todas
					//solo se pon un sleep y no pasa nada

					if (hordaMayor[i]->getdisparos()[j]!=nullptr && diep->getdisparos()[z]!= nullptr && diep->getdisparos()[z]->colision(hordaMayor[i]->getdisparos()[j]))
					{
						diep->getdisparos()->RemoveAt(z);
						hordaMayor[i]->getdisparos()->RemoveAt(j);
					}
				}
			}
		}

	}

	//aca se implementa el choque de las balas con el diep, pero no me funciona son las 23:00
	//piedad :(
	/*void matar(CDiep^diep)
	{

		for (int i = 0; i < hordaMayor[i]->getdisparos()->Count; i++)
		{

			if (diep->colision(hordaMayor[i]->getdisparos()[i]))
			{
				diep->setVidas(diep->getVidas() - 1);
				
			}
		}
	}*/
	List<CRojo^>^ getHordaMayor()
	{
		return this->hordaMayor;
	}
};

