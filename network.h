#ifndef __NETWORK_H__
#define __NETWORK_H__

#include <event2/event.h>
#include <event2/event_struct.h>
#include <event2/dns.h>
#include <event2/http.h>
#include <event2/http_struct.h>

#include "utp.h"
#include "dht.h"


#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define lenof(x) (sizeof(x)/sizeof(x[0]))
#define alloc(type) calloc(1, sizeof(type))


typedef struct event_base event_base;
typedef struct evdns_base evdns_base;
typedef struct event event;
typedef struct evhttp evhttp;
typedef struct evbuffer evbuffer;
typedef struct bufferevent bufferevent;
typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr_storage sockaddr_storage;
typedef in_port_t port_t;

typedef struct {
    event_base *evbase;
    evdns_base *evdns;
    int fd;
    event udp_event;
    utp_context *utp;
    dht *dht;
    evhttp *http;
} network;

network* network_setup(char *address, port_t port);
int network_loop(network *n);

#endif // __NETWORK_H__
