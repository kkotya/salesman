import csv
import matplotlib.pyplot as plt

mesuares_full_search = []
mesuares_nearest_neig = []
with open('full search.csv') as csvfile:
    reader = csv.reader(csvfile, delimiter=';')
    for row in reader:
       print(row)
       mesuares_full_search.append(row[1])

with open('nearest neighbour.csv') as csvfile:
    reader = csv.reader(csvfile, delimiter=';')
    for row in reader:
       mesuares_nearest_neig.append(row[1])

plt.plot(range(len(mesuares_full_search)), mesuares_full_search, color='red')
plt.plot(range(len(mesuares_full_search)), mesuares_nearest_neig, color='blue')
plt.legend(['full search', 'nearest neighbour'])
plt.show()
    