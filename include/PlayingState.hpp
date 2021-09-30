#pragma once
#include <SDL.h>
#include <vector>
#include "GameState.hpp"
#include "Text.hpp"
#include "Entity.hpp"
#include "Constants.hpp"
#include "BasicButton.hpp"

class PlayingState : public GameState {
public:
	PlayingState();
	void handleInput(Game &game, const SDL_Event &event);
	void update(Game &game);
	void setGameMode(game_mode mode);
	void cycleColor(bool backward);
	void randomPlayerToMove();
	void nextPlayerToMove(bool force = false);
	void updatePlayerMoveText();
	SDL_Texture *getArrowTex();
	void placeToken(int col);
	void checkWinOrDraw();
	void win(bool red_won);
	void draw();
	void resetGame();
	bool checkValidMouseLocation();
	int parseMouseLocation();
#ifdef DEBUG_CONTROLS
	void nearlyFillBoard();
#endif
private:
	game_mode game_mode_;
	int color_index_location_;
	std::vector<SDL_Color> colors_;
	Uint32 color_cycle_ticks_;
	bool won_;
	bool drawn_;
	bool player2_to_move_;
	Text player_to_move_text_;
	std::vector<Text> numbers_text_;
	Text win_text_;
	Text draw_text_;
	int mouse_x_;
	int mouse_y_;
	int current_mouse_location_;
	bool bound_to_board_;
	bool bound_to_restart_screen_;
	SDL_Texture *red_tex_;
	SDL_Texture *blue_tex_;
	SDL_Texture *red_arrow_;
	SDL_Texture *blue_arrow_;
	std::vector<std::vector<Entity>> board_;
	std::vector<Entity> display_arrows_;
	BasicButton restart_button_;
	BasicButton back_to_intro_button_;
#ifdef DEBUG_CONTROLS
	bool player_color_lock_;
#endif
};