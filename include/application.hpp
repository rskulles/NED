#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include<SFML/Graphics.hpp>
#include<theme.hpp>

class Application{
    public:
        Application();
        ~Application();
        auto run()->void;

    private://methods
        auto create_themes()->void;
        auto handle_events()->void;
        auto update(float dt)->void;
        auto render()->void;

    private://fields
        bool is_running_;
        bool is_full_screen_;
        sf::RenderWindow window_;
        sf::Font font_;
        sf::Text text_;
        Theme* current_theme_;
        Theme* themes_;
};

#endif