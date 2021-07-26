""" Consider telephone book database of N clients. Make use of a hash table implementation to 
quickly look up client‘s telephone number  """

from collections import defaultdict

count = 0

class HashLinearProbing:
    def __init__(self, size):
        self.hash_table = defaultdict(list)

        for itr in range(size):
            self.hash_table[itr] = []

        print(self.hash_table)
    
    def hashing(self, name):
        ascii_sum = 0

        for itr in range(0, len(name)):
            ascii_sum = ascii_sum + ord(name[itr])  # Adding the ASCII values of all the letters in the string
        
        return(ascii_sum % size)    # Returning the modulo value of ASCII Sum and the size of the table

    def insertIntoHashIndexWithoutReplacement(self, name, index, phone_no):
        global count

        load_factor = ((count / size) * 100)

        if load_factor < 80:
            if len(self.hash_table[index]) == 0:
                self.hash_table[index].append(name)
                self.hash_table[index].append(phone_no)
                count+=1
            else:
                self.findVacantIndex(name, index)
        else:
            print("Hash Table is FULL.")

    def searchbyIndex(self, name, index):
        for i in range(size):
            pos = (index + i) % size
            if self.hash_table[pos,0] == name:
                print(dict(self.hash_table(pos)[0]))
                return
            else:
                continue
        
        
    def findVacantIndex(self, key, index):
        for i in range(1, size):
            pos = (index + i) % size
            if self.hash_table[pos] == -1:
                self.hash_table[pos] = key
                break

    def display(self):
        print("\nHash Table :\n")
        print(self.hash_table)

        for itr in self.hash_table.items():
            print(itr)

# ------------------------------------------------------ #

print("Telephone Directory : \n")
size = int(input("Enter Telephone Book Size : "))
hash_object = HashLinearProbing(size)

while 1:
    print("\n1. Insert Information\n2. Find a Phone Number\n3. Display the Table\n4. Exit")
    user_choice = int(input("Enter the option: "))

    if user_choice == 1:    
        for i in range(size):
            name = str.strip(input("Enter the Name : "))
            name = name.upper()
            phone_no = int(input("Enter Phone Number : "))
            index = hash_object.hashing(name)
            print(index)
            hash_object.insertIntoHashIndexWithoutReplacement(name, index, phone_no)    
        hash_object.display()
    
    elif user_choice == 2:
        name = str.strip(input("Enter the Name : "))
        name = name.upper()
        index = hash_object.hashing(name)
        print(index)
        print("The Phone Number is ")
        hash_object.searchbyIndex(name, index) 

    elif user_choice == 3:
        hash_object.display()

    elif user_choice == 4:
        break

    else:
        print("\nPlease enter a valid input.")

print("[Program Terminated]")




