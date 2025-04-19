n = int(input('Enter Number of Elements: '))
a = list(map(int, input('Enter Elements (separated by space): ').split()))
print('Original Array: ', a)
for i in range(n):
    for j in range(i+1, n):
        if a[i]>a[j]:
            a[i], a[j] = a[j], a[i]
print('Sorted Array: ', a)