'''==========================================

第五題-Python Student Inheritance

=========================================='''

''' 本題重點：Python物件繼承 '''

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
        print(str(self.getYear()) + "-" + str(self.getMonth()) + "-" + str(self.getDay()), end=' ')

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

# Student 類別 (繼承 Person)
class Student(Person):
    # 建構子
    def __init__(self, newName, newMathScore, newChineseScore, newBirthday):
        self.__mathScore = newMathScore
        self.__chineseScore = newChineseScore
        super().__init__(newName, newBirthday)
    # 設定數學成績
    def setMathScore(self, newMathScore):
        self.__mathScore = newMathScore
    # 設定國文成績
    def setChineseScore(self, newChineseScore):
        self.__chineseScore = newChineseScore
    # 取得數學成績
    def getMathScore(self):
        return self.__mathScore
    # 取得國文成績
    def getChineseScore(self):
        return self.__chineseScore
    # 計算平均成績
    def average(self):
        return (self.__mathScore + self.__chineseScore) / 2
    # 輸出
    def toString(self):
        super().toString()
        print(self.average())

# 主程式
if __name__ == "__main__":
    # 根據題目宣告兩個 Student 物件
    s1 = Student("Candy", 70, 100, Date(1999, 6, 1))
    s2 = Student("Spotlight", 89, 60, Date(1997, 10, 8))

    # 分別輸出
    s1.toString()
    s2.toString()