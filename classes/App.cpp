#include "TaskList.cpp"

class App
{
public:
    void start()
    {
        loop();
    }

private:
    TaskList list;

    enum options
    {
        Exit,
        Add_Tasks,
        Show_Tasks,
        Change_Task,
        Delete_Task,
    };

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
                list.AddTasks();
                break;
            case options::Show_Tasks:
                list.ShowTasks();
                break;
            case options::Change_Task:
                list.ChangeTask();
                break;
            case options::Delete_Task:
                list.DeleteTask();
                break;
            case options::Exit:
                isExit = true;
                break;
            }
        }
    }
};