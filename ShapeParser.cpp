#include "ShapeParser.h"

#define PI 3.14159265358979323846

size_t FindCaseInsens(std::string str, std::string substr)
{
    std::transform(str.begin(), str.end(), str.begin(), tolower);
    std::transform(substr.begin(), substr.end(), substr.begin(), tolower);
    return str.find(substr, 0);
}

std::pair<double, double> ParseCircle(std::string& str)
{
    int x1 = 0;
    int y1 = 0;
    float radius = 0;
    sscanf(str.data(), "circle(%d %d, %f)", &x1, &y1, &radius);

    return (std::make_pair(pow(radius, 2) * PI, radius * (2 * PI)));
}

std::pair<double, double> ParseTriangle(std::string& str)
{
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    int x3 = 0;
    int y3 = 0;
    float perimeter = 0;
    float area = 0;

    sscanf(str.data(),
           "triangle(%d %d, %d %d, %d %d)",
           &x1,
           &y1,
           &x2,
           &y2,
           &x3,
           &y3);

    float a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    float b = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    float c = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    perimeter = a + b + c;
    float half_p = perimeter / 2;
    area = sqrt(half_p * (half_p - a) * (half_p - b) * (half_p - c));

    return std::make_pair(area, perimeter);
}
