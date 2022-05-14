#include "DirectorEscenes.h"

#include "Especials/Intro.h"
#include "Especials/MainMenu.h"
#include "Especials/Proves.h"
#include "Granja/Granja.h"

DirectorEscenes* DirectorEscenes::_directorEscenesInstance = NULL;


void DirectorEscenes::Update()
{
	EscenaEnum numeroEscena = _LASTSCENE;
	
	switch (_escenaActual)
	{
	case INTRO: _vectorEscenes[INTRO]->Update(); break;
	case MAINMENU: _vectorEscenes[MAINMENU]->Update(); break;
	case GRANJA: _vectorEscenes[GRANJA]->Update(); numeroEscena = ((Granja*)_vectorEscenes[GRANJA])->getNumEscena(); break;
	case PROVES: _vectorEscenes[PROVES]->Update(); break;
	case _LASTSCENE: break;
	default:
		break;
	}

	if (numeroEscena != _LASTSCENE)
	{
		CanviEscena(numeroEscena);
	}
}

void DirectorEscenes::Render()
{
	switch (_escenaActual)
	{
	case INTRO: _vectorEscenes[INTRO]->Render(); break;
	case MAINMENU: _vectorEscenes[MAINMENU]->Render(); break;
	case GRANJA: _vectorEscenes[GRANJA]->Render(); break;
	case PROVES: _vectorEscenes[PROVES]->Render(); break;
	case _LASTSCENE: break;
	default:
		break;
	}
}

void DirectorEscenes::CanviEscena(EscenaEnum SeguentEscena)
{
	_vectorEscenes[SeguentEscena]->ReInit();
	_escenaActual = SeguentEscena;

	NomEscenaActual();
}

void DirectorEscenes::NomEscenaActual()
{
	switch (_escenaActual)
	{
	case INTRO: cout << "INTRO" << endl; break;
	case MAINMENU: cout << "MAINMENU" << endl; break;
	case GRANJA: cout << "GRANJA" << endl; break;
	case PROVES: cout << "PROVES" << endl; break;
	case _LASTSCENE: cout << "_LASTSCENE" << endl; break;
	default:
		break;
	}
}

DirectorEscenes::~DirectorEscenes()
{
}

DirectorEscenes::DirectorEscenes(Video* video, ResourceManager* rscManager, Jugador* jugador)
{
	_vectorEscenes.resize(NUM_SCENES);

	Intro* intro = new Intro();
	MainMenu* mainMenu = new MainMenu();
	Granja* granja = new Granja();
	Proves* proves = new Proves();

	_vectorEscenes[INTRO] = intro;
	_vectorEscenes[MAINMENU] = mainMenu;
	_vectorEscenes[GRANJA] = granja;
	_vectorEscenes[PROVES] = proves;

	intro->Init(video, rscManager);
	mainMenu->Init(video, rscManager);
	granja->Init(video, rscManager);
	granja->setJugador(jugador);
	proves->Init(video, rscManager);

	_escenaActual = INTRO;
}