n = int(input()) 
plus = [] 
minus = [] 

for i in range(n): 
    x, y = map(int, input().split()) 
    plus.append(x + y) 
    minus.append(x - y) 

result = max(max(plus) - min(plus), max(minus) - min(minus)) 
print(result)
