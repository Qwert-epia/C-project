#pragma once
#include <string>
#include <vector>

#include "../../Efectes adversos/Temps/Estacio.h"
#include "Llavor.h"
#include "../../Mapa/Tileset.h"

class Cultiu {

public:
	std::string nom;
	float preu;
	int dies;
	int numFases;
	vector<int> fases;
	vector<Estacio> quanPlantar;
	bool renovable;
	string nomTilemap;		// sourceTsx
	vector<int> idTiles;	// Id de cada tile
};