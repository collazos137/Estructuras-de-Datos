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
		listA = [int(i) for i in stdin.readline()[0:-1].split()]
		listB = [int(i) for i in stdin.readline()[0:-1].split()]
		ans = [str(i) for i in diferenciaListas(listA[1:],listB[1:])]
		print(", ".join(ans))

#######################################################################################################################################################
#4
"""
def esPrimo(n, listprim):
  if n < 2: ans = False
  else:
    i, ans = 2, True
    while i * i <= n and ans:
      if n % i == 0: ans = False
      i += 1
  return ans
"""

def esPrimo(num, listprim):
	ans = True
	if num != 2: 
		i = 0
		while listprim[i] * listprim[i] <= num and ans:
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
	listprim, sumDigitosPri = [], []
	char = ""
	i = 2
	print("Numeros primos entre 1 y %d:" %(num))

	while i <= num:
		if esPrimo(i, listprim):
			listprim.append(i)
			print("%s--> %d" %(char, i), end = "")
			if esPrimo(sumarDigitos(i), listprim):
				sumDigitosPri.append(str(i))
			if char == "":
				char = ",\n"
		i += 1

	print("\n")
	print("Numeros entre 1 y %d con suma de digitos con valor primo:" %(num))
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