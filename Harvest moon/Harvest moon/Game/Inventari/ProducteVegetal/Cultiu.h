#pragma once
#include <string>

enum Llavors
{
	NAP, PATATA, TOMAQUET, BLAT, ALBERGINIA, CACAUET, PASTANAGA, BROQUIL, HERBA
};

enum Estacions {
	PRIMAVERA, ESTIU, TARDO, HIVERN
};

class Cultiu
{
public:

private:
	std::string nom;
	float preu;
	int dies;
	int numFases;
	int fases[20];
	Estacions quanPlantar[4];
	bool renovable;
};