# PassGen [![Build Status](https://travis-ci.org/BugOverflow/PassGen.svg?branch=master)](https://travis-ci.org/BugOverflow/PassGen)
![](/GUI_Screen.png?raw=true "Пример графического интерфейса")

Курсовой проект группы ИВ-521 по дисциплине "Технологии разработки программного обеспечения (ТРПО)"

## Установка
### Скачать 
Для 64-х битной платформы есть возможность скачать последний [релиз](../../releases/latest)
### Самостоятельная сборка
#### Зависимости
* GCC >= 4.7
* CMake >= 3.2.2
* Qt5 (для GUI)

Установка зависимостей в Ubuntu >= 14.04
```bash
sudo apt-get install build-essentials cmake
```
Для компиляции GUI необходимо установить фреймворк [Qt5](http://qt.io)

##### Примеры различных вариантов конфигурирования
* Cтандартная сборка (Только консольная утилита)
```bash
cd build
cmake ../
make
```
* Тестовая сборка (Консольная утилита + тесты)
```bash
cd build
cmake ../ -DBUILD_TEST=1
make
```
* Интерфейс сборка (Консольная утилита + GUI)
```bash
cd build
cmake ../ -DBUILD_GUI=1 -DQT_PATH=~/Qt/5.5/gcc_64
make
```
Скомпилированные исполняемые файлы находятся в папке `bin`

Запуск тестов
```bash
cd build
make tests
```

##### Дополнительные параметры компиляции
* `-DCMAKE_BUILD_TYPE="Debug"`
    	Добавление отладочной информации
* `-DBUILD_TEST=1`
    	Сборка юнит-тестов
* `-DQT_PATH=/home/Qt/5.5/gcc`
	Путь до библиотек Qt
* `-DBUILD_GUI=1`
	Флаг сборки GUI
* `-DWITH_WARNINGS=1`
	Показывать все предупреждения при компиляции
* `-DCMAKE_INSTALL_PREFIX=/usr/local/bin`
	Путь для установки бинарных файлов (`make install`)
