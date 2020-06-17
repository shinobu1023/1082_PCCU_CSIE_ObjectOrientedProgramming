'''==========================================

第四題-Python Composition

=========================================='''

''' 本題重點：Python物件封裝、物件組合 '''

# Date 類別
class Date():
    # 建構子
    def __init__(self, newYear, newMonth, newDay):
        self.__year = newYear
        self.__month = newMonth
        self.__day = newDay
    # 設定年
    def setYear(self, newYear):
        self.__year = newYear
    # 設定月
    def setMonth(self, newMonth):
        self.__month = newMonth
    # 設定日
    def setDay(self, newDay):
        self.__day = newDay
    # 取得年
    def getYear(self):
        return self.__year
    # 取得月
    def getMonth(self):
        return self.__month
    # 取得日
    def getDay(self):
        return self.__day
    # 輸出
    def toString(self):
        print(str(self.getYear()) + "-" + str(self.getMonth()) + "-" + str(self.getDay()))

# Person 類別
class Person():
    # 建構子
    def __init__(self, newName, newBirthday):
        self.__name = newName
        self.__birthday = newBirthday
    # 設定名字
    def setName(self, newName):
        self.__name = newName
    # 設定生日
    def setBirthday(self, newBirthday):
        self.__birthday = newBirthday
    # 取得名字
    def getName(self):
        return self.__name
    # 取得生日
    def getBirthday(self):
        return self.__birthday
    # 輸出
    def toString(self):
        print(self.getName(), end=' ')
        self.getBirthday().toString()

# 主程式
if __name__ == "__main__":
    # 根據題目宣告兩個 Person 物件
    p1 = Person("Candy", Date(1999, 6, 1))
    p2 = Person("Spotlight", Date(1997, 10, 8))

    # 輸入兩個變數，分別為名字與月份
    newName = input()
    newMonth = input()

    # 根據題目依序修改
    p1.setName(newName)
    p2.setBirthday(Date(1997, newMonth, 8))

    # 分別輸出
    p1.toString()
    p2.toString()