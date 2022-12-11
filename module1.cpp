#include <bits/stdc++.h>
#include <fstream>
using namespace std;

char M[100][4];
char R[4];
char IR[4];
int IC;
int C;
char Buff[40];

fstream input;
fstream output;

void init()
{

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            M[i][j] = ' ';
        }
    }

    for (int i = 0; i < 4; i++)
    {
        IR[i] = ' ';
        R[i] = ' ';
    }

    int IC = 0;
    int C = 0; // toggle register
}

void load()
{

    do
    {

        for (int i = 0; i < 40; i++)
            Buff[i] = '\0';

        input.getline(Buff, 40);

        for (int i = 0; i < 40; i++)
            cout << Buff[i];

        if (Buff[0] == '$' && Buff[1] == 'A' && Buff[2] == 'M' && Buff['3'] == 'J')
        {
            init();
        }

        else if (Buff[0] == '$' && Buff[1] == 'D' && Buff[2] == 'T' && Buff['3'] == 'A')
        {
            // se();
        }

        else if (Buff[0] == '$' && Buff[1] == 'E' && Buff[2] == 'N' && Buff['3'] == 'D')
        {
            // CONTINUE;
        }

        else
        {

            int k = 0;
            for (int i = 0; i < 100; i++)
                for (int j = 0; j < 4; j++)
                {
                    M[i][j] = Buff[k];
                    k++;
                }
            if (k == 40 || k == ' ' || k == '\n' || k == '\0')
            {
                break;
            }
        }
        // break;

    } while (!input.eof());
}

int main()
{

    input.open("input1.txt", ios::in);

    do
    {
        input.getline(Buff, 40);
        for (int i = 0; i < 40; i++)
            cout << Buff[i];
    } while (!input.eof());
    load();
    output.open("output1.txt", ios::out);
}
