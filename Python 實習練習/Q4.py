'''==========================================

第四題-GeometricObject_Inheritance

=========================================='''

import math # 將會使用 pi

# GeometricObject 類別
class GeometricObject:
    # 建構子
    def __init__(self, color, filled):
        self.__color = color
        self.__filled = filled
    # 取得顏色函式
    def getColor(self):
        return self.__color
    # 設定顏色函式
    def setColor(self, color):
        self.__color = color
    # 判斷是否填滿函式
    def isFilled(self):
        return self.__filled
    # 填滿顏色函式
    def setFilled(self, filled):
        self.__filled = filled
    # 輸出函式
    def __str__(self):
        return "color: " + self.__color + \
            " and filled: " + str(self.__filled)

# Circle 類別 (繼承 GeometricObject)
class Circle(GeometricObject):
    # 建構子
    def __init__(self, radius, color, filled):
        super().__init__(color, filled)
        self.__radius = radius
    # 取得半徑函式
    def getRadius(self):
        return self.__radius
    # 設定半徑函式
    def setRadius(self, radius):
        self.__radius = radius
    # 取得面積函式
    def getArea(self):
        return self.__radius * self.__radius * math.pi
    # 取得直徑函式
    def getDiameter(self):
        return 2 * self.__radius
    # 取得周長函式
    def getPerimeter(self):
        return 2 * self.__radius * math.pi
    # 輸出函式
    def printCircle(self):
        print(self.__str__() + " radius: " + str(self.__radius))

# Rectangle 類別 (繼承 GeometricObject)
class Rectangle(GeometricObject):
    # 建構子
    def __init__(self, width, height, color, filled):
        super().__init__(color, filled)
        self.__width = width
        self.__height = height
    # 取得寬函式
    def getWidth(self):
        return self.__width
    # 設定寬函式
    def setWidth(self, width):
        self.__width = width
    # 取得高函式
    def getHeight(self):
        return self.__height
    # 設定高函式
    def setHeight(self, height):
        self.__height = self.__height
    # 取得面積函式
    def getArea(self):
        return self.__width * self.__height
    # 取得周長函式
    def getPerimeter(self):
        return 2 * (self.__width + self.__height)

# 主程式
if __name__ == "__main__":
    # 輸入兩個值
    cr = input()
    rw = input()
    rh = input()
    circleColor = input()
    circleFilled = input()
    RectangleColor = input()
    RectangleFilled = input()

    # 建立兩個物件
    c = Circle(int(cr), circleColor, bool(circleFilled))
    r = Rectangle(int(rw), int(rh), RectangleColor, bool(RectangleFilled))

    # 輸出
    print("Circle:")
    print("Radius is", c.getRadius())
    print("Diameter is", c.getDiameter())
    print("Area is", c.getArea())
    print("Perimeter is", c.getPerimeter())
    print(c.__str__())

    print("\nRectangle:")
    print("Width is", r.getWidth())
    print("Height is", r.getHeight())
    print("Area is", r.getArea())
    print("Perimeter is", r.getPerimeter())
    print(r.__str__())