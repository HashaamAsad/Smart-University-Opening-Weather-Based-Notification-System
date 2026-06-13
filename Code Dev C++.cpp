#include <iostream>
#include <string>

using namespace std;

class Weather
{
private:
    float temperature;
    int rainLevel;
    int stormLevel;
    string date;

public:
    void setWeather()
    {
        cin.ignore();

        cout << "Enter Date: " << endl;
        getline(cin, date);

        cout << "Enter Temperature in Celsius: " << endl;
        cin >> temperature;

        cout << "Enter Rain Level (0 = No Rain, 1 = Light Rain, 2 = Heavy Rain): " << endl;
        cin >> rainLevel;

        cout << "Enter Storm Level (0 = No Storm, 1 = Mild Storm, 2 = Severe Storm): " << endl;
        cin >> stormLevel;
    }

    void displayWeather()
    {
        cout << "Date: " << date << endl;
        cout << "Temperature: " << temperature << " C" << endl;
        cout << "Rain Level: " << rainLevel << endl;
        cout << "Storm Level: " << stormLevel << endl;
    }

    float getTemperature()
    {
        return temperature;
    }

    int getRainLevel()
    {
        return rainLevel;
    }

    int getStormLevel()
    {
        return stormLevel;
    }

    string getDate()
    {
        return date;
    }
};

class UniversitySystem
{
private:
    Weather weatherRecords[100];
    int totalRecords;

public:
    UniversitySystem()
    {
        totalRecords = 0;
    }

    void addWeatherRecord()
    {
        if (totalRecords < 100)
        {
            weatherRecords[totalRecords].setWeather();
            totalRecords++;

            cout << "Weather Record Added Successfully!" << endl;
        }
        else
        {
            cout << "Storage Full!" << endl;
        }
    }

    void displayAllRecords()
    {
        if (totalRecords == 0)
        {
            cout << "No Weather Records Found!" << endl;
            return;
        }

        for (int i = 0; i < totalRecords; i++)
        {
            cout << "========== RECORD " << i + 1 << " ==========" << endl;

            weatherRecords[i].displayWeather();

            cout << "================================" << endl;
        }
    }

    void checkUniversityStatus()
    {
        if (totalRecords == 0)
        {
            cout << "No Weather Data Available!" << endl;
            return;
        }

        Weather latest = weatherRecords[totalRecords - 1];

        cout << "===== UNIVERSITY STATUS REPORT =====" << endl;

        latest.displayWeather();

        if (latest.getStormLevel() == 2 || latest.getRainLevel() == 2 || latest.getTemperature() > 45)
        {
            cout << "University Status: CLOSED" << endl;
            cout << "Notification: Severe weather conditions detected." << endl;
            cout << "Students and staff are advised to stay at home." << endl;
        }
        else if (latest.getStormLevel() == 1 || latest.getRainLevel() == 1 || latest.getTemperature() > 38)
        {
            cout << "University Status: OPEN WITH CAUTION" << endl;
            cout << "Notification: Moderate weather conditions detected." << endl;
            cout << "Students should travel carefully." << endl;
        }
        else
        {
            cout << "University Status: OPEN" << endl;
            cout << "Notification: Weather conditions are normal." << endl;
        }

        cout << "====================================" << endl;
    }

    void searchRecord()
    {
        string searchDate;
        bool found = false;

        cin.ignore();

        cout << "Enter Date to Search Record: " << endl;
        getline(cin, searchDate);

        for (int i = 0; i < totalRecords; i++)
        {
            if (weatherRecords[i].getDate() == searchDate)
            {
                cout << "Record Found!" << endl;

                weatherRecords[i].displayWeather();

                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Record Not Found!" << endl;
        }
    }
};

int main()
{
    UniversitySystem system;

    int choice;

    do
    {
        cout << endl;
        cout << "===== SMART UNIVERSITY OPENING SYSTEM =====" << endl;
        cout << "1. Add Weather Record" << endl;
        cout << "2. Display All Records" << endl;
        cout << "3. Check University Status" << endl;
        cout << "4. Search Weather Record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Your Choice: " << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            system.addWeatherRecord();
            break;

        case 2:
            system.displayAllRecords();
            break;

        case 3:
            system.checkUniversityStatus();
            break;

        case 4:
            system.searchRecord();
            break;

        case 5:
            cout << "Exiting System..." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
