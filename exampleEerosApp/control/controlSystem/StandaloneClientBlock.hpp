#ifndef ORG_EEROS_CONTROL_STANDALONE_CLIENT_BLOCK_HPP_
#define ORG_EEROS_CONTROL_STANDALONE_CLIENT_BLOCK_HPP_

#include <eeros/control/Block.hpp>
#include <eeros/core/System.hpp>

#include <iostream>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>      /* inet_ntoa() to format IP address */
#include <iostream>
#include <array>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>


template< typename T = double >
class StandaloneClientBlock : public eeros::control::Block {
public:
	StandaloneClientBlock(char* ip, int port) :
	server_ip (ip),
// 	server_ip ((char*)ip),
	port(port)
	{
		out0.getSignal().clear();
		out1.getSignal().clear();
		out2.getSignal().clear();
		
		
		sockfd = socket(AF_INET, SOCK_STREAM, 0);
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
		
		
	}
	
	virtual void run() override {
		auto time = eeros::System::getTimeNs();
		this->out0.getSignal().setTimestamp(time);
		this->out1.getSignal().setTimestamp(time);
		this->out2.getSignal().setTimestamp(time);
		
		
// 		// 1. WRITE
// 		std::cout << "w: ";
// 		for (int i = 0; i < sizeof(writeBuf)/sizeof(writeBuf[0]); i++) {
// 			writeBuf[i] = dataToSend;
// 			dataToSend += 0.1;
// 			std::cout << writeBuf[i] << "\t";
// 		}
// 		std::cout << std::endl;
// 		n = write(sockfd, writeBuf, sizeof(writeBuf));
// 		if (n < 0) std::cout << "ERROR writing to socket" << std::endl;
		
		// 2. READ
		n = read(sockfd, readBuf, sizeof(readBuf));
		if (n < 0) std::cout << "ERROR reading from socket" << std::endl;
		
		std::cout << "rec: ";
		for (int i = 0; i < sizeof(readBuf)/sizeof(readBuf[0]); i++) {
			std::cout << readBuf[i] << "\t";
		}
		std::cout << std::endl;
		
		
		
		this->out0.getSignal().setValue(readBuf[0]);
		this->out1.getSignal().setValue(readBuf[1]);
		this->out2.getSignal().setValue(readBuf[2]);
	}
	
	char* server_ip;
	int port;
	struct sockaddr_in serv_addr;
	
	double readBuf[3];
	double writeBuf[6]; 
	int n;
	int sockfd;
	
	double dataToSend = 0.1;
			
	virtual eeros::control::Output<T>& getOut0() {	return out0;	}
	virtual eeros::control::Output<T>& getOut1() {	return out1;	}
	virtual eeros::control::Output<T>& getOut2() {	return out2;	}
	
protected:
	eeros::control::Output<T> out0;
	eeros::control::Output<T> out1;
	eeros::control::Output<T> out2;
	
};


#endif /* ORG_EEROS_CONTROL_STANDALONE_CLIENT_BLOCK_HPP_ */