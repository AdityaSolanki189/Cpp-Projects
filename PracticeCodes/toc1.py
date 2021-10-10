import re
para="My name is Aditya Solanki and I am pursuing BTech. in Computer Science And Engineering form MIT ADT University, Pune."
print("\nThe Paragraph is given below :\n")
print(para)

while(True):
    print("\n1. To search for word\n2. Exit\n")
    choice = int(input("Enter Your Choice : "))
    if choice==1:
        ch=input("\nEnter word to be searched\n")
        print('Searching the word "%s"...' %(ch))
        if re.search(ch,para):
           print("[Match Found]")
        else:
            print("[No Match Found]") 
    else:
        exit(0)
