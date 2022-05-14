#include "Granja.h"

void Granja::Init(Video* video, ResourceManager* rscManager) {
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
}

void Granja::Render()
{
}

void Granja::Update()
{
	cout << "Entra a granja" << endl;

	bool goexit = false;
	bool key_Up = false;
	bool key_Down = false;
	bool key_Right = false;
	bool key_Left = false;

	bool key_escena1 = false;	// F5
	bool key_escena2 = false;	// F6
	bool key_escena3 = false;	// F7
	bool key_escena4 = false;	// F8

	bool key_Requadre = false;
	bool key_Guardar = false;
	bool mouse_click_plantar = false;
	bool mouse_click_desplantar = false;

	do {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {

			case SDL_QUIT:
				goexit = true;
				break;

			case SDL_KEYDOWN:
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
					goexit = true;
				}
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
				if (event.key.keysym.scancode == SDL_SCANCODE_G) {
					if (!key_Guardar)
						key_Guardar = true;
				}

				if (event.key.keysym.scancode == SDL_SCANCODE_F5) {
					if (!key_escena1)
						key_escena1 = true;
				}
				if (event.key.keysym.scancode == SDL_SCANCODE_F6) {
					if (!key_escena2)
						key_escena2 = true;
				}
				if (event.key.keysym.scancode == SDL_SCANCODE_F7) {
					if (!key_escena3)
						key_escena3 = true;
				}
				if (event.key.keysym.scancode == SDL_SCANCODE_F8) {
					if (!key_escena4)
						key_escena4 = true;
				}

				// SORTIR MANUAL
				if (event.key.keysym.scancode == SDL_SCANCODE_F1) {
					goexit = true;
				}
				break;

			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT) {
					mouse_click_plantar = true;
				}
				if (event.button.button == SDL_BUTTON_RIGHT) {
					mouse_click_desplantar = true;
				}
				break;

			default:
				break;
			}
		}

		if (key_Right)
		{
			dirActual = EST;
			if (!map->HiHaObstacle_EST(posMonX, posMonY))
				posMonX++;

			EscriurePosicio(dirActual, map, key_Requadre);
		}
		if (key_Left)
		{
			dirActual = OEST;
			if (!map->HiHaObstacle_OEST(posMonX, posMonY))
				posMonX--;

			EscriurePosicio(dirActual, map, key_Requadre);
		}
		if (key_Up)
		{
			dirActual = NORD;
			if (!map->HiHaObstacle_NORD(posMonX, posMonY))
				posMonY--;

			EscriurePosicio(dirActual, map, key_Requadre);
		}
		if (key_Down)
		{
			dirActual = SUD;
			if (!map->HiHaObstacle_SUD(posMonX, posMonY))
				posMonY++;

			EscriurePosicio(dirActual, map, key_Requadre);
		}



		if (key_escena1)
		{

		}
		if (key_escena2)
		{

		}
		if (key_escena3)
		{

		}
		if (key_escena4)
		{

		}



		if (key_Requadre) map->setActivarRequadre(true);
		else map->setActivarRequadre(false);

		if (key_Guardar)
		{
			map->GuardarMapa();
			cout << "Partida guardada!" << endl;
			key_Guardar = false;
		}
		if (mouse_click_plantar)
		{
			map->ModificarData_PlantarTomata();
			cout << "Tomata plantada!" << endl;
			mouse_click_plantar = false;
		}
		if (mouse_click_desplantar)
		{
			map->ModificarData_Desplantar();
			cout << "Desplantat!" << endl;
			mouse_click_desplantar = false;
		}


		// Posicions Mon, Camera, Jugador i Requadre
		int posCamX = map->NovaPosicioCamX(posMonX);
		int posCamY = map->NovaPosicioCamY(posMonY);
		int posJugadorX = posMonX - posCamX;
		int posJugadorY = posMonY - posCamY;

		// RENDERS
		map->renderMap(posCamX, posCamY);
		_jugadorGranja->RenderJugador(posJugadorX, posJugadorY);
		map->RenderRequadre(posMonX, posMonY, posJugadorX, posJugadorY, dirActual);

		_videoEscena->updateScreen();

		int contigutCela = map->ContigutCela();
		// Canvis d'escenes
		if (contigutCela == 290)
		{
			goexit = true;
			_numEscenaQueVullAnar = POBLE;
			cout << "Vas a poble" << endl;
		}
		else if (contigutCela == 291)
		{
			goexit = true;
			_numEscenaQueVullAnar = CASA;
			cout << "Vas a casa" << endl;
		}
		else if (contigutCela == 292)
		{
			goexit = true;
			_numEscenaQueVullAnar = ESTABLE_VAQUES;
			cout << "Vas a vaques" << endl;
		}
		else if (contigutCela == 293)
		{
			goexit = true;
			_numEscenaQueVullAnar = ESTABLE_GALLINES;
			cout << "Vas a gallines" << endl;
		}
		else if (contigutCela == 294)
		{
			goexit = true;
			_numEscenaQueVullAnar = CASETA;
			cout << "Vas a caseta" << endl;
		}

		// Contenidor negocis
		if (contigutCela == 295)
		{
			// TODO : Incrementar diners segons el producte
			cout << "Toques contenidor" << endl;
		}

	} while (!goexit);

	cout << "Surt de granja" << endl;
	_numEscenaQueVullAnar = INTRO;
}

void Granja::EscriurePosicio(Direcio direcio, Mapa* map, bool actiu)
{
	/*switch (direcio)
	{
	case NORD: cout << "JugadorX:" << posMonX << ", JugadorY:" << posMonY << ", Dir:" << "NORD"; break;
	case SUD: cout << "JugadorX:" << posMonX << ", JugadorY:" << posMonY << ", Dir:" << "SUD"; break;
	case OEST: cout << "JugadorX:" << posMonX << ", JugadorY:" << posMonY << ", Dir:" << "OEST"; break;
	case EST: cout << "JugadorX:" << posMonX << ", JugadorY:" << posMonY << ", Dir:" << "EST"; break;
	default: break;
	}

	if (actiu)
		cout << ", RequadreX:" << map->getPosSquareX() << ", RequadreY:" << map->getPosSquareY() << endl;
	else
		cout << endl;*/
}