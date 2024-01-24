# Программирование на языке высокого уровня (Python).
# Задание №4.3.6. Вариант 1
#
# Выполнил: Таран Мария
# Группа: ПИН-б-о-21-1
# E-mail: taranma26agmail.com@yandex.ru

import Плеер
from АудиоПлеер import АудиоПлеер
from ВидеоПлеер import ВидеоПлеер
from DvdПлеер import DvdПлеер

if __name__ == "__main__":
    while True:
        typeOfContent = input(f"Выберите тип плеера: 1 - Аудио, 2 - Видео, 3 - DVD: ")
        if typeOfContent == '1':
            print("1. АудиоПлеер")
            name = str(input("Введите название песни: "))
            audio = АудиоПлеер(name)

            while True:
                runOrStop = input(f"1 - запустить аудио: {name}; \n0 -  остановить аудио: {name};\nдругое - выбрать другой файл: ")
                if runOrStop == '0':
                    audio.stop()
                elif runOrStop == '1':
                    audio.run()
                else:
                    break

        if typeOfContent == '2':
            print("2. ВидеоПлеер")
            name = str(input("Введите название видео: "))
            video = ВидеоПлеер(name)

            while True:
                runOrStop = input(f"1 - запустить видео: {name}; \n0 -  остановить видео: {name};\nдругое - выбрать другой файл: ")
                if runOrStop == '0':
                    video.stop()
                elif runOrStop == '1':
                    video.run()
                else:
                    break
        if typeOfContent == '3':
            print("3. DvdПлеер")
            name = str(input("Введите название DVD-видео: "))
            dvd = DvdПлеер(name)

            while True:
                runOrStop = input(f"1 - запустить DVD: {name}; \n0 -  остановить DVD: {name};\nдругое - выбрать другой файл: ")
                if runOrStop == '0':
                    dvd.stop()
                elif runOrStop == '1':
                    dvd.run()
                else:
                    break
