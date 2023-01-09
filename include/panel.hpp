#ifndef PANEL_HPP
#define PANEL_HPP
#include<scene_object.hpp>

enum class PanelType{
    Stack,
    Grid,
    Scroll,
};

class Panel: public SceneObject{
public:

    auto get_type() -> ObjectType const override {
        return ObjectType::Panel;
    }

    virtual auto update(const float &dt)->void override{

    }

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {

    }
};

#endif//PANEL_HPP