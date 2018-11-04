#include "Graphics/Color.h"
#include "Graphics/PlatformRenderer.h"
#include "Graphics/RenderItem.h"
#include "Matrix.h"
#include "Vector2.h"
#include "SDL_opengl.h"
using namespace Inferno;
using namespace Graphics;

//Constructor

PlatformRenderer::PlatformRenderer()
{
	
}

//Methods

void PlatformRenderer::begin(Matrix* translation_matrix) const
{
	if (translation_matrix == nullptr)
		translation_matrix = Matrix::identity;

	glLoadMatrixf(translation_matrix->get_array());
}

void PlatformRenderer::end() const
{
	
}

void PlatformRenderer::render(RenderItem* item) const
{
	//Apply color
	if (item->color == nullptr)
		item->color = new Color(1, 1, 1, 1);

	glColor4f(item->color->get_r(), item->color->get_g(), item->color->get_b(), item->color->get_a());

	//Apply line width
	glLineWidth(item->line_width);

	//Apply origin
	glTranslatef(-item->origin->x, -item->origin->y, 0.0f);

	//Apply rotation
	//TODO

	switch (item->type)
	{
		case rectangle:
			break;

		default:
			throw "Unsupported render item type.";
	}

	//Flush
	glFlush();

	//Restore matrix
	glPopMatrix();
}

