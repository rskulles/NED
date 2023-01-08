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
    virtual ~SceneObject() = default;
    virtual auto get_type() -> ObjectType const = 0;

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
#endif // SCENE_OBJECT_HPP
