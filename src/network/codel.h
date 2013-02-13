#ifndef CODEL_HH
#define CODEL_HH

#include <math.h>
#include "ingress-queue.h"
#include "tracked-packet.h"

/* Class to Implement CoDel */
class CoDel {
  private :

    /* CoDel specific structure */
    typedef struct {
         TrackedPacket p; 
         bool ok_to_drop;
    } dodeque_result; 

    /* Ingress Queue */
    IngressQueue & _queue;

    /* Codel - specific parameters */
    static const uint64_t    target=5 ;    /* 5   ms as per the spec */
    static const uint64_t  interval=100;   /* 100 ms as per the spec */
    static const uint16_t maxpacket=1500;    /* MTU of the link */
  
    /* Codel - specific tracker variables */
    uint64_t first_above_time;
    uint64_t drop_next;
    uint32_t count;
    bool     dropping;
    uint32_t _bytes_in_queue;
    uint32_t drop_count; /* for statistics */

    /* Codel - control rule */
    uint64_t control_law (uint64_t t) { return t + interval/sqrt(count);}

    /* Main codel routines */
    dodeque_result dodeque ( void );
    void drop ( TrackedPacket p);

    /* Number of bytes in queue */
    uint32_t bytes( void ) { return _queue.total_length(); };
    
  public :
    CoDel( IngressQueue & queue );
    /* Interface to the outside world */
    void enque( std::string payload );
    TrackedPacket deque ( void ); 

};

#endif
