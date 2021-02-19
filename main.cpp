#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

const char* SHAPES_FNAME = "shapes.txt";

#define IS_DEBUG

//������� ��� ���������� ��������� � ������ ��� ����������� �� ��������
size_t FindCaseInsens(std::string str, std::string substr)
{
    std::transform(str.begin(), str.end(), str.begin(), tolower);
    std::transform(substr.begin(), substr.end(), substr.begin(), tolower);
    return str.find(substr, 0);
}

void ParseCircle(std::string& str)
{
    int x1 = 0;
    int y1 = 0;
    float radius = 0;
    sscanf(str.data(), "circle(%d %d, %f)", &x1, &y1, &radius);
#ifdef IS_DEBUG
    printf("%d %d %f\n", x1, y1, radius);
#endif
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
    sscanf(str.data(),
           "triangle(%d %d, %d %d, %d %d)",
           &x1,
           &y1,
           &x2,
           &y2,
           &x3,
           &y3);
#ifdef IS_DEBUG
    printf("%d %d %d %d %d %d ", x1, y1, x2, y2, x3, y3);
#endif
}

int main(int argc, char* argv[])
{
    if (argc > 1) {
        SHAPES_FNAME = argv[2];
    }

    std::ifstream file(SHAPES_FNAME);

    int line_num = 0;
    while (!file.eof()) {
        std::string temp;

        std::getline(file, temp);
        if (FindCaseInsens(temp, "circle") != std::string::npos) {
            ParseCircle(temp);
        } else if (FindCaseInsens(temp, "triangle") != std::string::npos) {
            ParseTriangle(temp);
        } else {
            std::cout << "Warning! Unknown type of figure in line " << line_num
                      << " : " << temp << "\n";
        }
        line_num++;
    }
    return 0;
}
