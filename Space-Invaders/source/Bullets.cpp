#include "Bullet.h"
#include <iostream>

Bullet::Bullet(const sf::Vector2f& startPosition, float bulletSpeed) : position(startPosition), speed(bulletSpeed) {
    sf::Texture bulletTexture;
    const std::string img_filepath = "assets/textures/laser_bullet.png";
    if (!bulletTexture.loadFromFile(img_filepath)) {
        // Handle error if texture loading fails
        std::cerr << "Failed to load bullet texture" << std::endl;
    }
    sprite.setTexture(bulletTexture);
    sprite.setPosition(startPosition);
}

Bullet::~Bullet() {}

void Bullet::update() {
    position.y -= speed;
    sprite.setPosition(position);
}

bool Bullet::isOutOfBounds() const {
    return position.y < 0;
}

const sf::Sprite& Bullet::getSprite() const {
    return sprite;
}

SimpleBullet::SimpleBullet(const sf::Vector2f& startPosition) : Bullet(startPosition, 5.0f) {}

SimpleBullet::~SimpleBullet() {}

FrostBeam::FrostBeam(const sf::Vector2f& startPosition) : Bullet(startPosition, 7.0f) {}

FrostBeam::~FrostBeam() {}
