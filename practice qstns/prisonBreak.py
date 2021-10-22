
# m-> number of vertical rods, n-> number of horizontal rods
# h-> list of horizontal rods removed, v-> list of vertical rods removed 
# To find the maximum area of gap produced by removing certain rods from prison

n,m=8,10
h=[1,5,6]
v=[2,8]

# A = max vertical consecutive distance b/w rods * max horizontal consecutive distance b/w rods

v_rods = [x for x in range(0,m+2) if x not in v]
h_rods = [y for y in range(0,n+2) if y not in h]

maxdiff_v =0
maxdiff_h =0

for i in range(len(v_rods)-1):
    maxdiff_v = max(maxdiff_v,abs(v_rods[i+1]-v_rods[i]))

for i in range(len(h_rods)-1):
    maxdiff_h = max(maxdiff_h,abs(h_rods[i+1]-h_rods[i]))

Area = maxdiff_v * maxdiff_h

print(Area)