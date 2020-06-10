'''==========================================

第一題-LeapYear_NotOOP

=========================================='''

# 判斷閏年函式
def isLeapYear(newYear):
    # 是閏年回傳true，否則回傳false
	if newYear % 4 == 0 and newYear % 100 != 0 or newYear % 400 == 0:
		return True
	else:
		return False

# 主程式
if __name__ == "__main__":
    # 迴圈執行三次
    for i in range(3):
        # 輸入
        year = int(input())
        # 呼叫函式判斷
        if isLeapYear(year):
            print("The %d is leap year." % (year))
        else:
            print("The %d isn't leap year." % (year))