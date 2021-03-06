# BatteryProtectorBoard
Этот проект описывает плату защиты акуумулятора и включает в себя: 
- Схему устройства
- Чертёж платы 
- Исходник платы в виде EasyEDA JSON
- Прошивку для Atmel 328p
- Схемы, чертежи, наброски
- Фото прототипа платы

Характеристики: 
- Рабочее напряжение: 5-15В
- Потребление тока в простое: 35мА
- Потребление тока минимум 20мА максимум 70 мА
- Рабочий ток для подключённого устройства: 1А
- Пиковый ток для подключённого устройства: 3А
- Точность измерения напряжения +-0.05В

Плата состоит из:
- Тестолитовая плата, 2 сторонняя
- Atmel 328p
- Диод 1n4007
- Кварцевый резонатор для Atmel
- Линейный стабилизатор напряжения AMS1117
- Силовой мосфет IRF520N
- 2 кнопки
- 4 RGB светодиода
- 2 разъёма XT-60
- 3 SMD светодиода
- 2 конденсатора 100мкФ 25В (для стабилизации напряжения)
- 1 SMD резистор на 180 Ом (маркировка 181) (для делителя напряжения)
- 1 SMD резистор на 2.2 кОм (маркировка 222) (для делителя напряжения)
- 15 SMD резисторов на 1 кОм (маркировка 102 или 1001)

Умеет делать:
- Измерять напряжение на входе
- Управлять питанием устройства на выхоже
- Отключать устройство при достижении нижнего порога напряжения
- Отключать устройство при достижении верхнего порога напряжения
- Отключать устройство с кнопки (если подержать секунду)
- Показывать уровень заряда 4мя светодиодами (с учётом нелинейности падения напряжения для литиевых аккумуляторов)
- Калиброваться в диапазоне напряжений 5В - 18В (по дефолту калиброван для 3S аккумулятора)
- Программироваться как Arduino, можно допиливать по своему усмотрению

Как изготавливать:
- Изготовить плату последней версии в папке с Gerber файлами.
- Распаять комплектуху. Atmel идеально снимать с Arduino Pro Mini, она уже прошита так как нужно.
- Открыть скетч в редакторе Arduino, скомпилировать.
- Прошить плату по UART через FTDI программатор. Во время прошивки ткнуть reset, чтобы началась прошивка.
- Проверить расниновку светодиодов на плате и соответствие цветов. Заряд более 40% должен отобраться зелёным, а калибровка синим.
(Если цвета не соответствуют, исправить константы описывающие распиновку диодов)
- Готово.

Как пользоваться:
После включения в течении секунды отображается анимация включения, после чего переход в режим отображеня заряда. 
В режиме отображения заряда заряд ниже 40% отображается розовым цветом, а заряд выше 40% отображается зелёным цветом.
При напряжении ниже минимального (стандартно это 10В) все светодиоды мигают розовым цветом, а подключённое устройство обесточивается.
При напряжении выше максимального (стандартно это 12.5В) все светодиоды мигают зелёным цветом, а подключённое устройство обесточивается.
Чтобы вручную отключить подключённое устройство, необходимо подержать кнопку 1 секунду, до завершения анимации, после чего 4й светодиод загорится синим. 
Это означает, что устройство обесточено вручную.В таком режиме плата будет находиться пока устройство не будет включено обратно вручную.  
Чтобы включить устройство обратно, требуется подержать кнопку нажатой секунду до завершения анимации, после чего плата переходит в режим отображения уровня заряда.

Как калибровать:
Диапазон напряжений можно калибровать. Он может находиться в диапазоне от 5В до 18В. 
Чтобы перейти в режим калибровки, нужно подключить плату к регулируемому блоку питания и перезагрузить плату держа нажатой кнопку выключения.
Когда режим калибровки активен, все светодиоды светят синим цветом. 
После того как Вы отпустите кнопку выключения, начнёт мигать зелёным 4й светодиод, это означает что сейчас калибруется верхний порог напряжения. 
Выставьте на блоке питания желаемое верхнее напряжение, убедитесь напряжение стабильно и нажмите кнопку включения на плате. 
В течении нескольких секунд плата будет измерять напряжение и сохранит измеренное напряжение в памяти и перейдёт в режим калибровки нижнего порога напряжения.
В режиме калибровки нижнего порога напряжения начнёт мигать 1й светодиод красным цветом. Выставьте на блоке питания желаемое нижнее напряжение и нажмите кнопку выключения. 
В течении нескольких секунд плата будет измерять напряжение и сохранит измеренное напряжение в памяти и перейдёт в режим отображения уровня заряда (нормальной работы).
