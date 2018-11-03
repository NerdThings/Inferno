#include "SDL.h"
#include "PlatformGame.h"

namespace Inferno
{
	PlatformGame::PlatformGame(Game* parentGame)
	{
		_parentGame = parentGame;
	}

	bool PlatformGame::runEvents()
	{
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT) {
				return false;
			}
		}

		return true;
	}
}