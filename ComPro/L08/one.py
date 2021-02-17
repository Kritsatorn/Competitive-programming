class Dog :
    species = 'mammal'
    nbDogs = 0
    dogs = [] 
    breed = "Dog"
    def __init__ (self, name , age ,color = "black" , nickname = " FuckYou") :
        self.name = name 
        self.age = age
        self._color = color
        self.__nickname = nickname
        Dog.nbDogs += 1
        Dog.dogs.append(self)
    def print_all_Dog() :
        for i in Dog.dogs :
            print("Dog name = {}".format(i.name))
    def get_the_oldest_dog() :
        MaxAge = 0 
        DogName = []
        for i in Dog.dogs :
            if i.age > MaxAge :
                MaxAge = i.age
                DogName = i.name
        return "{} is oldest {} years old ".format(DogName , MaxAge )
        
    def speaks(self, sound):
        return "{} says {}.".format(self.name, sound)
    def get_nickname(self) :
        return self.__nickname
    def set_nickname(self, nn ):
        self.__nickname = nn 

    def changeDogName(self , name ):
        self.name = name 

    
    def des(self) :
        print(f"   {self.name }  is {self.age} years old ")
class BullDog :
    breed = "Bull-Dog"
    


a = Dog("Fuck",10)
B = Dog("You",101)
print("{} == {} ".format(a.name , a.age))
a.changeDogName("FuckYou")

a.des()
print(Dog.get_the_oldest_dog())

Dog.print_all_Dog()

c = BullDog("Hi",102)
print(c.name)
