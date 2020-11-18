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

    enum main_menu
    {
        Exit,
        Add_Tasks,
        Show_Tasks,
        Change_Task,
        Delete_Task,
        settings,
    };

    void ShowMenu()
    {
        clear_console();
        cout << "Menu:" << endl;
        cout << main_menu::Add_Tasks << " Add tasks" << endl;
        cout << main_menu::Show_Tasks << " Show tasks" << endl;
        cout << main_menu::Change_Task << " Change task" << endl;
        cout << main_menu::Delete_Task << " Delete task" << endl;
        cout << main_menu::settings << " Settings" << endl;
        cout << main_menu::Exit << " exit" << endl;
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
            case main_menu::Add_Tasks:
                list.AddTasks();
                break;
            case main_menu::Show_Tasks:
                list.ShowTasks();
                break;
            case main_menu::Change_Task:
                list.ChangeTask();
                break;
            case main_menu::Delete_Task:
                list.DeleteTask();
                break;
            case main_menu::Exit:
                isExit = true;
                break;
            }
        }
    }
};