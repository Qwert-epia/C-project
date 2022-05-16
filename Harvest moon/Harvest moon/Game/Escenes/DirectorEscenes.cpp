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
	case INTRO:				_vectorEscenes[INTRO]->Update();			break;
	case MAINMENU:			_vectorEscenes[MAINMENU]->Update();			break;
	case GRANJA:			_vectorEscenes[GRANJA]->Update();	numeroEscena = ((Granja*)_vectorEscenes[GRANJA])->getNumEscena(); break;
	case POBLE:				_vectorEscenes[POBLE]->Update();			break;
	case CASA:				_vectorEscenes[CASA]->Update();				break;
	case ESTABLE_GALLINES:	_vectorEscenes[ESTABLE_GALLINES]->Update();	break;
	case ESTABLE_VAQUES:	_vectorEscenes[ESTABLE_VAQUES]->Update();	break;
	case CASETA:			_vectorEscenes[CASETA]->Update();			break;
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
	case INTRO:				_vectorEscenes[INTRO]->Render();			break;
	case MAINMENU:			_vectorEscenes[MAINMENU]->Render();			break;
	case GRANJA:			_vectorEscenes[GRANJA]->Render();			break;
	case POBLE:				_vectorEscenes[POBLE]->Render();			break;
	case CASA:				_vectorEscenes[CASA]->Render();				break;
	case ESTABLE_GALLINES:	_vectorEscenes[ESTABLE_GALLINES]->Render();	break;
	case ESTABLE_VAQUES:	_vectorEscenes[ESTABLE_VAQUES]->Render();	break;
	case CASETA:			_vectorEscenes[CASETA]->Render();			break;
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
	case INTRO:				cout << "INTRO" << endl;			break;
	case MAINMENU:			cout << "MAINMENU" << endl;			break;
	case GRANJA:			cout << "GRANJA" << endl;			break;
	case POBLE:				cout << "POBLE" << endl;			break;
	case CASA:				cout << "CASA" << endl;				break;
	case ESTABLE_GALLINES:	cout << "ESTABLE_GALLINES" << endl; break;
	case ESTABLE_VAQUES:	cout << "ESTABLE_VAQUES" << endl;	break;
	case CASETA:			cout << "CASETA" << endl;			break;
	case _LASTSCENE:		cout << "_LASTSCENE" << endl;		break;
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
	_vectorEscenes[POBLE] = granja;
	_vectorEscenes[CASA] = granja;
	_vectorEscenes[ESTABLE_GALLINES] = granja;
	_vectorEscenes[ESTABLE_VAQUES] = granja;
	_vectorEscenes[CASETA] = granja;

	intro->Init(video, rscManager);
	mainMenu->Init(video, rscManager);
	granja->Init(video, rscManager);
	granja->setJugador(jugador);
	proves->Init(video, rscManager);

	_escenaActual = INTRO;
}