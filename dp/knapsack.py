import sys
from numpy import random
x=random.randint(6,size=(2,6))
file_path='input1.txt'
sys.stdout=open(file_path,"w")
print(x)