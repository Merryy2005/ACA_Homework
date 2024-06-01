#include <iostream>
#include <string>

class Artist{
    private:
        std::string m_name;
        std::string m_genre;
    public:
        Artist():
              m_name(""),
              m_genre("")
        {

        };

        Artist(std::string name , std::string genre):
              m_name(name),
              m_genre(genre)
        {

        };

        void printArtist() const
        {
            std::cout << m_name << " " << m_genre << std::endl;
        };

        ~Artist()
        {

        };
};

class Date{
    private:
        int m_year;
        int m_month;
        int m_day;
    public:
        Date():
            m_year(0),
            m_month(0),
            m_day(0)
        {

        };

        Date(int year , int month , int day):
            m_year(year),
            m_month(month),
            m_day(day)
        {

        };

        void printDate() const
        {
            if(m_day < 10){
                std::cout << "0" << m_day << ".";
            }
            else{
                std::cout << m_day << ".";
            }
            if(m_month < 10){
                std::cout << "0" << m_month << ".";
            }
            else{
                std::cout << m_day << ".";
            }
            std::cout << m_year << std::endl;
        };

        ~Date()
        {

        };
};

class Song{
    private:
        std::string m_name;
        Artist m_artist;
        int m_duration; //in minutes
        Date m_date; // release date

    public:
        Song(): 
            m_name(""), 
            m_duration(0)
        {

        };

        Song(std::string songname , std::string artistname , std::string genre , int duration , int year , int month , int day) : 
            m_name(songname),
            m_artist(artistname , genre),
            m_duration(duration),
            m_date(year , month , day)
        {

        };

        void printSong() const
        {
            std::cout << "Name : " << m_name << std::endl;
            std::cout << "Artist : ";
            m_artist.printArtist();
            std::cout << "Duration : " << m_duration << " minutes" << std::endl;
            std::cout << "Release date : ";
            m_date.printDate();
        };
};

int main()
{
    Song s("Havana" , "Camila Cabello" , "Pop" , 210 , 2017 , 8 , 3);
    s.printSong();
}