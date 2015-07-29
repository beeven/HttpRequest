import httplib

conn = httplib.HTTPConnection("183.63.251.70",80)
conn.request("GET","/SingleWindow/SingleWindowMessageService.svc/json/")
res = conn.getresponse()
d = res.read()
print d
conn.close()