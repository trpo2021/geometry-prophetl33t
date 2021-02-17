#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

void ParseCircle(std::string& str)
{
    int x1 = 0;
    int y1 = 0;
    float radius = 0;
    FILE* f = fopen("C:\\geom_build\\file.txt", "rb");
    fscanf(f, "circle(%d %d, %f)", &x1, &y1, &radius);
    printf("%d %d %f\n", x1, y1, radius);
}

void ParseTriangle(std::string& str)
{
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    int x3 = 0;
    int y3 = 0;
    float radius = 0;
    FILE* f = fopen("C:\\geom_build\\file.txt", "rb");
    fscanf(f, "triangle(%d %d, %d %d, %d %d)", &x1, &y1, &x2, &y2, &x3, &y3);
    printf("%d %d %d %d %d %d ", x1, y1, x2, y2, x3, y3);
}

int main()
{
    std::ifstream file("file.txt");
    int a = 0;
    while (!file.eof()) {
        std::string temp;

        std::getline(file, temp);
        if (temp.find("circle") != std::string::npos) {
            ParseCircle(temp);
        } else if (temp.find("triangle") != std::string::npos) {
            ParseTriangle(temp);
        } else {
            std::cout << "Warning! Unknown type of figure in line " << a
                      << " : " << temp << "\n";
        }
        a++;
    }
    return 0;
}
