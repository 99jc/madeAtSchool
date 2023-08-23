import requests
from bs4 import BeautifulSoup

def weather_crawling():
    url = "https://search.naver.com/search.naver?query=날씨"
    
    crawling_output = []
    
    source = requests.get(url)
    soup = BeautifulSoup(source.content,"html.parser")
    table = soup.find("div", {"class":"weather_info"})
    
    # temperature data
    temp_data = table.find("div", {"class":"temperature_text"})
    
    for i in range(2):
        temp_data.find('span').decompose() # delete unnecessary data
    temp = temp_data.text.replace(" ", "") # delete blank
    crawling_output.append(str(temp + "*C"))

    
    # humidity data
    summary = table.find_all("dd")
    
    humidity = summary[1].text.replace(" ", "")
    crawling_output.append(str(humidity))
    
    # weather inform
    weather_data = table.find("span", {"class":"weather before_slash"}).text
    weather = weather_data.replace(" ", "") # delete blank
    crawling_output.append(str(weather))
    
    # dust inform
    dust = table.find("span", {"class":"txt"}).text.replace(" ", "")
    crawling_output.append(str(dust))
    crawling_result = "_".join(crawling_output)
    
    return (crawling_result + "_")

def test_sunny() :
    return "6.3*C_48%_맑음_좋음_"

def test_cloudy() :
    return "2.7*C_52%_흐림_좋음_"

def test_rainy() :
    return "14*C_96%_비_좋음_"

def test_snowy() :
    return "-12*C_87%_눈_좋음_"

def test_dust() :
    return "14*C_48%_흐림_매우나쁨_"