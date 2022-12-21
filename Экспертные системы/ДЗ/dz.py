from __future__ import print_function
import math
import copy


# Класс, хранящий в себе данные об определённой конфигурации ПК
class ComputerConfiguration(object):
    name = None
    motherboard = None
    CPU = None
    graphics_card = None
    RAM = None
    storage_device = None
    cpu_cooler = None
    power_supply = None

    def __init__(self, name, motherboard, CPU, graphics_card, RAM, storage_device, cpu_cooler, power_supply):
        self.name = name
        self.motherboard = motherboard
        self.CPU = CPU
        self.graphics_card = graphics_card
        self.RAM = RAM
        self.storage_device = storage_device
        self.cpu_cooler = cpu_cooler
        self.power_supply = power_supply

    def display(self):
        print(self.name + ":\n" +
              "   Процессор: " + self.motherboard + "\n" +
              "   Материнская плата: " + self.CPU + "\n" +
              "   Видеокарта: " + self.graphics_card + "\n" +
              "   ОЗУ: " + self.RAM + "\n" +
              "   Накопитель: " + self.storage_device + "\n" +
              "   Процессорный кулер: " + self.cpu_cooler + "\n" +
              "   Блок питания: " + self.power_supply)


# Объявление конфигураций ПК с различными комплектующими
starting_AMD = ComputerConfiguration(
    "Стартовая сборка (AMD)",
    "AMD Ryzen 5 1600",
    "AMD B450",
    "AMD Radeon RX 570 8 Гбайт",
    "8 Гбайт DDR4-3000/3200",
    "SSD, 240-256 Гбайт, SATA 6 Гбит/с (Crucial BX500) или HDD на выбор пользователя",
    "PCcooler GI-X2",
    "Be Quiet System Power 9 500 Вт")

basic_AMD = ComputerConfiguration(
    "Базовая сборка (AMD)",
    "AMD Ryzen 5 3600",
    "AMD B450",
    "AMD Radeon RX 5500 XT 8 Гбайт",
    "16 Гбайт DDR4-3000/3200",
    "SSD, 480-512 Гбайт, PCI Express x4 3.0 (ADATA XPG SX6000) + HDD на выбор пользователя",
    "ID-COOLING SE-224-W",
    "Be Quiet System Power 9 600 Вт")

optimal_AMD = ComputerConfiguration(
    "Оптимальная сборка (AMD)",
    "AMD Ryzen 5 3600",
    "AMD 350/450",
    "AMD Radeon RX 5700, 8 Гбайт GDDR6",
    "16 Гбайт DDR4-3000/3200",
    "SSD, 480-512 Гбайт, PCI Express x4 3.0 (ADATA XPG SX8200 Pro) + HDD на выбор пользователя",
    "ID-COOLING SE-224-W",
    "Be Quiet Pure Power 11-CM 600 Вт")

advanced_AMD = ComputerConfiguration(
    "Продвинутая сборка (AMD)",
    "AMD Ryzen 7 3700X",
    "AMD B450",
    "NVIDIA GeForce RTX 2070 Super, 8 Гбайт GDDR6",
    "32 Гбайт DDR4-3200/3466",
    "SSD, 480-512 Гбайт, PCI Express x4 3.0 (DATA XPG SX8200 Pro) + HDD на выбор пользователя",
    "ID-COOLING SE-224-XT Basic",
    "Be Quiet Pure Power 11-CM 600 Вт")

maximum_AMD = ComputerConfiguration(
    "Максимальная сборка (AMD)",
    "AMD Ryzen 9 3900X",
    "AMD X570",
    "NVIDIA GeForce RTX 2080 Ti, 11 Гбайт GDDR6",
    "32 Гбайт DDR4-3466/3600",
    "SSD, 1 Тбайт, PCI Express x4 3.0 (Samsung 970 EVO Plus)",
    "NZXT Kraken X62",
    "Be Quiet Straight Power 11 Platinum, 750 Вт")

starting_Intel = ComputerConfiguration(
    "Стартовая сборка (Intel)",
    "Intel Core i3 9100F",
    "ASUS ROG Strix Z390-F Gaming",
    "Palit GeForce GTX 1650 SUPER 1530MHz",
    "8 Гбайт DDR4-3000/3200 (Crucial BX500)",
    "SSD, 240-256 Гбайт, SATA 6 Гбит/с (Crucial BX500) или HDD на выбор пользователя",
    "PCcooler GI-X2",
    "Be Quiet System Power 9 500 Вт")

basic_Intel = ComputerConfiguration(
    "Базовая сборка (Intel)",
    "Intel Core i5-9400F",
    "Intel B360/B365 Express",
    "  NVIDIA GeForce GTX 1660 SUPER",
    "16 Гбайт DDR4-3000/3200",
    "SSD, 480-512 Гбайт, PCI Express x4 3.0 (ADATA XPG SX6000) + HDD на выбор пользователя",
    "ID-COOLING SE-224-W",
    "Be Quiet System Power 9 600 Вт")

optimal_Intel = ComputerConfiguration(
    "Оптимальная сборка (Intel)",
    "Intel Core i5-9400F",
    "Intel Z370/Z390 Express",
    "AMD Radeon RX 5700, 8 Гбайт GDDR6",
    "16 Гбайт DDR4-3000/3200",
    "SSD, 480-512 Гбайт, PCI Express x4 3.0 (ADATA XPG SX8200 Pro) + HDD на выбор пользователя",
    "ID-COOLING SE-224-W",
    "Be Quiet Pure Power 11-CM 600 Вт")

advanced_Intel = ComputerConfiguration(
    "Продвинутая сборка (Intel)",
    "Intel Core i7-9700F",
    "Intel Z390 Express",
    "NVIDIA GeForce RTX 2070 Super, 8 Гбайт GDDR6",
    "32 Гбайт DDR4-3200/3466",
    "SSD, 480-512 Гбайт, PCI Express x4 3.0 (DATA XPG SX8200 Pro) + HDD на выбор пользователя",
    "ID-COOLING SE-224-XT Basic",
    "Be Quiet Pure Power 11-CM 600 Вт")

maximum_Intel = ComputerConfiguration(
    "Максимальная сборка (Intel)",
    "Intel Core i9-9900K",
    "Intel Z390",
    "NVIDIA GeForce RTX 2080 Ti, 11 Гбайт GDDR6",
    "32 Гбайт DDR4-3466/3600",
    "SSD, 1 Тбайт, PCI Express x4 3.0 (Samsung 970 EVO Plus)",
    "NZXT Kraken X62",
    "Be Quiet Straight Power 11 Platinum, 750 Вт")

# Добавление объявленных комплектаций в один массив
ListOfConfigurations = [starting_AMD,   basic_AMD,  optimal_AMD,    advanced_AMD,   maximum_AMD,
                        starting_Intel, basic_Intel, optimal_Intel, advanced_Intel, maximum_Intel]

# Объявление ключевых вопросов, которые в дальнейшем будут задаваться пользователю
Questions = \
    ["Требуется ли вам максимально возможная производительность конфигурации для запуска требовательных приложений и современных игр?",
    "Является ли для вас важным аргументом низкая стоимость конфигурации?",
    "Важна ли для вас возможность дальнейшего апгрейда системы с сохранением имеющейся материнской платы? ",
    "Большое ли для вас имеет значение, чтобы система была построена на базе процессора компании Intel?",
    "Устроит ли вас система, построенная на основе процессора компании AMD, при условии, что в данном случае система будет более выгодной?",
    "Необходим ли вам при использовании системы большой запас оперативной памяти для запуска требовательных к ней приложений?",
    "Необходим ли вам при использовании системы большой объём накопителя?",
    "Важна ли для вас высокая скорость работы накопителя?"]

# Определение весовых коэффициентов для ответов на ключевые вопросы
KnowledgeBase = [# 1    2    3    4    5    6    7    8
                [0.3, 0.9, 0.2, 0.0, 1.0, 0.3, 0.5, 0.3],
                [0.4, 0.8, 0.6, 0.0, 1.0, 0.6, 0.5, 0.4],
                [0.6, 0.6, 0.6, 0.0, 1.0, 0.6, 0.6, 0.6],
                [0.8, 0.3, 1.0, 0.0, 1.0, 0.6, 0.6, 0.7],
                [1.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.9, 1.0],

                [0.2, 0.9, 0.2, 1.0, 0.0, 0.3, 0.5, 0.3],
                [0.3, 0.8, 0.5, 1.0, 0.0, 0.6, 0.5, 0.4],
                [0.5, 0.5, 0.6, 1.0, 0.0, 0.6, 0.5, 0.6],
                [0.8, 0.2, 0.9, 1.0, 0.0, 0.6, 0.6, 0.7],
                [0.9, 0.0, 1.0, 1.0, 0.0, 1.0, 0.9, 1.0]]

# Получение ответов на ключевые вопрос от пользователя
BuffBase = copy.deepcopy(KnowledgeBase)
inputKnowledge = []
print("\nДля работы экспертной системы вам необходимо ввести ответ о вашей системе.")
print("Возможен ввод цифр из диапазона от 0 до 10.")
for i in range(len(Questions)):
    print("\nВопрос: " + Questions[i])
    print("0 – точно нет, 1-4 –  скорее нет, 5 – не уверен, 6-9 – скорее да, 10 – точно да")
    print("Ваши ответ: ", end=' ')
    inputKnowledge.append(int(input()) / 10)

# Вывод всех заданных вопросов (объектов базы знаний) с их индексами
print("\n\nСПИСОК ВОПРОСОВ (ОБЪЕКТОВ) С ИХ ИНДЕКСАМИ: \n")
for i in range(len(Questions)):
    print(i + 1, "-", Questions[i])

# Вывод существующей базы знаний (информация для каждого вопроса по индексу)
print('\n\nБАЗА ЗНАНИЙ ЭКСПЕРТНОЙ СИСТЕМЫ: \n')
print('Индексы вопросов'.center(30), end='||')
for i in range(len(Questions)):
    print('{:^5}'.format(i + 1), end='||')
print()
for i in range(len(ListOfConfigurations)):
    print('\n', ListOfConfigurations[i].name.center(29), end='||')
    for j in range(len(KnowledgeBase[i])):
        print('{:^5}'.format(KnowledgeBase[i][j]), end='||')
    print()
for i in range(len(ListOfConfigurations)):
    for j in range(len(KnowledgeBase[i])):
        BuffBase[i][j] = round(math.fabs(KnowledgeBase[i][j] - inputKnowledge[j]), 1)

# Выполнение расчётов
Delta = []
TotalSum = 0
for i in range(len(ListOfConfigurations)):
    for j in range(len(KnowledgeBase[i])):
        TotalSum += BuffBase[i][j]
    Delta.append(round(math.fabs(9 - TotalSum), 1))
    TotalSum = 0

# Сравнение списка ответов пользователя с объектом базы знаний
print("\n\nСРАВНЕНИЕ СПИСКА ОТВЕТОВ ПОЛЬЗОВАТЕЛЯ С ОБЪЕКТОМ БАЗЫ ЗНАНИЙ: \n")
EstimateIndex = Delta.index(max(Delta))
print('Индексы вопросов'.center(30), end='||')
print('{:^30}'.format("Характеристики конфигурации"), end='||')
print('{:^30}'.format("Введенные характеристики"), end='||')
print()
for i in range(len(Questions)):
    print('{:^30}'.format(i + 1), end='||')
    print('{:^30}'.format(KnowledgeBase[EstimateIndex][i] * 10), end='||')
    print('{:^30}'.format(inputKnowledge[i] * 10), end='||')
    print()

# Вывод итогового решения
print('\n\nИТОГОВОЕ РЕШЕНИЕ: \n')
ListOfConfigurations[EstimateIndex].display()
