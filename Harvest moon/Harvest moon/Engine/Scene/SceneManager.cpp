#include "SceneManager.h"

// Escenes
/*
#include "SceneMain.h"
#include "SceneOptions.h"
#include "SceneSaveLoad.h"
#include "SceneIntro.h"
#include "SceneGame.h"
#include "SceneGameOver.h"
*/


SceneManager* SceneManager::_sceneManagerInstance = NULL;

SceneManager* SceneManager::getInstance() {
	if (!_sceneManagerInstance) {
		_sceneManagerInstance = new SceneManager();
	}
	return _sceneManagerInstance;
}

SceneManager::SceneManager() {
	init();
}

SceneManager::~SceneManager() {
}

void SceneManager::init() {
	_vectorScenes.resize(NUM_SCENES);

	/*SceneMain* main = new SceneMain();
	SceneOptions* options = new SceneOptions();
	SceneSaveLoad* save = new SceneSaveLoad();
	SceneIntro* intro = new SceneIntro();
	SceneGame* game = new SceneGame();
	SceneGameOver* gameover = new SceneGameOver();

	_vectorScenes[MAIN] = main;
	_vectorScenes[OPTIONS] = options;
	_vectorScenes[SAVE_LOAD] = save;
	_vectorScenes[INTRO] = intro;
	_vectorScenes[GAME] = game;
	_vectorScenes[GAMEOVER] = gameover;

	main->init();
	options->init();
	save->init();
	config->init();
	intro->init();
	game->init();
	gameover->init();

	_currScene = MAIN;*/
}

void SceneManager::changeScene(EscenaEnum next_scene, bool reinit) {
	_vectorScenes[next_scene]->setReInit(reinit);
	_currScene = next_scene;
}
