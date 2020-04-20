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

void read_file(vector<vector<string> > &lines, string file_name)
{
    string line, field;
    vector<string> fields;
    fstream myFile(file_name.c_str());

    if (!myFile.is_open())
        throw std::runtime_error("Could not open file");

    getline(myFile, line);      // read columns name.
    while(getline(myFile, line))
    {
        stringstream ss(line);
        while(getline(ss, field, ','))
            fields.push_back(field);

        lines.push_back(fields);
        fields.clear();
    }
    myFile.close();
}

int search_book(vector<Book> &books, int low, int high, int target_id)
{
	int mid = (low + high) / 2; /*low + (high - low)/2;*/
	if (high < low)
		return -1;

	if (target_id == books[mid].get_id())
		return mid;

	if (target_id > books[mid].get_id())
		return search_book(books, (mid + 1), high, target_id);

	return search_book(books, low, (mid - 1), target_id);
}

void add_review(vector<Book> &books, vector<string> &review)
{
    int id = atoi(review[0].c_str());
    int rating = atoi(review[1].c_str());
    int number_of_likes = atoi(review[2].c_str());
    int result = rating * number_of_likes;
    int book_index = search_book(books, 0, books.size(), id);
    books[book_index].increase_review_number();
    books[book_index].increase_rating_like(result);
}

int main(int argc, char* argv[])
{
    string genre = argv[0];
    vector<Book> books;
    vector<vector<string> > books_lines;
    vector<vector<string> > reviews_lines;

    read_file(books_lines, BOOKS);
    for (auto book : books_lines)
        add_book(books, book);

    read_file(reviews_lines, REVIEWS);
    for (auto review : reviews_lines)
        add_review(books, review);

    /// TODO: calculate_pupolarity for each book
    /// TODO: find_result
    /// TODO: show_result

    exit(EXIT_SUCCESS);
}
