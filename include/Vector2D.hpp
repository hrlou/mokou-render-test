#pragma once
#include <iostream>
#include <cmath>

class Vector2D {
public:
	Vector2D();
	Vector2D(float x, float y)
		: m_x(x), m_y(y) {}
	inline Vector2D operator+(const Vector2D& v2) { return Vector2D(m_x + v2.m_x, m_y + v2.m_y); }
	inline Vector2D operator-(const Vector2D& v2) { return Vector2D(m_x - v2.m_x, m_y - v2.m_y); }
	inline Vector2D operator*(float scalar) { return Vector2D(m_x * scalar, m_y * scalar); }
	inline Vector2D operator/(float scalar) { return Vector2D(m_x / scalar, m_y / scalar); }

	inline Vector2D operator+=(const Vector2D& v2) { return *this = *this + v2; }
	inline Vector2D operator-=(const Vector2D& v2) { return *this = *this - v2; }
	inline Vector2D operator*=(float scalar) { return *this = *this * scalar; }
	inline Vector2D operator/=(float scalar) { return *this = *this / scalar; }

	inline friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
		return os << "x = " << v.get_x() << ", y = " << v.get_y() << ", l = " << v.length();
	}

	float get_x(void) const { return m_x; }
	float get_y(void) const { return m_y; }
	float length(void) const { return sqrt(m_x * m_x + m_y * m_y); }

	void set_x(float x) { m_x = x; }
	void set_y(float y) { m_y = y; }
	
	void normalise(void) {
	    float aux_length = length();
	    if (aux_length > 0) {
	        *this *= 1 / aux_length;
	    }
	}
private:
	float m_x, m_y;
};