#ifndef _BOOK_H_
#define _BOOK_H_

#include <iomanip>
#include <iostream>
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
        int get_id();
        float get_popularity();
        void increase_review_number(int value=1);
        void increase_rating_like(int value);
        void calculate_popularity();
        void show();
        int have_genre(string genre);

    private:
        int id;
        string title;
        string genre_1;
        string genre_2;
        int pages;
        string author_name;
        float author_average_rating;
        int sum_of_rating_like;
        int total_book_review;
        float popularity;
};

#endif
