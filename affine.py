a=5
b=17

def encryptmessage(msg):
	cipher = ""
	for i in range(0,len(msg)):
		if(msg[i]!=' '):
			cipher = cipher + chr((a* (ord(msg[i])-ord('A')) + b)%26 + ord('A'))
		else:
			cipher+= msg[i]
	return cipher

def decryptcipher(cipher):
	msg=""
	a_inv=0
	flag=0

	for i in range(0,26):
		flag = (a*i)%26

		if(flag==1):
			a_inv=i

	for i in range(0,len(cipher)):
		if(cipher[i]!= ' '):
			msg = msg +chr(((a_inv * ((ord(cipher[i])+ord('A') - b)) % 26)) + ord('A'))
		else:
			msg+= cipher[i]

	return msg
m ="PROFESSOR"
emsg = encryptmessage(m)
dmsg = decryptcipher(emsg)

print(emsg + " " + dmsg)