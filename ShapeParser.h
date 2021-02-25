#pragma once
#include <string>
#include <algorithm>

void ParseCircle(std::string& str);
void ParseTriangle(std::string& str);

//Функция для нахождения подстроки в строке вне зависимости от регистра
size_t FindCaseInsens(std::string str, std::string substr);
