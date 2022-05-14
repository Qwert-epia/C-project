#pragma once
enum Estacio
{
	PRIMAVERA, ESTIU, TARDO, HIVERN
};

enum Clima
{
	ASSOLELLAT, PLUJA, TORNADO, NEVA
};

class Meteorologia
{
public:
	Estacio estacioActual;
	Clima climaActual;
};

