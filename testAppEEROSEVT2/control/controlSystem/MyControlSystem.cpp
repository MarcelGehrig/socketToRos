#include <math.h> 
#include <iomanip>

#include <eeros/core/Executor.hpp>
#include "MyControlSystem.hpp"

using namespace eeros::control;
using namespace std;


MyControlSystem::MyControlSystem(double dt, ros::NodeHandle& rosNodeHandler) :
// MyControlSystem::MyControlSystem(double dt) :
dt(dt),
rosNodeHandler(rosNodeHandler),

printDouble0(1),
printBool0(1),
rosBlockPublisherDouble0(rosNodeHandler, "/debug/rosBlockPublisherDouble0", 100),
rosBlockPublisherDouble1(rosNodeHandler, "/debug/rosBlockPublisherDouble1", 100),
rosBlockPublisherDouble2(rosNodeHandler, "/debug/rosBlockPublisherDouble2", 100),
tcpClient0("127.0.0.1", 9876),

timedomain("Main time domain", dt, true)

{
	// Connect Blocks
	rosBlockPublisherDouble0.getIn().connect(tcpClient0.getOut0());
	rosBlockPublisherDouble1.getIn().connect(tcpClient0.getOut1());
	rosBlockPublisherDouble2.getIn().connect(tcpClient0.getOut2());

	// Run blocks
	timedomain.addBlock(&tcpClient0);
	timedomain.addBlock(&rosBlockPublisherDouble0);
	timedomain.addBlock(&rosBlockPublisherDouble1);
	timedomain.addBlock(&rosBlockPublisherDouble2);
				
	eeros::task::Periodic td("control system",dt, timedomain);
	eeros::Executor::instance().add(td);
}
	
