#include <iostream>
#include <cmath>

class Vector3
{
public:
    double x, y, z;

    Vector3() : x(0.0), y(0.0), z(0.0) {}

    Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

    Vector3 operator+(const Vector3 &other) const
    {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3 operator-(const Vector3 &other) const
    {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    double operator*(const Vector3 &other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }

    Vector3 operator*(double scalar) const
    {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    double abs() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    void print() const
    {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};

class Matrix3
{
public:
    double data[3][3];

    Matrix3()
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                data[i][j] = (i == j) ? 1.0 : 0.0;
            }
        }
    }

    Vector3 operator*(const Vector3 &vector) const
    {
        Vector3 result;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                result.data[i] += data[i][j] * vector.data[j];
            }
        }
        return result;
    }

    Matrix3 operator*(const Matrix3 &other) const
    {
        Matrix3 result;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    double det() const
    {
        // Determinant of a 3x3 matrix
        return data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) -
               data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]) +
               data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);
    }

    void print() const
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    Vector3 v1(1.0, 2.0, 3.0);
    Vector3 v2(4.0, 5.0, 6.0);

    std::cout << "Vector addition: ";
    (v1 + v2).print();

    std::cout << "Vector subtraction: ";
    (v1 - v2).print();

    std::cout << "Dot product: " << (v1 * v2) << std::endl;

    std::cout << "Scalar multiplication: ";
    (v1 * 2.0).print();

    std::cout << "Vector norm: " << v1.abs() << std::endl;

    Matrix3 m1;
    Matrix3 m2;

    std::cout << "Matrix multiplication:" << std::endl;
    (m1 * m2).print();

    std::cout << "Determinant of the identity matrix: " << m1.det() << std::endl;

    return 0;
}
