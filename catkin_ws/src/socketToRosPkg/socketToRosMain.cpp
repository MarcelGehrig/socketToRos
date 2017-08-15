#include "ros/ros.h"
// #include "std_msgs/float64_header.h"
#include "std_msgs/String.h"

//#include "socketToRos/msg/float64_header.msg"

#include <sstream>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>      /* inet_ntoa() to format IP address */
#include <iostream>
#include <array>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "talker");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;

  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing. After this advertise() call is made, the master
   * node will notify anyone who is trying to subscribe to this topic name,
   * and they will in turn negotiate a peer-to-peer connection with this
   * node.  advertise() returns a Publisher object which allows you to
   * publish messages on that topic through a call to publish().  Once
   * all copies of the returned Publisher object are destroyed, the topic
   * will be automatically unadvertised.
   *
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages.  If messages are published more quickly
   * than we can send them, the number here specifies how many messages to
   * buffer up before throwing some away.
   */
   
	char* server_ip;
	int port;
	
	
  	ros::Publisher chatter_pub = n.advertise<std_msgs::float>("publisherEEROS", 1000);
  	ros::Rate loop_rate(1000);


	
	server_ip = "0.0.0.0";
	server_ip = "127.0.0.1";
	port = 9876;
	
	
	
	
	struct sockaddr_in serv_addr;
	
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) std::cout << "ERROR opening socket" << std::endl;
	
	auto server = gethostbyname(server_ip); 
	
	if (server == NULL) {
		std::cout << "ERROR, no such host\n" << std::endl;
		exit(0);
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(port);
	
	if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
		std::cout << "ERROR connecting" << std::endl;
	
	// Start communication
	std::cout << "Client thread started" << std::endl;
	
	double b_write[4]; double b_read[4];
	int n;
	
	double dataToSend = 0;

	std_msgs::String msg;
	
	while(ros::ok()){
		// 1. WRITE
		std::cout << "w: ";
		for(int i = 0; i < sizeof(b_write)/sizeof(b_write[0]); i++){
			b_write[i] = dataToSend;
			dataToSend++;
			std::cout << b_write[i] << "\t";
		}
		std::cout << std::endl;
		n = write(sockfd,b_write,sizeof(b_write)*8);
		if (n < 0) std::cout << "ERROR writing to socket" << std::endl;
		
		// 2. READ
		n = read(sockfd,b_read,sizeof(b_read)*8);
		if (n < 0) std::cout << "ERROR reading from socket" << std::endl;
		
		std::cout << "rec: ";
		for(int i=0;i<4;i++){
			std::cout << b_read[i] << "\t";
		}
		std::cout << std::endl;
		
		chatter_pub.publish(msg);
		ros::spinOnce();
		usleep(100000);
	}
	
	close(sockfd);
	
	
	
//   /**
//   * A count of how many messages we have sent. This is used to create
//    * a unique string for each message.
//    */
//   int count = 0;
//   while (ros::ok())
//   {
//     /**
//      * This is a message object. You stuff it with data, and then publish it.
//      */
//     std_msgs::String msg;
// 
//     std::stringstream ss;
//     ss << "hello world " << count;
//     msg.data = ss.str();
// 
//     ROS_INFO("%s", msg.data.c_str());
// 
//     /**
//      * The publish() function is how you send messages. The parameter
//      * is the message object. The type of this object must agree with the type
//      * given as a template parameter to the advertise<>() call, as was done
//      * in the constructor above.
//      */
//     chatter_pub.publish(msg);
// 
//     ros::spinOnce();
// 
//     loop_rate.sleep();
//     ++count;
//   }


  return 0;
}
