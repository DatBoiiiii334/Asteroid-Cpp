#include "Player.h"
#include "GDExample.h"

using namespace godot;

void Player::_ready(){
	_input = godot::Input::get_singleton();
	_screen_size = get_viewport_rect().size;
	_playerSpeed = 0.0;
}

void Player::_init(){}

void Player::_process(float delta){
	Player::_movement(delta);
}

void Player::_movement(float delta){
	Vector2 myVelocity(0,0);
	float myInput = 0.0;	

	if(_input->is_action_pressed("ui_left")){
		myInput = _direction = -1.0;
	}else if(_input->is_action_pressed("ui_right")){
		myInput = _direction = 1.0;	
	}

	if(myInput == 0.0){
		if(_playerSpeed > 0){
			_playerSpeed -= delta * _playerDeceleration;
			if(_playerSpeed < 0){
				_playerSpeed = 0;
			}
		}else{
				_playerSpeed += delta * _playerDeceleration;
				if(_playerSpeed > 0){
					_playerSpeed = 0;
				}
			}
		}else{
		_playerSpeed += delta * myInput * _playerAcceleration;
		}

	if(_direction != _last_dir){
		_playerSpeed /= 2.0;
	}

	_last_dir = _direction;
	_playerSpeed = Math::clamp(_playerSpeed, -_playerMaxSpeed, _playerMaxSpeed);
	myVelocity.x = _playerSpeed;

	Vector2 playerPos = get_position();
	playerPos += myVelocity * delta;
	playerPos.x = Math::clamp(playerPos.x, (real_t)-50.0, _screen_size.x);
	set_position(playerPos);
}

void Player::_on_Player_body_entered(godot::Node2D *_body) {
	emit_signal("hit");
}

void Player::_register_methods() {
    godot::register_method("_ready", &Player::_ready);
    godot::register_method("_process", &Player::_process);
    register_method("_on_Player_body_entered", &Player::_on_Player_body_entered);
	register_property<Player, real_t>("_playerMaxSpeed", &Player::_playerMaxSpeed, 600.0);
	register_property<Player, real_t>("_playerAcceleration", &Player::_playerAcceleration, 800.0);
	register_property<Player, real_t>("_playerDeceleration", &Player::_playerDeceleration, 1500.0);
	register_signal<Player>("hit", Dictionary());
}