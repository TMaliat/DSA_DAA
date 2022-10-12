import sys
from numpy import random
x=random.randint(8,size=(1,8))
file_path='input3.txt'
sys.stdout=open(file_path,"w")
print(x)