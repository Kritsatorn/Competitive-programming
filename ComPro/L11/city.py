#std61: Kun Toto Na MikeLab.Net
#date: 16NOV2018
#program: cityTemperature.py
#description: demostrate how to use Python in some simple data analytical tasks, in 01204111 year 2018

class Country():
  def __init__(self, cname):
    self.name = cname
    self.nbOfCities = 0
    self.eu = 'no'
    self.cityList = {}
  def addCity(self, cityObj):
    if cityObj.name in self.cityList.keys():
      print(f"ERROR: city named [{cityObj.name}] has already been in country [{cname}]!") 
      return None
    self.nbOfCities += 1
    self.eu = cityObj.eu
    self.cityList[cityObj.name] = cityObj
    return True
#   def delCity(self, cityName):
#     if cityName not in self.cityList.keys():
#       print(f"ERROR: city named [{cityName}] not found in country [{self.name}]!")
#       return None
#     del self.cityList[cityName]
#     self.nbOfCities -= 1
#     return True
  def print(self):
    s = "Country Name: " + self.name 
    if self.eu == "yes":
      s += " (EU)\n"
    else:
      s += " (Non EU)\n"
    s += "Number of cities: " + str(self.nbOfCities) + '\n'
    s += "Cities in this country: " + '\n'
    for c in self.cityList.keys():
      s += "[" + c + "] "
    s += '\n'
    return s
  def __repr__(self):
    return self.print()
    
class City():
  def __init__(self, name, country, eu, height, coastLine, latX, longY, temp):
    self.name = name
    self.country = country
    self.eu = eu
    self.height = float(height)
    self.coastLine = coastLine
    self.latX = float(latX)
    self.longY = float(longY)
    self.temp = float(temp)
#   def print(self):
#     dic = {}
#     dic['name'] = self.name
#     dic['country'] = self.country
#     dic['eu'] = self.eu
#     dic['height'] = self.height
#     dic['coastline'] = self.coastLine    
#     dic['latitude'] = self.latX
#     dic['longtitude'] = self.longY
#     dic['temperature'] = self.temp
#     return dic
#   def __repr__(self):
#     return str(self.print())
#
# main begins here
def readCity(fname):
  country = {} # keep the country object already created
  nb_city = 0
  f = open(fname)
  for line in f:
    #print(line)
    k = line.strip().split(',')
    #print(k)
    if k[1] not in country.keys():
      co = Country(k[1])
      country[k[1]] = co
    # now insert new city in a country
    city = City(k[0],k[1],k[2],k[3],k[4],k[5],k[6],k[7])
    country[k[1]].addCity(city)
  return country
 
#>>>>> main begins from here
res = readCity("city_temp.txt")
print(res)
'''
#(1) How many cities in Italy?
len(res['Italy'].cityList)
res['Italy']
#(2) Which country has the most number of cities?
maxCity = 0
cc = ''
for i in res.keys():
  print(f"{i}: Nunber of cities = {res[i].nbOfCities}")
  if res[i].nbOfCities > maxCity:
    maxCity = res[i].nbOfCities
    cc = res[i].name
print(cc)
#(3) Which city in which country locate below the 1000 metres height of the sea level?
for i in res.keys():
  for j in res[i].cityList:
    if res[i].cityList[j].height < 1000:l
      print(f"{res[i].cityList[j].country}, {res[i].cityList[j].name}: {res[i].cityList[j].height}")
#(4) What is the average latitude of all EU cities?
#(4.1) overall
#(4.2) for cities with temperature < 10?
#(4.3) for cities where both the city name and the country name end in the letter 'a'?
'''
# your code here
"""
(5) Which are warmer on average -- cities in the EU and cities not in the EU?
(6) What is the westernmost country with no coastline? You should define the longtitude of a country as the average longitude of cities in that country, and remember that smaller logitudes are further west.
(7) What is the easternmost country with no coastline?
"""
# your code here