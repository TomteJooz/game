#include "quadtree.h"

Quadtree::Quadtree(int maxPoints, sf::FloatRect baseRect) : MAX_POINTS{maxPoints}, root{std::make_shared<Quadtree::Quad>(baseRect)}
{
}

void Quadtree::insert(std::shared_ptr<Hitbox> obj)
{
    root->insert(obj, MAX_POINTS);
}

std::vector<std::shared_ptr<Hitbox>> Quadtree::retrieve(sf::FloatRect rect)
{
    return root->retrieve(rect);
}

Quadtree::Quad::Quad(sf::FloatRect rect, std::shared_ptr<Quadtree::Quad> parent) : Rect{rect}, Parent{parent}
{
}

bool Quadtree::Quad::contains(sf::Vector2f point)
{
    return Rect.contains(point);
}

void Quadtree::Quad::subdivide()
{
    sf::Vector2f midpoint(Rect.left + Rect.width / 2.0f, Rect.top + Rect.height / 2.0f);

    Children[0] = std::make_shared<Quadtree::Quad>(Quadtree::Quad(sf::FloatRect(Rect.left, Rect.top, midpoint.x - Rect.left, midpoint.y - Rect.top), std::make_shared<Quadtree::Quad>(*this)));
    Children[1] = std::make_shared<Quadtree::Quad>(Quadtree::Quad(sf::FloatRect(midpoint.x, Rect.top, Rect.left + Rect.width - midpoint.x, midpoint.y - Rect.top), std::make_shared<Quadtree::Quad>(*this)));
    Children[2] = std::make_shared<Quadtree::Quad>(Quadtree::Quad(sf::FloatRect(Rect.left, midpoint.y, midpoint.x - Rect.left, Rect.top + Rect.height - midpoint.y), std::make_shared<Quadtree::Quad>(*this)));
    Children[3] = std::make_shared<Quadtree::Quad>(Quadtree::Quad(sf::FloatRect(midpoint.x, midpoint.y, Rect.left + Rect.width - midpoint.x, Rect.top + Rect.height - midpoint.y), std::make_shared<Quadtree::Quad>(*this)));
}

void Quadtree::Quad::insert(std::shared_ptr<Hitbox> obj, const int MAX_POINTS)
{
    // The Quadtree::Quad should only save it if the point is inside its boundingbox
    if (!contains(obj->getPosition()))
    {
        return;
    }
    // Add it as deep as possible
    if (Children[0])
    {
        for (int i = 0; i < 4; i++)
        {
            Children[i]->insert(obj, MAX_POINTS);
            if ((Children[i]->Objects).size() == MAX_POINTS)
                Children[i]->subdivide();
        }
    }
    else
        Objects.push_back(obj);
}

std::vector<std::shared_ptr<Hitbox>> Quadtree::Quad::retrieve(sf::FloatRect rect)
{
    std::vector<std::shared_ptr<Hitbox>> foundObjects;
    // Check if the range intersects with the quadrant
    if (!Rect.intersects(rect))
    {
        return foundObjects;
    }
    // Add objects in current quadrant to the list
    for (auto obj : Objects)
    {
        if (obj->getRect().intersects(rect))
        {
            foundObjects.push_back(obj);
        }
    }
    // If the quadrant has child quadrants, retrieve objects from the appropriate child quadrants
    for (auto child : Children)
    {
        if (child)
        {
            std::vector<std::shared_ptr<Hitbox>> childObjects = child->retrieve(rect);
            foundObjects.insert(foundObjects.end(), childObjects.begin(), childObjects.end());
        }
    }
    return foundObjects;
}
