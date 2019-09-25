#pragma once


#include"CMenu.h"
namespace Game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	/// <summary>
	/// Resumen de Plataforma
	/// </summary>
	public ref class Plataforma : public System::Windows::Forms::Form
	{
		SoundPlayer^ variableSonido = gcnew SoundPlayer("MusicJuego.wav");
		SoundPlayer^ variableSonido2 = gcnew SoundPlayer("disparo.wav");
		BufferedGraphicsContext^ contexto;
		BufferedGraphics^ buffer;
		CMenu^ menu;
		Pen^ pencil;
		SolidBrush^ brocha;
		FontFamily^ ff;
		System::Drawing::Font^ font;
		

		int nivel;

			 int contador;
	public:
		Plataforma(void)
		{
			InitializeComponent();
			this->contexto     = BufferedGraphicsManager::Current;
			this->buffer       = contexto->Allocate(this->CreateGraphics(), this->ClientRectangle);
			this->menu         = gcnew CMenu(this->ClientRectangle);
			this->contador     = 0;
			this->ff           = gcnew FontFamily("Arial");
			this->font         = gcnew System::Drawing::Font("Arial", 30);
			this->brocha       = gcnew SolidBrush(Color::WhiteSmoke);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Plataforma()
		{
			if (components)
			{
				delete components;
				delete  contexto;
				delete  buffer;
				delete  menu;
				delete  ff;
				delete  font;
				delete  brocha;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		


#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Plataforma::timer1_Tick);
			// 
			// Plataforma
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1386, 788);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(9, 10, 9, 10);
			this->Name = L"Plataforma";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Plataforma";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Plataforma::Plataforma_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Plataforma::Plataforma_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Plataforma::Plataforma_KeyPress);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Plataforma::Plataforma_KeyUp);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Plataforma::Plataforma_MouseClick);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Plataforma_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		menu->Animar(buffer->Graphics,MousePosition.X,MousePosition.Y);
		switch (contador)
		{
		case 100:
			menu->getDiep()->cambNivel(2);
			menu->setNivel(2);
			break;
		case 200:
			menu->getDiep()->cambNivel(3);
			menu->setNivel(3);
			break;
		case 300:
			menu->getDiep()->cambNivel(4);
			menu->setNivel(4);
			break;
		case 400:
			menu->getDiep()->cambNivel(5);
			menu->setNivel(5);
			break;
		
		}
		
		if (menu->getOnPlay()==true)
		{
			contador++;
			buffer->Graphics->DrawString("Tiempo: " + Convert::ToString(contador), font, brocha, 900, 10);
			if (menu->getDiep()->getVidas()<=0)
			{
				timer1->Enabled = false;
			}
		}
		buffer->Render();
	}
	private: System::Void Plataforma_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	}
	private: System::Void Plataforma_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		menu->getDiep()->direccion = Direcciones::Ninguna;
		menu->getMapa()->direccion = Direcciones::Ninguna;
	}
	private: System::Void Plataforma_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		nivel = menu->getNivel();
			switch (e->KeyCode)
			{
			case Keys::W:
					menu->getDiep()->direccion = Direcciones::Arriba;
					menu->getMapa()->direccion = Direcciones::Arriba;
				break;
			case Keys::S:
					menu->getDiep()->direccion = Direcciones::Abajo;
					menu->getMapa()->direccion = Direcciones::Abajo;
				break;
			case Keys::Enter:
				variableSonido->PlayLooping();
					menu->setOnMenu(false);
					menu->setOnPlay(true);
				break;
			case Keys::A:
				menu->getDiep()->direccion = Direcciones::Izquierda;
				menu->getMapa()->direccion = Direcciones::Izquierda;

				break;
			case Keys::D:
				menu->getDiep()->direccion = Direcciones::Derecha;
				menu->getMapa()->direccion = Direcciones::Derecha;

				break;
			case Keys::Escape:
				if (menu->getOnMenu())
				{
					this->Close();
				}
				else
				{
					variableSonido->Stop();
					menu->setOnMenu(true);
					menu->setOnPlay(false);
				}
				break;
			case Keys::L:
				if (nivel<=4)
				{
					contador = contador + 100;
					nivel++;
					menu->setNivel(nivel);
					menu->getDiep()->cambNivel(nivel);
				}
				break;
			case Keys::J:
				if (nivel >= 2)
				{
					contador = contador - 100;
					nivel--;
					
					menu->setNivel(nivel);
					menu->getDiep()->cambNivel(nivel);
				}
				break;
			case Keys::Q:
				menu->getDiep()->disparar(MousePosition.X, MousePosition.Y);
				
				break;
			case Keys::R:
				menu->getDiep()->cambNivel(nivel);
				break;
			}
	}
	private: System::Void Plataforma_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
		menu->getDiep()->disparar(MousePosition.X, MousePosition.Y);
	}
};
}
