#include <iostream>
#include "vex_by_gerard.cpp"


using namespace std;

int main(){

    Motor vex;

    vex.forward(5, 2);
    vex.turn(90, 10);
    vex.forward(5, 20);
    vex.setReversed(true);

    vex.toString();



}
