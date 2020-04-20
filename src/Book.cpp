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
