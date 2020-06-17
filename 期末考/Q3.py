'''==========================================

第三題-Python list sort and max

=========================================='''

''' 本題重點：Python迴圈、條件、list '''

# 找出 list 中最大值
def max(list):
    # 先將第一個值設為預設最大值
    currentMax = list[0]
    # 用迴圈依序造訪 list 中每一個值比較大小
    for i in range(0, len(list)):
        if list[i] > currentMax:
            currentMax = list[i]
    # 回傳最大值
    return currentMax

# selectionSort 排序 list
def selectionSort(list):
    for i in range(0, len(list)):
        currentMin = list[i]
        currentMinIndex = i
        for j in range(i+1, len(list)):
            if currentMin > list[j]:
                currentMin = list[j]
                currentMinIndex = j
        if currentMinIndex != i:
            list[currentMinIndex] = list[i]
            list[i] = currentMin

# 主程式
if __name__ == "__main__":
    # 宣告一個整數 list
    integerList = [75, 55, 4, 44, 31, 81, 98, 75, 81, 86, 54, 40]
    # 宣告一個浮點數 list
    decimalList = [7.5, 5.5, 4.0, 4.4, 3.1, 8.1, 9.8, 7.5, 8.1, 8.6, 5.4, 40.0]

    # 排序後印出
    selectionSort(integerList)
    print("Integer list sort:")
    for i in range(0, len(integerList)):
        print(integerList[i], end=' ')
    print("\nInteger list maximum value:", max(integerList))

    # 排序後印出
    selectionSort(decimalList)
    print("\nDecimal list sort:")
    for i in range(0, len(decimalList)):
        print(decimalList[i], end=' ')
    print("\nDecimal list maximum value:", max(decimalList))