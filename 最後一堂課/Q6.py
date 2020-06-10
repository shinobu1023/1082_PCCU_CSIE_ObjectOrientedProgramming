'''==========================================

第六題-Python 物件組合

=========================================='''

# Body 類別
class Body():
    # 建構子
    def __init__(self, newHeight, newWeight):
        self.__height = newHeight
        self.__weight = newWeight
    # 設定身高函式
    def setHeight(self, newHeight):
        self.__height = newHeight
    # 取得身高函式
    def getHeight(self):
        return self.__height
    # 設定體重函式
    def setWeight(self, newWeight):
        self.__weight = newWeight
    # 取得體重函式
    def getWeight(self):
        return self.__weight
    # 輸出函式
    def toString(self):
        bmi = self.getWeight() / (self.getHeight() * self.getHeight())
        print(round(bmi, 2), end=' ')

# Teacher 類別
class Teacher():
    # 建構子
    def __init__(self, newName, newBody, newSalary):
        self.__name = newName
        self.__body = newBody
        self.__salary = newSalary
    # 設定名字函式
    def setName(self, newName):
        self.__name = newName
    # 取得名字函式
    def getName(self):
        return self.__name
    # 設定身體資訊函式
    def setBody(self, newBody):
        self.__body = newBody
    # 取得身體資訊函式
    def getBody(self):
        return self.__body
    # 設定薪水函式
    def setSalary(self, newSalary):
        self.__salary = newSalary
    # 取得薪水函式
    def getSalary(self):
        return self.__salary
    # 輸出函式
    def toString(self):
        print(self.getName(), end=' ')
        self.getBody().toString()
        print(self.getSalary())

# 主程式
if __name__ == "__main__":
    # 根據題目建立兩個物件
    teacher1 = Teacher("Candy", Body(1.7, 80), 88000)
    teacher2 = Teacher("Linda", Body(1.6, 90), 61000)

    # 輸入三個值
    name = input()
    height = input()
    weight = input()

    # 將第一個值修改第一個物件的名字
    teacher1.setName(name)
    # 將第二個值修改第二個物件的身高、體重
    teacher2.setBody(Body(float(height), int(weight)))

    # 將兩物件輸出
    teacher1.toString()
    teacher2.toString()
