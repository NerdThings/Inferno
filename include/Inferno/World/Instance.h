//
// Created by Reece Mackie on 15/11/18.
//

#ifndef INFERNO_INSTANCE_H
#define INFERNO_INSTANCE_H

#include "Inferno/Graphics/Renderer.h"
#include "Inferno/Graphics/Sprite.h"
#include "Inferno/Physics/BaseCollider.h"
#include "Inferno/Inferno.h"
#include "Inferno/Scene.h"
#include "Inferno/Vector2.h"

namespace Inferno {
    namespace World
    {
		/*
	 * A game instance
	 */
		class INFERNO_API Instance {
			//Fields

			/*
			 * The instance height
			 */
			int _height;

			/*
			 * The instance width
			 */
			int _width;

		protected:

			//Fields

			/*
			 * The instance position
			 */
			Vector2 _position = Vector2(0, 0);

		public:
			//Fields

			/*
			 * The instance collision checker
			 */
			Physics::BaseCollider* collider = nullptr;

			/*
			 * The instance depth
			 */
			float depth = 0;

			/*
			 * The instance parent scene
			 */
			Scene* parent_scene = nullptr;

			/*
			 * The instance rotation
			 */
			float rotation = 0;

			/*
			 * This is the point from which the instance will rotate from.
			 * This will not be applied to the sprite, use sprite->origin for that.
			 */
			Vector2 rotation_origin = Vector2();

			/*
			 * The instance sprite
			 */
			Graphics::Sprite* sprite = nullptr;

			/*
			 * The instance type.
			 * This is used for identifying an instance in collisions.
			 */
			std::string type = "";

			/*
			 * The instance velocity
			 * This is added to the position at the end of every frame
			 */
			Vector2 velocity = Vector2(0, 0);

			//Constructors

			/*
			 * Create a new Instance
			 */
			explicit Instance(Scene* parent_scene);

			/*
			 * Create a new Instance
			 */
			Instance(Scene* parent_scene, Vector2 position, float depth = 0);

			//Deconstructors

			/*
			 * Clean up a Deleted Instance
			 */
			~Instance();

			//Methods

			/*
			 * Begin updating the instance
			 */
			virtual void begin_update();

			/*
			 * Draw the instance
			 */
			virtual void draw(Graphics::Renderer* renderer);

			/*
			 * End instance update
			 */
			virtual void end_update();

			/*
			 * Get the instance bounds
			 */
			virtual Rectangle get_bounds();

			/*
			 * Get the instance height
			 */
			int get_height();

			/*
			 * Get the next position
			 */
			virtual Vector2 get_next_position();

			/*
			 * Get the current position
			 */
			virtual Vector2 get_position();

			/*
			 * Get the instance width
			 */
			int get_width();

			/*
			 * Set the instance height
			 */
			void set_height(int height);

			/*
			 * Set the instance position
			 */
			virtual void set_position(Vector2 position);

			/*
			 * Set the instance width
			 */
			void set_width(int width);

			/*
			 * Update the instance
			 */
			virtual void update();
		};
    }
}

#endif //INFERNO_INSTANCE_H
