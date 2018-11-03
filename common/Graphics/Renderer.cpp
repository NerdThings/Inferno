#include "Graphics/Color.h"
#include "Graphics/Renderer.h"
#include "Graphics/PlatformRenderer.h"
#include "Matrix.h"
#include "Rectangle.h"

using namespace Inferno;
using namespace Graphics;

//Constructor

Renderer::Renderer()
{
	_platform_renderer = new PlatformRenderer();
	_rendering = false;
}

//Batch controls

void Renderer::begin(Matrix* translation_matrix)
{
	//Clear batch
	_batch.clear();

	//Mark as rendering
	_rendering = true;

	//Begin on platform side
	_platform_renderer->begin(translation_matrix);
}

void Renderer::end()
{
	//Draw batch
	for (RenderItem* batch_item : _batch)
	{
		_platform_renderer->render(batch_item);
	}

	//Mark as not rendering
	_rendering = false;

	//End on platform side
	_platform_renderer->end();
}

void Renderer::draw_rectangle(Rectangle* rect, Color* color, float depth)
{
	RenderItem* item = new RenderItem();

	item->type = rectangle;
	item->destination_rectangle = rect;
	item->color = color;
	item->depth = depth;

	_batch.push_back(item);
}

//Draw calls
