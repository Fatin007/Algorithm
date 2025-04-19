n = int(input('Enter Number of Elements: '))
a = list(map(int, input('Enter Elements (separated by space): ').split()))
print('Original Array: ', a)
for i in range(n):
    mn_idx = i
    for j in range(i+1, n):
        if a[i]>a[j]:
            mn_idx = j
    a[i], a[mn_idx] = a[mn_idx], a[i]
print('Sorted Array: ', a)