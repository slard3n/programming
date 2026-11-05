#include <iomanip>
#include <iostream>

using namespace std;

const float PERSON_WT = 170.0f;
const float LBS_PER_GAL = 6.7f;
const float EMPTY_WEIGHT = 9887.0f;
const float EMPTY_MOMENT = 3185853.0f;

const float CREW_ARM = 143.0f;
const float ROW1_ARM = 219.0f;
const float ROW2_ARM = 265.0f;
const float ROW3_ARM = 295.0f;
const float ROW4_ARM = 341.0f;
const float CLOSET_ARM = 182.0f;
const float BAGGAGE_ARM = 386.0f;

void GetData(int& crew, int& passengers, float& closet,
             float& baggage, float& fuel)
{
    cout << "Кількість членів команди (1-2): ";
    cin >> crew;
    cout << "Кількість пасажирів (0-8): ";
    cin >> passengers;
    cout << "Вага вмісту туалету (до 160 фунтів): ";
    cin >> closet;
    cout << "Вага багажу (до 525 фунтів): ";
    cin >> baggage;
    cout << "Кількість палива (0-565 галонів): ";
    cin >> fuel;
}

float CrewMoment(int crew)
{
    return crew * PERSON_WT * CREW_ARM;
}

float PassengerMoment(int passengers)
{
    float moment = 0.0f;
    int passenger = 0;

    while (passenger < passengers)
    {
        float arm;

        if (passenger < 2)
            arm = ROW2_ARM;
        else if (passenger < 4)
            arm = ROW1_ARM;
        else if (passenger < 6)
            arm = ROW3_ARM;
        else
            arm = ROW4_ARM;

        moment += PERSON_WT * arm;
        passenger++;
    }

    return moment;
}

float CargoMoment(float closet, float baggage)
{
    return closet * CLOSET_ARM + baggage * BAGGAGE_ARM;
}

float FuelDistance(float fuel)
{
    if (fuel <= 59.0f)
        return 314.6f * fuel;
    if (fuel <= 360.0f)
        return 305.8f - 0.01233f * (fuel - 60.0f);
    if (fuel <= 520.0f)
        return 303.0f + 0.12500f * (fuel - 361.0f);
    return 323.0f - 0.04444f * (fuel - 521.0f);
}

float FuelMoment(float fuel)
{
    return fuel * LBS_PER_GAL * FuelDistance(fuel);
}

void PrintWarning(int crew, int passengers, float closet,
                  float baggage, float fuel)
{
    if (crew < 1 || crew > 2)
    {
        cout << "Попередження: команда повинна складатися з 1 або 2 осіб." << endl;
    }
    if (passengers > 8)
    {
        cout << "Попередження: у літаку лише 8 пасажирських місць." << endl;
    }
    if (closet > 160.0f)
    {
        cout << "Попередження: перевищено максимальну вагу туалету." << endl;
    }
    if (baggage > 525.0f)
    {
        cout << "Попередження: перевищено максимальну вагу багажу." << endl;
    }
    if (fuel < 0.0f || fuel > 565.0f)
    {
        cout << "Попередження: кількість палива має бути від 0 до 565 галонів." << endl;
    }
}

int main()
{
    int crew, passengers;
    float closet, baggage, fuel;

    GetData(crew, passengers, closet, baggage, fuel);

    float totalWeight = EMPTY_WEIGHT
        + (crew + passengers) * PERSON_WT
        + closet + baggage
        + fuel * LBS_PER_GAL;

    float centerOfGravity = (CrewMoment(crew)
        + PassengerMoment(passengers)
        + CargoMoment(closet, baggage)
        + FuelMoment(fuel)
        + EMPTY_MOMENT) / totalWeight;

    cout << fixed << setprecision(2);
    cout << "\nРезультат" << endl;
    cout << totalWeight << endl;
    cout << centerOfGravity << endl;

    PrintWarning(crew, passengers, closet, baggage, fuel);

    return 0;
}
