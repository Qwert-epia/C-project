#include "Granja.h"

void Granja::Init(Video* video, ResourceManager* rscManager)
{
	_videoEscena = video;
	_rscManagerEscena = rscManager;

	// TODO: Guardar i/o obtenir el dia actual desde un fitxer
	dia = 0;
	meteoActual.climaActual = ASSOLELLAT;
	meteoActual.estacioActual = PRIMAVERA;
	map = Mapa::getInstance(_videoEscena, _rscManagerEscena);
}

void Granja::ReInit()
{
	_videoEscena->clearScreen();

	_posMonX = 34;
	_posMonY = 408;

	_dirActual = EST;

	_numEscenaQueVullAnar = GRANJA;

	map->setActivarRequadre(false);
	map->ResetsPosicioRequadre();
}

void Granja::Render()
{
	// Posicions Mon, Camera, Jugador i Requadre
	int posCamX = map->NovaPosicioCamX(_posMonX);
	int posCamY = map->NovaPosicioCamY(_posMonY);
	int posJugadorX = _posMonX - posCamX;
	int posJugadorY = _posMonY - posCamY;

	// RENDERS
	map->renderMap(posCamX, posCamY);
	_jugadorGranja->RenderJugador(posJugadorX, posJugadorY);
	map->RenderRequadre(_posMonX, _posMonY, posJugadorX, posJugadorY, _dirActual);
	_videoEscena->updateScreen();
}

void Granja::Update()
{
	std::cout << "Entra a granja" << endl;

	bool goexit = false;
	bool key_Up = false;
	bool key_Down = false;
	bool key_Right = false;
	bool key_Left = false;

	bool key_Requadre = false;
	bool key_Guardar = false;
	bool mouse_click_plantar = false;
	bool mouse_click_desplantar = false;

	do {
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type) {

			case SDL_KEYDOWN:
				if (event.key.keysym.scancode == SDL_SCANCODE_UP || event.key.keysym.scancode == SDL_SCANCODE_W) {
					key_Up = true;
				}
				if (event.key.keysym.scancode == SDL_SCANCODE_DOWN || event.key.keysym.scancode == SDL_SCANCODE_S) {
					key_Down = true;
				}
				if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT || event.key.keysym.scancode == SDL_SCANCODE_D) {
					key_Right = true;
				}
				if (event.key.keysym.scancode == SDL_SCANCODE_LEFT || event.key.keysym.scancode == SDL_SCANCODE_A) {
					key_Left = true;
				}
				break;

			case SDL_KEYUP:
				if (event.key.keysym.scancode == SDL_SCANCODE_UP || event.key.keysym.scancode == SDL_SCANCODE_W) { key_Up = false; }
				if (event.key.keysym.scancode == SDL_SCANCODE_DOWN || event.key.keysym.scancode == SDL_SCANCODE_S) { key_Down = false; }
				if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT || event.key.keysym.scancode == SDL_SCANCODE_D) { key_Right = false; }
				if (event.key.keysym.scancode == SDL_SCANCODE_LEFT || event.key.keysym.scancode == SDL_SCANCODE_A) { key_Left = false; }
				if (event.key.keysym.scancode == SDL_SCANCODE_E)
				{
					if (key_Requadre) key_Requadre = false;
					else key_Requadre = true;
				}
				if (event.key.keysym.scancode == SDL_SCANCODE_G)
				{
					if (!key_Guardar)
						key_Guardar = true;
				}
				break;

			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					mouse_click_plantar = true;
				}
				if (event.button.button == SDL_BUTTON_RIGHT)
				{
					mouse_click_desplantar = true;
				}
				break;

			default:
				break;
			}
		}

		if (key_Right)
		{
			_dirActual = EST;
			if (!map->HiHaObstacle_EST(_posMonX, _posMonY))
				_posMonX++;

			EscriurePosicio(_dirActual, map, key_Requadre);
		}
		if (key_Left)
		{
			_dirActual = OEST;
			if (!map->HiHaObstacle_OEST(_posMonX, _posMonY))
				_posMonX--;

			EscriurePosicio(_dirActual, map, key_Requadre);
		}
		if (key_Up)
		{
			_dirActual = NORD;
			if (!map->HiHaObstacle_NORD(_posMonX, _posMonY))
				_posMonY--;

			EscriurePosicio(_dirActual, map, key_Requadre);
		}
		if (key_Down)
		{
			_dirActual = SUD;
			if (!map->HiHaObstacle_SUD(_posMonX, _posMonY))
				_posMonY++;

			EscriurePosicio(_dirActual, map, key_Requadre);
		}


		if (key_Requadre) map->setActivarRequadre(true);
		else map->setActivarRequadre(false);

		if (key_Guardar)
		{
			map->GuardarMapa();
			std::cout << "Partida guardada!" << endl;
			key_Guardar = false;
		}
		if (mouse_click_plantar)
		{
			map->ModificarData_PlantarTomata();
			std::cout << "Tomata plantada!" << endl;
			mouse_click_plantar = false;
		}
		if (mouse_click_desplantar)
		{
			map->ModificarData_Desplantar();
			std::cout << "Desplantat!" << endl;
			mouse_click_desplantar = false;
		}


		// CELES ESPECIALS
		int contigutCela = map->ContigutCela();

		// Contenidor negocis
		if (contigutCela == 295)
		{
			// TODO : Incrementar diners segons el producte
			std::cout << "Toques contenidor" << endl;
		}

		// Canvis d'escenes
		if (contigutCela == 290)
		{
			goexit = true;
			_numEscenaQueVullAnar = POBLE;
			std::cout << "Vas a poble" << endl;
		}
		else if (contigutCela == 291)
		{
			goexit = true;
			_numEscenaQueVullAnar = CASA;
			std::cout << "Vas a casa" << endl;
		}
		else if (contigutCela == 292)
		{
			goexit = true;
			_numEscenaQueVullAnar = ESTABLE_VAQUES;
			std::cout << "Vas a vaques" << endl;
		}
		else if (contigutCela == 293)
		{
			goexit = true;
			_numEscenaQueVullAnar = ESTABLE_GALLINES;
			std::cout << "Vas a gallines" << endl;
		}
		else if (contigutCela == 294)
		{
			goexit = true;
			_numEscenaQueVullAnar = CASETA;
			std::cout << "Vas a caseta" << endl;
		}
		else
			Render();

	} while (!goexit);

	std::cout << "Surt de granja" << endl;
}

void Granja::EscriurePosicio(Direcio direcio, Mapa* map, bool actiu)
{
	switch (direcio)
	{
	case NORD: std::cout << "JugadorX:" << _posMonX << ", JugadorY:" << _posMonY << ", Dir:" << "NORD"; break;
	case SUD: std::cout << "JugadorX:" << _posMonX << ", JugadorY:" << _posMonY << ", Dir:" << "SUD"; break;
	case OEST: std::cout << "JugadorX:" << _posMonX << ", JugadorY:" << _posMonY << ", Dir:" << "OEST"; break;
	case EST: std::cout << "JugadorX:" << _posMonX << ", JugadorY:" << _posMonY << ", Dir:" << "EST"; break;
	default: break;
	}

	if (actiu)
		std::cout << ", RequadreX:" << map->getPosSquareX() << ", RequadreY:" << map->getPosSquareY() << endl;
	else
		std::cout << endl;
}