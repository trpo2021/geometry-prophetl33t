#pragma once
#include <algorithm>
#include <string>

//���������� ������� � �������� �����
std::pair<double, double> ParseCircle(std::string& str);

//���������� ������� � �������� ������������
std::pair<double, double> ParseTriangle(std::string& str);

//������� ��� ���������� ��������� � ������ ��� ����������� �� ��������
size_t FindCaseInsens(std::string str, std::string substr);
