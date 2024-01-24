# Программирование на языке высокого уровня (Python).
# Задание №4.3.4 - 4.3.5. Вариант 1
#
# Выполнил: Таран Мария
# Группа: ПИН-б-о-21-1
# E-mail: taranma26agmail.com@yandex.ru


from vector import Vector
from VectorCollection import VectorCollection

if __name__ == "__main__":
    v = Vector(10, 5)
    v2 = Vector(3, 4)
    vectors = VectorCollection(v, v2)
    print("VectorCollection \n", vectors)

    print(f"{v} + {v2} = {v + v2}")
    print(f"{v} - {v2} = {v - v2}")
    print(f"{v} * {v2} = {v * 5}")
    print(f"{v} / {v2} = {v / 4}")
    print(f"Длина вектора {v} равна {v.get_lenght()}")
    print(f"Координаты нормализованного вектора {v}: {v.normalize()}")
    print(f"Длина вектора {v} оставляет: {v.get_lenght()}")
    x = "12 42"
    v3 = Vector(0, 0).from_string(x)
    print(f'Вектор, составленный из строки "{x}": {v3}')
    vectors.add(v3)

    print("VectorCollection \n", vectors)

    filename = ("Векторы")
    v.save(filename)
    vectors.save(filename)

    print(VectorCollection.__getitem__(vectors, 0))

