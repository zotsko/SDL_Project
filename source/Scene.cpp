#include "Scene.h"

void Scene::OnEnter()
{
}

void Scene::OnExit()
{
	for (Object* o : _objects) {
		delete o;
	}
	_objects.clear();

	for (Object* o : _ui) {
		delete o;
	}
	_ui.clear();
}

void Scene::Update() 
{
	// 1) Destruir objectos que pendientes de destrucción
	for (int i = _objects.size() - 1; i >= 0; i--) {
		if (_objects[i]->IsPendingDestroy()) {
			delete _objects[i];
			_objects.erase(_objects.begin() + 1);
		}
	}

	for (int i = _ui.size() - 1; i >= 0; i--) {
		if (_ui[i]->IsPendingDestroy()) {
			delete _ui[i];
			_ui.erase(_ui.begin() + 1);
		}
	}

	// 2) Actualizar objetos

	for (Object* o : _objects) {
		o->Update();
	}
	for (Object* u : _ui) {
		u->Update();
	}

	// 3) Comprovar colisiones
	int size = _objects.size();
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < _objects.size(); j++) {
			_objects[i]->GetRigidBody()->CheckCollision(_objects[j]->GetRigidBody());
		}
	}

	size = _ui.size();
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < _ui.size(); j++) {
			_ui[i]->GetRigidBody()->CheckCollision(_ui[j]->GetRigidBody());
		}
	}
	
}

void Scene::Render()
{
	for (Object* o : _objects) {
		o->Render();
	}
	for (Object* u : _ui) {
		u->Render();
	}
}