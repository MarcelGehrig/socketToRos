#include <eeros/control/TimeDomain.hpp>
#include <eeros/hal/HAL.hpp>

#include "Print.hpp"
#include <eeros/control/ROS/RosBlockPublisherDouble.hpp>
#include "RosBlockSubscriber_SensorMsgs_LaserScan.hpp"
#include "RosBlockPublisher_SensorMsgs_LaserScan.hpp"

#include "StandaloneClientBlock.hpp"

using namespace eeros::control;

class MyControlSystem {		
public:
// 	MyControlSystem(double dt);
	MyControlSystem(double dt, ros::NodeHandle& rosNodeHandler);

	
	// Define blocks
	Print<double> printDouble0;
	Print<bool> printBool0;
	StandaloneClientBlock<double> tcpClient0;
	
	RosBlockPublisherDouble rosBlockPublisherDouble0;
	RosBlockPublisherDouble rosBlockPublisherDouble1;
	RosBlockPublisherDouble rosBlockPublisherDouble2;
			
//	protected:
	double dt;
	ros::NodeHandle& rosNodeHandler;
	bool realtime;
	eeros::control::TimeDomain timedomain;
};
