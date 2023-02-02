# Juan Diego Collazos Mejia # ID: 8977837 # january 25st 2023
####################################################################################################################################################################################
from sys import stdin
#########################################################################################################################################################################################
#1
def verificarDiagonales(mat):
	ans = True
	i = 0
	while (i < len(mat)) and ans:
		k = (i + 1) * -1
		if mat[i][i] != mat[i][k]:
			ans = False
		i += 1
	return ans

####################################################################################################################################################################################
#2
def esCapicua(l):
	ans = True
	i = 0
	lim = len(l) // 2 
	while (i < lim) and ans:
		k = (i + 1) * -1
		if l[i] != l[k]:
			ans = False
		i += 1
	return ans

######################################################################################################################################################################################
#3
#(a)
def diferenciaListas(listA, listB):
	ans = []
	for i in listA:
		if i in listB:
			listB.remove(i)
		else:
			ans.append(i)
	return ans

#(b)
def leerImprimirDiferenciaListas():
	numberCases = int(stdin.readline())
	for i in range(numberCases):
		listA = stdin.readline()[0:-1].split()
		listB = stdin.readline()[0:-1].split()
		ans = diferenciaListas(listA[1:],listB[1:])
		print(", ".join(ans))

#######################################################################################################################################################
#4
def esPrimo(num, listprim):
	ans = True
	i = 0
	while i < len(listprim) and ans:
		if num % listprim[i] == 0:
			ans = False
		i += 1
	return ans

def sumarDigitos(num):
	ans = 0
	ax1 = 0
	while num != 0:
		ax1 = num % 10
		ans += ax1
		num //= 10

	return ans

def mostrarPrimos(num):
	sumDigitosPri = []
	listprim = []
	char = ""
	print("Números primos entre 1 y %d:" %(num))
	for i in range(2, num):
		if esPrimo(i, listprim):
			listprim.append(i)
			print("%s--> %d" %(char, i), end = "")
			if char == "":
				char = ",\n"
			if sumarDigitos(i) in listprim:
				sumDigitosPri.append(str(i))
	print("\n")
	print("Números entre 1 y %d con suma de dígitos con valor primo:" %(num))
	print(", ".join(sumDigitosPri))

#######################################################################################################################
#5
def sumarValoresMatriz(mat, par):
	ans = 0
	for i in range(len(par)):
		y = par[i][0]
		if y in dis:
			x = par[i][1]
			j = 0
			flag = True
			while j < len(dis[y]) and flag:
				if dis[y][j][0] == x:
					ans += dis[y][j][1]
					flag = False
				elif dis[y][j][0] > x:
					flag = False
				j += 1
	return ans

#############################################################################################################################################