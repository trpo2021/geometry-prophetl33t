#pragma once
#include <string>
#include <algorithm>

void ParseCircle(std::string& str);
void ParseTriangle(std::string& str);

//������� ��� ���������� ��������� � ������ ��� ����������� �� ��������
size_t FindCaseInsens(std::string str, std::string substr);
