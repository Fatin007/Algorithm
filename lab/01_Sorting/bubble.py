n = int(input('Enter Number of Elements: '))
a = list(map(int, input('Enter Elements (separated by space): ').split()))
print('Original Array: ', a)
for i in range(n):
    for j in range(n-i-1):
        if a[j]>a[j+1]:
            a[j], a[j+1] = a[j+1], a[j]
print('Sorted Array: ', a)