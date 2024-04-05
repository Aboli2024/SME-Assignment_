#include <vector>
#include <chrono> // for time-based operations

// Define a Bullet class
class Bullet {
public:
    // Constructor to initialize bullet position and type
    Bullet(float x, float y, BulletType type) : posX(x), posY(y), bulletType(type) {}

    // Public methods to get bullet position
    float getX() const { return posX; }
    float getY() const { return posY; }

    // Method to update bullet position (e.g., move bullet)
    void update() {
        // Update bullet position based on type and velocity
        // Example: posY += velocity;
    }

private:
    float posX;
    float posY;
    BulletType bulletType; // Enum to distinguish bullet types
    // Other bullet properties like velocity, damage, etc.
};

// Define a PlayerShip class
class PlayerShip {
public:
    // Constructor to initialize player ship
    PlayerShip() {}

    // Method to handle firing bullets
    void fireBullet() {
        // Check if enough time has passed since last bullet fired
        auto currentTime = std::chrono::high_resolution_clock::now();
        auto timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastFireTime).count();
        
        if (timeDiff >= fireCooldown) {
            // Spawn a new bullet from player ship position
            bullets.push_back(Bullet(posX, posY, BulletType::Simple));
            
            // Update last fire time
            lastFireTime = currentTime;
        }
    }

private:
    float posX;
    float posY;
    std::vector<Bullet> bullets; // Store bullets fired by player
    std::chrono::time_point<std::chrono::high_resolution_clock> lastFireTime;
    const int fireCooldown = 200; // Fire cooldown in milliseconds
};

// Define an EnemyShip class (simplified example)
class EnemyShip {
public:
    // Constructor to initialize enemy ship
    EnemyShip() {}

    // Method to handle firing bullets
    void fireBullet() {
        // Similar to PlayerShip::fireBullet(), implement firing logic here
    }

private:
    // Enemy ship properties and methods
};
