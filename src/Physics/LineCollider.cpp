//
// Created by Reece Mackie on 12/12/18.
//

#include "Inferno/Physics/CircleCollider.h"
#include "Inferno/Physics/LineCollider.h"
#include "Inferno/Physics/RectangleCollider.h"

namespace Inferno {
    namespace Physics {
        //Constructors
    
        LineCollider::LineCollider(Instance *instance, std::vector<Line> lines) : BaseCollider(instance), lines(lines) {}
        
        //Methods
        
        bool LineCollider::check_collisions(Vector2 position) {
            //Add the position onto each line
            std::vector<Line> old_lines = lines;
            std::vector<Line> new_lines;
            for (Line line : lines) {
                Vector2 p1 = line.p1 + position;
                Vector2 p2 = line.p2 + position;
                new_lines.emplace_back(Line(p1, p2));
            }
            
            lines = new_lines;
            
            bool pass = BaseCollider::check_collisions(position);
            
            lines = old_lines;
            
            return pass;
        }
        
        bool LineCollider::is_colliding(BaseCollider *b) {
            //Get colliders
            auto* circle_collider = b->as<CircleCollider>();
            auto* line_collider = b->as<LineCollider>();
            auto* rect_collider = b->as<RectangleCollider>();
    
            //Collider types
            if (rect_collider != nullptr) {
                //TODO
                //for (Line line : lines) {
                //    if (rect_collider->get_rectangle().intersects(line))
                //        return true;
                //}
            } else if (line_collider != nullptr) {
                //This may also have issues.
                for (Line line : lines) {
                    for (Line lineb : line_collider->lines) {
                        if (line.intersects(lineb))
                            return true;
                    }
                }
            } else if (circle_collider != nullptr) {
                //TODO
            } else {
                //TODO: Do collision checks for other colliders
            }
    
            return false;
        }
    }
}