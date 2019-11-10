import math
roomNum = input()
max = 0

for i in range(48, 54):
    cnt = roomNum.count(chr(i))
    if max < cnt:
        max = cnt
for i in range(55,57):
    cnt = roomNum.count(chr(i))
    if max < cnt:
        max = cnt

cnt = math.ceil((roomNum.count('6') + roomNum.count('9'))/2)
if max < cnt:
    max = cnt

print(max)