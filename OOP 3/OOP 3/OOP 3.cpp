#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

struct NOTEBOOK
{
    std::string model; // наименование
    struct size // габаритные размеры
    {
        float x;
        float y;
        float z;
    }s; //размеры
    float w; // вес
    int price; // цена
    int frame;
};

void bubbleSort(int list[], int listLength, NOTEBOOK models[])
{
    while (listLength--)
    {
        bool swapped = false;

        for (int i = 0; i < listLength; i++)
        {
            if (models[list[i]].price < models[list[i + 1]].price)
            {
                std::swap(list[i], list[i + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

void write(NOTEBOOK NB)
{
    std::ofstream fout("C:\\note2.txt", std::ios::app);
    if (fout.is_open())
    {
        fout << NB.model << std::endl;
        fout << NB.s.x << std::endl;
        fout << NB.s.y << std::endl;
        fout << NB.s.z << std::endl;
        fout << NB.w << std::endl;
        fout << NB.price << std::endl;
        fout << NB.frame << std::endl;
    }
}

NOTEBOOK* read()
{
    int n;
    std::string line;
    std::ifstream fin("C:\\note.txt");
    if (fin.is_open())
    {
        getline(fin, line);
        std::cout << line << std::endl;;
        n = stoi(line);
        NOTEBOOK* models = new NOTEBOOK[n];
        for (int i = 1; i < n * 7 + 1; i++)
        {
            if ((i == 1) or ((i - 1) % 7 == 0))
            {
                getline(fin, line);
                models[((i + 6) / 7)-1].model = line;
                std::cout << line << std::endl;
            }
            else if ((i == 2) or ((i - 2) % 7 == 0))
            {
                getline(fin, line);
                float x = std::stof(line);
                models[((i + 5) / 7)-1].s.x = x;
                std::cout << line << std::endl;
            }
            else if (i == 3 or (i - 3) % 7 == 0)
            {
                getline(fin, line);
                float y = std::stof(line);
                models[((i + 4) / 7)-1].s.y = y;
                std::cout << line << std::endl;
            }
            else if (i == 4 or (i - 4) % 7 == 0)
            {
                getline(fin, line);
                float z = std::stof(line);
                models[((i + 3) / 7)-1].s.z = z;
                std::cout << line << std::endl;
            }
            else if (i == 5 or (i - 5) % 7 == 0)
            {
                getline(fin, line);
                float w = std::stof(line);
                models[((i + 2) / 7)-1].w = w;
                std::cout << line << std::endl;
            }
            else if (i == 6 or (i - 6) % 7 == 0)
            {
                getline(fin, line);
                int price = stoi(line);
                models[((i + 1) / 7)-1].price = price;
                std::cout << line << std::endl;
            }
            else if (i % 7 == 0)
            {
                getline(fin, line);
                int frame = stoi(line);
                models[(i / 7)-1].frame = frame;
                std::cout << line << std::endl;
            }
        }
        return models;
    }
}

int main()
{
    NOTEBOOK* models = read();
    models = read();
    int k=0;
    int* count = new int[k];
    int i = 0;
    while (models[i].frame != NULL)
    {
        if (models[i].frame > 120)
        {
            k=k+1;
            count[k - 1] = i;
        }
        i=i+1;
    }
    bubbleSort(count, k, models);
    for (i = 0; i < k; i++)
    {
        write(models[count[i]]);
    }
}
