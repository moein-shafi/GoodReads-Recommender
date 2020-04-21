#include "Book.h"

using namespace std;

Book::Book(int id,
           string title,
           string genre_1,
           string genre_2,
           int pages,
           string author_name,
           float author_average_rating):
                    id(id),
                    title(title),
                    genre_1(genre_1),
                    genre_2(genre_2),
                    pages(pages),
                    author_name(author_name),
                    author_average_rating(author_average_rating)
{
    this->sum_of_rating_like = 0;
    this->total_book_review = 0;
    this->popularity = 0;
}

int Book::get_id()
{
    return this->id;
}

float Book::get_popularity()
{
    return this->popularity;
}

void Book::increase_review_number(int value)
{
    this->total_book_review += value;;
}

void Book::increase_rating_like(int value)
{
    this->sum_of_rating_like += value;;
}

void Book::calculate_popularity()
{
    float review_grade;

    if (total_book_review < 1)
        review_grade = 0;
    else
        review_grade = sum_of_rating_like / total_book_review;

    float grade = author_average_rating + review_grade;
    this->popularity = 0.1 * grade;
}

void Book::show()
{
    cout << "id: " << this->id << endl;
    cout << "Title: " << this->title << endl;
    cout << "Genres: " << this->genre_1 << ", " << this->genre_2 << endl;
    cout << "Number of Pages: " << this->pages << endl;
    cout << "Author: " << this->author_name << endl;
    cout << "Average Rating: " << std::fixed << std::setprecision(2) << this->popularity << endl;
}
