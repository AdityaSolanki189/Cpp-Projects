#Create a hash table and handle the collisions using linear probing with or without replacement.

from collections import defaultdict

count = 0

class HashLinearProbing:
    def __init__(self, size):
        self.hash_table = defaultdict().fromkeys(range(size), -1)
        print(self.hash_table)
    
    def hashing(self, key):
        return(key % size)

    def insertIntoHashIndexWithoutReplacement(self, key, index):
        global count

        load_factor = ((count / size) * 100)

        if load_factor < 80:
            if self.hash_table[index] == -1:
                self.hash_table[index] = key
                count = count + 1
            else:
                self.findVacantIndex(key, index)
        else:
            print("Hash Table is FULL. Key Not Inserted")

    def insertIntoHashIndexWithReplacement(self, key, index):
        if self.hash_table[index] == -1:
            self.hash_table[index] = key
        elif index == self.hashing(self.hash_table[index]):
            self.findVacantIndex(key, index)
        else:
            temp = self.hash_table[index]
            self.hash_table[index] = key
            self.findVacantIndex(temp, index)
        
    def findVacantIndex(self, key, index):
        for i in range(1, size):
            pos = (index + i) % size
            if self.hash_table[pos] == -1:
                self.hash_table[pos] = key
                break

    def display(self):
        print("Hash Table Keys")
        print(self.hash_table)

        for itr in self.hash_table.items():
            print(itr)

# ------------------------------------------------------ #

print("## Handling Collisons using Linear Probing ##\n")
size = int(input("Enter Table Size : "))
hash_object = HashLinearProbing(size)

while 1:
    print("Enter \n1 for Insert Without Replacement\n2 for Insert With Replacement\n3 to Display the Hash table\n4 to Exit : ")
    user_choice = int(input("Enter the option : "))

    if user_choice == 1:    
        for i in range(size):
            key_value = int(input("Enter key value : "))
            index = hash_object.hashing(key_value)
            hash_object.insertIntoHashIndexWithoutReplacement(key_value, index)
        print("\nThe Hash Table After Linear Probing WITHOUT Replacement : \n")
        hash_object.display()

    elif user_choice == 2:
        for i in range(size):
            key_value = int(input("Enter key value : "))
            index = hash_object.hashing(key_value)
            hash_object.insertIntoHashIndexWithReplacement(key_value, index)
        print("\nThe Hash Table After Linear Probing WITH Replacement : \n")
        hash_object.display()

    elif user_choice == 3:
        print("\nThe Hash Table : \n")
        hash_object.display()

    elif user_choice == 4:
        break

    else:
        print("Please Enter a Valid Option.")
