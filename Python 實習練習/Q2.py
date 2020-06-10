'''==========================================

第二題-Rectangle_Encapsulation

=========================================='''

# Rectangle 類別
class Rectangle():
    # 建構子
	def __init__(self, newLength, newWidth):
		self.__length = newLength
		self.__width = newWidth
    # 設定長函式
	def setLength(self, newLength):
		self.__length = newLength
    # 取得長函式
	def getLength(self):
		return self.__length
    # 設定寬函式
	def setWidth(self,newWidth):
		self.__width = newWidth
    # 取得寬函式
	def getWidth(self):
		return self.__width
    # 取得面積函式
	def getArea(self):
		return self.__length * self.__width
    # 取得周長函式
	def getPerimeter(self):
		return (self.__length + self.__width) * 2


# 主程式
if __name__ == "__main__":
    # 輸入四個值
    Length_1 = input()
    Length_2 = input()
    Width_1 = input()
    Width_2 = input()
    # 宣告兩個物件
    r1 = Rectangle(int(Length_1),int(Width_1))
    r2 = Rectangle(int(Length_2),int(Width_2))
    # 印出兩物件
    print("%d %d"%(r1.getArea(), r1.getPerimeter()))
    print("%d %d"%(r2.getArea(), r2.getPerimeter()))
    # 根據題目進行設定
    r2.setWidth(50)
    r2.setLength(25)
    # 將設定完之物件，再印出
    print("%d %d"%(r2.getArea(), r2.getPerimeter()))