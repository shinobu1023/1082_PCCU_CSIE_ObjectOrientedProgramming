'''==========================================

第三題-StudentCard_Composition

=========================================='''

# Student 類別
class Student():
    # 建構子
	def __init__(self, newName, newDate, newScore):
		self.__name = newName
		self.__date = newDate
		self.__score = newScore
    # 設定名字函式
	def setName(self, newName):
		self.__name = newName
    # 取得名字函式
	def getName(self):
		return self.__name
    # 設定日期函式
	def setDate(self, newDate):
		self.__date = newDate
    # 取得日期函式
	def getDate(self):
		return self.__date
    # 設定分數函式
	def setScore(self, newScore):
		self.__score = newScore
    # 取得分數函式
	def getScore(self):
		return self.__score
    # 輸出函式
	def toString(self):
		print(self.getName(), end=' ')
		self.getDate().toString()
		print(self.getScore())

# Date 類別
class Date():
    # 建構子
	def __init__(self, newMonth, newDay, newYear):
		self.__month = newMonth
		self.__day = newDay
		self.__year = newYear
    # 設定月份函式
	def setMonth(self, newMonth):
		self.__month = newMonth
    # 取得月份函式
	def getMonth(self):
		return self.__month
    # 設定日期函式
	def setDay(self, newDay):
		self.__day = newDay
    # 取得日期函式
	def getDay(self):
		return self.__day
    # 設定年份函式
	def setYear(self, newYear):
		self.__year = newYear
    # 取得年份函式
	def getYear(self):
		return self.__year
    # 輸出函式
	def toString(self):
		print(str(self.getMonth()) + "\\" + str(self.getDay()) + "\\"  + str(self.getYear()), end=' ')


# 主程式
if __name__ == "__main__":
    # 宣告兩個物件
    s1 = Student("John", Date(6, 1, 1999), 90)
    s2 = Student("Marry", Date(10, 8, 1997), 80)
    # 根據題意進行輸入
    newName = input()
    newMonth = input()
    newDay = input()
    newYear = input()
    # 設定
    s1.setName(newName)
    s2.setDate(Date(int(newMonth), int(newDay), int(newYear)))
    # 輸出
    s1.toString()
    s2.toString()