#pragma once

#include <iostream>
#include <vector>
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
