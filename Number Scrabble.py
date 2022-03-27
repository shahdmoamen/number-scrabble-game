# FUNCTION THAT LOOP OVER EVERY NUMBER THAT EACH PLAYER CHOOSE TO GET ANY
#         COMBINATION OF NUMBER WHICH ITS SUMMATION IS 15
def checkfunction(A,list_size,sum):
    for i in range(0, list_size - 2):
        for j in range(i + 1, list_size - 1):
            for k in range(j + 1, list_size):
                if A[i] + A[j] + A[k] == sum:
                    return True
    return False


check=0
original_list=[1, 2, 3, 4, 5, 6, 7, 8, 9]
player_one= []
player_two= []
print("Welcome To Number Scrabble")

# INDCATES THE GAME'S RULES
print('RULES')
print("* You are Given numbers from (1 , 9 ) you have to pick numbers so that the sum of 3 chosen numbers (at least) equal 15")
print("* you cannot pick the number twice")
while check == 0:
    while True:
        print(original_list)
        x = int(input("PLAYER ONE; choose a number from above: "))
        if x in original_list:
            original_list.remove(x)
            player_one.append(x)
            print("PLAYER ONE; chosen numbers:", player_one)
            # CHECKS IF PLAYER ONE WON
            if checkfunction(player_one, len(player_one), 15) and len(player_one) >= 3:
                print("PLAYER one WINS!")
                check = 1
            break
        # IF ANY PLAYER ONR ENTERED INVALID NUMBER
        else:
            print("Error, Number not available! , please enter another number")
    # CHECKS IF ITS A DRAW
    if original_list == []:
        print("Draw!")
        break
    if check == 0:
        # ALLOW PLAYER TWO TO ENTER NUMBER FROM THE LIST AND PLAY HIS TURN
        while True:
            print(original_list)
            y = int(input("PLAYER TWO; choose a number from above: "))
            if y in original_list:
                original_list.remove(y)
                player_two.append(y)
                print("PLAYER TWO NUMBERS :", player_two)
                # CHECKS IF PLAYER TWO WON
                if checkfunction(player_two, len(player_two), 15) and len(player_two) >= 3:
                    print("PLAYER TWO WINS!")
                    check = 1
                break
            # IF ANY PLAYER TWO ENTERED INVALID NUMBER
            else:
                print("Error, Number not available! , please enter another number")
    # CHECKS IF ITS A DRAW
    if original_list == []:
        print("Draw!")
        break
