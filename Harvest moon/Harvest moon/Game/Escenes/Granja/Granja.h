#pragma once
#include "../Escena.h"
#include "../../Efectes adversos/Temps/Meteorologia.h"
#include "../../Mapa/Mapa.h"
#include "../../Jugador/Jugador.h";
#include "../DirectorEscenes.h"

class Granja : public Escena
{
public:
	int dia;
	Meteorologia meteoActual;
	Mapa* map;

	void Init(Video* video, ResourceManager* rscManager);
	void ReInit();
	void Render();
	void Update();

	void setJugador(Jugador* jugador) { _jugadorGranja = jugador; };
	EscenaEnum getNumEscena() { return _numEscenaQueVullAnar; };


private:
	int posMonX = 16;
	int posMonY = 16;
	Direcio dirActual = SUD;
	void EscriurePosicio(Direcio direcio, Mapa* map, bool actiu);
	Jugador* _jugadorGranja;
	EscenaEnum _numEscenaQueVullAnar;
};

