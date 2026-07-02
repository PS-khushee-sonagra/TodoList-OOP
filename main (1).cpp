#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Task
{
private:
    string title;
    bool completed;

public:
    Task(string t)
    {
        title = t;
        completed = false;
    }

    void markComplete()
    {
        completed = true;
    }

    string getTitle()
    {
        return title;
    }

    bool isCompleted()
    {
        return completed;
    }
};
class ImportantTask : public Task
{
public:
    ImportantTask(string t) : Task(t)
    {
    }
};
void showMenu()
{
    cout << "\n===== TO DO LIST =====\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task Complete\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
}
int main()
{
    vector<Task> tasks;

    int choice;

    while (true)
    {
        showMenu();

        cin >> choice;

        if (choice == 1)
        {
            string title;

            cout << "Enter task: ";

            cin.ignore();

            getline(cin, title);

            Task t(title);

            tasks.push_back(t);

            cout << "Task Added!\n";
        }
                else if (choice == 2)
        {
            if (tasks.empty())
            {
                cout << "No tasks available.\n";
            }
            else
            {
                cout << "\nTasks:\n";

                for (int i = 0; i < tasks.size(); i++)
                {
                    cout << i + 1 << ". "
                         << tasks[i].getTitle();

                    if (tasks[i].isCompleted())
                        cout << " (Completed)";

                    cout << endl;
                }
            }
        }
                else if (choice == 3)
        {
            int num;

            cout << "Enter task number: ";

            cin >> num;

            if (num >= 1 && num <= tasks.size())
            {
                tasks[num -1].markComplete();

                cout << "Task Completed!\n";
            }else
               {
                cout << "Invalid Task!\n";
            }
        }
                else if (choice == 4)
        {
            cout << "Goodbye!\n";
            break;
        }

        else
        {
            cout << "Invalid Choice!\n";
        }
    }

    return 0;
}
