#ifndef ASTEROID_H
#define ASTEROID_H

#include <Godot.hpp>
#include <Input.hpp>
#include <Sprite.hpp>
#include <RigidBody2D.hpp>
#include <RandomNumberGenerator.hpp>
#include "GDExample.h"

namespace godot {
	class Asteroid : public RigidBody2D {
		GODOT_CLASS(Asteroid, RigidBody2D)

	public:

		GDExample *_mainFile;
		real_t _movement;
		real_t _movementSpeed;
		real_t _accelerationSpeed = 400;
		float _max_movementSpeed = 700;
		float _speed = 1.0;
		float _time;
		Ref<RandomNumberGenerator> _random;
		Vector2 direction = Vector2(0, 1);
	
		void _init();
		void _ready();
		void _process(float delta);
		void _destroy();
		
		static void _register_methods();
	};
}
#endif