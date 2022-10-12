import sys
from numpy import random
x=random.randint(1,size=(1,1))
file_path='input2.txt'
sys.stdout=open(file_path,"w")
print(x)