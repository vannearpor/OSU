#Author: Vannear Por
#Date: July 30, 2018
#Description: This program is a Python program that will create 3 new files
# that will contain 10 random characters. The file contents will then be displayed
# along with 2 random integers between 1 and 42 on the next lines. The last line
# will contain the product of those 2 random integers.

import string
import random

#Creates and opens 3 new files to write into
tempWrite1 = open ("fileOne", 'w')
tempWrite2 = open ("fileTwo", 'w')
tempWrite3 = open ("fileThree", 'w')

#Places the tempFiles in an array for easy looping
writeFiles = [
              tempWrite1,
              tempWrite2,
              tempWrite3
              ]

#Populates 3 new files with 10 characters
for tempWrite in writeFiles:
    populateData = random.choice(string.ascii_lowercase)
    for i in range(9):
        populateData += (random.choice(string.ascii_lowercase))

    #Append newline at the end for display purposes
    populateData += "\n"
        
    #Writes populateData into the temp files and close
    tempWrite.write(populateData)
    tempWrite.close()

#Gets 2 random integers betwee 1 and 42 and their product and saves into variables
randomOne = random.randint(1,42)
randomTwo = random.randint(1,42)
randomProduct = randomOne * randomTwo

#Opens and reads the tempFiles
tempRead1 = open ("fileOne", 'r')
tempRead2 = open ("fileTwo", 'r')
tempRead3 = open ("fileThree", 'r')

displayFile1 = tempRead1.read(10)
displayFile2 = tempRead2.read(10)
displayFile3 = tempRead3.read(10)

#Displays contents of all 3 files, 2 random integers, and the product of the 2 integers.
print displayFile1
print displayFile2
print displayFile3 
print randomOne
print randomTwo
print randomProduct
