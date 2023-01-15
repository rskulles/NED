#ifndef PANEL_HPP
#define PANEL_HPP
#include <scene_object.hpp>
#include <theme.hpp>

enum class PanelType
{
    Stack,
    Grid,
    Scroll,
};

class Panel : public SceneObject
{
public:
    Panel(Theme &theme, const sf::FloatRect rect_def) : drawable_()
    {
        set_dimensions(sf::Vector2f(rect_def.width, rect_def.height));
        set_position(sf::Vector2f(rect_def.left, rect_def.top));
        update_theme(theme);
    }

    auto get_type() -> ObjectType const override
    {
        return ObjectType::Panel;
    }

    virtual auto update(const float &dt) -> void override
    {
    }

    void set_dimensions(const sf::Vector2f &dimensions)
    {
        drawable_.setSize(dimensions);
    }

    void set_position(const sf::Vector2f &posision)
    {
        drawable_.setPosition(posision);
    }

    void update_theme(Theme &theme)
    {
        auto color = theme.panel_background_color;
        drawable_.setFillColor(sf::Color(color.red, color.green, color.blue, color.alpha));
    }

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override
    {
        states.transform = drawable_.getTransform();
        target.draw(drawable_,states);
    }

private:
    sf::RectangleShape drawable_;
};

#endif // PANEL_HPP