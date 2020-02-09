#include "../include/simulator.h"
#include <stdio.h>
#include <string.h>
/* ******************************************************************
 ALTERNATING BIT AND GO-BACK-N NETWORK EMULATOR: VERSION 1.1  J.F.Kurose

   This code should be used for PA2, unidirectional data transfer
   protocols (from A to B). Network properties:
   - one way network delay averages five time units (longer if there
     are other messages in the channel for GBN), but can be larger
   - packets can be corrupted (either the header or the data portion)
     or lost, according to user-defined probabilities
   - packets will be delivered in the order in which they were sent
     (although some can be lost).
**********************************************************************/

/********* STUDENTS WRITE THE NEXT SEVEN ROUTINES *********/

int seqnumA;
int seqnumB;
int acknumA;
int acknumB;

struct msg* buffer[1000];

int nextseqnum= 1;
int base = 1;

 int calc_checksum(struct pkt* packet){
  int sum = packet->seqnum;
  sum += packet->acknum;
  for(int i=0;i<20;i++){
    sum = sum + packet->payload[i];
  }
  return sum;
}

//fil in packet info
static pkt* make_packet(int nextseqnum, int nextack, char* message){
  struct pkt* packet = new pkt();
  packet->seqnum = nextseqnum;
  packet->acknum = nextack;
  for(int i=0; i<20;i++){
    packet->payload[i]=message[i];
  }
  packet->checksum = calc_checksum(packet);
  return packet;
}

/* called from layer 5, passed the data to be sent to other side */
void A_output(struct msg message) {
  //add message to buffer
  struct msg* m = new msg();
  for(int i=0; i<20;i++){
    m->data[i]=message.data[i];
  }
  buffer[nextseqnum] = m;
  //send packet
  if (nextseqnum == base) {
    struct pkt* packet = make_packet(base, acknumA, buffer[nextseqnum]->data);
    tolayer3(0, *packet);
    starttimer(0, 23.0); //timeout is at minimum double the RTT (10*2=20)
  }
  nextseqnum++;
}

/* called from layer 3, when a packet arrives for layer 4 */
void A_input(struct pkt packet) {
    if (packet.checksum != calc_checksum(&packet)) {
    return;
  }//corrupt
  acknumA = packet.seqnum;
  base = packet.acknum + 1;
  stoptimer(0); //restart timer
  if (base < nextseqnum) {
    struct pkt* packet = make_packet(base, acknumA, buffer[base]->data);
    tolayer3(0, *packet);
    starttimer(0, 23.0);
  }
}

/* called when A's timer goes off */
//retransmit packet
void A_timerinterrupt() {
  struct pkt* packet = make_packet(base, acknumA, buffer[base]->data);
  tolayer3(0, *packet);
  starttimer(0, 23.0);
}

/* the following routine will be called once (only) before any other */
/* entity A routines are called. You can use it to do any initialization */
void A_init() {
  seqnumA = 1;
  acknumA = 1;
}

/* called from layer 3, when a packet arrives for layer 4 at B*/
void B_input(struct pkt packet) {
  if (packet.checksum != calc_checksum(&packet)) {
    return;
  }
  char message[20];
  for(int i=0; i<20;i++){
    message[i]= packet.payload[i];
  }
  //receive a packet and send ack
  if(packet.seqnum >= seqnumB){
    acknumB = packet.seqnum;
    seqnumB = packet.acknum + 1;
    struct pkt *ack = make_packet(seqnumB, acknumB, packet.payload);
    tolayer3(1, *ack);
    tolayer5(1, packet.payload);
  }

}

/* the following rouytine will be called once (only) before any other */
/* entity B routines are called. You can use it to do any initialization */
void B_init(){
    seqnumB = 1;
    acknumB = 1;
}
