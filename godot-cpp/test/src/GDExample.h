#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <Godot.hpp>
#include <Sprite.hpp>
#include <Timer.hpp>
#include <PackedScene.hpp>
#include <RandomNumberGenerator.hpp>
#include "GameUI.h"
#include <SceneTree.hpp>

namespace godot {

class GDExample : public Sprite {
	GODOT_CLASS(GDExample, Sprite)
	
public:
	GameUI *_gameUI;
	Timer *_spawnTimer;
	Timer *_countDown;
	Ref<RandomNumberGenerator> _random;
	
	Vector2 _screen_size;
	Ref<PackedScene> myAssteroid;
	inline static bool _endgame = false;
	inline static int _dodgeCounter = 0;
	
	static void _register_methods();

	void _init() {}
	void _ready();
	void _hit();
	void _miss();
	void _process(float delta);
	
	void _on_SpawnTimer();
	void _on_CountDown();
	};
}
#endif
