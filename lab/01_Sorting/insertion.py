n = int(input('Enter Number of Elements: '))
a = list(map(int, input('Enter Elements (separated by space): ').split()))
print('Original Array: ', a)
for i in range(1, n):
    key = a[i]
    j=i-1
    while j>=0 and key<a[j]:
        a[j+1] = a[j]
        j-=1
    a[j+1] = key
print('Sorted Array: ', a)