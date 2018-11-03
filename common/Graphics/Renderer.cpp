#include "Graphics/Renderer.h"
#include "Graphics/PlatformRenderer.h"

using namespace Inferno;
using namespace Graphics;

//Constructor

Renderer::Renderer()
{
	_platformRenderer = new PlatformRenderer();
	_rendering = false;
}

//Batch controls

void Renderer::begin(Matrix* translationMatrix)
{
	//Clear batch
	_batch.clear();

	//Mark as rendering
	_rendering = true;

	//Begin on platform side
	_platformRenderer->begin(translationMatrix);
}

void Renderer::end()
{
	//Draw batch
	for (RenderItem batchItem : _batch)
	{
		
	}

	//Mark as not rendering
	_rendering = false;

	//End on platform side
	_platformRenderer->end();
}
