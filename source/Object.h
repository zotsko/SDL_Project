#pragma once
#include "Vector2.h"
#include "Renderer.h"
#include <SDL3/SDL.h>
#include <string>

#include"RigidBody.h"

class Object
{
private:
	bool _isPendingDestroy = false;
protected:
	Transform* _transform;
	Renderer* _renderer = nullptr;
	RigidBody* _physics;

public:
	Object() { _transform = new Transform(); _physics = new RigidBody(_transform); }
	~Object() {
		delete _transform;

		delete _physics;

		delete _renderer;
	}

	RigidBody* GetRigidBody() const { return _physics; }
	Transform* GetTransform() const { return _transform; }
	bool IsPendingDestroy() const { return _isPendingDestroy; }
	virtual void Destroy() { _isPendingDestroy = true; }
	virtual void Update() { 
		if (_physics != nullptr)
			_physics->Update(0.02f);

		_renderer->Update(0.02f); 
	}
	virtual void Render() { _renderer->Render(); }
};