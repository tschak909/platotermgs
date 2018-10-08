/********************************************
*
* Marinetti TCP/IP header for ORCA/C
*
* By Mike Westerfield, Byte Works, Inc.
* This file is released to the public domain.
*
********************************************/

#ifndef __TYPES__
#include <TYPES.h>
#endif

/* Various numeric equates */
/*-------------------------*/

#define conEthernet 1					/* Connect methods */
#define conMacIP 2
#define conPPPCustom 3
#define conSLIP 4
#define conTest 5
#define conPPP 6
#define conDirectConnect 7
#define conAppleEthernet 8

#define protocolAll 0					/* Protocols */
#define protocolICMP 1
#define protocolTCP 6
#define protocolUDP 17

#define terrOK 0						/* Tool Error codes */
#define terrBADIPID 0x3601				/* Bad IPID for this request */
#define terrNOCONNECTION 0x3602			/* Not connected to the network */
#define terrNORECONDATA 0x3603			/* No reconnect data */
#define terrLINKERROR 0x3604			/* Problem with the link layer */
#define terrSCRIPTFAILED 0x3605			/* The script failed / timed out */
#define terrCONNECTED 0x3606			/* Not while connected to the network */
#define terrSOCKETOPEN 0x3607			/* Socket still open */
#define terrINITNOTFOUND 0x3608			/* Init not found in memory */
#define terrVERSIONMISMATCH 0x3609		/* Different versions of tool, init, cdev */
#define terrBADTUNETABLELEN 0x360A		/* Bad tune table length */
#define terrIPIDTABLEFULL 0x360B		/* IPID table full */
#define terrNOICMPQUEUED 0x360C			/* No ICMP datagrams in the queue */
#define terrLOGINSPENDING 0x360D		/* There are still IPIDs logged in */
#define terrTCPIPNOTACTIVE gequ	0x360E	/* Not active. Probably in P8 mode. */
#define terrNODNSERVERS 0x360F			/* No servers registered with Marinetti */
#define terrDNRBUSY 0x3610				/* DNR is current busy. Try again later */
#define terrNOLINKLAYER 0x3611			/* Unable to load link layer module */
#define terrBADLINKLAYER 0x3612			/* Not a link layer module */
#define terrENJOYCOKE 0x3613			/* But not so close to the keyboard */
#define terrNORECONSUPPRT 0x3614		/* This module doesn't support reconnect */
#define terrUSERABORTED 0x3615			/* The user aborted the connect/disconnect script */
#define terrBADUSERPASS 0x3616			/* Invalid username and/or password */
#define terrBADPARAMETER 0x3617			/* Invalid parameter for this call */
#define terrBADENVIRONMENT 0x3618		/* No desktop or tools not started */
#define terrNOINCOMING 0x3619			/* There is no pending incoming request */
#define terrLINKBUSY 0x361A				/* Modem or interface is busy */
#define terrNOLINKINTERFACE 0x361B		/* No dial tone or similar */
#define terrNOLINKRESPONSE 0x361C		/* No modem answer or similar */
#define terrNODNRPENDING 0x361D			/* No such entry in DNR list */
#define terrBADALIVEMINUTES 0x361E		/* Minutes value is invalid */
#define terrBUFFERTOOSMALL 0x361F		/* Buffer is too small */
#define terrNOTSERVER 0x3620			/* This ipid is not set up as a server */

#define terrmask 0x00FF

										/* DNR status codes
#define DNR_Pending 0					/* Request still being processed */
#define DNR_OK 1						/* Request completed successfully */
#define DNR_Failed 2					/* Network error/timeout */
#define DNR_NoDNSEntry 3				/* Requested domain has no DNS entry */
#define DNR_Cancelled 4					/* Cancelled by user */

										/* TCP logic errors */
#define tcperrOK 0						/* "tcperr" error codes from TCP RFC */
#define tcperrDeafDestPort 1
#define tcperrHostReset 2
#define tcperrConExists 3				/* "connection already exists" */
#define tcperrConIllegal 4				/* "connection illegal for this process" */
#define tcperrNoResources 5				/* "insuficient resources" */
#define tcperrNoSocket 6				/* "foreign socket unspecified" */
#define tcperrBadPrec 7					/* "precedence not allowed" */
#define tcperrBadSec 8					/* "security/compartment not allowed" */
#define tcperrBadConnection 9			/* "connection does not exist" */
#define tcperrConClosing 10				/* "connection closing" */
#define tcperrClosing 11				/* "closing" */
#define tcperrConReset 12				/* "connection reset" */
#define tcperrUserTimeout 13			/* "connection aborted due to user timeout" */
#define tcperrConRefused 14				/* "connection refused" */

#define TCPSCLOSED 0					/* TCP states */
#define TCPSLISTEN 1
#define TCPSSYNSENT 2
#define TCPSSYNRCVD 3
#define TCPSESTABLISHED 4
#define TCPSFINWAIT1 5
#define TCPSFINWAIT2 6
#define TCPSCLOSEWAIT 7
#define TCPSLASTACK 8
#define TCPSCLOSING 9
#define TCPSTIMEWAIT 10
#define nTCPSTATES 11


#define TCPIPSaysHello 0x8101
#define TCPIPSaysNetworkUp 0x8102
#define TCPIPSaysNetworkDown 0x8103

/* Miscellaneous datagram header equates */
/*---------------------------------------*/
/* ICMP types - TCP_TYPE - Comer/Steven, vol II, p128 */

#define ICT_ECHORP 0
#define ICT_DESTUR 3
#define ICT_SRCQ 4
#define ICT_REDIRECT 5
#define ICT_ECHORQ 8
#define ICT_TIMEX 11
#define ICT_PARAMP 12
#define ICT_TIMERQ 13
#define ICT_TIMERP 14
#define ICT_INFORQ 15
#define ICT_INFORP 16
#define ICT_MASKRQ 17
#define ICT_MASKRP 18
#define ictmax 19
                                                                                       
#define ICC_NETUR 0						/* p128, Internetworking with TCP/IP Vol 2. */
#define ICC_HOSTUR 1					/*       Design Implementation, and Internals */
#define ICC_PROTOUR 2					/*       Douglas E. Comer / David L. Stevens */
#define ICC_PORTUR 3
#define ICC_FNADF 4
#define ICC_SRCRT 5
#define ICC_NETRD 0
#define ICC_HOSTRD 1
#define IC_TOSNRD 2
#define IC_TOSHRD 3
#define ICC_TIMEX 0
#define ICC_FTIMEX 1
#define IC_HLEN 8
#define IC_PADLEN 3
#define IC_RDTTL 300

										/* UDP standard port numbers */
#define UP_ECHO 7						/* echo server */
#define UP_DISCARD 9					/* discard packet */
#define UP_USERS 11						/* users server */
#define UP_DAYTIME 13					/* day and time server */
#define UP_QOTD 17						/* quote of the day server */
#define UP_CHARGEN 19					/* character generator */
#define UP_TIME 37						/* time server */
#define UP_WHOIS 43						/* who is server (user information) */
#define UP_DNAME 53						/* domain name server */
#define UP_TFTP 69						/* trivial file transfer protocol server */
#define UP_RWHO 513						/* remote who server (ruptime) */
#define UP_RIP 520						/* route information exchange (RIP) */

#define ip_verlen 0						/* IP header */
#define ip_tos 1
#define ip_len 2
#define ip_id 4
#define ip_fragoff 6
#define ip_ttl 8
#define ip_proto 9						/* protocol */
#define ip_cksum 10
#define ip_src 12
#define ip_dst 16
#define ip_data 20

										/* ICMP header */
#define ic_type 0						/* ICT_* */
#define ic_code 1						/* ICC_* */
#define ic_cksum 2
#define ic_data 4
#define ic_echo_id 4					/* Echo Offsets */
#define ic_echo_seq 6

										/* UDP header */
#define u_source 0						/* source UDP port number - UP_* */
#define u_dst 2							/* destination UDP port number */
#define u_len 4							/* length of UDP data */
#define u_cksum 6						/* UDP checksum (0 = none) */
#define u_data 8

										/* TCP header*/
#define tcp_sport 0						/* source port - TCP_* */
#define tcp_dport 2						/* destination port */
#define tcp_seq 4						/* sequence number */
#define tcp_ack 8						/* acknowledgement number */
#define tcp_offset 12					/* longword count in header (def=6) */
#define tcp_code 13						/* flags */
#define tcp_window 14					/* window advertisement */
#define tcp_cksum 16					/* checksum */
#define tcp_urgptr 18					/* urgent pointer */
#define tcp_options 20
#define tcp_data 20

/* Types */
/*-------*/

typedef struct {
	long tcpDGMSTBLEN;				/* The total length of the error table, in bytes, including tcpDGMSTBLEN */

	long tcpDGMSTOTAL;				/* Total datagrams received (good and bad) */
	long tcpDGMSFRAGSIN;			/* Got a fragment (datagram is queued to frag list) */
	long tcpDGMSFRAGSLOST;			/* Fragment purged after timeout in queue */
	long tcpDGMSBUILT;				/* Built a datagram from fragments (is then queued) */

	long tcpDGMSOK;					/* Datagrams queued from link or tcpDGMSBUILT */

	long tcpDGMSBADCHK;				/* Bad IP checksum (datagram is purged) */
	long tcpDGMSBADHEADLEN;			/* Bad IP header lengths (datagram is purged) */
	long tcpDGMSBADPROTO;			/* Unsupported protocols (added to misc queue) */
	long tcpDGMSBADIP;				/* Not my or loopback IP (datagram is purged) */

	long tcpDGMSICMP;				/* ICMP total datagrams in (good and bad) */
	long tcpDGMSICMPUSER;			/* ICMP user datagrams */
	long tcpDGMSICMPKERNEL;			/* ICMP kernel datagrams */

	long tcpDGMSICMPBAD;			/* ICMP bad checksum or datagram too short */
	long tcpDGMSICMPBADTYPE;		/* ICMP bad ic_type */
	long tcpDGMSICMPBADCODE;		/* ICMP bad ic_code */
	long tcpDGMSICMPECHORQ;			/* ICMP ECHORQs in */
	long tcpDGMSICMPECHORQOUT;		/* ICMP ECHORQ replies sent out */
	long tcpDGMSICMPECHORP;			/* ICMP ECHORPs in */
	long tcpDGMSICMPECHORPBADID;	/* ICMP ECHORPs unclaimed */

	long tcpDGMSUDP;				/* UDPs OK (added to UDP queue) */
	long tcpDGMSUDPBAD;				/* Bad UDP header (datagram is purged) */
	long tcpDGMSUDPNOPORT;			/* No such logged in port (datagram is purged) */

	long tcpDGMSTCP;				/* TCPs OK (returned to TCP main logic) */
	long tcpDGMSTCPBAD;				/* Bad TCP header or checksum (datagram is purged) */
	long tcpDGMSTCPNOPORT;			/* No such logged in port (datagram is purged) */
	long tcpDGMSTCPQUEUED;			/* Arrived before required (datagram is queued) */
	long tcpDGMSTCPOLD;				/* Already received this segment (datagram is purged) */

	long tcpDGMSOFRAGMENTS;			/* Fragments transmitted */
	long tcpDGMSFRAGMENTED;			/* Datagrams fragmented for transmission */
    } errTable, *errTablePtr;

typedef struct {						/* tuning table */
	Word tcpTUNECOUNT;			/* The total length of the tuning table, in
    							   bytes, including tcpTUNECOUNT. Currently 10.
                                */
    Word tcpTUNEIPUSERPOLLCT;	/* The number of datagrams Marinetti will build
    							   per TCPIPPoll request. The valid range is 1
                                   through 10 inclusive. The default is 2. */
    Word tcpTUNEIPRUNQFREQ;		/* The RunQ frequency value (60ths of a second).
    							   The default is 30 (half a second). */
	Word tcpTUNEIPRUNQCT;		/* The number of datagrams Marinetti will build
    							   per RunQ dispatch. The valid range is 1
                                   through 10 inclusive. The default is 2. */
	Word tcpTUNETCPUSERPOLL;	/* The TCP steps to perform per user, per
    							   TCPIPPoll request and RunQ dispatch. The
                                   valid range is 1 through 10 inclusive. The
                                   default is 2. */
	} tuneStruct, *tunePtr;

typedef struct {
    Byte length;
    char name[50];
    } username, *usernamePtr;

typedef struct {
    Byte length;
    char name[50];
    } password, *passwordPtr;

typedef struct {
    Byte length;
    char name[50];
    } hostName, *hostNamePtr;

typedef struct {
	Word liMethodID;		/* The connect method. See the conXXX equates at the end of this document */
    char liName[21];		/* Pstring name of the module */
    Long liVersion;			/* rVersion (type 0x8029 resource layout) of the module */
    Word liFlags;			/* Contains the following flags:
								bit 15 This link layer uses the built in Apple IIGS serial ports
								bits 14-0 Reserved - set to zeros */
	char liFilename[16];	/* Pstring filename of the module */
	Byte liMenuItem[14];	/* bytes rMenuItem template ready for use, which defines this connect method as a menu item */
    } module, (*moduleListPtr)[];

typedef struct {
	Word liMethodID;		/* The connect method. New modules will need to apply to the author for a unique ID to use. See conXXX equates for details of already defined values */
    char liName[21];		/* Pstring name of the module */
    Long liVersion;			/* rVersion (type 0x8029 resource layout) of the
                               module */
    Word liFlags;			/* Contains the following flags:
                                  bit15 This link layer uses the built in Apple
                                      IIGS serial ports
                                  bits14-1 Reserved - set to zeros
                                  bit0 Indicates whether the module contains an
                                      rIcon resource */
    } linkInfoBlk, *linkInfoBlkPtr;

typedef struct {
	Long DNSMain;			/* Main DNS IP address */
    Long DNSAux;			/* Auxilliary DNS IP address */
    } DNSRec, *DNSRecPtr;

typedef struct {
	Word DNRstatus;			/* Current status of DNR for this request */
	Long DNRIPaddress;		/* Returned IP address */
	} dnrBuffer, *dnrBufferPtr;

typedef struct {
	Word uvQueueSize;		/* Number of entries in receive queue */
    Word uvError;			/* Last ICMP type 3 error code */
    Long uvErrorTick;		/* Tick of when error occurred */
    Long uvCount;			/* Total received for this ipid */
    Long uvTotalCount;		/* Total received for all ipids */
    Word uvDispatchFlag;	/* UDP dispatch flag */
    } udpVars, *udpVarsPtr;

typedef struct {
    Long rrBuffCount;		/* Length of the returned data */
    Handle rrBuffHandle;	/* Handle to the data */
    Word rrMoreFlag;		/* Is there more data received? */
    Word rrPushFlag;		/* word Was this buffer pushed? */
    Word rrUrgentFlag;		/* Is this urgent data? */
    } rrBUff, *rrBuffPtr;

typedef struct {
    Long rlrBuffCount;      /* Length of the returned data */
    Handle rlrBuffHandle;	/* Handle to the data */
    Word rlrIsDataFlag;		/* Was a line actually read? */
    Word rlrMoreFlag;		/* Is there more data received? */
    Long rlrBuffSize;		/* Required buffer size */
    } rlrBuff, *rlrBuffPtr;

typedef struct {
    Word srState;			/* TCP state */
    Word srNetworkError;	/* ICMP error code */
    Long srSndQueued;		/* Bytes left in send queue */
    Long srRcvQueued;		/* Bytes left in receive queue */
    Long srDestIP;			/* Destination IP address */
    Word srDestPort;		/* Destination port */
    Word srConnectType;		/* Connection type */
    Word srAcceptCount;		/* If in listen mode, number of pending incoming
                               requests */
    } srBuff, *srBuffPtr;

typedef struct {
	Word drUserID;			/* UserID used by this ipid */
    Long drDestIP;			/* Destination IP address */
    Word drDestPort;		/* Destination port number */
    } destRec, *destRecPtr;

typedef struct {
	Long cvtIPAddress;		/* Returned IP address */
    Word cvtPort;			/* word Port number or nil if none */
    } cvtRec, *cvtRecPtr;

typedef struct {
	Word inwLength;			/* Length of buffer, including this, is $000E */
    Long inwIP;				/*  Your IP address */
    Word inwMethod;			/* The connect method currently being used */
    Word inwMTU;			/* The MTU currently being used */
    Long inwLVPtr;			/*  longword Pointer to link layer variables currently being used */
    } variablesStruct, *variablesPtr;

typedef void (*displayPtr)(char *);

typedef Handle conHandle;
typedef Handle disconHandle;  
typedef ptr messagePtr;
typedef ptr udpPtr;
typedef ptr datagramPtr;
typedef Handle dgmHandle;
typedef ptr dataPtr;

/* Tool calls */
/*------------*/

extern pascal void TCPIPBootInit (void) inline(0x0136,dispatcher);
extern pascal void TCPIPStartUp (void) inline(0x0236,dispatcher);
extern pascal void TCPIPShutDown (void) inline(0x0336,dispatcher);
extern pascal Word TCPIPVersion (void) inline(0x0436,dispatcher);
extern pascal void TCPIPReset (void) inline(0x0536,dispatcher);
extern pascal Boolean TCPIPStatus (void) inline(0x0636,dispatcher);
extern pascal Long TCPIPLongVersion (void) inline(0x0836,dispatcher);
extern pascal Boolean TCPIPGetConnectStatus (void) inline(0x0936,dispatcher);
extern pascal errTablePtr TCPIPGetErrorTable (void) inline(0x0A36,dispatcher);
extern pascal Boolean TCPIPGetReconnectStatus (void) inline(0x0B36,dispatcher);
extern pascal displayPtr TCPIPReconnect (void) inline(0x0C36,dispatcher);
extern pascal Long TCPIPGetMyIPAddress (void) inline(0x0F36,dispatcher);
extern pascal Word TCPIPGetConnectionMethod (void) inline(0x1036,dispatcher);
extern pascal void TCPIPSetConnectionMethod (Word) inline(0x1136,dispatcher);
extern pascal displayPtr TCPIPConnect (void) inline(0x1236,dispatcher);
extern pascal void TCPIPDisconnect (Boolean, displayPtr) inline(0x1336,dispatcher);
extern pascal Word TCPIPGetMTU (void) inline(0x1436,dispatcher);
extern pascal conHandle TCPIPGetConnectData (Word, Word) inline(0x1636,dispatcher);
extern pascal void TCPIPSetConnectData (Word, conHandle) inline(0x1736,dispatcher);
extern pascal disconHandle TCPIPGetDisconnectData (Word, Word) inline(0x1836,dispatcher);
extern pascal void TCPIPSetDisconnectData (Word, disconHandle) inline(0x1936,dispatcher);
extern pascal void TCPIPLoadPreferences (void) inline(0x1A36,dispatcher);
extern pascal void TCPIPSavePreferences (void) inline(0x1B36,dispatcher);
extern pascal tunePtr TCPIPGetTuningTable (void) inline(0x1E36,dispatcher);
extern pascal void TCPIPSetTuningTAble (tunePtr) inline(0x1F36,dispatcher);
extern pascal Boolean TCPIPGetConnectMsgFlag (void) inline(0x4236,dispatcher);
extern pascal void TCPIPSetConnectMsgFlag (Boolean) inline(0x4336,dispatcher);
extern pascal usernamePtr TCPIPGetUsername (void) inline(0x4436,dispatcher);
extern pascal void TCPIPSetUsername (usernamePtr) inline(0x4536,dispatcher);
extern pascal passwordPtr TCPIPGetPassword (void) inline(0x4636,dispatcher);
extern pascal void TCPIPSetPassword (passwordPtr) inline(0x4736,dispatcher);
extern pascal variablesPtr TCPIPGetLinkVariables (void) inline(0x4A36,dispatcher);
extern pascal void TCPIPEditLinkConfig (Handle, Handle) inline(0x4B36,dispatcher);
extern pascal void TCPIPGetModuleNames (ModuleListPtr) inline(0x4C36,dispatcher);
extern pascal hostNamePtr TCPIPGetHostName (void) inline(0x5136,dispatcher);
extern pascal void TCPIPSetHostName (hostNamePtr) inline(0x5236,dispatcher);
extern pascal linkInfoBlkPtr TCPIPGetLinkLayer (void) inline(0x5436,dispatcher);
extern pascal handle TCPIPGetAuthMessage (Word) inline(0x5736,dispatcher);
extern pascal Boolean TCPIPGetAliveFlag (void) inline(0x5A36,dispatcher);
extern pascal void TCPIPSetAliveFlag (Boolean) inline(0x5B36,dispatcher);
extern pascal Word TCPIPGetAliveMinutes (void) inline(0x5C36,dispatcher);
extern pascal void TCPIPSetAliveMinutes (Word) inline(0x5D36,dispatcher);
extern pascal Boolean TCPIPGetBootConnectFlag (void) inline(0x5F36,dispatcher);
extern pascal void TCPIPSetBootConnectFlag (Boolean) inline(0x6036,dispatcher);
extern pascal DNSRecPtr TCPIPGetDNS (void) inline(0x1C36,dispatcher);
extern pascal void TCPIPSetDNS (DNSRecPtr) inline(0x1D36,dispatcher);
extern pascal void TCPIPCancelDNR (dnrBufferPtr) inline(0x2036,dispatcher);
extern pascal void TCPIPDNRNameToIP (char *, dnrBufferPtr) inline(0x2136,dispatcher);
extern pascal void TCPIPPoll (void) inline(0x2236,dispatcher);
extern pascal void TCPIPSendIPDatagram (datagramPtr) inline(0x4036,dispatcher);
extern pascal Word TCPIPLogin (Word, Long, Word, Word, Word) inline(0x2336,dispatcher);
extern pascal void TCPIPLogout (Word) inline(0x2436,dispatcher);
extern pascal void TCPIPSendICMP (Word, messagePtr, Word) inline(0x2536,dispatcher);
extern pascal void TCPIPSendUDP (Word, udpPtr, Word) inline(0x2636,dispatcher);
extern pascal Word TCPIPGetDatagramCount (Word, Word) inline(0x2736,dispatcher);
extern pascal dgmHandle TCPIPGetNextDatagram (Word, Word, Word) inline(0x2836,dispatcher);
extern pascal Word TCPIPGetLoginCount (void) inline(0x2936,dispatcher);
extern pascal void TCPIPSendICMPEcho (Word, Word) inline(0x2A36,dispatcher);
extern pascal Word TCPIPReceiveICMPEcho (Word) inline(0x2B36,dispatcher);
extern pascal void TCPIPStatusUDP (Word, udpVarsPtr) inline(0x5336,dispatcher);
extern pascal void TCPIPSetUDPDispatch (Word, Boolean) inline(0x6136,dispatcher);
extern pascal Word TCPIPOpenTCP (Word) inline(0x2C36,dispatcher);
extern pascal Word TCPIPListenTCP (Word) inline(0x4E36,dispatcher);
extern pascal Word TCPIPWriteTCP (Word, dataPtr, Long, Boolean, Boolean)
                       inline(0x2D36,dispatcher);
extern pascal Word TCPIPReadTCP (Word, Word, Ref, Long, rrBuffPtr) inline(0x2E36,dispatcher);
extern pascal Word TCPIPReadLineTCP (Word, char *, Word, Ref, Long, rlrBuffPtr)
                       inline(0x5E36,dispatcher);
extern pascal Word TCPIPCloseTCP (Word) inline(0x2F36,dispatcher);
extern pascal Word TCPIPAbortTCP (Word) inline(0x3036,dispatcher);
extern pascal Word TCPIPStatusTCP (Word, srBuffPtr) inline(0x3136,dispatcher);
extern pascal Word TCPIPAcceptTCP (Word, Word) inline(0x4F36,dispatcher);
extern pascal Word TCPIPGetSourcePort (Word) inline(0x3236,dispatcher);
extern pascal Word TCPIPGetTOS (Word) inline(0x3336,dispatcher);
extern pascal void TCPIPSetTOS (Word, Word) inline(0x3436,dispatcher);
extern pascal Word TCPIPGetTTL (Word) inline(0x3536,dispatcher);
extern pascal void TCPIPSetTTL (Word, Word) inline(0x3636,dispatcher);
extern pascal void TCPIPSetSourcePort (Word, Word) inline(0x3736,dispatcher);
extern pascal Long TCPIPGetUserStatistic (Word, Word) inline(0x4936,dispatcher);
extern pascal void TCPIPSetNewDestination (Word, Long, Word) inline(0x5036,dispatcher);
extern pascal void TCPIPGetDestination (Word, destRecPtr) inline(0x6236,dispatcher);

extern pascal void TCPIPConvertIPToHex (cvtRecPtr, char *) inline(0x0D36,dispatcher);
extern pascal void TCPIPConvertIPCToHex (cvtRecPtr, char *) inline(0x3F36,dispatcher);
extern pascal Word TCPIPConvertIPToASCII (Long, char *, Word) inline(0x0E36,dispatcher);
extern pascal Word TCPIPConvertIPToCASCII (Long, char *, Word) inline(0x5836,dispatcher);
extern pascal Word TCPIPConvertIPToClass (Long) inline(0x4136,dispatcher);
extern pascal Word TCPIPMangleDomainName (Word, char *) inline(0x5936,dispatcher);
extern pascal void TCPIPPtrToPtr (ptr, ptr, Long) inline(0x5536,dispatcher);
extern pascal void TCPIPPtrToPtrNeg (ptr, ptr, Long) inline(0x5636,dispatcher);
extern pascal Word TCPIPValidateIPString (char *) inline(0x4836,dispatcher);
extern pascal Word TCPIPValidateIPCString (char *) inline(0x1536,dispatcher);
