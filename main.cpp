#include <fstream>
#include <iostream>
#include "ShapeParser.h"

const char* SHAPES_FNAME = "shapes.txt";

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
            printf("Warning! Unknown type of figure in line %d\n%s\n",
                   line_num,
                   temp.data());
        }
        line_num++;
    }
    return 0;
}
