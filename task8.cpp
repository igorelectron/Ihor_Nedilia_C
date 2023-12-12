#include <iostream>
#include <vector>

class Point
{
public:
    double x, y;

    Point(double x, double y) : x(x), y(y) {}
};

class Figure
{
public:
    virtual double getPerimeter() const = 0;
    virtual bool isConvex() const = 0;
};

class Rectangle : public Figure
{
private:
    Point topLeft;
    Point bottomRight;

public:
    Rectangle(const Point &topLeft, const Point &bottomRight) : topLeft(topLeft), bottomRight(bottomRight) {}

    double getPerimeter() const override
    {
        double length = bottomRight.x - topLeft.x;
        double width = topLeft.y - bottomRight.y;
        return 2 * (length + width);
    }

    double getArea() const
    {
        double length = bottomRight.x - topLeft.x;
        double width = topLeft.y - bottomRight.y;
        return length * width;
    }

    bool isConvex() const override
    {
        return true;
    }
};

class Triangle : public Figure
{
private:
    Point vertices[3];

public:
    Triangle(const Point &v1, const Point &v2, const Point &v3)
    {
        vertices[0] = v1;
        vertices[1] = v2;
        vertices[2] = v3;
    }

    double getPerimeter() const override
    {
        double side1 = distance(vertices[0], vertices[1]);
        double side2 = distance(vertices[1], vertices[2]);
        double side3 = distance(vertices[2], vertices[0]);
        return side1 + side2 + side3;
    }

    double getArea() const
    {
        double s = getPerimeter() / 2;
        double side1 = distance(vertices[0], vertices[1]);
        double side2 = distance(vertices[1], vertices[2]);
        double side3 = distance(vertices[2], vertices[0]);
        return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    bool isConvex() const override
    {
        return true; 
    }

private:
    static double distance(const Point &p1, const Point &p2)
    {
        double dx = p2.x - p1.x;
        double dy = p2.y - p1.y;
        return std::sqrt(dx * dx + dy * dy);
    }
};

class Pentagon : public Figure
{
private:
    Point vertices[5];

public:
    Pentagon(const Point &v1, const Point &v2, const Point &v3, const Point &v4, const Point &v5)
    {
        vertices[0] = v1;
        vertices[1] = v2;
        vertices[2] = v3;
        vertices[3] = v4;
        vertices[4] = v5;
    }

    double getPerimeter() const override
    {
        double perimeter = 0.0;
        for (int i = 0; i < 4; ++i)
        {
            perimeter += distance(vertices[i], vertices[i + 1]);
        }
        perimeter += distance(vertices[4], vertices[0]);
        return perimeter;
    }

    double getArea() const
    {
        double s1 = distance(vertices[0], vertices[1]);
        double s2 = distance(vertices[1], vertices[2]);
        double s3 = distance(vertices[2], vertices[3]);
        double s4 = distance(vertices[3], vertices[4]);
        double s5 = distance(vertices[4], vertices[0]);

        double area = 0.25 * std::sqrt(
                                 (s1 + s3 + s5) * (s3 + s5 - s2) * (s5 + s1 - s4) * (s1 + s3 - s2) *
                                 (s3 + s5 + s2) * (s5 + s1 + s4) * (s1 + s3 + s4) * (s3 + s5 - s4));

        return area;
    }

    bool isConvex() const override
    {
        // Implement a convexity check for a pentagon
        // (e.g., no angles larger than 180 degrees)
        return true;
    }

private:
    static double distance(const Point &p1, const Point &p2)
    {
        double dx = p2.x - p1.x;
        double dy = p2.y - p1.y;
        return std::sqrt(dx * dx + dy * dy);
    }
};

class Polygon : public Figure
{
protected:
    std::vector<Point> vertices;

public:
    Polygon(const std::vector<Point> &vertices) : vertices(vertices) {}

    double getPerimeter() const override
    {
        double perimeter = 0.0;
        int n = vertices.size();
        for (int i = 0; i < n - 1; ++i)
        {
            perimeter += distance(vertices[i], vertices[i + 1]);
        }
        perimeter += distance(vertices[n - 1], vertices[0]);
        return perimeter;
    }

    bool isConvex() const override
    {
        // Implement a convexity check for a polygon
        // (e.g., no angles larger than 180 degrees)
        return true;
    }

private:
    static double distance(const Point &p1, const Point &p2)
    {
        double dx = p2.x - p1.x;
        double dy = p2.y - p1.y;
        return std::sqrt(dx * dx + dy * dy);
    }
};

int main()
{
    Point p1(0, 0);
    Point p2(2, 0);
    Point p3(1, 1);
    Point p4(0, 1);
    Point p5(-1, 0);

    Rectangle rectangle(p1, p2);
    Triangle triangle(p1, p2, p3);
    Pentagon pentagon(p1, p2, p3, p4, p5);

    std::vector<Figure *> figures = {&rectangle, &triangle, &pentagon};

    std::cout << "Convex polygons:" << std::endl;
    for (const auto &figure : figures)
    {
        if (figure->isConvex())
        {
            std::cout << "Perimeter: " << figure->getPerimeter() << std::endl;
        }
    }

    
    Figure *smallestPerimeterFigure = nullptr;
    double smallestPerimeter = std::numeric_limits<double>::max();
    for (const auto &figure : figures)
    {
        if (figure->getPerimeter() < smallestPerimeter)
        {
            smallestPerimeter = figure->getPerimeter();
            smallestPerimeterFigure = figure;
        }
    }

    if (smallestPerimeterFigure != nullptr)
    {
        std::cout << "Figure with the smallest perimeter:" << std::endl;
        std::cout << "Perimeter: " << smallestPerimeterFigure->getPerimeter() << std::endl;
    }

    return 0;
}
