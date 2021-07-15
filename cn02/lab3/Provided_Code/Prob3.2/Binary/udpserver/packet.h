#ifndef PACKET_H
#define PACKET_H

#define JOIN_REQ    1
#define PASS_REQ    2
#define PASS_RESP   3
#define PASS_ACCEPT 4
#define DATA        5
#define TERMINATE   6
#define REJECT      7

typedef struct ctrl_msg_packet{
    short header;
    unsigned int len_payload;
} CTRL_MSG_PACKET;

typedef struct pass_resp_packet{
    short header;
    unsigned int len_payload;
    char password[50];
} PASS_RESP_PACKET;

typedef struct terminate_packet{
    short header;
    unsigned int len_payload;
    char digest[20];
} TERMINATE_PACKET;

typedef struct data_packet{
    short header;
    unsigned int len_payload;
    int id;
    char data[1000];
} DATA_PACKET;

typedef union {
    CTRL_MSG_PACKET     ctrl_msg;
    PASS_RESP_PACKET    pass_resp;
    TERMINATE_PACKET    terminate;
    DATA_PACKET         data;
} Packets;

#endif // PACKET_H
