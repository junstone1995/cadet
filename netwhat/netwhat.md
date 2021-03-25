## What is an IP address

네트워킹이 가능한 장비를 식별하는 주소  
네트워킹 하는 장비들에게 숫자 12개의 고유한 주소를 줌  

* IPv4 (132.321.456.789) : 약 40억개 주소가 존재할 수 있도록 설계  

  ​	한 사람이 가지는 네트워킹이 가능한 단말기 수가 늘어남에 따라 40억개가 부족해짐  

* IPv6 (21DA:00D3:0000:2F3B:02AA:00FF:FE28:9C5A) : 2의 128제곱개수  
  	IPv4보다 보안적인 부분도 뛰어나고 여러면에서 뛰어난 ip주소체계  

## What is a Netmask

네트워크 주소 부분의 비트를 1로 치환한것이 넷 마스크 

IP 주소와 넷 마스크를 AND 연산하면 네트워크 주소를 얻을 수 있다.  

기본 서브넷 마스크 : 255.255.255.0

Subnet mask (/8) : 255.0.0.0

Subnet mask (/16) : 255.255.0.0

Subnet mask (/24) : 255.255.255.0

## What is the subnet of an IP with Netmask

* 네트워크 주소

  하나의 네트워크를 통칭하기 위한 주소

  해당 네트워크의 첫번째 IP 주소

  계산 방벙 : IP 주소와 서브넷마스크의 AND연산

* 브로드캐스트 주소

  특정 네트워크에 속하는 모든 호스트들이 갖게 되는 주소

  해당 네트워크에 속하는 모든 IP 주소 가운데 맨 마지막 IP 주소

  계산방벙 : 서브넷 마스크의 '0'인 부분을 모두 1로 바꾼다.

## What is the broadcast address of a subnet

* 특정 네트워크에 속하는 모든 호스트들이 듣게되는 주소를 의미

예) C 클래스 하나로 특정 네트워크를 구성하였고 네트워크 주소가 192.168.2.0 이라 한다면 브로드캐스트 주소는 192.168.2.255 가 된다.

broadcast 주소는 network 내의 모든 device들과 통신하기 위해 사용된다.

DHCP server로부터 IP주소를 요청하는 host가 사용된다. 

## What are the different ways to represent an IP address with the Netmask



## What are the differenes between public and private IPs

1. Public IP(공인 IP)

   인터넷 사용자의 로컬 네트워크를 식별하기 위해 ISP(인터넷 서비스 공급자)가 제공하는 IP주소

   * Public IP는 전세계에서 유일한 IP 주소를 갖는다.
   * Public IP 주소가 외부에 공개되어 있기에 인터넷에 연결된 다른 PC로부터의 접근이 가능하다.

2. Private IP(사설 IP)

   * 일반 가정이나 회사 내 등에 할당된 네트워크의 IP 주소이며 , 로컬 IP

   * 사설 IP 주소 구역

     Class A : 10.0.0.0 ~ 10.255.255.255

     Class B : 172.16.0.0 ~ 172.31.255.255

     Class C : 192.168.0.0 ~ 192.168.255.255

   * 사설 IP와 공인 IP의 차이

     | ㅇ        | Public IP                     | Private IP                  |
     | --------- | ----------------------------- | --------------------------- |
     | 할당 주체 | ISP(인터넷 서비스 공급자)     | 라우터(공유기)              |
     | 할당 대상 | 개인 또는 회사의 서버(라우터) | 개인 또는 회사의 기기       |
     | 고유성    | 인터넷 상에서 유일한 주소     | 하나의 네트워크 안에서 유일 |
     | 공개 여부 | 내/외부 접근 가능             | 외부 접근 불가능            |

   * 고정 IP 와 유동 IP

     고정 IP는 컴퓨터에 고정적으로 부여된 IP로 한번 부여되면 IP를 반납하기 전까지는 다른 장비에 부여할 수 없는 IP 주소를 말한다.

     유동 IP는 장비에 고정적으로 IP를 부여하지 않고 컴퓨터를 사용할 때 남아 있는 IP 중에서 돌아가면서 부여하는 IP를 뜻한다.

     **인터넷 상에서 서버를 운영하고자 할 때는 공인 IP를 고정 IP로 부여해야 한다는 것이 중요하다.**

## What is a class of IP addresses

네트워크를 효율적으로 운영하기 위해 하나의 network에 필요한 hosts의 개수에 따라 A,B,C,D,E 의 총 다섯 개의 class로 IP 계층을 나누어 사용한다.

#### Class A 주소

1st octec의 첫 bit는 0이다. 따라서 첫 octet 값의 범위는 1~127(0000 0001 ~ 0111 1111)이 된다. 하지만 127.x.x.x는 loopback IP 주소들로 사용하기 때문에, Class A에 속한 IP 주소는 1.x.x.x ~ 126.x.x.x의 값을 갖게 된다.

Class A IP 주소에 사용되는 default subnet mask는 255.0.0.0이다. 128(2^7)개의 네트워크와 16777214(2^24 - 2)개의 호스트가 있다.

#### Class B 주소

최상위 2bits가 10으로 구성된 주소이다. default subnet mask는 255.255.0.0이고 IP 주소는 128(10000000).0.x.x ~ 191(10111111).255.x.x의 값을 갖게 된다. 16384(2^14)개의 네트워크와 65534(2^16 - 2)개의 호스트가 있다.

#### Class C 주소

최상위 3bits가 110으로 구성된 주소이다. Default subnet mask는 255.255.255.0이고 IP 주소는 192(11000000).0.0.x ~ 223(11011111).255.255.x의 값을 갖게 된다. 2097152(2^21)개의 네트워크와 254(2^8 - 2)개의 호스트가 있다.

#### Class D 주소

최상위 4bits가 1110으로 구성된 주소이다. 224.0.0.0 ~ 239.255.255.255의 범위를 갖고 multicasting을 위한 주소이다. 서브넷 마스크는 없다.

#### Class E 주소

최상위 4bits가 1111로 구성된다. 240.0.0.0 ~ 255.255.255.255의 범위를 갖는다. 서브넷 마스크가 없다.

## What is TCP

TCP(Transmission Control Protocol)는 Internet protocol suite 중 하나로, IP network에 있는 host 간 통신을 위한 데이터 흐름을 안정적으로 처리할 수 있다. Connection-oriented 란 특성 때문에, client와 server 간 연결을 성립한 이후에 데이터를 주고 받는다. 

이러한 connection establishment는 three-way handshake 방식으로 진행된다. 

- Step 1 (SYN) : client는 server와 연결하기 위해 전송하려는 시작 segment의 번호 정보(x)와 함께 SYN(Synchronize Sequence Number) 신호를 보낸다.
- Step 2 (SYN-ACK) : 이에 대한 반응으로, server에서 client로 y번호의 SYN과 x+1 번호의 ACK(Acknowlegement) 신호를 보낸다.
- Step 3 (ACK) : 마지막으로 client에서 y+1번호의 ACK 신호를 server로 보내면서 둘 사이의 연결이 성립된다.

1,2 과정과 2,3과정으로 각 방향에 대한 연결이 성립된 것이고, full-duplex 통신이 가능해진다.

연결 종료는 4-way handshake 방식으로 진행되며 각각 FIN 패킷과 ACK패킷을 주고 받으면 각 방향으로의 연결을 종료시킨다.

## What is UDP

UDP(User Datagram Protocol)은 메시지에 해당하는 datagram이라고 불리는 전송 unit을 사용하여 통신한다. connectionless communication model을 사용하여 빠른 속도로 데이터 통신을 할 수 있다. Error check나 correction이 필요 없고 빠른 속도를 요구하는 application에서 사용하는 전송 프로토콜이다.

## What are the network layers



## What is the OSI model

OSI(Open System Interconnection) model은 표준 통신 프로토콜을 이용하여 여러 통신 시스템에서 정보 처리의 상호 운용을 가능케 하기 위한 목적으로 설계된 개념적 모델이다. 각 layer는 상위, 하위 layer와 필요한 정보를 주고 받아 역할을 수행한다.

- Layer 1: Physical Layer

  physical layer는 device와 physical transmission medium 간의 unstructured raw data 전송과 수신 process를 처리한다. 

- Layer 2: Data Link Layer

  data link layer는 물리적으로 연결된 두개의 device간의 연결을 맺고 종료하는 역할을 수행한다. 그리고 physical layer에서 발생하는 error를 확인하고 수정하며, 송신측과 수신측의 데이터 흐름 rate을 맞추기 위한 flow control도 수행한다.

- Layer 3: Network Layer

  network layer는 packet이라 불리는 다양한 길이의 data sequence를 다른 네트워크에 속한 node로 전송하는 기능적 절차적 수단을 제공한다. 네트워크에는 여러개의 node가 있고, 송신 노드에서 중간 노드들을 거쳐 최종적인 수신 노드까지 가는 network path를 정한다. 그리고 만약, data link layer에서 생성한 message가 길다면 여러개의 fragment로 쪼개어 독립적으로 전송하고 재조립하는 역할도 수행한다. 전송 에러에 대한 처리도 가능하다.

- Layer 4: Transport Layer

  transport layer는 두 host간의 데이터 전송에 관한 기능적 절차적 수단을 제공한다. 흐름 제어, segmentation/desegmentation, error control을 통해 안정성을 보장할 수 있다. 즉, 전송하는 segment를 감시하여, 성공적인 수신을 확인하고 손실시에 재전송하여 다음 데이터를 보내는 과정을 반복한다. 그리고 application layer에서 받은 message를 쪼개어 segment로 분리하는 역할도 수행한다. TCP와 UDP는 OSI 참조 모델에 속하지는 않지만, transport layer로 분류한다.

- Layer 5: Session Layer

  session layer는 컴퓨터 간의 connection establishment, management, termination을 제어한다. full-duplex, half-duplex, simplex와 같은 통신 방식을 관리하며 transport layer의 TCP에서 처리하는 closing session에 대한 역할도 수행한다. 그리고 session checkpoint 설정과 복구에 관한 역할도 수행한다. 

- Layer 6: Presentation Layer

  syntax layer라고도 불리는 presentation layer는 application 과 network간의 데이터 변환을 처리한다. 

- Layer 7: Application Layer

  application layer는 user interface로서 presentation layer와 상호작용할 수 있는 데이터와 그림을 사용자에게 보여주는 역할을 수행한다.

## What is a DHCP server and the DHCP protocol

DHCP(Dynamic Host Configuration Protocol)는 IP network에서 사용되는 network management protocol이다. DHCP로 인해 DHCP server는 네트워크 내부의 각 device에 IP 주소와 network configuration parameters 를 할당할 수 있고, 다른 IP network와 통신할 수 있는 것이다.

​                                                                  

## What is a DNS server and the DNS protocol

DNS(Domain Name System)은 Internet의 전화번호부로 비유되는데, DNS server에 저장된 매핑 정보를 통해 domain name인 google.com을 IP 주소로 연결시켜준다.

## What are the rules to make 2 devices communicate using IP addresses



## How does routing work with IP



## What is a default gateway for routing



## What is a port from an IP point of view and what is it used for when connecting to another device







