#pragma once
#include "../Escena.h"
#include "../DirectorEscenes.h"

class Casa : public Escena
{
public:
	
	void Init(Video* video, ResourceManager* rscManager);
	void ReInit();
	void Render();
	void Update();

	void setJugador(Jugador* jugador) { _jugadorCasa = jugador; };
	EscenaEnum getNumEscena() { return _numEscenaQueVullAnar; };


private:
	int _idImatgeInteriorCasa;
	Jugador* _jugadorCasa;
	EscenaEnum _numEscenaQueVullAnar;
};