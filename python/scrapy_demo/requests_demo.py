#-*-coding:utf-8-*-
import requests, sys
from bs4 import BeautifulSoup
'''
param = {"wd":"Python scraping"}
r = requests.get('http://www.baidu.com/s', params = param)
print(r.url)

下载《笔趣看》网小说《一念永恒》
parameters: no
returns: no
Modify: 2018-07-24
'''
class downloader(object):
    
    def __init__(self):
        self.server = 'http://www.biqukan.com/'
        self.target = 'http://www.biqukan.com/1_1094/'
        self.names = []
        self.urls = []
        self.nums = 0
    
    ##获取下载链接
    def get_download_url(self):
        req = requests.get(url = self.target)
        html = req.text
        div_bf = BeautifulSoup(html, "lxml")
        div = div_bf.find_all('div',class_='listmain')
        a_bf = BeautifulSoup(str(div[0]), "lxml")
        a = a_bf.find_all('a')
        self.nums = len(a[15:])
        for each in a[15:]:
            self.names.append(each.string)
            self.urls.append(self.server + each.get('href'))
    
    '''
    获取章节内容
    parameters: target 下载连接
    returns：texts 章节内容
    '''
    def get_contents(self, target):
        req = requests.get(url = target)
        html = req.text
        bf = BeautifulSoup(html,"lxml")
        texts = bf.find_all('div',class_='showtxt')
        texts = texts[0].text.replace('\xa0'*8,'\n\n')
        return texts

    ##writer to file
    def writer(self, name, path, text):
        write_flag = True
        with open(path, 'a', encoding='utf-8') as f:
            f.write(name + '\n')
            f.writelines(text)
            f.write('\n\n')
    
if __name__=='__main__':
    dl = downloader()
    dl.get_download_url()
    print('Begin download...')
    for i in range(dl.nums):
        dl.writer(dl.names[i],'一念永恒.txt',dl.get_contents(dl.urls[i]))
        sys.stdout.write(" 已下载：%.3f%%" % float(i/dl.nums) + '\r')
        sys.stdout.flush()
    print('Done')
