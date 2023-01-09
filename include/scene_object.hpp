#ifndef SCENE_OBJECT_HPP
#define SCENE_OBJECT_HPP
#include <SFML/Graphics.hpp>

enum class ObjectType
{
    Panel,
    Element,
};

class SceneObject : public sf::Drawable
{
public:
    SceneObject() = default;
    virtual ~SceneObject() = default;
    virtual auto get_type() -> ObjectType const = 0;
    virtual auto update(const float &dt)->void = 0;

};
#endif // SCENE_OBJECT_HPP
