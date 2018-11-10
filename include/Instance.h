#ifndef INFERNO_INSTANCE
#define INFERNO_INSTANCE

#include "Inferno.h"

namespace Inferno {
	class Scene;
	struct Vector2;
	struct Rectangle;

    class INFERNO_API Instance
    {
        //Fields

        //Collision mask

		int _height;

		Vector2* _position;

		int _width;

    public:

        //Fields

		bool affected_by_gravity;

        //CollisionMode

		Rectangle* collision_rectangle;

		float depth;

		bool draws;

		bool inherit_from_parent;

		Instance* parent;

		const Scene* parent_scene;

		float roughness;

        //Sprite

		bool updates;

		Vector2* velocity;

        //Constructor

		Instance(Scene parent_scene, Vector2 position, float depth = 0.0f, bool updates = false, bool draws = false, Instance* parent = nullptr);

        //Methods

        ///Parenting

		void remove_parent();

		void set_parent(Instance* parent);

        ///Management

		Instance* clone();

		void Destroy();

        ///Runtime

		virtual void begin_update();

		virtual void draw();

		virtual void end_update();

		virtual void update();

        //TODO: Collisions
    };
}

#endif