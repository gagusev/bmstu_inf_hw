import matplotlib.pyplot as plt
from time import time

import gen
import solver

size, step = 3200, 100
steps = [i for i in range(step, size+step, step)]

data = []

for s in steps:
    graph = gen.generateGraph(s)

    start = time()

    ans = solver.solve(graph, s/10)

    elapsed = time() - start
    data.append(elapsed*100)
    print('Graph size: %d, time elapsed: %f, answer is: %d;' % (s, elapsed*100, len(ans)))

plt.plot(steps, data)
plt.title('Эффективность алгоритма поиска всех вершин с заданной степенью')
plt.xlabel('Кол-во вершин в графе')
plt.ylabel('Затраченное время (секунды)')
plt.savefig('analysis1.png')