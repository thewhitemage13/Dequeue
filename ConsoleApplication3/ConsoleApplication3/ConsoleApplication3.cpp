#include <iostream>
#include <algorithm>
using namespace std;

class ExclusionProirityQueue
{
    string* data;
    int* priorities;
    unsigned int max_count;
    unsigned int real_count = 0;

public:
    ExclusionProirityQueue(unsigned int max_count)
    {
        this->max_count = max_count;
        data = new string[max_count];
        priorities = new int[max_count];
    }

    ~ExclusionProirityQueue()
    {
        if (data != nullptr) delete[] data;
        if (priorities != nullptr) delete[] priorities;
    }


    void Clear()
    {
        real_count = 0;
    }

    bool IsEmpty() const
    {
        return real_count == 0;
    }

    bool IsFull() const
    {
        return real_count == max_count;
    }

    int GetCount() const
    {
        return real_count;
    }

    void Enqueue(string value, int priority)
    {
        if (!IsFull())
        {
            int index_to_insert = real_count;
            for (int i = 0; i < real_count; i++)
            {
                if (priority > priorities[i])
                {
                    index_to_insert = i;
                    break;
                }
            }
            for (int i = real_count; i > index_to_insert; i--)
            {
                data[i] = data[i - 1];
                priorities[i] = priorities[i - 1];
            }
            data[index_to_insert] = value;
            priorities[index_to_insert] = priority;
            real_count++;
        }
        else
        {
            throw "Queue is full!";
        }
    }

    string Dequeue()
    {
        if (!IsEmpty())
        {
            string result = data[0];
            for (int i = 0; i < real_count - 1; i++)
            {
                data[i] = data[i + 1];
                priorities[i] = priorities[i + 1];
            }
            real_count--;
            return result;
        }
        else
        {
            throw "Queue is empty!";
        }
    }

    void Print() const
    {
        cout << "-----------------------------------------------------\n";
        for (int i = 0; i < real_count; i++)
            cout << i + 1 << ") " << data[i] << "\n";
        cout << "-----------------------------------------------------\n";
    }
};

int main()
{
    setlocale(0, "");

    ExclusionProirityQueue q(25);

    q.Enqueue("teacher, Alexander", 100);
    q.Enqueue("branch manager, Diane", 4);
    q.Enqueue("training manager, Ekaterina", 2);
    q.Enqueue("department chair, Christina", 3);
    q.Enqueue("CEO, Dmitry", 5);

    q.Enqueue("God, Pavlo ", 200);
    q.Print();

    q.Dequeue();

    q.Print();

    q.Dequeue();

    q.Print();

    q.Dequeue();

    q.Print();

    q.Dequeue();

    q.Print();
}