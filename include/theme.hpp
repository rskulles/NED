#ifndef THEME_HPP
#define THEME_HPP

#include <string>

class RGBAColor
{
public:
    RGBAColor() = default;

    RGBAColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
    {
        this->red = red;
        this->green = green;
        this->blue = blue;
        this->alpha = alpha;
    }

    auto adjust_color(const int8_t &by_value) -> void
    {
        red += by_value;
        green += by_value;
        blue += by_value;
    }
    auto copy()->RGBAColor{
        return RGBAColor(this->red, this->green, this->blue,this->alpha);
    }
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
};

class Theme
{
public:
    Theme() = default;

    Theme(std::string name, RGBAColor bg_color, RGBAColor fg_color) 
    {
        this->name = name;
        this->background_color = bg_color;
        this->foreground_color = fg_color;
        this->panel_background_color = bg_color.copy();
        this->panel_foreground_color = fg_color.copy();
        is_dark(true);
        is_dark(false);
    }

    auto is_dark(bool is_dark) -> void
    {

        if (is_dark_mode_ == is_dark)
        {
            return;
        }

        panel_background_color = background_color;
        panel_foreground_color = foreground_color;

        is_dark_mode_ = is_dark;
        int8_t value_adjustment;
        if (is_dark_mode_)
        {
            value_adjustment = 8;
        }
        else
        {
            value_adjustment = -8;
        }
        panel_background_color.adjust_color(value_adjustment);
        panel_foreground_color.adjust_color(-value_adjustment);
    }

    RGBAColor background_color;
    RGBAColor panel_background_color;
    RGBAColor panel_foreground_color;
    RGBAColor foreground_color;
    std::string name;

private:
    bool is_dark_mode_;
};

#endif // THEME_HPP