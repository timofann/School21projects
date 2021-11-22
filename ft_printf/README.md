# Printf check-list

* Необходимо обработать спецификаторы 1) с флагами 2) и 3).
* Обработка должна соответствовать обработке функцией printf

1. c s p d i u x X % 
2. '-'  '0'  '.'
3. '#'  ' '  '+'


### '0' - дополнить нулями слева до ширины

* Игнорируется с флагом '-' (справа дополняем только пробелами)
* Игнорируется для p, d, i, u, x, X при назначенной точности (дополняем пробелами)
* Для s и c не игнорируется при назначенной точности
* x и X дополняет ПОСЛЕ 0х или 0Х при включенном флаге '#' (пробелами дополняем ДО 0х или 0Х)
* p дополняет ПОСЛЕ 0х (пробелами дополняем ДО 0х)


### '-' - выравнивание по левому краю

* Отключает действие флага '0'
* Сначала обрабатываем флаги '#' ' ' + и точность, затем ширину

### '#' - дополняет ненулевое значение слева 0х / 0X

* работает только с x и X 


### '+' - добавить + перед беззнаковым числом 

работает только с d и i / просто игнорируется для других типов в любом количестве
Отменяет действие ' '
Рассматривается как флаг, где бы ни стоял
Любые дополнительные плюсы до спецификатора игнорируются, если строка валидная (является формат-строкой)


### ' '  - добавить пробел перед беззнаковым числом

* работает только с d и i / просто игнорируется для других типов в любом количестве
* Игнорируется при наличии '+'
* Рассматривается как флаг, где бы ни стоял
* Любые дополнительные пробелы до спецификатора игнорируются, если строка валидная (является формат-строкой)


### Точность

* c: Не работает с символами с (игнорируется)
* %: Не работает с % (игнорируется)
* p: Увеличивает количество знаков после 0х заполняя пространство от 0х до указателя нулями (игнорируется при значениях точности меньше или равных 12 - длины указателя)
* x и X: при назначенном '#' также увеличивает количество нулей после 0x или 0X в пределах точности
* В предыдущих двух случаях точность равна длине строки после 0х или 0Х
* s:  ограничивает количество выводимых на печать символов строки (если точность больше длины, она игнорируется)
* Для p d i u x X нулевая точность отменяет печать нуля.
* Отменяет действие флага '0' для p d i u x X
* Отрицательная точность игнорируется, поведение как с флагом '-'
* Действие точности ограничивается количеством выводимых символов для u x X
* В качестве точности используется последнее число с точкой перед ним

* Для определения числового значения точности используем подобие atoi, как только находим точку
* Изначально точность нельзя устанавливать на ноль, потому что поведение printf при нулевой и при незададанной точности отличается в некоторых случаях (при нулевых значениях p d i x X u)
* Если точность определяется числом, выходящим за границы типа int (больше максимального int), то печатается все, включая предыдущий спецификатор, и на нем вывод символов прекращается (если спецификатора не было, ничего не печатается), возвращается -1


### Ширина

* Отрицательная ширина не игнорируется, рассматривается как положительная и флаг -
* Ширина игнорируется, пока ее значение меньше длины строки с примененной точностью (можно сказать, что она не игнорируется, но ее действие незаметно, т.к. она не укорачивает строки)
* В качестве ширины используется последнее число без точек кроме 0, 0 - это флаг

* Для определения числового значения ширины используем подобие atoi, как только находим цифру, отличную от нуля
* Изначально ширину можно установить равной нулю (но я все флаги установила на -1)
* Если ширина определяется числом, выходящим за границы типа int (больше максимального int), то печатается все, включая предыдущий спецификатор, и на нем вывод символов прекращается (если спецификатора не было, ничего не печатается), возвращается -1


### Особенности типов

* c: если в спецификатор передается ‘\0’, то этот символ не распечатывается, но считается как распечатанный при подсчете распечатанных символов
* s: Если в строку подан NULL, печатается (null), точность оказывает на (null) тот же эффект, что на обычные строки
* s: сегается, если подан указатель не на строчку
* u, x и X: приводят входные данные к типу unsigned int
* i, d: приводят входные данные к типу int
* p:  позволяет вывести в шестнадцатеричной системе любое число, возможное к представлению типом unsigned long long, однако даже попытка работы с переполнением и приведением большего числа к данному типу вызывает системную ошибку integer literal is too large to be represented in any integer type (думаю, что такое поведение можно не обрабатывать отдельно, системная ошибка также может возникать при использовании подобия itoa)
* Будем считать, что p приводит входные данные к типу unsigned long long


### Обработка невалидныx формат-строк

* Если после флагов и ширины нет ничего (\0), то формат-строка просто пропускается
* Если после находится какой-либо символ кроме спецификатора, то этот символ обрабатывается как чар с применением флагов


### Порядок печати:

1. '#' '+' ' ' с флагом '-'
2. аргумент и точность с флагом '-'
3. ширина с флагом '-'
4. '#' '+' ' '  с флагом '0', без флага '-' (при включенной точности отключаем '0' для p d i u x X)
5. ширина и '0' без флага '-' (при включенной точности отключаем '0' для p d i u x X)
6. '#' '+' ' '  без флага '0' без флага '-' (при включенной точности отключаем '0' для p d i u x X)
7. аргумент и точность без флага '-'