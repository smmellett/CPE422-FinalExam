# reads in the text file whose name is specified on the command line,
# and reports the number of temps below a certain temperture
# prints average of all data
import sys

f = open(sys.argv[1])
#inittemp = sys.argv[2]
inittemp = 20
sumtemp = 0
numtemp = 0
belowtemp = 0
count = 0
temp = 0

flines = f.readlines()
numtemp = len(flines) # len() returns number of elements in a list

for count in range(numtemp):
    temp = int(flines[count])
    sumtemp += temp
    if temp<inittemp:
       belowtemp += 1
    count += 1
avgtemp = sumtemp/numtemp


print "CPE 422 Final Exam"
print "File name of sensor temperatures: "
print filename
print "Number of temperatures below 20 degrees C: "
print belowtemp
print "Average temperature: "
print avgtemp

