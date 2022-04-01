#ifndef PLAYER_H
#define PLAYER_H

#include <Area2D.hpp>
#include <CollisionShape2D.hpp>
#include <Godot.hpp>
#include <Input.hpp>

namespace godot {

class Player : public Area2D {
	GODOT_CLASS(Player, Area2D)
	
public:
	
	void _init();
	void _ready();
	void _process(float delta);
	void _movement(float delta);
	void _on_Player_body_entered(godot::Node2D *_body);

	float _playerSpeed;
	float _playerMaxSpeed = 600;
	float _playerAcceleration = 700;
	float _playerDeceleration = 900;

	Input *_input;
	real_t _direction = 0;
	real_t _last_dir = 0;
	Vector2 _screen_size;
	CollisionShape2D *_collision_shape;

	static void _register_methods();
	};
}
#endif