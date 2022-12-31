# input two matrices of size n x m 

a = [[0,1,0], 
		[1,1,0], 
		[0,0,1]] 
b = [[0,1,0], 
		[1,1,0], 
		[0,0,1]] 

res = [[0 for x in range(3)] for y in range(3)] 
inva = [[0 for x in range(3)] for y in range(3)] 
c=[[0 for x in range(3)] for y in range(3)] 
def mul(matrix1,matrix2):
	for i in range(len(matrix1)): 
		for j in range(len(matrix2[0])): 
			for k in range(len(matrix2)): 
				res[i][j] += matrix1[i][k] * matrix2[k][j] 
	return res

def assign():
	a=c


def invmat(a):
	for i in range(len(a)):
		determinant = determinant + (a[0][i] * (a[1][(i+1)%3] * a[2][(i+2)%3] - a[1][(i+2)%3] * a[2][(i+1)%3]))
		print(determinant)

		for i in range(len(a)): 
			for j in range(len(b)): 
				inva[i][j]=((a[(j+1)%3][(i+1)%3] * a[(j+2)%3][(i+2)%3]) - (a[(j+1)%3][(i+2)%3] * a[(j+2)%3][(i+1)%3]))/ determinant
		


def powermat(n,a,b):
	l=1
	while(l<n):
		mul(a,b)
		assign()
		l=l+1




res  = mul(a,b)
powermat(2,a,b)
invmat(a)

print(inva)