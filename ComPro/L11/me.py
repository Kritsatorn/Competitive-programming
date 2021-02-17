
class Country() :
    def __init__(self,cname):
        self.name = cname 
        self.Ncity = 0 
        self.eu = 'no'
        self.dict = {}
        self.Ntemp = 0.0
    def add(self , cityOb) :
        if cityOb.name in self.dict.keys() :
            return None
        self.Ncity += 1
        self.Ntemp += cityOb.temp  
        self.eu = cityOb.eu
        self.dict[cityOb.name] = cityOb 
        return True 
    



class mycity():
    def __init__(self, name, country, eu, height, coastLine, latX, longY, temp):
        self.name = name
        self.country = country
        self.eu = eu
        self.height = float(height)
        self.coastLine = coastLine
        self.latX = float(latX)
        self.longY = float(longY)
        self.temp = float(temp)
    
    
def readCity(fname) :
    country_dict = {}
    
    f = open(fname)
    for line in f :
        k = line.strip().split(',')
        if k[1] not in country_dict.keys()  :
            temp = Country(k[1])
            country_dict[k[1]] = temp 

        city = mycity(k[0],k[1],k[2],k[3],k[4],k[5],k[6],k[7])
        country_dict[k[1]].add(city)
    return country_dict
    
res = readCity("city_temp.txt")
#print(res)

# print(len( res['Italy'].dict ))
# print(res['Italy'].dict.keys())
summ = 0
N = 0
for i in res.keys() :
    if res[i].eu == 'yes' :
        for j in res[i].dict.keys() :
            summ += res[i].dict[j].latX 
            N += 1 
        
print(summ/N)


# summ_eu = 0
# summ_not_eu = 0
# N_eu = 0
# N_not_eu = 0
# for i in res.keys() :
#     if res[i].eu == 'yes' :
#         summ_eu += res[i].Ntemp
#         N_eu += res[i].Ncity
#     else :
#         summ_not_eu += res[i].Ntemp
#         N_not_eu += res[i].Ncity
# print(summ_eu/N_eu , '  ', summ_not_eu/N_not_eu)