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
// laserScanIn (rosNodeHandler, "/rosNodeTalker/TestTopic3", 100, false),
// laserScanOut(rosNodeHandler, "/CSNodeTalker/TestTopic23", 100),
rosBlockPublisherDouble0(rosNodeHandler, "/debug/rosBlockPublisherDouble0", 100),
rosBlockPublisherDouble1(rosNodeHandler, "/debug/rosBlockPublisherDouble1", 100),
rosBlockPublisherDouble2(rosNodeHandler, "/debug/rosBlockPublisherDouble2", 100),
tcpClient0("146.136.36.76", 9876),

timedomain("Main time domain", dt, true)

{
	// Connect Blocks
	rosBlockPublisherDouble0.getIn().connect(tcpClient0.getOut0());
	rosBlockPublisherDouble1.getIn().connect(tcpClient0.getOut1());
	rosBlockPublisherDouble2.getIn().connect(tcpClient0.getOut2());
// 	rosBlockPublisherDouble0.getIn().connect(laserScanIn.getAngle_incrementOutput());
// 	printDouble0.getIn().connect(laserScanIn.getAngle_incrementOutput());
// 	laserScanOut.getAngle_minInput().connect(laserScanIn.getAngle_minOutput());
// 	laserScanOut.getAngle_maxInput().connect(laserScanIn.getAngle_maxOutput());
// 	laserScanOut.getIntensitiessInput().connect(laserScanIn.getIntensitiesOutput());
// 	laserScanOut.getIntensitiessInput().connect(laserScanIn.getRangesOutput());
// 	printDouble0.getIn().connect(analogIn0.getOut());
// 	printBool0.getIn().connect(digitalIn0.getOut());
// 	analogOut0.getIn().connect(analogIn0.getOut());
// 	digitalOut0.getIn().connect(digitalIn0.getOut());

	// Run blocks
	timedomain.addBlock(&tcpClient0);
// 	timedomain.addBlock(&laserScanIn);
// 	timedomain.addBlock(&analogIn0);
// 	timedomain.addBlock(&digitalIn0);
// 	timedomain.addBlock(&printDouble0);
// 	timedomain.addBlock(&printBool0);
// 	timedomain.addBlock(&analogOut0);
// 	timedomain.addBlock(&digitalOut0);
// 	timedomain.addBlock(&laserScanOut);
	timedomain.addBlock(&rosBlockPublisherDouble0);
	timedomain.addBlock(&rosBlockPublisherDouble1);
	timedomain.addBlock(&rosBlockPublisherDouble2);
				
	eeros::task::Periodic td("control system",dt, timedomain);
	eeros::Executor::instance().add(td);
}
	
