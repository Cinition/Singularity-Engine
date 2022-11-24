#pragma once

template <typename T> class Vector2;
template <typename T> class Vector3;

namespace Singularity
{
    template <typename T>
    class Vector4 {

    public:

        Vector4(void) = default;
        explicit Vector4(T _x) { x = _x; y = _x; z = _x; w = _x; }
        Vector4(T _x, T _y) { x = _x; y = _y; z = T(0); w = T(0); }
        Vector4(T _x, T _y, T _z) { x = _x; y = _y; z = _z; w = T(0); }
        Vector4(T _x, T _y, T _z, T _w) { x = _x; y = _y; z = _z; w = _w; }
        explicit Vector4(Vector2<T> _v) { x = _v.x; y = _v.y; z = T(0); w = T(0); }
        explicit Vector4(Vector2<T> _v, T _z, T _w) { x = _v.x; y = _v.y; z = _z; w = _w; }
        explicit Vector4(Vector2<T> _v, Vector2<T> _v2) { x = _v.x; y = _v.y; z = _v2.x; w = _v2.y; }
        explicit Vector4(Vector3<T> _v, T _w) { x = _v.x; y = _v.y; z = _v.z; w = _w; }
        Vector4(const Vector4<T>& _v) { x = _v.x; y = _v.y; z = _v.z; w = _v.w; }

        ////////////////////////////////////////////////////////////////

        template<typename T2> Vector4 operator + (const T2 _o) { return { x + _o, y + _o, z + _o, w + _o }; }
        template<typename T2> Vector4 operator - (const T2 _o) { return { x - _o, y - _o, z - _o, w - _o }; }
        template<typename T2> Vector4 operator / (const T2 _o) { return { x / _o, y / _o, z / _o, w / _o }; }
        template<typename T2> Vector4 operator * (const T2 _o) { return { x * _o, y * _o, z * _o, w * _o }; }

        template<typename T2> Vector4 operator + (const Vector4<T2> _v) { return { x + _v.x, y + _v.y, z + _v.z, w + _v.w }; }
        template<typename T2> Vector4 operator - (const Vector4<T2> _v) { return { x - _v.x, y - _v.y, z - _v.z, w - _v.w }; }
        template<typename T2> Vector4 operator / (const Vector4<T2> _v) { return { x / _v.x, y / _v.y, z / _v.z, w / _v.w }; }
        template<typename T2> Vector4 operator * (const Vector4<T2> _v) { return { x * _v.x, y * _v.y, z * _v.z, w * _v.w }; }

        ////////////////////////////////////////////////////////////////

        template<typename T2> Vector4 operator += (const T2 _o) { return { x += _o, y += _o, z += _o, w += _o }; }
        template<typename T2> Vector4 operator -= (const T2 _o) { return { x -= _o, y -= _o, z -= _o, w -= _o }; }
        template<typename T2> Vector4 operator /= (const T2 _o) { return { x /= _o, y /= _o, z /= _o, w /= _o }; }
        template<typename T2> Vector4 operator *= (const T2 _o) { return { x *= _o, y *= _o, z *= _o, w *= _o }; }

        template<typename T2> Vector4 operator += (const Vector4<T2> _v) { return { x += _v.x, y += _v.y, z += _v.z, w += _v.w }; }
        template<typename T2> Vector4 operator -= (const Vector4<T2> _v) { return { x -= _v.x, y -= _v.y, z -= _v.z, w -= _v.w }; }
        template<typename T2> Vector4 operator /= (const Vector4<T2> _v) { return { x /= _v.x, y /= _v.y, z /= _v.z, w /= _v.w }; }
        template<typename T2> Vector4 operator *= (const Vector4<T2> _v) { return { x *= _v.x, y *= _v.y, z *= _v.z, w *= _v.w }; }

        ////////////////////////////////////////////////////////////////

        T x = T(0);
        T y = T(0);
        T z = T(0);
        T w = T(0);

    };

    typedef Vector4 <int>    Vector4i;
    typedef Vector4 <float>  Vector4f;
    typedef Vector4 <double> Vector4d;

}