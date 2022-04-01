#include "GameUI.h"
#include "GDExample.h"

using namespace godot;

void GameUI::_ready() {
	_scoreText = get_node<Label>("ScoreLabel");
	_timeText = get_node<Label>("TimeLabel");
	_timer = get_node<Timer>("GameTimer");
	_loseScreen = get_node<CanvasItem>("LoseScreen");
	_loseScreen->hide();
	_winScreen = get_node<CanvasItem>("WinScreen");
	_winScreen->hide();
}

void GameUI::StartGameTimer() {
	if(GDExample::_endgame) return;
	
	currentTime++;
	
	auto remaining_time = _duration - currentTime;
	String current_time = "0:";
	current_time += String::num_int64(remaining_time);
	_timeText->set_text(current_time);
	
	if(remaining_time <= 0) {
		DisplayWinScreen();
		return;
	}
	_timer->start();
}

void GameUI::DisplayLoseScreen() {
	GDExample::_endgame = true;
	_timer->stop();
	_loseScreen->show();
}

void GameUI::DisplayWinScreen() {
	GDExample::_endgame = true;
	_timer->stop();
	_winScreen->show();
}

void GameUI::UpdateScoreBoard(int p_score) {
	String text = "Assteroids dodged counter: ";
	text += String::num_int64(p_score);
	_scoreText->set_text(text);
}

void GameUI::_register_methods() {
	register_method("_ready", &GameUI::_ready);
	register_method("StartGameTimer", &GameUI::StartGameTimer);
	register_method("UpdateScoreBoard", &GameUI::UpdateScoreBoard);
	register_method("DisplayLoseScreen", &GameUI::DisplayLoseScreen);
	register_method("DisplayWinScreen", &GameUI::DisplayWinScreen);
	register_property("_duration", &GameUI::_duration, (real_t)60.0);
}