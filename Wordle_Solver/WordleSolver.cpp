#include <iostream> 
#include <string>
#include <algorithm> 

std::string board [5];

void resetBoard();
void initializeBoard();
void display(std::string b[]);
int userEntry(int location);
void play();

std::string getInput(std::string prompt) {
        std::cout << prompt << " ";
        std::string input;
        std::getline(std::cin, input);
        return input;

          }

           int userEntry(int location) {
        std::string initialState = board[location];
        board[location] = "=";
        display(board);
        std::string userInput = getInput("");

        if (userInput == " " || userInput.empty()) {
            board[location] = initialState;
            return location + 1;
        } else if (userInput == "0") {
            board[location] = initialState;
            return 5;
        } else if (userInput == "1") {
            board[location] = "_";
            return std::max(location - 1, 0);
        } else {
            board[location] = userInput;
            return location + 1;
        }
    }
        void initializeBoard() {
        int i = 0;
        while (i < 5) {
            i = userEntry(i);
        }
        display(board);
        std::cout << std::endl;
      }
             void play() {
    std::string prompt = "Your current cell is marked with a '='.\n * Enter a letter if you know it belongs in that cell.\n * Enter a space if you want to skip to the next cell.\n * Enter '1' to move one cell back and make changes.\n * Enter '0' to exit the board editing process.";
    std::cout << prompt << std::endl;
    resetBoard();
    initializeBoard();
             } 
             void display(std::string b[]) { 
              int i = 0; 
              while (i < 5) {
                std::cout << b[i] << "";
                i++;
              }
              std::cout << std::endl;
              }
            void resetBoard() {
            }
       int main () {
        play(); 
        return 0; 
}