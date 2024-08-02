#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> buffer;
const unsigned int maxBufferSize = 10; 
bool doneProducing = false;


void producer() 
{
    int count = 0;
    while (count < 5) 
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return buffer.size() < maxBufferSize; });
        buffer.push(count);
        std::cout << "Producer produced " << count << std::endl;
        ++count;
        lock.unlock();
        cv.notify_all();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::unique_lock<std::mutex> lock(mtx);
    doneProducing = true;
    lock.unlock();
    cv.notify_all();
}

void consumer() 
{
    while (true) 
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !buffer.empty() || doneProducing; });
        if (buffer.empty() && doneProducing) 
        {
            break; 
        }
        int item = buffer.front();
        buffer.pop();
        std::cout << "Consumer consumed " << item << std::endl;
        lock.unlock();
        cv.notify_all();
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

int main() 
{
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);
    producerThread.join(); 
    consumerThread.join();
    return 0;
}
