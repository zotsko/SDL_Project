#pragma once
#include "SDL3/SDL.h"

#include <math.h>

#define TIME TimeManager::Instance()
class TimeManager {
private:
	TimeManager() : _deltaTime(0.0f), _elapsedTime(0.0f), _previousElapsedTime(0.0f) {
		_previousElapsedTime = (double)SDL_GetTicks() / 1000.0;
		_frameTime = 1.0f / (float)_FPS;
	}
	~TimeManager() = default;

	TimeManager(const TimeManager& t) = delete;
	TimeManager& operator=(const TimeManager& t) = delete;

	// Time Control
	float _deltaTime;
	float _elapsedTime;
	float _previousElapsedTime;

	//FPS Control
	const int _FPS = 60;
	float _frameTime;
public:
	static TimeManager& Instance() {
		static TimeManager instance;

		return instance;
	}

	float GetDeltaTime() { return _deltaTime; }
	float GetElasedTime() { return _elapsedTime; }

	// Para reiniciar delta time cuando sume el tiempo del frame
	bool ShouldUpdateGame() { return _deltaTime >= _frameTime; }

	void ResetDeltaTime() {
		_deltaTime = _deltaTime - (float)(floor(_deltaTime / _frameTime) * _frameTime);
	}

	void Update() {
		_elapsedTime = (double)SDL_GetTicks() / 1000.0;
		_deltaTime += _elapsedTime - _previousElapsedTime;
		_previousElapsedTime = _elapsedTime;
	}
};