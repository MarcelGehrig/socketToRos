#include <iostream>
#include <signal.h>
#include <sstream>

#include <eeros/hal/HAL.hpp>
#include <eeros/core/Executor.hpp>
#include <eeros/task/Lambda.hpp>
#include <eeros/safety/SafetySystem.hpp>
#include <eeros/logger/Logger.hpp>
#include <eeros/logger/StreamLogWriter.hpp>

#include <eeros/logger/ROSLogWriter.hpp>

#include "control/controlSystem/MyControlSystem.hpp"
#include "control/safetySystem/MySafetyProperties.hpp"

using namespace eeros;
using namespace eeros::logger;


void signalHandler(int signum) {
	Executor::stop();
}

int main(int argc, char **argv) {
	double dt = 0.001;
	
	// Create and initialize logger
	// ////////////////////////////////////////////////////////////////////////
	StreamLogWriter w(std::cout);
	Logger::setDefaultWriter(&w);
	Logger log;
	w.show();
 
	log.info() << "EEROS started";
		
	// Control System
	// ////////////////////////////////////////////////////////////////////////
	MyControlSystem controlSystem(dt);
	
	// Safety System
	// ////////////////////////////////////////////////////////////////////////
	MySafetyProperties safetyProperties;
	eeros::safety::SafetySystem safetySystem(safetyProperties, dt);
	
	// Executor
	// ////////////////////////////////////////////////////////////////////////
	signal(SIGINT, signalHandler);	
	auto &executor = Executor::instance();
	executor.setMainTask(safetySystem);
	executor.run();
	
	return 0;
}
