import sys
from numpy import random
x=random.randint(6,size=(1,6))
file_path='input5.txt'
sys.stdout=open(file_path,"w")
print(x)