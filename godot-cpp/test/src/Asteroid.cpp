#include "Asteroid.h"
#include <string>

using namespace godot;

void Asteroid::_init() {	
	_random = (Ref<godot::RandomNumberGenerator>)RandomNumberGenerator::_new();
	_random->randomize();
	_movement = _random->randf_range(10.0, 20.2);
	_movementSpeed = _random->randf_range(8.0, 12.0);
	_accelerationSpeed = _random->randf_range(1.0, 5.0);
	_speed = 0.5;
	_time = 0.0;
}

void Asteroid::_ready() {
	_mainFile = get_node<GDExample>("../");
}

void Asteroid::_process(float delta) {	
	_time += delta;
	Vector2 velocity(0, 0);
	Vector2 position = get_position();
	_speed += delta * _accelerationSpeed;
	_speed = Math::clamp(_speed, (float)0.0, _max_movementSpeed);
	position.y += _speed * (real_t)delta;
	position.x += sin(_time * _movementSpeed) * _movement;
	set_position(position);
	if(position.y > 600){
		_destroy();
	} 
}

void Asteroid::_destroy() {
	_mainFile->_miss();
	queue_free(); 
}

void Asteroid::_register_methods() {
	register_method("_process", &Asteroid::_process);
	register_method("_ready", &Asteroid::_ready);
	register_property("_max_movementSpeed", &Asteroid::_max_movementSpeed, (float)350.0);
	register_method("_destroy", &Asteroid::_destroy);
}