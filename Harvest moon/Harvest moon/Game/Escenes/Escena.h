#pragma once
#include "../../Engine/Graphics/Video.h"
#include "../../Engine/Graphics/ResourceManager.h"

class Escena
{
	//https://rivermanmedia.com/object-oriented-game-programming-the-scene-system/

public:
	Escena();
	// virtual: serveix per indicar que els metodes es poden redefinir en les classes heredades.	
	virtual void Init(Video* video, ResourceManager* rscManager);	// Inicialitzar l'escena.	
	virtual void ReInit();	// Fer resets de totes les variables/posicions de l'escena, si cal
	virtual void Render();	// Gestionar els dibuixos de l'escena
	virtual void Update();	// Gestionar els updates de l'escena

	/*void setReInit(bool loaded) { ferReInit = loaded; };
	bool calFerReInit() { return ferReInit; };*/

	virtual ~Escena();


protected:
	//	bool ferReInit; // Reload when returning to scene
	Video* _videoEscena;
	ResourceManager* _rscManagerEscena;
};