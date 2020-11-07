#include <iostream>
#include <string>
#include <map>

#include "..\functions\console.cpp"
#include "..\functions\utils.cpp"

using namespace std;

class TaskList
{
public:
    void AddTasks()
    {
        clear_console();
        cout << "Enter new tasks:" << endl;
        cout << "Enter empty string for stop" << endl;
        while (true)
        {
            string task = ReadLine();
            if (task.empty())
                break;
            else
            {
                int id = CreateId();
                tasks[id] = {id, task};
            }
        }
    }

    void ShowTasks()
    {
        clear_console();
        cout << "id:\ttask:" << endl;
        for (const auto [key, task] : tasks)
            cout << task.id << "\t" << task.text << endl;
        pause_console();
    }

    void ChangeTask()
    {
        clear_console();
        cout << "Enter task ID:" << endl;
        const int id = ReadNumber();
        if (id > tasks.size())
        {
            cout << "Out of range" << endl;
            pause_console();
        }
        else
        {
            Task task = tasks.at(id);
            cout << "Current task: " << task.text << endl;
            cout << "Enter new tesk: " << endl;
            cout << "Enter empty string for cancel" << endl;
            string new_text = ReadLine();
            if (!new_text.empty())
            {
                tasks[id].text = new_text;
            }
        }
    }

    void DeleteTask()
    {
        cout << "Enter task ID:" << endl;
        const int id = ReadNumber();
        if (id > tasks.size())
        {
            cout << "Out of range" << endl;
            pause_console();
        }
        else
        {
            Task task = tasks.at(id);
            cout << "Delete this task: " << task.text << endl;
            cout << "yes / no" << endl;
            string answer = ReadLine();
            if (answer == "yes")
                tasks.erase(id);
        }
    }

private:
    struct Task
    {
        int id;
        string text;
    };

    map<int, Task> tasks;
    int _id = 0;

    int CreateId()
    {
        return _id++;
    }
};