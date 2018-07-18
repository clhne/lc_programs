#!/usr/bin/python3
import urllib.request
request_url = 'http://www.baidu.com'
response = urllib.request.urlopen(request_url)
print(response.read().decode('utf-8'))
