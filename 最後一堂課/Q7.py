'''==========================================

第七題-Python 繼承

=========================================='''

# Shape 類別
class Shape():
    # 建構子
    def __init__(self, newColor):
        self.__color = newColor
    # 設定顏色函式
    def setColor(self, newColor):
        self.__color = newColor
    # 取得顏色函式
    def getColor(self):
        return self.__color
    # 輸出函式
    def __str__(self):
        return "Shape"

# Sphere 類別 (繼承 Shape)
class Sphere(Shape):
    # 建構子
    def __init__(self, newRadius, newColor):
        self.__radius = newRadius
        super().__init__(newColor)
    # 設定半徑函式
    def setRadius(self, newColor):
        self.__radius = newRadius
    # 取得半徑函式
    def getRadius(self):
        return self.__radius
    # 取得體積函式
    def getVolume(self):
        return 3.14159 * self.getRadius() * self.getRadius() * self.getRadius() * 4 / 3
    # 輸出函式
    def __str__(self):
        return "Sphere"

# Cuboid 類別 (繼承 Shape)
class Cuboid(Shape):
    # 建構子
    def __init__(self, newLength, newWidth, newHeight, newColor):
        self.__length = newLength
        self.__width = newWidth
        self.__height = newHeight
        super().__init__(newColor)
    # 設定長函式
    def setLength(self, newLength):
        self.__length = newLength
    # 取得長函式
    def getLength(self):
        return self.__length
    # 設定寬函式
    def setWidth(self, newWidth):
        self.__width = newWidth
    # 取得寬函式
    def getWidth(self):
        return self.__width
    # 設定高函式
    def setHeight(self, newHeight):
        self.__height = newHeight
    # 取得高函式
    def getHeight(self):
        return self.__height
    # 取得體積函式
    def getVolume(self):
        return self.getLength() * self.getWidth() * self.getHeight()
    # 輸出函式
    def __str__(self):
        return "Cuboid"

# 主程式
if __name__ == "__main__":
    # 輸入六個值
    radius = input()
    sphereColor = input()
    length = input()
    width = input()
    height = input()
    cuboidColor = input()

    # 將輸入值建立兩個物件
    sphere = Sphere(int(radius), sphereColor)
    cuboid = Cuboid(int(length), int(width), int(height), cuboidColor)

    # 依照題目範例格式輸出
    print(sphere.__str__() + ":(" + str(sphere.getRadius()) + ")," +
          str(round(sphere.getVolume(), 1)) + "," + sphere.getColor())
    print(cuboid.__str__() + ":(" + str(cuboid.getLength()) + "," + str(cuboid.getWidth()) + "," +
          str(cuboid.getHeight()) + ")," + str(round(float(cuboid.getVolume()), 1)) + "," + cuboid.getColor())
