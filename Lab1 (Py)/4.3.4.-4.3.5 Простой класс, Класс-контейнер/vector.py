# Программирование на языке высокого уровня (Python).
# Задание №4.3.4 - 4.3.5. Вариант 1
#
# Выполнил: Таран Мария
# Группа: ПИН-б-о-21-1
# E-mail: taranma26agmail.com@yandex.ru

import json


class Vector:

    def __init__(self, x, y):
        if not isinstance(x, int) and not isinstance(x, float):
            raise TypeError
        if not isinstance(y, int) and not isinstance(y, float):
            raise TypeError
        self._x = x
        self._y = y

    def __str__(self):
        return "({},{})".format(self._x, self._y)

    def __add__(self, other):
        if not isinstance(other, Vector):
            raise TypeError
        return Vector(self._x + other._x, self._y + other._y)

    def __sub__(self, other):
        if not isinstance(other, Vector):
            raise TypeError
        return Vector(self._x - other._x, self._y - other._y)

    def __mul__(self, other):
        if not isinstance(other, int):
            raise TypeError
        return Vector(self._x * other, self._y * other)

    def __rmul__(self, other):
        return self.__mul__(other)

    def __truediv__(self, other):
        if not isinstance(other, int):
            raise TypeError
        return Vector(self._x / other, self._y / other)

    def get_lenght(self):
        return (self._x ** 2 + self._y ** 2) ** 0.5

    def normalize(self):
        divisor = self.get_lenght()
        if divisor != 0:
            return Vector(self._x / divisor, self._y / divisor)

    def from_string(self, value):
        self._str = str(value)
        numbers = self._str.split()
        for i in range(len(numbers)):
            numbers[i] = int(numbers[i])
        v = Vector(numbers[0], numbers[1])
        self = v
        return self

    def save(self, filename):
        if not (isinstance(filename, str)):
            raise TypeError("Имя файла должно быть строкой!")
        with open("{}.json".format(filename), "w", encoding="utf-8") as vec:
            vec.write(json.dumps(str(self), ensure_ascii=False, indent=4))

    def load(self, filename):
        if not (isinstance(filename, str)):
            raise TypeError("Имя файла должно быть строкой!")
        try:
            with open("{}.json".format(filename), encoding="utf-8") as vec:
                vector_str = json.loads(vec.read())
                return self.from_string(vector_str)
        except Exception as err:
            print("При загрузке файла произошла ошибка {}!".format(err))
