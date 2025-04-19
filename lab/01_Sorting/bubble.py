print('Enter Number of Elements: ')
n = int(input())
print('Enter Elements: ')
a = list(map(int, input().split()))
print('Original Array: ', a)
for i in range(n):
    for j in range(n-i-1):
        if a[j]>a[j+1]:
            a[j], a[j+1] = a[j+1], a[j]
print('Sorted Array: ', a)