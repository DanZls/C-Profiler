#pragma once

#include <iostream>
#include <ctime>

class Profiler{
	clock_t t0;
	bool IsStarted = false;
public:
	void StartLap(){
		IsStarted = true;
		std::cout << "Time lap started." << std::endl;
		t0 = std::clock();
	}
	void EndLap(){
		if(IsStarted){
			IsStarted = false;
			int msec = double(std::clock()-t0)/CLOCKS_PER_SEC*1000;
			std::cout << "Time elapsed: ";
			if(msec / 1000 > 0) std::cout << msec / 1000 << "s ";
			std::cout << msec % 1000 << "ms." << std::endl;
		}
		else{
			std::cout << "Time lap had not started." << std::endl;
		}
	}
};

Profiler PROFILER_;

#define TIC PROFILER_.StartLap();
#define TAC PROFILER_.EndLap();
