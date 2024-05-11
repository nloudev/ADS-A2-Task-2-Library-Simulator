#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <windows.h>
#include <iomanip>

int findBookInBorrowed(std::vector<int> borrowed_books, int bookID)
{
    for (int i = 0; i < borrowed_books.size(); ++i)
    {
        if (borrowed_books[i] == bookID)
        {
            return i;
        }
    }
}

int main(void)
{
    // book library
    std::map<int, std::string> idToBooks;
    idToBooks.insert(std::pair<int, std::string>(22, "Moby Dick"));
    idToBooks.insert(std::pair<int, std::string>(3, "Harry Potter"));
    idToBooks.insert(std::pair<int, std::string>(16, "Percy Jackson"));
    idToBooks.insert(std::pair<int, std::string>(31, "Beauty and Beast"));
    idToBooks.insert(std::pair<int, std::string>(13, "How to Un mush brain"));
    idToBooks.insert(std::pair<int, std::string>(7, "Anime"));
    idToBooks.insert(std::pair<int, std::string>(5, "Pokemon"));
    idToBooks.insert(std::pair<int, std::string>(35, "Mario"));
    idToBooks.insert(std::pair<int, std::string>(420, "Grass is good"));
    idToBooks.insert(std::pair<int, std::string>(69, "Family Friendly"));

    std::map<int, std::string> booksToId;
    booksToId.emplace(22, "22");
    booksToId.emplace(3, "3");
    booksToId.emplace(16, "16");
    booksToId.emplace(31, "31");
    booksToId.emplace(13, "13");
    booksToId.emplace(7, "7");
    booksToId.emplace(5, "5");
    booksToId.emplace(35, "35");
    booksToId.emplace(420, "420");
    booksToId.emplace(69, "69");


    // borrowing a book
    std::vector<int> borrowed_books;

    int myBorrowInt;


    std::vector<int>::iterator it; // seaching if element is in vector
    it = find(borrowed_books.begin(), borrowed_books.end(), myBorrowInt);

    // returning a book
    int myReturnInt;

    /*
            {
                int indexOfBookToReturn = findBookInBorrowed(borrowed_books, 3);
                borrowed_books.erase(borrowed_books.begin() + indexOfBookToReturn);
            }
    */

    // Console colour
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);



    int choice;
    bool gameOn = true;
    while (gameOn != false)
    {
        SetConsoleTextAttribute(h, 7); // changes console colour to white

        std::cout
            << "\n----------------------------------------------------------------------------------------\n" << std::endl;
        std::cout
            << "Menu that doesn't display my broken brain :)\n" << std::endl;
        std::cout
            << " 1 - List of Books on loan." << std::endl;
        std::cout
            << " 2 - Return a book." << std::endl;
        std::cout
            << " 3 - Library." << std::endl;
        std::cout
            << " 4 - Borrow a book." << std::endl;
        std::cout
            << " 5 - Exit." << std::endl;
        std::cout
            << "\n Enter your choice and press enter: ";

        std::cin >> choice;

        std::cout << std::endl;

        switch (choice)
        {

        case 1:

            SetConsoleTextAttribute(h, 2); // changes console colour to blue

            for (int i : borrowed_books)
                std::cout << "                       "
                << "You have borrowed: " << i << ": " << idToBooks[i] << "\n" << std::endl;


            system("pause");

            break;
        case 2:

            std::cout <<
                "Choose a book ID to Return: ";
            std::cin >> myReturnInt;


            // Does abort when trying to return an existing book in library
            // Doesn't abort when trying to return a book in loan
            if (booksToId.count(myReturnInt))                       // can return a borrowed book
            {
                SetConsoleTextAttribute(h, 4);
                int indexOfBookToReturn = findBookInBorrowed(borrowed_books, myReturnInt);
                borrowed_books.erase(borrowed_books.begin() + indexOfBookToReturn);
                std::cout << "                       "
                    << "\nYou have Returned: " << idToBooks[myReturnInt] << std::endl;
            }
            else
            {
                std::cout << "\nNot a valid Book, Please check Books on Loan :)" << std::endl;
            }

            /*
            * Doesn't abort when returning an existing book in library
            * Does abort * Does abort when trying to return a book in loan
            *
            if (it != borrowed_books.end())                       // can't return a borrowed book
            {
                int indexOfBookToReturn = findBookInBorrowed(borrowed_books, myReturnInt);
                borrowed_books.erase(borrowed_books.begin() + indexOfBookToReturn);
            }
            else
            {
                std::cout << "\nNot a valid Book, Please check Books on Loan :)" << std::endl;
            }
            */

            break;
        case 3:
            std::cout
                << "\nAvailable Books: (ID: Name)" << std::endl;

            std::cout << std::endl << "                       "
                << booksToId[22] << ": " << idToBooks[22] << std::endl;
            std::cout << "                       "
                << booksToId[3] << ": " << idToBooks[3] << std::endl;
            std::cout << "                       "
                << booksToId[16] << ": " << idToBooks[16] << std::endl;
            std::cout << "                       "
                << booksToId[31] << ": " << idToBooks[31] << std::endl;
            std::cout << "                       "
                << booksToId[13] << ": " << idToBooks[13] << std::endl;
            std::cout << "                       "
                << booksToId[7] << ": " << idToBooks[7] << std::endl;
            std::cout << "                       "
                << booksToId[5] << ": " << idToBooks[5] << std::endl;
            std::cout << "                       "
                << booksToId[35] << ": " << idToBooks[35] << std::endl;
            std::cout << "                       "
                << booksToId[420] << ": " << idToBooks[420] << std::endl;
            std::cout << "                       "
                << booksToId[69] << ": " << idToBooks[69] << std::endl

                << std::endl;

            system("pause");

            break;
        case 4:

            // Note : learn how to check if I borrow the same book twice
            //          , if borrowed twice then don't allow them to borrow again

            std::cout <<
                "Choose a book ID to borrow: ";
            std::cin >> myBorrowInt;


            if (booksToId.count(myBorrowInt))
            {
                SetConsoleTextAttribute(h, 1);
                borrowed_books.push_back(myBorrowInt);
                std::cout << "                       "
                    << "\nYou have borrowed: " << idToBooks[myBorrowInt] << std::endl;
            }
            else
            {
                std::cout << "\nNot a valid Book, Please check library :)" << std::endl;
            }



            break;
        case 5:

            std::cout << "Bye bye!" << std::endl;

            gameOn = false;
            break;
        default:
            std::cout << "\nYour Wrong >:(" << std::endl;
            std::cout << "Choose better: ";
            std::cin >> choice;
            break;

        }

    }

    return 0;
}