#include <eeros/control/TimeDomain.hpp>
#include <eeros/hal/HAL.hpp>

#include <eeros/control/Mux.hpp>
#include <eeros/control/SocketData.hpp>
#include <eeros/control/Constant.hpp>

using namespace eeros::control;

class MyControlSystem {		
public:
// 	MyControlSystem(double dt);
	MyControlSystem(double dt);

	
	// Define blocks
	Constant<double> const0;
	Constant<double> const1;
	Constant<double> const2;

	Mux<3, double, eeros::math::Matrix<3,1,double>>	mux;
	
	SocketData<eeros::math::Matrix<3,1,double>, std::nullptr_t>	tcpSocket;
	
	
			
//	protected:
	double dt;
	bool realtime;
	eeros::control::TimeDomain timedomain;
};