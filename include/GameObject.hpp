#pragma once

class GameObject {
public:
    GameObject();
    virtual void draw();
    virtual void update();
    virtual void clean();
protected: 
    // GameObject(const LoaderParams* pParams) {}
    virtual ~GameObject() {}

    Vector2D m_position, m_velocity, m_acceleration;
    int m_width, m_height, m_currentFrame;
    std::string m_texture, m_sprite;
};