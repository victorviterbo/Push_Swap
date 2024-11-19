import random
import os
import math as m
from scipy.stats import linregress
import json
import subprocess
import numpy as np
import time

os.system("rm out.tmp ok.txt")
RERUN = True
red = "\033[31m"
yellow = "\033[33m"
green = "\033[32m"
reset = "\033[0m"
x = [3, 4, 5, 7] + [100, 500]# + [pow(3, i) for i in range(2, 7, 1)] 
if (RERUN):
	os.system("rm test.json")
	results = dict()
	for size in x:
		results[size] = []
		print("Running for size "+str(size))
		for j in range(5):
			tmp = list(range(size))
			random.shuffle(tmp)
			a = " ".join([str(i) for i in tmp])
			os.system('echo "'+str(a)+'" > arg.txt')
			t = time.time() #leaks --atExit --
			os.system('ARG="'+str(a)+'";./push_swap $ARG > out.tmp; cat out.tmp | ./checker_Mac $ARG > ok1.txt')
			t = time.time() - t
			os.system('ARG="'+str(a)+'"; cat out.tmp | ./checker $ARG > ok2.txt')
			with open("ok1.txt", "r") as f:
				ok1 = f.read()
				ok2 = open("ok2.txt", "r").read()
				if not ok1 or not ok2:
					print("ERROR ! checker produced no output")
				if (ok1 != "OK\n" or ok1 != ok2):
					ok1 = ok1[:-1]
					ok2 = ok2[:-1]
					print(f"{red}{ok2} with official checker, {ok1} with homemade{reset}")
					print(f"{red}Failed with input :{reset}")
					print(a)
					quit()
			with open("out.tmp", "r") as f:
				n = len(f.readlines())
				if ((n > 5500 and size == 500) or (n > 700 and size == 100) or t > 2):
					print(f"{yellow}OK ! (size {size} :{n} operations), time = {round(t, 4)}s{reset}")
				else:
					print(f"{green}OK ! (size {size} :{n} operations), time = {round(t, 4)}s{reset}")
			results[size].append(n)
	with open("test.json", "w") as json_file:
		json.dump(results, json_file, indent=4)

with open("test.json", "r") as json_file:
	results = json.load(json_file)

x = [int(i) for i in results.keys()]
xstr = results.keys()
y1 = []
for size in xstr:
	y1.append(sum(results[size]) / len(results[size]))
x1 = x
x2 = [m.log(i) for i in x]
x3 = [i * m.log(i) for i in x]
x4 = [i * i for i in x]

r_values = []
slopes = []
slope, intercept, r_value, p_value, std_err = linregress(x1, y1)
r_values.append(r_value)
slopes.append(slope)
slope, intercept, r_value, p_value, std_err = linregress(x2, y1)
r_values.append(r_value)
slopes.append(slope)
slope, intercept, r_value, p_value, std_err = linregress(x3, y1)
r_values.append(r_value)
slopes.append(slope)
slope, intercept, r_value, p_value, std_err = linregress(x4, y1)
r_values.append(r_value)
slopes.append(slope)

if r_values[0] == max(r_values):
	best_fit = 0
	best_R = 0
	for exponent in np.arange(0.5, 2, 0.1):
		exp = round(exponent, 1)
		x_n = [pow(i, exp) for i in x]
		slope, intercept, r_value, p_value, std_err = linregress(x_n, y1)
		if best_R < r_value:
			best_fit = exp
			best_R = r_value
			bestslope = slope
	print("Your program time complexity is O(n) = "+str(round(bestslope, 2))+"*n^"+str(round(exponent, 2))+" with an R^2 of "+str(round(r_values[3], 3)))
elif  r_values[1] == max(r_values):
	print("Your program time complexity is O(n) = "+str(round(slopes[1], 2))+"*log(n) with an R^2 of "+str(round(r_values[1], 3)))
elif  r_values[2] == max(r_values):
	print("Your program time complexity is O(n) = "+str(round(slopes[2], 2))+"*nlog(n) with an R^2 of "+str(round(r_values[2], 3)))
elif  r_values[3] == max(r_values):
	best_fit = 0
	best_R = 0
	for exponent in np.arange(2, 3, 0.1):
		exp = round(exponent, 1)
		x_n = [pow(i, exp) for i in x]
		slope, intercept, r_value, p_value, std_err = linregress(x_n, y1)
		if best_R < r_value:
			best_fit = exp
			best_R = r_value
			bestslope = slope
	print("Your program time complexity is O(n) = "+str(round(bestslope, 2))+"*n^"+str(round(exponent, 1))+" with an R^2 of "+str(r_values[3]))

os.system("rm ok1.txt ok2.txt arg.txt out.tmp")