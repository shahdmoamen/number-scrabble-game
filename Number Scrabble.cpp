#include <iostream>
#include <vector>
using namespace std;
//function to check win by looping over every number that the player has chosen to
//        check if any combination of three number is equal to 15
bool checkfunction(vector<int> A) {
    int arr_size = A.size();
    for (int i = 0; i < arr_size - 2; i++) {
        for (int j = i + 1; j < arr_size - 1; j++) {
            for (int k = j + 1; k < arr_size; k++) {
                if (A[i] + A[j] + A[k] == 15) {
                    return true;
                }
            }
        }
    }
    return false;
}
//function to check if the chosen number is in the list
bool check1(int number, int numbers[9]) {
    for (int i = 0; i < 9; i++) {
        if (numbers[i] == number);
        return true;
    }
}
// function to check if it's a draw
bool draw(int numbers[9]) {
    for (int i = 0; i < 9; i++) {
        if (numbers[i] != 0) {
            return false;
        }
    }
    return true;
}

// to print the list
void print(int number_list[9]) {
    for (int i = 0; i < 9; i++) {
        cout << number_list[i] << " ";
    }
}


int main() {
    int check = 0;
    int number_list[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> player_one, player_two;
    // printing the game's rules
    cout << "Welcome To Number Scrabble" << endl;
    cout << "RULES" << endl;
    cout<< "* You are Given numbers from (1 , 9 ) you have to pick numbers so that the sum of 3 chosen numbers (at least) equal 15"<< endl;
    cout << "* You cannot pick the number twice" << endl;
    while (check == 0) {
        print(number_list);
        cout << endl << "PLAYER ONE; choose a number from above: ";
        int x;
        cin >> x;
        // check if player one choose a number from the list
        if (check1(x, number_list)) {
           // add the number that player one has chosen to his list
            player_one.push_back(x);
            number_list[x - 1] = 0;
           // check if player one wins
            if (player_one.size() >= 3) {
                if (checkfunction(player_one)) {
                    cout << "Player 1 is the winner !";
                    check = 1;
                    break;
                }
                // check if it's a draw
                else if (draw(number_list) == 1) {
                    cout << "its a draw !";
                    check = 1;
                    break;

                }

            }


        }

        // print the list after removing the numbers which each player has chosen
        print(number_list);
        cout << endl << "PLAYER 2; choose a number from above: ";
        int y;
        cin >> y;
        // check if player two choose a number from the list
        if (check1(y, number_list)) {
            // add the number that player two has chosen to his list
            player_two.push_back(y);
            number_list[y - 1] = 0;
            // check if player two wins
            if (player_two.size() >= 3) {
                if (checkfunction(player_two)) {
                    cout << "Player 2 is the winner !";
                    check = 1;
                    break;
                }
                // check if it's a draw
                else if  (draw(number_list) == 1) {
                    cout << "its a draw !";
                    check = 1;
                    break;

                }

            }


        }



    }
    return 0;
}
