def merge(a, l, mid, r):
    tmp = []
    i = l
    j = mid + 1
    while i <= mid and j <= r:
        if a[i] < a[j]:
            tmp.append(a[i])
            i += 1
        else:
            tmp.append(a[j])
            j += 1
    
    while i <= mid:
        tmp.append(a[i])
        i += 1

    while j <= r:
        tmp.append(a[j])
        j += 1

    for i in range(len(tmp)):
        a[l + i] = tmp[i]

def divide(a, l, r):
    if l==r:
        return
    mid = (l+r)//2
    divide(a, l, mid)
    divide(a, mid+1, r)
    merge(a, l, mid, r)

n = int(input('Enter the number of elements: '))
a = list(map(int, input('Enter elements (separated by space): ').split()))
print('Original Array: ', a)
divide(a, 0, n-1)
print('Sorted Array: ', a)

