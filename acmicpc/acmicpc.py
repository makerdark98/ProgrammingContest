import urllib.request
import re
import codecs
import os
from bs4 import BeautifulSoup

def convertHtmlToStr(string:str):
    string = re.sub("<br />","\n",str(string))
    string = re.sub("<br>","\n",str(string))
    string = re.sub("<[^>]*>","",str(string))
    string = re.sub("&lt;","<",str(string))
    string = re.sub("&gt;",">",str(string))
    string = re.sub("&quot;","\"",str(string))
    string = re.sub("&#39;","\'",str(string))
    return string

def saveProblem(Number:int, titleName:str, description:str,prefix:str=""):
    file=codecs.open(prefix+str(Number)+".txt","w","utf-8")
    file.write(titleName+"\n\n")
    file.write(description)
    file.close()

def save(problemNumber:int):
    urlname = "https://www.acmicpc.net/problem/"
    prefix = str(problemNumber)+"/"
    os.makedirs(str(problemNumber),exist_ok=True)
    req = urllib.request.Request(urlname+str(problemNumber),headers={'User-Agent':'Mozilla/5.0'})
    data = urllib.request.urlopen(req).read()

    bs = BeautifulSoup(data, 'html.parser')

    titleRawData = bs.find(id="problem_title")
    titleName = convertHtmlToStr(titleRawData)

    description = "="*30+"\n문제\n"
    descriptionRawData = bs.find(id="problem_description")
    description += convertHtmlToStr(descriptionRawData)
    description += "="*30+"\n입력\n"
    descriptionRawData = bs.find(id="problem_input")
    description += convertHtmlToStr(descriptionRawData)
    description += "="*30+"\n출력\n"
    descriptionRawData = bs.find(id="problem_output")
    description += convertHtmlToStr(descriptionRawData)

    saveProblem(problemNumber,titleName,description,prefix)

    sampleinput=[]
    sampleoutput=[]

    for i in range(1,10):
        inputRawData = bs.find(id=("sample-input-"+str(i)))
        if inputRawData == None:
            break
        inputData = convertHtmlToStr(inputRawData)

        outputRawData = bs.find(id=("sample-output-"+str(i)))
        if outputRawData == None:
            break
        outputData = convertHtmlToStr(outputRawData)

        sampleinput.append(inputData)
        sampleoutput.append(outputData)


    for i, inputData, outputData in zip(range(1,len(sampleinput)+1), sampleinput, sampleoutput):
        os.makedirs(prefix+"sample",exist_ok=True)
        inputFile = codecs.open(prefix+"sample/input"+str(i)+".txt","w","utf-8")
        inputFile.write(inputData)
        inputFile.close()
        outputFile = codecs.open(prefix+"sample/output"+str(i)+".txt","w", "utf-8")
        outputFile.write(outputData)
        outputFile.close()


def main():
    f = open("list.txt")
    numbers = f.readlines()
    for number in numbers:
        print(number)
        save(int(number))


if __name__=="__main__":
    main()
    #saveProblem(1,"Test","description\n","1\n2\n","1\n")
