#ifndef QUADTREE_H
#define QUADTREE_H

#include <SFML/Graphics.hpp>

#include "../components/hitbox.h"

class Quadtree
{
public:
    explicit Quadtree(int maxPoints, sf::FloatRect baseRect);
    void insert(std::shared_ptr<Hitbox> obj);
    std::vector<std::shared_ptr<Hitbox>> retrieve(sf::FloatRect rect);

private:
    struct Quad
    {
        sf::FloatRect Rect;
        std::shared_ptr<Quad> Parent;
        std::shared_ptr<Quad> Children[4];
        std::vector<std::shared_ptr<Hitbox>> Objects;

        Quad(sf::FloatRect rect, std::shared_ptr<Quad> parent = nullptr);

        bool contains(sf::Vector2f point);
        void subdivide();
        void insert(std::shared_ptr<Hitbox> obj, const int MAX_POINTS);
        std::vector<std::shared_ptr<Hitbox>> retrieve(sf::FloatRect rect);
    };

    std::shared_ptr<Quad> root;
    const int MAX_POINTS;
};

#endif
