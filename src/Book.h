#include <string>

using namespace std;

class Book
{
    public:
        Book(int id,
             string title,
             string genre_1,
             string genre_2,
             int pages,
             string author_name,
             float author_average_rating);

    private:
        int id;
        string title;
        string genre_1;
        string genre_2;
        int pages;
        string author_name;
        float author_average_rating;
        float sum_of_rating_like;
        int total_book_review;
        float popularity;
};
