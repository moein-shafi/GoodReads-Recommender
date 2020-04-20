#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Book.h"

using namespace std;

#define BOOKS "../datasets/books.csv"
#define REVIEWS "../datasets/reviews.csv"

void add_book(vector<Book> &books, vector<string> fields)
{
    int index = 0;
    int first = 0;
    int last = books.size() - 1;

    if (books.size() < 1)
    {
         books.push_back(Book(atoi(fields[0].c_str()),
                            fields[1], fields[2], fields[3],
                            atoi(fields[4].c_str()),
                            fields[5],
                            stof(fields[6])));
        return;
    }
    if (books[last].get_id() <= atoi(fields[0].c_str()))
    {
         books.push_back(Book(atoi(fields[0].c_str()),
                            fields[1], fields[2], fields[3],
                            atoi(fields[4].c_str()),
                            fields[5],
                            stof(fields[6])));
        return;
    }
    if (books[first].get_id() >= atoi(fields[0].c_str()))
    {
         books.insert(books.begin(),
                     Book(atoi(fields[0].c_str()),
                            fields[1], fields[2], fields[3],
                            atoi(fields[4].c_str()),
                            fields[5],
                            stof(fields[6])));
        return;
    }

    while (first + 1 < last)
    {
        index = (last - first) / 2;
        index += first;
        if (books[index].get_id() >= atoi(fields[0].c_str()))
            last = index;
        else
            first = index;
    }
    if (books[index].get_id() >= atoi(fields[0].c_str()))
    {
        books.insert(books.begin() + index,
                 Book(atoi(fields[0].c_str()),
                        fields[1], fields[2], fields[3],
                        atoi(fields[4].c_str()),
                        fields[5],
                        stof(fields[6])));
    }

    else
    {
        books.insert(books.begin() + index + 1,
                 Book(atoi(fields[0].c_str()),
                        fields[1], fields[2], fields[3],
                        atoi(fields[4].c_str()),
                        fields[5],
                        stof(fields[6])));
    }
}

void read_books(vector<Book> &books)
{
    string line, field;
    vector<string> fields;
    fstream myFile(BOOKS);

    if (!myFile.is_open())
        throw std::runtime_error("Could not open file");

    getline(myFile, line);      // read columns name.
    while(getline(myFile, line))
    {
        stringstream ss(line);
        while(getline(ss, field, ','))
            fields.push_back(field);

        add_book(books, fields);
        fields.clear();
    }
    myFile.close();
}

int main(int argc, char* argv[])
{
    string genre = argv[0];
    vector<Book> books;
    read_books(books);

    /// TODO: add_review for each book
    /// TODO: calculate_pupolarity for each book
    /// TODO: find_result
    /// TODO: show_result

    exit(EXIT_SUCCESS);
}
