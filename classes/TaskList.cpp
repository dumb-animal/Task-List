#include <iostream>
#include <string>
#include <map>

#include "..\functions\console.cpp"
#include "..\functions\utils.cpp"

using namespace std;

class TaskList
{
public:

    void start()
    {
        loop();
    }

private:
    struct Task
    {
        int id;
        string text;
    };

    map<int, Task> tasks;
    int _id = 0;

    enum options
    {
        Exit,
        Add_Tasks,
        Show_Tasks,
        Change_Task,
        Delete_Task,
    };

    int CreateId()
    {
        return _id++;
    }

    void ShowMenu()
    {
        clear_console();
        cout << "Menu:" << endl;
        cout << options::Add_Tasks << " Add tasks" << endl;
        cout << options::Show_Tasks << " Show tasks" << endl;
        cout << options::Change_Task << " Change task" << endl;
        cout << options::Delete_Task << " Delete task" << endl;
        cout << options::Exit << " exit" << endl;
    }

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
        cout << "id\ttask" << endl;
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

    void loop()
    {
        bool isExit = false;
        while (!isExit)
        {
            ShowMenu();
            int option = ReadNumber();
            switch (option)
            {
            case options::Add_Tasks:
                AddTasks();
                break;
            case options::Show_Tasks:
                ShowTasks();
                break;
            case options::Change_Task:
                ChangeTask();
                break;
            case options::Delete_Task:
                DeleteTask();
                break;
            case options::Exit:
                isExit = true;
                break;
            }
        }
    }
};