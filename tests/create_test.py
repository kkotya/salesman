import itertools
import random
import subprocess as sp
import os

max_rand = 100000
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 15, 20, 50, 100, 250, 500, 1000]

for count in numbers:
    filename = "test{}".format(count)
    test = open(filename, "w")
    test.write("{} {}\n".format(count, (count * (count - 1)//2)))

    for f, t in itertools.combinations(range(1, count + 1), 2):
        number = random.randint(0, 100000)
        test.write("{} {} {}\n".format(f, t, number))
        
    if count < 13:
        a = sp.Popen("time ../full_search/full_search < {}".format(filename), shell=True)
        a.communicate()
        a.kill()
    a = sp.Popen("time ../nearest_neighbourg/nearest_neighbor < {}".format(filename), shell=True)
    a.communicate()
    a.kill()
    
  	
