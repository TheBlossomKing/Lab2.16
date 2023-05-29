/*2.16: Задано множество точек на плоскости, все точки этого множества попарно различны. Рассмотрим замкнутую ломаную,
последовательно проходящую через эти точки. Определить,имеет ли эта ломаная самопересечения.*/

#include <iostream>

struct Point {
    double x;
    double y;
};

bool isSelfIntersecting(const Point* points, int numPoints) {
    for (int i = 0; i < numPoints; ++i) {
        const Point& p1 = points[i];
        const Point& p2 = points[(i + 1) % numPoints];

        for (int j = i + 1; j < numPoints; ++j) {
            const Point& p3 = points[j];
            const Point& p4 = points[(j + 1) % numPoints];

            // Проверяем пересечение отрезков
            double dx1 = p2.x - p1.x;
            double dy1 = p2.y - p1.y;
            double dx2 = p4.x - p3.x;
            double dy2 = p4.y - p3.y;

            double denominator = dx1 * dy2 - dx2 * dy1;

            if (denominator != 0) {
                double t1 = ((p3.x - p1.x) * dy2 - (p3.y - p1.y) * dx2) / denominator;
                double t2 = ((p3.x - p1.x) * dy1 - (p3.y - p1.y) * dx1) / denominator;

                // Проверяем, что точки пересечения находятся внутри отрезков
                if (t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1) {
                    return true; // Ломаная самопересекается
                }
            }
        }
    }

    return false; // Ломаная не имеет самопересечений
}

int main() {
    int numPoints;

    std::cout << "Enter the number of points (at least 3): ";
    std::cin >> numPoints;

    if (numPoints < 3) {
        std::cout << "Invalid number of points. At least 3 points are required." << std::endl;
        return 0;
    }

    Point* points = new Point[numPoints];

    std::cout << "Enter the coordinates of each point:" << std::endl;
    for (int i = 0; i < numPoints; ++i) {
        std::cout << "Point " << i + 1 << ": ";
        std::cin >> points[i].x >> points[i].y;
    }

    bool isIntersecting = isSelfIntersecting(points, numPoints);

    if (isIntersecting) {
        std::cout << "The polygon has self-intersections." << std::endl;
    }
    else {
        std::cout << "The polygon does not have self-intersections." << std::endl;
    }

    delete[] points;

    return 0;
}


