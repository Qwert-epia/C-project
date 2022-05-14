#include "Scene.h"

Scene::Scene() {
	_reinit = true;
}

Scene::~Scene() {
}

void Scene::init() {
	_reinit = false;
}

void Scene::reinit() {
	_reinit = true;
}

void Scene::render()
{
}

void Scene::update()
{
}
