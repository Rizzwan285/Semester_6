import random

n = 10**7
eps = 0.01
p = 0.7
votes = [1]*int(p*n) + [0]*int((1-p)*n)

votes = random.shuffle(votes)
print(votes)