#include "vex_by_gerard.h"
#include <iostream>
#include <string>
#include <vector>

double distance;
double speedInMPS;
double speedInKPH;
double turnDegrees;


// for displaying to check what it needs to do
std::vector<std::string> instuctions;

// this allows us to see stuff like degrees or meters. allowing us to plot the robots track before hittng run
std::vector<std::vector<int>> values;

// our headers contuctor  // not in use
vex_by_gerard::vex_by_gerard()
{


}

// forward logic // basic shit
void Motor::forward(double meter, double seconds){

    distance = meter;
    speedInMPS = meter / seconds;
    speedInKPH = (meter / seconds) * 3.6;

    instuctions.push_back("forward");

    std::vector<int> tempValues;
    tempValues.push_back(distance);
    tempValues.push_back(seconds);

    values.push_back(tempValues);


}

void Motor::turn(double degrees, double meters){

    instuctions.push_back("turn");

    std::vector<int> tempValues;

    tempValues.push_back(degrees);
    tempValues.push_back(meters);

    values.push_back(tempValues);


}

void Motor::setReversed(bool binaryVal){

    std::vector<int> tempValues;

    if(binaryVal){
        tempValues.push_back(1);

    }
    else {
        tempValues.push_back(0);
    }

    instuctions.push_back("dirChange");
    values.push_back(tempValues);

}
// to see our values
void Motor::toString(){


    std::cout << distance << " meters " << speedInKPH << " km/h " << speedInMPS << " m/s" << std::endl;




}
