#include <iostream>
#include <string>

class Song{
    private:
        std::string m_name;
        std::string m_artist;
        int m_duration; //in minutes
        int m_year;

    public:
        Song() : 
            m_name(""), 
            m_artist(""), 
            m_duration(0), 
            m_year(0)
        {

        };

        Song(std::string name , std::string artist , int duration , int year) : 
            m_name(name),
            m_artist(artist),
            m_duration(duration),
            m_year(year)
        {

        };

        void printSong() const
        {
            std::cout << "Name : " << m_name << std::endl;
            std::cout << "Artist : " << m_artist << std::endl;
            std::cout << "Duration : " << m_duration << " minutes" << std::endl;
            std::cout << "Release year : " << m_year << std::endl;
        };
};

class Playlist{
    private:
        Song** m_songs;
        int m_count; //current songs
        int m_size; //maximum number of songs
    public:
        Playlist() :
                m_songs(nullptr),
                m_count(0),
                m_size(0)
        {

        };

        Playlist(int size) :
                m_size(size),
                m_count(0)
        {
            m_songs = new Song*[m_size];
        };

        Playlist(Playlist& other) :
            m_count(other.m_count),
            m_size(other.m_size)
        {
            m_songs = new Song*[m_size];
            for(int i = 0 ; i < m_count ; i++)
            {
                m_songs[i] = other.m_songs[i];
            }
        };

        Playlist& operator= (Playlist& other)
        {
            if(this != &other)
            {
                //just deleting m_songs so that after assignment 
                //the songs that were in the playlist are not deleted and can be used for other playlists
                delete[] m_songs;
                m_size = other.m_size;
                m_count = other.m_count;
                m_songs = new Song*[m_size];
                for(int i = 0 ; i < m_count ; i++)
                {
                    m_songs[i] = other.m_songs[i];
                }
            }
            return *this;
        };

        bool registerSong(Song* song)
        {
            bool bRes = false;
            for(int i = 0 ; i < m_count ; i++)
            {
                if(m_songs[i] == song)
                {
                    std::cout << "Already registered" << std::endl;
                    return bRes;
                }
            }
            if(m_count < m_size)
            {
                m_songs[m_count++] = song;
                bRes = true;
            }
            return bRes;
        };

        bool deRegisterSong(Song* song)
        {
            bool bRes = false;
            for(int i = 0 ; i < m_count ; i++)
            {
                if(m_songs[i] == song)
                {
                    bRes = true;
                    m_count--;
                    for(int j = i ; j < m_count ; j++)
                    {
                        m_songs[j] = m_songs[j+1];
                    }
                    m_songs[m_count] = nullptr;
                    return bRes;
                }
            }
            return bRes;
        };

        void printPlaylist() const
        {
            std::cout << "Found " << m_count << " songs" << std::endl;
            std::cout << "---------------" << std::endl;
            for(int i = 0 ; i < m_count ; i++)
            {
                std::cout << "Song number " << (i+1) << std::endl;
                m_songs[i] -> printSong();
                std::cout << std::endl;
            }
            std::cout << "---------------" << std::endl;
        };

        ~Playlist()
        {
            delete[] m_songs;
            m_songs = nullptr;
            m_size = 0;
            m_count = 0;
        };
};

int main(){
    Song* s1 = new Song("Don't blame me" , "Taylor Swift" , 236 , 2017);
    Song* s2 = new Song("You broke me first" , "Tate McRae" , 170 , 2020);
    Song* s3 = new Song("Summertime sadness" , "Lana Del Rey" , 265 , 2012);
    Playlist playlist1(10);
    playlist1.registerSong(s1);
    playlist1.registerSong(s2);
    playlist1.registerSong(s3);
    playlist1.registerSong(s3);
    playlist1.printPlaylist();
    playlist1.deRegisterSong(s2);
    playlist1.printPlaylist();
    Playlist playlist2(10);
    playlist2.registerSong(s2);
    playlist2.registerSong(s3);
    playlist1 = playlist2;
    playlist1.printPlaylist();
    playlist2.registerSong(s1);
    playlist2.printPlaylist();
    delete s1;
    delete s2;
    delete s3;
    return 0;
}