#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_

#include <iostream>
using namespace std;

/**
 * @class Complex
 * @brief Класс для работы с комплексными числами.
 *
 * Этот класс реализует основные операции с комплексными числами, включая
 * сложение, вычитание, умножение, деление и методы для получения модуля.
 */
class Complex {
private:
    double Re; ///< Действительная часть комплексного числа.
    double Im; ///< Мнимая часть комплексного числа.

public:
    /**
     * @brief Конструктор для инициализации комплексного числа.
     * @param aRe Действительная часть.
     * @param aIm Мнимая часть (по умолчанию 0).
     */
    Complex(double aRe = 0, double aIm = 0);

    /**
     * @brief Конструктор копирования.
     * @param c Комплексное число, которое нужно скопировать.
     */
    Complex(const Complex& c);

    /**
     * @brief Деструктор.
     */
    ~Complex();

    /**
     * @brief Устанавливает значения для действительной и мнимой частей.
     * @param aRe Действительная часть.
     * @param aIm Мнимая часть (по умолчанию 0).
     */
    void Set(double aRe, double aIm = 0);

    /**
     * @brief Преобразует комплексное число в его модуль.
     * @return Модуль комплексного числа.
     */
    operator double();

    /**
     * @brief Вычисляет модуль комплексного числа.
     * @return Модуль комплексного числа.
     */
    double abs();

    /**
     * @brief Оператор ввода для комплексного числа.
     * @param in Поток ввода.
     * @param c Комплексное число для ввода.
     * @return Поток ввода.
     */
    friend istream& operator>>(istream& in, Complex& c);

    /**
     * @brief Оператор вывода для комплексного числа.
     * @param out Поток вывода.
     * @param c Комплексное число для вывода.
     * @return Поток вывода.
     */
    friend ostream& operator<<(ostream& out, Complex& c);

    /**
     * @brief Оператор сложения двух комплексных чисел.
     * @param c Комплексное число для сложения.
     * @return Результат сложения.
     */
    Complex operator+(const Complex& c);

    /**
     * @brief Оператор вычитания двух комплексных чисел.
     * @param c Комплексное число для вычитания.
     * @return Результат вычитания.
     */
    Complex operator-(const Complex& c);

    /**
     * @brief Оператор сложения комплексного числа с числом типа double.
     * @param d Число типа double для сложения.
     * @return Результат сложения.
     */
    Complex operator+(const double& d);

    /**
     * @brief Оператор сложения числа типа double с комплексным числом.
     * @param d Число типа double для сложения.
     * @param c Комплексное число для сложения.
     * @return Результат сложения.
     */
    friend Complex operator+(const double& d, const Complex& c);

    /**
     * @brief Оператор вычитания числа типа double из комплексного числа.
     * @param d Число типа double для вычитания.
     * @return Результат вычитания.
     */
    Complex operator-(const double& d);

    /**
     * @brief Оператор вычитания числа типа double из комплексного числа.
     * @param d Число типа double для вычитания.
     * @param c Комплексное число для вычитания.
     * @return Результат вычитания.
     */
    friend Complex operator-(const double& d, const Complex& c);

    /**
     * @brief Оператор умножения двух комплексных чисел.
     * @param c Комплексное число для умножения.
     * @return Результат умножения.
     */
    Complex operator*(const Complex& c);

    /**
     * @brief Оператор умножения комплексного числа на число типа double.
     * @param d Число типа double для умножения.
     * @return Результат умножения.
     */
    Complex operator*(const double& d);

    /**
     * @brief Оператор умножения числа типа double на комплексное число.
     * @param d Число типа double для умножения.
     * @param c Комплексное число для умножения.
     * @return Результат умножения.
     */
    friend Complex operator*(const double& d, const Complex& c);

    /**
     * @brief Оператор деления комплексного числа на число типа double.
     * @param d Число типа double для деления.
     * @return Результат деления.
     */
    Complex operator/(const double& d);

    /**
     * @brief Оператор присваивания для сложения с комплексным числом.
     * @param c Комплексное число для сложения.
     * @return Ссылка на объект.
     */
    Complex& operator+=(const Complex& c);

    /**
     * @brief Оператор присваивания для вычитания с комплексным числом.
     * @param c Комплексное число для вычитания.
     * @return Ссылка на объект.
     */
    Complex& operator-=(const Complex& c);

    /**
     * @brief Оператор присваивания для умножения на комплексное число.
     * @param c Комплексное число для умножения.
     * @return Ссылка на объект.
     */
    Complex& operator*=(const Complex& c);

    /**
     * @brief Оператор присваивания для сложения с числом типа double.
     * @param d Число типа double для сложения.
     * @return Ссылка на объект.
     */
    Complex& operator+=(const double& d);

    /**
     * @brief Оператор присваивания для вычитания числа типа double.
     * @param d Число типа double для вычитания.
     * @return Ссылка на объект.
     */
    Complex& operator-=(const double& d);

    /**
     * @brief Оператор присваивания для умножения на число типа double.
     * @param d Число типа double для умножения.
     * @return Ссылка на объект.
     */
    Complex& operator*=(const double& d);

    /**
     * @brief Оператор присваивания для деления на число типа double.
     * @param d Число типа double для деления.
     * @return Ссылка на объект.
     */
    Complex& operator/=(const double& d);

    /**
     * @brief Оператор присваивания для копирования комплексного числа.
     * @param c Комплексное число для копирования.
     * @return Ссылка на объект.
     */
    Complex& operator=(const Complex& c);

    /**
     * @brief Оператор присваивания для присваивания значения числу типа double.
     * @param d Число типа double для присваивания.
     * @return Ссылка на объект.
     */
    Complex& operator=(const double& d);
};

#endif
