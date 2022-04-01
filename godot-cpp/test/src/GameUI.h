#ifndef GAMEUI
#define GAMEUI

#include <Godot.hpp>
#include <string>
#include <CanvasLayer.hpp>
#include <Label.hpp>
#include <Timer.hpp>
#include <CanvasItem.hpp>

namespace godot {
	class GameUI: public CanvasLayer {
		GODOT_CLASS(GameUI, CanvasLayer)

	public:
		Label *_scoreText;
		Label *_timeText;
		Timer *_timer;
		CanvasItem *_loseScreen;
		CanvasItem *_winScreen;
		float currentTime= 0.0;
		real_t _duration = 60.0;

		void _init() {} 
		void _ready();
		void DisplayLoseScreen();
		void DisplayWinScreen();
		void UpdateScoreBoard(int score);
		void StartGameTimer();
		static void _register_methods();
	};
}
#endif