# Программирование на языке высокого уровня (Python).
# Задание №4.3.4 - 4.3.5. Вариант 1
#
# Выполнил: Таран Мария
# Группа: ПИН-б-о-21-1
# E-mail: taranma26agmail.com@yandex.ru

import json
from functools import reduce
from vector import Vector


class VectorCollection:
    def __init__(self, *vectors):
        self._vectors = []

        for vector in vectors:
            self.add(vector)

    def __str__(self):
        return reduce(lambda res, x: res + "\n{}".format(x),
                      self._vectors,
                      "Список элементов ({}):".format(len(self._vectors)))

    def __getitem__(self, index):
        if not (isinstance(index, int)):
            raise TypeError("index должен быть int!")
        return self._vectors[index]

    def add(self, value):
        if not (isinstance(value, Vector)):
            raise TypeError("Допускает хранение только экземпляров"
                            " класса Vector!")

        self._vectors.append(value)

    def remove(self, index):
        if not (isinstance(index, int)):
            raise TypeError("index должен быть int!")
        if not (0 <= index <= len(self._vectors)):
            raise ValueError("index вне диапазона!")
        del self._vectors[index]

    def save(self, filename):
        if not (isinstance(filename, str)):
            raise TypeError("Имя файла должно быть строкой!")
        with open("{}.json".format(filename), "w", encoding="utf-8") as vec:
            data = []
            for vector in self._vectors:
                data.append(str(f"{vector._x} {vector._y}"))
            vec.write(json.dumps(data, ensure_ascii=False, indent=4))

    def load(self, filename):
        if not (isinstance(filename, str)):
            raise TypeError("Имя файла должно быть строкой!")

        with open("{}.json".format(filename), encoding="utf-8") as vec:
            lst = json.loads(vec.read())
            _vectors = []
            for item in lst:
                print(item)
                _vectors.append(Vector.from_string(item))

            self._vectors = _vectors
