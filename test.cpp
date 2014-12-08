//#include "commandline/argparcer.h"
#include "tools/daytimer.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
/*
    ArgParcer *ap = new ArgParcer();
    string data = ap->GetTagData("-t", argv, argc);
    cout << data;
*/

    DayTimer *dt = new DayTimer();
    //cout << dt->Get24HourTime() << endl;

    //cout << dt->Get12HourTime() << endl;
/*
    for(int i = 0; i < 130 ; i++){
        dt->IncrementHour();
        //dt->IncrementMinute();

        cout << dt->Get12HourTime() << endl;

    }
*/
    ++(*dt);
    ++(*dt);
    ++(*dt);
    (*dt)++;
    (*dt)++;
    (*dt)++;
    cout << (*dt);


    return 0;
}