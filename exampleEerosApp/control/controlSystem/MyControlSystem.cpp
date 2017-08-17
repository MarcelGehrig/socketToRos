#include <math.h> 
#include <iomanip>

#include <eeros/core/Executor.hpp>

#include "MyControlSystem.hpp"

using namespace eeros::control;
using namespace std;


MyControlSystem::MyControlSystem(double dt) :
dt(dt),
tcpSocket(9876, 0.01),

timedomain("Main time domain", dt, true)

{
	const0.setValue(1.1);
	const1.setValue(2.2);
	const2.setValue(3.3);
	
	mux.getIn(0).connect(const0.getOut());
	mux.getIn(1).connect(const1.getOut());
	mux.getIn(2).connect(const2.getOut());
	
	tcpSocket.getIn().connect(mux.getOut());

	// Run blocks
	timedomain.addBlock(const0);
	timedomain.addBlock(const1);
	timedomain.addBlock(const2);
	timedomain.addBlock(mux);
	timedomain.addBlock(tcpSocket);
				
	eeros::task::Periodic td("control system",dt, timedomain);
	eeros::Executor::instance().add(td);
}