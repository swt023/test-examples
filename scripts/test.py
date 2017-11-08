import os
import platform

print platform.system();

x = 50

def func(y):
    print('x = ', y)
    global x
    x = 2
    print('local x is ', x)

func(x)
print('global x is ', x)

print 'begining...'
os.system('echo "sleep 5 seconds"; sleep 5')
print 'continue...'

s = "Buffalo;Rochester;Yonkers;Syracuse;Albany;Schenectady"

# Separate on semicolon.
# ... Split from the right, only split three.
cities = s.rsplit(";", 3)

# Loop and print.
for city in cities:
	    print(city)

print cities[-1]
