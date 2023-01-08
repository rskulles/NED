#include "application.hpp"
#include <SFML/System.hpp>

Application::Application()
    : is_running_(true),
      themes_(nullptr),
      current_theme_(nullptr)
{
    create_themes();
    window_.create(sf::VideoMode::getDesktopMode(), "NED", sf::Style::Default);
    window_.setFramerateLimit(120);
    window_.setPosition(sf::Vector2i(0,0));
    
    font_.loadFromFile("./content/fonts/indie_flower/IndieFlower-Regular.ttf");
    text_.setFont(font_);
    text_.setFillColor(sf::Color::White);
    text_.setString(L"THIS IS TOTALLY A STRING");
}

Application::~Application()
{
    delete[] themes_;
    window_.close();
}

auto Application::run() -> void
{
    sf::Clock clock;
    auto dt = clock.restart();

    // main loop
    while (is_running_)
    {
        // get the time between now and the last call to restart
        dt = clock.restart();

        handle_events();
        update(dt.asSeconds());
        render();
    }
}

auto Application::create_themes() -> void
{

    themes_ = new Theme[2];
    themes_[0] = Theme("Dark Theme", RGBAColor(0x1E, 0x1E, 0x1E, 0xFF), RGBAColor(0xFF, 0xFF, 0xFF, 0xFF));
    themes_[1] = Theme("Light Theme", RGBAColor(0xFF, 0xFF, 0xFF, 0xFF), RGBAColor(0x00, 0x00, 0x00, 0xFF));
    current_theme_ = &themes_[0];
}

auto Application::handle_events() -> void
{
    sf::Event e;
    while (window_.pollEvent(e))
    {
        switch (e.type)
        {
        case sf::Event::Closed:
            is_running_ = false;
            break;
        default:
            break;
        }
    }
}

auto Application::update(float dt) -> void
{
}

auto Application::render() -> void
{
    auto clear_color = current_theme_->background_color;
    window_.clear(sf::Color(clear_color.red, clear_color.green, clear_color.blue));
    window_.draw(text_);
    window_.display();
}