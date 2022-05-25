#pragma once
#include <string>
#include <vector>

#include "../../Efectes adversos/Temps/Estacio.h"
#include "../../Mapa/Tileset.h"
#include "Llavor.h"

class Cultiu {

public:
	string nom;
	int preu;
	int dies;
	int numFases;
	vector<int> fases;
	vector<Estacio> quanPlantar;
	bool renovable;
	string nomTilemap;		// sourceTsx
	vector<int> idTiles;	// Id de cada tile
};