#pragma once
#include "Object.h"
#include <vector>

class Scene {
protected:
	std::vector<Object*> _objects;
	std::vector<Object*> _ui;

public:
	Scene() = default;
	virtual void OnEnter();
	virtual void OnExit();
	virtual void Update();
	virtual void Render();
};