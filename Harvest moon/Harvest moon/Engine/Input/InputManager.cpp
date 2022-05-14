#include "InputManager.h"

InputManager::~InputManager()
{
}

void InputManager::PreHandleEvent() {
	for (const auto& controller : _controllers) {
		controller->ResetEvents();
	}
}

void InputManager::HandleEvent(const SDL_Event* event) {


	for (const auto& controller : _controllers) {
		controller->HandleEvent(event);
	}
}

void InputManager::Update(double elapsedSeconds)
{
}

void InputManager::AddController(Gamepad* controller) {
	_controllers.push_back(controller);
}