import sys
import heapq
r=sys.stdin.readline
X,Y,A,B,C=map(int,r().split())
Red=list(map(int,r().split()))
Green=list(map(int,r().split()))
White=list(map(int,r().split()))
Red.sort(reverse=True)
Green.sort(reverse=True)
White=[-x for x in White]
RedtoEat=Red[:X]
GreentoEat=Green[:Y]
heapq.heapify(RedtoEat)
heapq.heapify(GreentoEat)
heapq.heapify(White)
res=0
while True:
    if not White:
        break
    wtop=int(White[0]*(-1))
    rtop=int(RedtoEat[0])
    gtop=int(GreentoEat[0])
    if wtop<=rtop and wtop<=gtop:
        break
    else:
        if wtop>rtop and wtop>gtop:#둘다 후보임
            if rtop>gtop:
                heapq.heappop(GreentoEat)
                tmp=heapq.heappop(White)
                heapq.heappush(GreentoEat,-tmp)
            else:
                heapq.heappop(RedtoEat)
                tmp=heapq.heappop(White)
                heapq.heappush(RedtoEat,-tmp)
        elif wtop>rtop:
            heapq.heappop(RedtoEat)
            tmp=heapq.heappop(White)
            heapq.heappush(RedtoEat,-tmp)
        elif wtop>gtop:
            heapq.heappop(GreentoEat)
            tmp=heapq.heappop(White)
            heapq.heappush(GreentoEat,-tmp)
print(sum(RedtoEat)+sum(GreentoEat))