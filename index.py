import serial
import json

port = 'COM4'
baudrate = 9600

def sort_f(d):
	return d["data"]

ser = serial.Serial(port, baudrate)
for i in range(5):
	ser.readline()

max_r = 1
max_g = 1
max_b = 1
max_a = 1

min_r = 1000
min_g = 1000
min_b = 1000
min_a = 1000

while True:
	crude_data = ser.readline()
	str_data = str(crude_data)[2:-5]
	json_data = json.loads(str_data)

	r = json_data['r']
	g = json_data['g']
	b = json_data['b']
	a = json_data['a']

	# Max RGBA
	if r >= max_r:
		max_r = r

	if g >= max_g:
		max_g = g

	if b >= max_b:
		max_b = b

	if a >= max_a:
		max_a = a

	# Min RGBA
	if r <= min_r:
		min_r = r

	if g <= min_g:
		min_g = g

	if b <= min_b:
		min_b = b

	if a <= min_a:
		min_a = a

	# Percentage RGBA
	# ra = r*100/max_r
	# ga = g*100/max_g
	# ba = b*100/max_b

	print("---")
	c = 0

	if (r <= 123+c and r >= 33-c) and (g <= 123+c and g >= 34-c) and (b <= 47+c and b >= 14-c) and (a <= 123+c and a >= 45-c):
		print("verde")

	if (r <= 129+c and r >= 55-c) and (g <= 118+c and g >= 43-c) and (b <= 36+c and b >= 7-c) and (a <= 71+c and a >= 19-c):
		print("azul")

	if (r <= 88+c and r >= 23-c) and (g <= 162+c and g >= 89-c) and (b <= 46+c and b >= 12-c) and (a <= 128+c and a >= 67-c):
		print("vermelho")

	if (r <= 32+c and r >= 14-c) and (g <= 54+c and g >= 22-c) and (b <= 20+c and b >= 7-c) and (a <= 57+c and a >= 34-c):
		print("amarelo")

	if (r <= 130+c and r >= 116-c) and (g <= 171+c and g >= 141-c) and (b <= 51+c and b >= 35-c) and (a <= 133+c and a >= 100-c):
		print("preto")

	if (r <= 36+c and r >= 14-c) and (g <= 48+c and g >= 12-c) and (b <= 17+c and b >= 0-c) and (a <= 39+c and a >= 12-c):
		print("branco")

	''''
	# if ( ra <= 20 and ga <= 20 and ba <= 20 and a <= 20 ):
		# print("branco")

	# if ( a >= 100 ):
		# print("preto")


	if ( ra <= 20 and ga <= 10 and ba <= 10 and a >= 35 and a <= 55 ):
		print("amarelo")

	if ( ra <= 25 and ga <= 25 and ba <= 20 and a >= 60 and a <= 80 ):
		print("vermelho")

	if ( ra >= 28 and ra <= 70 and ga <= 18 and ba <= 20 and a >= 45 and a <= 70 ):
		print("verde")

	if ( ra >= 20 and ra <= 40 and ga <= 15 and ba <= 15 and a >= 15 and a <= 25 ):
		print("azul")
	'''

	# perc.sort( key=sort_f )
	# print(ra, ga, ba, a)
