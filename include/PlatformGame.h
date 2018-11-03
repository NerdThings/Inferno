#ifndef Inferno_PlatformGame
#define Inferno_PlatformGame

#include "Inferno.h"

namespace Inferno
{
	class Game;

	class INFERNO_API PlatformGame
	{
		const Game *_parent_game;
	public:
		PlatformGame(Game* parent_game);
		bool run_events();
	};
}

#endif