#include <SceneTree.hpp>
#include <NodePath.hpp>
#include <Viewport.hpp>
#include <string>
#include "GDExample.h"
#include "Player.h"
#include "Asteroid.h"
#include "GameUI.h"

using namespace godot;

void GDExample::_ready() { // Start fucntie
    _dodgeCounter = 0;
    _screen_size = get_viewport_rect().size;
    _random = (Ref<RandomNumberGenerator>)RandomNumberGenerator::_new();
    _random->randomize();

    _gameUI = get_node<GameUI>("GameUI");
    _spawnTimer = get_node<Timer>("SpawnTimer");
    _countDown = get_node<Timer>("Countdown");
    _countDown->start();
    
    GDExample::_endgame = false;
}

void GDExample::_hit() {
    if(GDExample::_endgame){
        return;
    } 
    _gameUI->DisplayLoseScreen();
}

void GDExample::_miss() {
    if(GDExample::_endgame){
       return; 
    } 
    _dodgeCounter++;
    _gameUI->UpdateScoreBoard(_dodgeCounter);
}

void GDExample::_on_SpawnTimer() {      
    if(GDExample::_endgame) return;
    
    godot::Node *Ass = myAssteroid->instance();
    add_child(Ass);
    
    Vector2 v = Vector2(_random->randf_range((double)0.0, (double)_screen_size.x - (double)10.0), -((double)_screen_size.y / (double)2.0));
    Ass->set("position", v);
}

void GDExample::_on_CountDown() {
    _spawnTimer->set_wait_time(_random->randf_range(1.1, 2.0));
    _spawnTimer->start();
}

void GDExample::_process(float delta) { // Update functie
    //_gameUI->_game_timer_tick();
}

void GDExample::_register_methods() {
    register_property("myAssteroid", &GDExample::myAssteroid, (Ref<PackedScene>)nullptr);
    godot::register_method("_ready", &GDExample::_ready);
    godot::register_method("_process", &GDExample::_process);

    register_method("_miss", &GDExample::_miss);
    register_method("_hit", &GDExample::_hit);
    register_method("_on_SpawnTimer", &GDExample::_on_SpawnTimer);
    register_method("_on_CountDown", &GDExample::_on_CountDown);
}

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
	godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
	godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
	godot::Godot::nativescript_init(handle);
	godot::register_class<GDExample>();
	godot::register_class<Player>();
    godot::register_class<Asteroid>();
    godot::register_class<GameUI>();
}