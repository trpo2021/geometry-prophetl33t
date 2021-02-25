#pragma once
#include <algorithm>
#include <string>

//Возвращает площадь и периметр круга
std::pair<double, double> ParseCircle(std::string& str);

//Возвращает площадь и периметр треугольника
std::pair<double, double> ParseTriangle(std::string& str);

//Функция для нахождения подстроки в строке вне зависимости от регистра
size_t FindCaseInsens(std::string str, std::string substr);
