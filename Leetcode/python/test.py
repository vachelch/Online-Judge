def swap(arr, i, j):
    tmp = arr[i]
    arr[i] = arr[j]
    arr[j] = tmp

def sort_dict(vals):
    for i in range(len(vals)-1, 0, -1):
        for j in range(i):
            print(j)
            if vals[j] < vals[j+1]:
                swap(vals, j, j+1)

test = [1,2,3,4,5,6]
sort_dict(test)
print(test)
