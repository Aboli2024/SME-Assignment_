#pragma once
#include <SFML/Graphics.hpp>

class Bullet {
protected:
    sf::Vector2f position;
    float speed;
    sf::Sprite sprite;

public:
    Bullet(const sf::Vector2f& startPosition, float bulletSpeed);
    virtual ~Bullet();

    void update();
    bool isOutOfBounds() const;
    const sf::Sprite& getSprite() const;
};

class SimpleBullet : public Bullet {
public:
    SimpleBullet(const sf::Vector2f& startPosition);
    ~SimpleBullet();
};

class FrostBeam : public Bullet {
public:
    FrostBeam(const sf::Vector2f& startPosition);
    ~FrostBeam();
};
