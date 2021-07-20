n = int(input())
pl = []
mi = []
ans = 0

for _ in range(n):
    k = int(input())
    if k == 1:
        ans += 1
    elif k > 0:
        pl.append(k)
    elif k <= 0:
        mi.append(k)

pl.sort(reverse=True)
mi.sort()

i = 0
j = 0
len_p = len(pl)
len_m = len(mi)

while i < len_p - 1:
    ans += pl[i] * pl[i + 1]
    i += 2
if len_p % 2 != 0:
    ans += pl[len_p - 1]

while j < len_m - 1:
    ans += mi[j] * mi[j + 1]
    j += 2
if len_m %2!=0:
    ans + =mi[len_m - 1]

print(ans)
