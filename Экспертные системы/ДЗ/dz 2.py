from __future__ import print_function
import copy

class Switchboard(object):
    name = None
    type = None
    count = None
    portSFP=None
    portQSFP=None
    cost = None
    purpose = None

    def __init__(self, name, type, count,portSFP,portQSFP, cost, purpose):
        self.name = name
        self.type = type
        self.count  = count
        self.portSFP=portSFP
        self.portQSFP=portQSFP
        self.cost = cost
        self.purpose = purpose

    def display(self):
        print("   "+self.name + ":\n" +
            "   Кол-во компьютеров: " + self.count + "\n" +
            "   Кол-во портов SFP: " + self.portSFP + "\n" +
            "   Кол-во портов QSFP+: " + self.portQSFP + "\n" +
            "   Топология сети: " + ','.join(self.purpose) + "\n" +
            "   Предел стоимости: " + self.cost + "\n" +  
            "   Тип: " + self.type + "\n")


Counts = ["от 2 до 20 компьютеров", "от 20 до 40 компьютеров", "от 40 до 50 компьютеров"]  
Topology = ["полносвязная", "ячеистая", "кольцевая", "звездообразная","смешанная","древовидная", "общая шина"]
Costs = ["от 20000р до 200000р", "от 200000р до 400000р", "от 400000р до 600000р"]  
Characteristics = [Counts, Topology, Costs]

basic_basic= Switchboard("Huawei S5735-L24T4S-A1","управляемый L2+",Counts[0],"1","0",Costs[0],[Topology[0],Topology[1],Topology[3],Topology[5], Topology[6]])
basic_basic_2 = Switchboard("D-Link DXS-1210-22C/A","управляемый",Counts[0],"1","0",Costs[0],[ Topology[2],Topology[4]])

basic_optimal = Switchboard("D-Link DGS-3000-28XS","настраиваемый", Counts[0],"2","0",Costs[1],[ Topology[0],Topology[1],Topology[3],Topology[5],Topology[6]])
basic_optimal_2 = Switchboard("D-Link DXS-12-12SC/A","настраиваемый",Counts[0],"3","0",Costs[1],[ Topology[0],Topology[1],Topology[3],Topology[2],Topology[4]])

basic_advanced = Switchboard("H3C LS-513S-52S-EI-GL","настраиваемый",Counts[0],"0","18",Costs[2],[ Topology[0],Topology[1],Topology[3],Topology[2],Topology[4],Topology[5],Topology[6]])


optimal_basic = Switchboard("Zyxel NebulaFlex Pro GS2220-28-EU0101F","управляемый",Counts[1],"1","0",Costs[0],[Topology[0], Topology[3], Topology[5], Topology[6]])
optimal_basic_2 = Switchboard("Zyxel XGS2210-28-EU0101F","управляемый",Counts[1],"1","0",Costs[0],[Topology[1],Topology[2], Topology[4]])

optimal_optimal = Switchboard("Zyxel NebulaFlex Pro GS2220-10HP-EU0101F","настраиваемый",Counts[1],"3","0",Costs[1],[Topology[0], Topology[1], Topology[2],Topology[4]])
optimal_optimal_2 = Switchboard("D-Link DGS-000-28XS","настраиваемый",Counts[1],"6","0",Costs[1],[Topology[3], Topology[5], Topology[6]])

optimal_advanced = Switchboard("Zyxel NebulaFlex GS23-10HP-EU9990F","настраиваемый",Counts[1],"12","2",Costs[2],[Topology[0], Topology[1], Topology[2],Topology[4],Topology[3], Topology[5],Topology[6]])


advanced_basic = Switchboard("H3C LS-5130S-52S-EI-GL","управляемый",Counts[2],"1","0",Costs[0],[Topology[0], Topology[1], Topology[4]])
advanced_basic_2 = Switchboard("H3C LS-5130S-52S-EI-GL","управляемый",Counts[2],"0","0",Costs[0],[Topology[5], Topology[6], Topology[2],Topology[3]])

advanced_optimal = Switchboard("H3C LS-5130S-52S-EI-GL","настраиваемый",Counts[2],"4","0",Costs[1],[Topology[0], Topology[1], Topology[4]])
advanced_optimal_2 = Switchboard("H3C LS-5130S-52S-EI-GL","управляемый",Counts[2],"6","0",Costs[1],[Topology[5], Topology[6], Topology[2],Topology[3]])

advanced_advanced = Switchboard("H3C S6520X-54QC-EI","настраиваемый",Counts[2],"48","2",Costs[2],[Topology[0], Topology[2], Topology[1], Topology[4], Topology[5],Topology[3],Topology[6]])

characteristicListSwitch = [
    basic_basic,basic_basic_2,basic_optimal,basic_optimal_2,basic_advanced,
    optimal_basic,optimal_basic_2,optimal_optimal,optimal_optimal_2,optimal_advanced,
    advanced_basic,advanced_basic_2,advanced_optimal,advanced_optimal_2,advanced_advanced
]

Questions = \
    ["Какое будет количество компьютеров в сети?",
    "Какая будет топология сети?",
    "Каковы пределы стоимости требуемого оборудования?"]
Answers = \
    [["1 - от 10 до 20 компьютеров", "2 - от 20 до 40 компьютеров", "3 - от 40 до 50 компьютеров"], 
    ["1 - Полносвязную", "2 - Ячеистую", "3 - Кольцевую","4 - Звездообразную","5 - Смешанную","6 - Древовидную","7 - Общую шину"],
    ["1 - от 200000р до 400000р", "2 - от 400000р до 800000р", "3 - от 800000р до 1000000р"]]


def filterDataCount(characteristicList):
    newSwitchboard = []
    for switch in characteristicList:
        if inputData[0] == switch.count:
            newSwitchboard.append(switch)
    return newSwitchboard

def filterDataPurpose(characteristicList):
    newSwitchboard = []
    for switch in characteristicList:
        if inputData[1] in switch.purpose:
            newSwitchboard.append(switch)
    return newSwitchboard        

def filterDataCost(characteristicList):
    newSwitchboard = []
    for switch in characteristicList:
        if inputData[2] == switch.cost:
            newSwitchboard.append(switch)
    return newSwitchboard 

listOfFilters = [filterDataCount, filterDataPurpose, filterDataCost]

inputData = []
resСharacteristicList = copy.deepcopy(characteristicListSwitch)
print("\nОтветьте пожалуйста на вопросы")
for i in range(len(Questions)):
    print("\n" + Questions[i])
    print(', '.join(Answers[i]))
    print("Ответ: ", end=' ')
    inputData.append(Characteristics[i][(int(input()) - 1)])
    resСharacteristicList = listOfFilters[i](resСharacteristicList)

print("\nВопросы:\n")
for i in range(len(Questions)):
    print(i + 1, "-", Questions[i])

print('\nБаза данных: \n')

print('№'.center(50), end='+')
print('{:^30}'.format(1), end='+')
print('{:^30}'.format(2), end='+')
print('{:^90}'.format(3))
print("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
for i in range(len(characteristicListSwitch)):
    print('\n', characteristicListSwitch[i].name.center(50), end='+')
    print('{:^30}'.format(characteristicListSwitch[i].count), end='+')
    print('{:^30}'.format(characteristicListSwitch[i].cost), end='+')
    print('{:^90}'.format(', '.join(characteristicListSwitch[i].purpose)), end='+')
    print("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")

print('\nВведеные данные: \n')
print("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
print('№'.center(10), end='+')
print('{:^100}'.format("Характеристики конфигурации"), end='+')
print('{:^100}'.format("Введенные характеристики"))
print("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
print('{:^10}'.format(1), end='+')
print('{:^100}'.format(resСharacteristicList[0].count), end='+')
print('{:^100}'.format(inputData[0]))
print("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
print('{:^10}'.format(2), end='+')
print('{:^100}'.format(', '.join(resСharacteristicList[0].purpose)), end='+')
print('{:^100}'.format(inputData[1]))
print("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
print('{:^10}'.format(3), end='+')
print('{:^100}'.format(resСharacteristicList[0].cost), end='+')
print('{:^100}'.format(inputData[2]))
print("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")

print('\nИТОГ: \n')
resСharacteristicList[0].display()
