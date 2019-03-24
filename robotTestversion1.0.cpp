#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <functional>

const double fullCircle = 360; 
const double fullRotation = 31.4;
const double oneDegree = 1 / 360;

using namespace std;

vector<vector<double>> newSlowRotation(double distance, double time1){ 

    vector<vector<double>> toReturn;

    ofstream file;
    file.open("log.txt");

    vector<double> speedVect;
    vector<double> timeVect;
    vector<double> distVect;

    double speed = distance / time1;


    double forTime = time1 / 6 / 10;
    double speedIncrement =  distance / time1 / 10;


    double totalDist;

    for(int step = 1;step < 11;++step){

        timeVect.push_back(forTime);
        speedVect.push_back(speedIncrement * step);
        distVect.push_back(speedIncrement * step * forTime);

        totalDist += distVect[step - 1];
    }

    double dist_total;
    double time_total;

    for(int step = 0;step < timeVect.size();++step){

        dist_total += (timeVect[step] * speedVect[step]) * 2;
        time_total += forTime * 2;

    }

    timeVect.push_back(time1 - time_total);
    distVect.push_back(distance - dist_total);
    speedVect.push_back((distance - dist_total) / (time1 - time_total));

    for(int step = 10;step > 0;--step){

        timeVect.push_back(forTime);
        speedVect.push_back(speedIncrement * step);
        distVect.push_back(speedIncrement * step * forTime);
    }


    double compTime;
    double compDist;

    for(int step = 0;step < timeVect.size();++step){

        compTime += timeVect[step];
        compDist += distVect[step];

        file << distVect[step] << " meters " << timeVect[step] << " seconds  " << speedVect[step] <<" meters per second\n";
        file << "----------------------------------------------------------------------------------------------------------\n";



    }
    file << compDist << "total meters     " << compTime << " total seconds";



    toReturn.push_back(timeVect);
    toReturn.push_back(distVect);   

    file.close();

    return toReturn;

}

void armMovement(double degrees, double seconds, function<vector<vector<double>>(double, double)> speedAlter){

    double RotationAmount = degrees * 0.002777777777777;

    double minutes = seconds / 60;

    double RPM = RotationAmount / minutes;

    double meters = (fullRotation * RPM / 6000) * seconds;

    cout << meters;

    vector<vector<double>> x = speedAlter(meters, seconds);

    vector<double> timeVect = x[0];
    vector<double> distVect = x[1];

    for(int i = 0;i < timeVect.size(); i++){

        double meter = distVect[i];
        double second = timeVect[i];

        double RPM_new = meter/second * 6000 / 31.4;

        /*
        Arm.setVelocity(RPM_new,velocityUnits::rpm);
        Arm.setReversed(false);
        Arm.spin(directionType::fwd);
        task::sleep(seconds * 1000);
        */
    }

    //Arm.stop();
}

int main(){

    vector<vector<double>> x = newSlowRotation(100,300);
    armMovement(30, 60, newSlowRotation);
    cout << "                                            ";
}


