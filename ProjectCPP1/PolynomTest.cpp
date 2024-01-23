#include <iostream>
#include <vector>
#include <cmath>

// Определение класса Polynomial
class Polynomial {
private:
    std::vector<double> coefficients;

public:
    Polynomial(const std::vector<double>& coeffs) : coefficients(coeffs) {}

    double evaluate(double x) const {
        double result = 0.0;
        for (int i = coefficients.size() - 1; i >= 0; --i)
            result = result * x + coefficients[i];
        return result;
    }

    Polynomial add(const Polynomial& other) const {
        std::vector<double> result_coeffs(std::max(coefficients.size(), other.coefficients.size()), 0.0);
        for (int i = 0; i < coefficients.size(); ++i)
            result_coeffs[i] += coefficients[i];
        for (int i = 0; i < other.coefficients.size(); ++i)
            result_coeffs[i] += other.coefficients[i];
        return Polynomial(result_coeffs);
    }

    Polynomial subtract(const Polynomial& other) const {
        std::vector<double> result_coeffs(std::max(coefficients.size(), other.coefficients.size()), 0.0);
        for (int i = 0; i < coefficients.size(); ++i)
            result_coeffs[i] += coefficients[i];
        for (int i = 0; i < other.coefficients.size(); ++i)
            result_coeffs[i] -= other.coefficients[i];
        return Polynomial(result_coeffs);
    }

    Polynomial multiply(const Polynomial& other) const {
        std::vector<double> result_coeffs(coefficients.size() + other.coefficients.size() - 1, 0.0);
        for (int i = 0; i < coefficients.size(); ++i)
            for (int j = 0; j < other.coefficients.size(); ++j)
                result_coeffs[i + j] += coefficients[i] * other.coefficients[j];
        return Polynomial(result_coeffs);
    }

    void print() const {
        for (int i = coefficients.size() - 1; i >= 0; --i)
            std::cout << coefficients[i] << "x^" << i << (i > 0 ? " + " : "");
        std::cout << std::endl;
    }

    // Новый метод, возвращающий вектор коэффициентов
    std::vector<double> getCoefficients() const {
        return coefficients;
    }
};

// Простые функции для проверки условий и вывода результатов
bool assertEqual(const std::vector<double>& actual, const std::vector<double>& expected, const char* message) {
    if (actual == expected) {
        std::cout << message << " - Passed" << std::endl;
        return true;
    }
    else {
        std::cout << message << " - Failed" << std::endl;
        std::cout << "  Actual: ";
        for (auto& val : actual)
            std::cout << val << " ";
        std::cout << "\n  Expected: ";
        for (auto& val : expected)
            std::cout << val << " ";
        std::cout << std::endl;
        return false;
    }
}

bool assertDoubleEqual(double actual, double expected, const char* message) {
    const double epsilon = 1e-6;
    if (std::fabs(actual - expected) < epsilon) {
        std::cout << message << " - Passed" << std::endl;
        return true;
    }
    else {
        std::cout << message << " - Failed" << std::endl;
        std::cout << "  Actual: " << actual << "\n  Expected: " << expected << std::endl;
        return false;
    }
}

// Тест для evaluate()
void testEvaluate() {
    Polynomial poly({ 1, -2, 3 });
    assertDoubleEqual(poly.evaluate(2.0), 13.0, "Evaluate Polynomial - Test 1");
    assertDoubleEqual(poly.evaluate(0.0), 1.0, "Evaluate Polynomial - Test 2");
}

// Тест для add()
void testAdd() {
    Polynomial poly1({ 1, -2, 3 });
    Polynomial poly2({ 0, 4, -1 });
    Polynomial sum = poly1.add(poly2);

    assertEqual(sum.getCoefficients(), { 1, 2, 2 }, "Add Polynomials");
}

// Тест для subtract()
void testSubtract() {
    Polynomial poly1({ 1, -2, 3 });
    Polynomial poly2({ 0, 4, -1 });
    Polynomial diff = poly1.subtract(poly2);

    assertEqual(diff.getCoefficients(), { 1, -6, 4 }, "Subtract Polynomials");
}

// Тест для multiply()
void testMultiply() {
    Polynomial poly1({ 1, -2, 3 });
    Polynomial poly2({ 0, 4, -1 });
    Polynomial product = poly1.multiply(poly2);

    assertEqual(product.getCoefficients(), { 0, 4, -9, 10, -3 }, "Multiply Polynomials");
}

int main() {
    // Запуск тестов
    testEvaluate();
    testAdd();
    testSubtract();
    testMultiply();

    return 0;
}
