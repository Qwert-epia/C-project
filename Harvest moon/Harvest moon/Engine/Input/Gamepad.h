#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL_events.h>

class Gamepad {

public:
	virtual void HandleEvent(const SDL_Event* event) = 0;
	virtual bool GetButtonDown(int actionId) const = 0;
	virtual bool GetButtonUp(int actionId) const = 0;
	virtual bool GetButton(int actionId) const = 0;
	virtual double GetAxis(const int actionId) const = 0;


	virtual void ResetEvents() = 0;
};

#endif