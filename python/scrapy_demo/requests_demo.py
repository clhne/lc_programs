import requests
param = {"wd":"Python scraping"}
r = requests.get('http://www.baidu.com/s', params = param)
print(r.url)