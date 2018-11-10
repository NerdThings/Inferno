#include <cstdio>
#include "Graphics/Color.h"
#include "Graphics/Renderer.h"
#include "Graphics/RenderItem.h"
#include "Matrix.h"
#include "Rectangle.h"
#include "Vector2.h"

#ifdef SDL
#include "glad/glad.h"
#include "SDL_opengl.h"
#endif

namespace Inferno {
    namespace Graphics {
        //Private Methods
        void Renderer::render(RenderItem* item) const {
            if (item == nullptr)
                return;
#if OPENGL

            //Save matrix
            glPushMatrix();

            //Apply color
            if (item->color == nullptr)
                item->color = new Color(1, 1, 1, 1);

            glColor4f(item->color->get_r(), item->color->get_g(), item->color->get_b(), item->color->get_a());

            //Apply line width
            glLineWidth(item->line_width);

            //Apply origin
            if (item->origin != nullptr)
                glTranslatef(-item->origin->x, -item->origin->y, 0.0f);

            //Apply rotation
            //TODO

            switch (item->type) {
                case rectangle:
                    //Get coords
                    int left = item->destination_rectangle->get_left_coord();
                    int right = item->destination_rectangle->get_right_coord();
                    int top = item->destination_rectangle->get_top_coord();
                    int bottom = item->destination_rectangle->get_bottom_coord();

                    //Build vertex array

                    float* vertexArray = new float[8];
                    vertexArray[0] = left;
                    vertexArray[1] = top;
                    vertexArray[2] = right;
                    vertexArray[3] = top;
                    vertexArray[4] = right;
                    vertexArray[5] = bottom;
                    vertexArray[6] = left;
                    vertexArray[7] = bottom;

                    glBindBuffer(GL_ARRAY_BUFFER, _vertex_array);

                    glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), vertexArray, GL_STATIC_DRAW);

                    glDrawBuffer(GL_FRONT_AND_BACK);

                    glBindBuffer(GL_ARRAY_BUFFER, 0);

                    break;
            }

            //Flush
            glFlush();

            //Restore matrix
            glPopMatrix();

#endif
        }


        //Constructor

        Renderer::Renderer() {
            _rendering = false;

#if OPENGL

            //Create vertex array
            glGenVertexArrays(1, &_vertex_array);
            glBindVertexArray(_vertex_array);

#endif
        }

        //Batch controls

        void Renderer::begin(Matrix* translation_matrix) {
            if (_rendering)
                throw "Cannot call begin before calling end!";

            //Clear batch
            _batch.clear();

            //Mark as rendering
            _rendering = true;

            //Set matrix to identity if null
            if (translation_matrix == nullptr)
                translation_matrix = Matrix::identity;

            //Apply matrix
#if OPENGL

            //Soon, this will no longer be called, instead we will use a custom shader
            glLoadMatrixf(translation_matrix->get_array());

#endif
        }

        void Renderer::end() {
            if (!_rendering)
                throw "Cannot call end before calling begin!";

            //Draw batch
            for (RenderItem* batch_item : _batch)
            {
                render(batch_item);
            }

            //Mark as not rendering
            _rendering = false;
        }

        void Renderer::draw_rectangle(Rectangle* rect, Color* color, float depth) {
            RenderItem* item = new RenderItem();

            item->type = rectangle;
            item->destination_rectangle = rect;
            item->color = color;
            item->depth = depth;

            _batch.push_back(item);
        }

        //Draw calls

    }
}