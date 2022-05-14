#pragma once
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <vector>
#include "Scene.h"

//! Enum Scenes.
/*! All the Scenes in the game. */
enum EscenaEnum {
	INTRO, MAIN_MENU, CASA, GRANJA, ESTABLE_VAQUES, ESTABLE_GALLINES,
	CASETA_EINES, COVA, COVA_TAPADA, COVA_SPA, COVA_PROFUNDA,
	POBLE, FLOWER_SHOP, JUICE_BAR, CARPENTER, CHURCH, TOOL_SHOP, RESTAURANT, ANIMAL_SHOP,
	_LASTSCENE
};

#define NUM_SCENES _LASTSCENE

class SceneManager
{

public:
	~SceneManager();

	void init();

	void changeScene(EscenaEnum next_scene, bool reinit = true);

	EscenaEnum getCurrSceneEnum() { return _currScene; };

	Scene* getCurrentScene() { return _vectorScenes[_currScene]; };

	//! Gets pointer to instance
	static SceneManager* getInstance();

protected:
	SceneManager();	


private:
	std::vector<Scene*>	_vectorScenes;
	EscenaEnum		_currScene;

	static SceneManager* _sceneManagerInstance;	/*!<  pointer instance*/
};

#endif
