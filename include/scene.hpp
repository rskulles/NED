#ifndef SCENE_HPP
#define SCENE_HPP

#include<SFML/Graphics.hpp>
#include<scene_object.hpp>

enum class NodeDirection{
    North,
    South,
    East,
    West,
    NorthEast,
    NorthWest,
    SouthEast,
    SouthWest
};

class SceneNode: public sf::Drawable{
    public:
        SceneNode():north_node_(nullptr),
        south_node_(nullptr),
        east_node_(nullptr),
        west_node_(nullptr),
        north_east_node_(nullptr),
        north_west_node_(nullptr),
        south_east_node_(nullptr),
        south_west_node_(nullptr)
        {

        }

        auto update(const float &dt)->void{
            this->data_->update(dt);
        }

        auto point_to(SceneNode& node, const NodeDirection &direction)->void{
            switch (direction)
            {
            case NodeDirection::North:
                north_node_= &node;
                break;
            case NodeDirection::South:
                south_node_ = &node;
                break;
            case NodeDirection::East:
                east_node_ = &node;
                break;
            case NodeDirection::West:
                west_node_ = &node;
                break;
            case NodeDirection::NorthEast:
                north_east_node_ = &node;
                break;
            case NodeDirection::NorthWest:
                north_west_node_ = &node;
                break;
            case NodeDirection::SouthEast:
                south_east_node_ = &node;
                break;
            case NodeDirection::SouthWest:
                south_west_node_ = &node;
                break;
            default:
                break;
            }
        }
        
        auto get_neighbor(const NodeDirection& direction)->SceneNode* const{
            SceneNode* ptr = nullptr;
            switch(direction){
                default:
                    break;
                case NodeDirection::North:
                    ptr = north_node_;
                    break;
                case NodeDirection::South:
                    ptr = south_node_;
                    break;
                case NodeDirection::East:
                    ptr = east_node_;
                    break;
                case NodeDirection::West:
                    ptr = west_node_;
                    break;
                case NodeDirection::NorthEast:
                    ptr = north_east_node_;
                    break;
                case NodeDirection::NorthWest:
                    ptr = north_west_node_;
                    break;
                case NodeDirection::SouthEast:
                    ptr = south_east_node_;
                    break;
                case NodeDirection::SouthWest:
                    ptr = south_west_node_;
                    break;
            }

            return ptr;
        }

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
            target.draw(*this, states);
    }

private:
        unsigned int id_;
        SceneNode* data_;
        SceneNode* north_node_;
        SceneNode* south_node_;
        SceneNode* east_node_;
        SceneNode* west_node_;
        SceneNode* north_east_node_;
        SceneNode* north_west_node_;
        SceneNode* south_east_node_;
        SceneNode* south_west_node_;
};

class Scene:public sf::Drawable{
    public:
        Scene();
        virtual ~Scene()= default;
        auto update(const float& dt)->void{
            update_node(dt,head_);
        }
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override{
                target.draw(*head_, states);
        }
    private:
    auto update_node(const float& dt,  SceneNode* node)->void{
        if(node == nullptr) return;
         node->update(dt);
         update_node(dt,node->get_neighbor(NodeDirection::North));
         update_node(dt,node->get_neighbor(NodeDirection::South));
         update_node(dt,node->get_neighbor(NodeDirection::East));
         update_node(dt,node->get_neighbor(NodeDirection::West));
         update_node(dt,node->get_neighbor(NodeDirection::NorthEast));
         update_node(dt,node->get_neighbor(NodeDirection::NorthWest));
         update_node(dt,node->get_neighbor(NodeDirection::SouthEast));
         update_node(dt,node->get_neighbor(NodeDirection::SouthWest));
    }
    SceneNode* head_;
};

#endif //SCENE_HPP