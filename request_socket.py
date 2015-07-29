from socket import *

s = socket(AF_INET, SOCK_STREAM)
s.connect(("183.63.251.70",80))
s.sendall("GET /SingleWindow/SingleWindowMessageService.svc/json/ HTTP/1.1\r\nHost: 183.63.251.70\r\nConnection: close\r\n\r\n")
while 1:
	data = s.recv(1024)
	if not data: break
	print data,
s.close()