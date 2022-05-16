#include "Casa.h"

void Casa::Init(Video* video, ResourceManager* rscManager)
{	
	_videoEscena = video;
	_rscManagerEscena = rscManager;

	_idImatgeInteriorCasa = rscManager->loadAndGetGraphicID("../../Resources/Images/Edificis/Interior casa.png");
}

void Casa::ReInit()
{
	_jugadorCasa->setPosicioX(100);
	_jugadorCasa->setPosicioY(100);
}

void Casa::Render()
{
}

void Casa::Update()
{
}
