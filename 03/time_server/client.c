#define _POSIX_C_SOURCE 200809L

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#include "message.h"

void err(char *msg)
{
  perror(msg);
  exit(EXIT_FAILURE);
}

// create a new socket
int createSocket()
{
  return socket(PF_INET, SOCK_STREAM, 0);
}

// connect given socket soc to server at "localhost" on port "2342"
void connectToTimeServer(int soc)
{

  struct addrinfo hints, *res; //aus Tut


  getaddrinfo("localhost", "2342", &hints, &res);

  if(connect(soc, res->ai_addr, res->ai_addrlen)){ //aus bjees
    err("no connect");
  }else{

  }
}

// send time request message to the server
void sendTimeRequest(int soc, const time_request_t* timeRequest)
{

  send(soc, timeRequest, sizeof(timeRequest), 1);
}

// receive time respond message from the server and store it in timeRespond
void receiveTimeRespond(int soc, time_respond_t* timeRespond)
{
  char* s;

  s = (char*) recv(soc, timeRespond, sizeof(timeRespond), 1);
  printf("%s\n", s);
}

int main(void)
{
  int soc = createSocket();
  connectToTimeServer(soc);

  time_request_t timeRequest;
  time_respond_t timeRespond;

  timeRequest.timezone = +1; // CET
  sendTimeRequest(soc, &timeRequest);

  receiveTimeRespond(soc, &timeRespond);
  printf("Current time in Münster: %s", timeRespond.time);


  timeRequest.timezone = -5; // EST
  sendTimeRequest(soc, &timeRequest);

  receiveTimeRespond(soc, &timeRespond);
  printf("Current time in New York: %s", timeRespond.time);


  // send disconnect message
  timeRequest.timezone = 127; // magic number
  sendTimeRequest(soc, &timeRequest);

  close(soc);
}
