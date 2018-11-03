#ifndef Inferno_PlatformGame
#define Inferno_PlatformGame

#include "Inferno.h"

namespace Inferno
{
	class Game;
	class INFERNO_API PlatformGame
	{
		const Game *_parentGame;
	public:
		PlatformGame(Game* parentGame);
		bool runEvents();
	};
}

#endif