#pragma once
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL_events.h>
#include <vector>
#include "Gamepad.h"

enum ButtonStates {
	None,
	Pressed,
	Released
};

struct InputButton {
	int ActionId;
	int Code;
	ButtonStates State;

	InputButton() : ActionId(0), Code(0), State(ButtonStates::None) {}

	InputButton(int actionId, int code) : ActionId(actionId), Code(code), State(ButtonStates::None) {
	}
};

struct InputAxis {
	int ActionId;
	int NegativeCode;
	int PositiveCode;
	int Value;

	InputAxis() : ActionId(0), NegativeCode(-1), PositiveCode(1), Value(0) {}

	InputAxis(int actionId, int negativeCode, int positiveCode) : ActionId(actionId), NegativeCode(negativeCode),
		PositiveCode(positiveCode), Value(0) {}
};

class InputManager {

public:
	void PreHandleEvent();
	void HandleEvent(const SDL_Event* event);
	void Update(double elapsedSeconds);
	void AddController(Gamepad* controller);

	~InputManager();


private:
	std::vector<Gamepad*> _controllers;

};

#endif