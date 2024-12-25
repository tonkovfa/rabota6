#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/**
 * @brief Конструктор с параметрами для инициализации комплексного числа.
 *
 * @param aRe Часть действительная числа.
 * @param aIm Часть мнимая числа.
 */
Complex::Complex(double aRe, double aIm) {
    Re = aRe;
    Im = aIm;
}

/**
 * @brief Конструктор копирования для создания копии комплексного числа.
 *
 * @param aRval Комплексное число, которое нужно скопировать.
 */
Complex::Complex(const Complex& aRval) {
    Re = aRval.Re;
    Im = aRval.Im;
}

/**
 * @brief Деструктор для освобождения ресурсов (хотя не требуется в данном случае).
 */
Complex::~Complex() {
    Re = 0.0;
    Im = 0.0;
}

/**
 * @brief Устанавливает новые значения для действительной и мнимой части.
 *
 * @param aRe Новая действительная часть.
 * @param aIm Новая мнимая часть.
 */
void Complex::Set(double aRe, double aIm) {
    Re = aRe;
    Im = aIm;
}

/**
 * @brief Преобразование комплексного числа в число типа double (модуль).
 *
 * @return Модуль комплексного числа.
 */
Complex::operator double() {
    return abs();
}

/**
 * @brief Вычисляет модуль комплексного числа.
 *
 * @return Модуль комплексного числа.
 */
double Complex::abs() {
    return sqrt(Re * Re + Im * Im);
}

/**
 * @brief Оператор сложения двух комплексных чисел.
 *
 * @param aRval Второе комплексное число.
 * @return Результат сложения.
 */
Complex Complex::operator+(const Complex& aRval) {
    Complex Result;
    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im;
    return Result;
}

/**
 * @brief Оператор вычитания двух комплексных чисел.
 *
 * @param aRval Второе комплексное число.
 * @return Результат вычитания.
 */
Complex Complex::operator-(const Complex& aRval) {
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}

/**
 * @brief Оператор сложения комплексного числа и действительного числа.
 *
 * @param aVal Действительное число.
 * @return Результат сложения.
 */
Complex Complex::operator+(const double& aVal) {
    Complex Result;
    Result.Re = Re + aVal;
    Result.Im = Im;
    return Result;
}

/**
 * @brief Оператор вычитания действительного числа из комплексного.
 *
 * @param aVal Действительное число.
 * @return Результат вычитания.
 */
Complex Complex::operator-(const double& aVal) {
    Complex Result(*this);
    Result.Re = Re - aVal;
    return Result;
}

/**
 * @brief Оператор умножения двух комплексных чисел.
 *
 * @param aRval Второе комплексное число.
 * @return Результат умножения.
 */
Complex Complex::operator*(const Complex& aRval) {
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}

/**
 * @brief Оператор умножения комплексного числа на действительное.
 *
 * @param aRval Действительное число.
 * @return Результат умножения.
 */
Complex Complex::operator*(const double& aRval) {
    Complex Result;
    Result.Re = Re * aRval;
    Result.Im = Im * aRval;
    return Result;
}

/**
 * @brief Оператор деления комплексного числа на действительное.
 *
 * @param aRval Действительное число.
 * @return Результат деления.
 */
Complex Complex::operator/(const double& aRval) {
    Complex Result;
    Result.Re = Re / aRval;
    Result.Im = Im / aRval;
    return Result;
}

/**
 * @brief Оператор добавления комплексных чисел (для добавления к текущему).
 *
 * @param aRval Комплексное число, которое нужно добавить.
 * @return Ссылка на текущее объект (для цепочки вызовов).
 */
Complex& Complex::operator+=(const Complex& aRval) {
    Re += aRval.Re;
    Im += aRval.Im;
    return *this;
}

/**
 * @brief Оператор вычитания комплексных чисел (для вычитания из текущего).
 *
 * @param aRval Комплексное число, которое нужно вычесть.
 * @return Ссылка на текущее объект (для цепочки вызовов).
 */
Complex& Complex::operator-=(const Complex& aRval) {
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}

/**
 * @brief Оператор умножения комплексных чисел (для умножения на текущее).
 *
 * @param aRval Комплексное число, которое нужно умножить.
 * @return Ссылка на текущее объект (для цепочки вызовов).
 */
Complex& Complex::operator*=(const Complex& aRval) {
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}

/**
 * @brief Оператор добавления действительного числа к комплексному.
 *
 * @param aRval Действительное число.
 * @return Ссылка на текущее объект (для цепочки вызовов).
 */
Complex& Complex::operator+=(const double& aRval) {
    Re += aRval;
    return *this;
}

/**
 * @brief Оператор вычитания действительного числа из комплексного.
 *
 * @param aRval Действительное число.
 * @return Ссылка на текущее объект (для цепочки вызовов).
 */
Complex& Complex::operator-=(const double& aRval) {
    Re -= aRval;
    return *this;
}

/**
 * @brief Оператор умножения комплексного числа на действительное.
 *
 * @param aRval Действительное число.
 * @return Ссылка на текущее объект (для цепочки вызовов).
 */
Complex& Complex::operator*=(const double& aRval) {
    Re *= aRval;
    Im *= aRval;
    return *this;
}

/**
 * @brief Оператор деления комплексного числа на действительное.
 *
 * @param aRval Действительное число.
 * @return Ссылка на текущее объект (для цепочки вызовов).
 */
Complex& Complex::operator/=(const double& aRval) {
    Re /= aRval;
    Im /= aRval;
    return *this;
}

/**
 * @brief Оператор присваивания копии комплексного числа.
 *
 * @param aRval Комплексное число, которое нужно присвоить.
 * @return Ссылка на текущее объект.
 */
Complex& Complex::operator=(const Complex& aRval) {
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}

/**
 * @brief Оператор присваивания действительного числа.
 *
 * @param aRval Действительное число, которое нужно присвоить.
 * @return Ссылка на текущее объект.
 */
Complex& Complex::operator=(const double& aRval) {
    Re = aRval;
    Im = 0.0;
    return *this;
}

/**
 * @brief Оператор ввода комплексного числа с консоли.
 *
 * @param stream Поток ввода.
 * @param a Комплексное число, в которое будет записан ввод.
 * @return Поток ввода.
 */
istream& operator>>(istream& stream, Complex& a) {
    char tmp[256];
    stream >> a.Re >> a.Im >> tmp;
    return stream;
}

/**
 * @brief Оператор вывода комплексного числа на экран.
 *
 * @param stream Поток вывода.
 * @param a Комплексное число, которое нужно вывести.
 * @return Поток вывода.
 */
ostream& operator<<(ostream& stream, Complex& a) {
    stream << a.Re;
    if (!(a.Im < 0)) {
        stream << '+';
    }
    stream << a.Im << 'i';
    return stream;
}

/**
 * @brief Оператор сложения действительного числа и комплексного.
 *
 * @param aLval Действительное число.
 * @param aRval Комплексное число.
 * @return Результат сложения.
 */
Complex operator+(const double& aLval, const Complex& aRval) {
    Complex Result;
    Result.Re = aLval + aRval.Re;
    Result.Im = aRval.Im;
    return Result;
}

/**
 * @brief Оператор вычитания действительного числа и комплексного числа.
 *
 * @param aLval Действительное число.
 * @param aRval Комплексное число.
 * @return Результат вычитания.
 */
Complex operator-(const double& aLval, const Complex& aRval) {
    Complex Result;
    Result.Re = aLval - aRval.Re;
    Result.Im = -aRval.Im;
    return Result;
}

/**
 * @brief Оператор умножения действительного числа на комплексное.
 *
 * @param aLval Действительное число.
 * @param a Комплексное число.
 * @return Результат умножения.
 */
Complex operator*(const double& aLval, const Complex& a) {
    Complex Result;
    Result.Re = aLval * a.Re;
    Result.Im = aLval * a.Im;
    return Result;
}
