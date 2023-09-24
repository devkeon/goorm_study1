# OSI 7 Layers


## OSI 7 Layer란?

7계층은 사진처럼 구분한다.(?)

![7Layer](http://wiki.hash.kr/images/7/71/OSI_7_계층.jpg)

<br/><br/>

### 왜 이렇게 나눠놨죠? 그냥 한 번에 쓰면 될 것같은데..
<br/>
개발자는 효율이 중요하죠..

비슷한 기능들끼리 컴포넌트화 되어있기 때문에 한 계층에서 장애가 발생하면
대응 시 다른 계층을 신경쓰지 않고 온전히 장애 대응에만 신경 쓸 수 있다.

즉, 장애가 발생한 계층에서 수정하면 된다. => 편리함

~~5계층에서 7계층으로 바꾸는 것에 실패했다는데..현업에 있어본 경험이 없으니..~~
   
<br/><br/>

## 각 계층에 대한 소개

<br/>

1. 물리 (Physical)

<br/>
물리 계층은 말그대로 전송 매체의 물리적 인터페이스에 대한 사항을 기술.

여기서는 비트 교환 문제를 다룸.

![](https://raw.githubusercontent.com/angeloyeo/angeloyeo.github.io/master/pics/2019-07-07-CTFT/pic1.png)


하드웨어 시스템으로 구현된다. (2계층부터는 소프트웨어 시스템으로 구현)
> ~~Fourier Transform..전기전자에서 하겠죠?~~

<br/><br/>

2. 데이터 링크 (Data Link)
> Data: Frame

<br/>
물리 계층을 통해 전송되는 데이터의 물리적 전송 오류를 해결함.
=> 네트워크 계층에 신뢰성 있는 패킷 전송을 보장.
(갈림길에서 전송 경로를 선택할 수 없으므로 호스트가 일대일로 연결 시에만 데이터 전송 지원)

흐름 제어, 에러 검출 기능 지원.
> CRC, Parity bit
> 슬라이딩 윈도우 프로토콜 (알고리즘에서 봤을 수도..), 피기 배킹..

<br/><br/>

3. 네트워크 (Network)
> Data: Packets(Datagram?)

<br/>
라우팅 문제를 처리.

라우터를 통해 이동할 경로를 선택.

그리고 해당 경로로 패킷을 전달해줌.

경로는 정적인 방식과 트래픽을 고려한 동적 방식으로 구분.

IP 주소를 사용하여 라우팅.

라우팅, 혼잡 제어, 패킷 분할과 병합 등등.. 기능 지원

![](https://2.bp.blogspot.com/-HRi64imuP9M/V5axFei6SSI/AAAAAAAAAaY/HUclv6l3o50Y6dlt6_a5b9zl3u3-pzkkQCLcB/s1600/2.PNG)

<br/><br/>

4. 전송 (Transport)
> Data: Segment(TCP) / Datagram(UDP)

<br/>
전송 계층은 송신 프로세스와 수신 프로세스를 직접 연결하는 End-to-End 통신 기능을 제공.

보통 포트 번호를 사용해 프로세스 구분. (여러 프로세스가 열려있다면 통신하는 프로세스 구분 위해)

흐름 제어, 오류 제어, 분할과 병합, 서비스 프리미티브 등..

TCP: 연결형 서비스 제공. (3 Way handshake, Ack 신호)
UDP: 비연결형 서비스 제공. (일단 보내고 봄., Best Effort 방식)
> TCP는 흐름 제어를 지원하려고 슬라이딩 윈도우 프로토콜을 사용하기도 함
> UDP는 도착 순서 변경 오류를 해결 할 수 없으므로 응용프로그램에서 순서 번호 기능이 구현되어야함.

![](https://blog.kakaocdn.net/dn/d2UbXC/btqzsVExN5l/lx9RkndbNduxK9qk78wLK1/img.jpg)

***

TCP/IP 5계층에서는 이 상위 계층들이 Application Layer
- 일반적으로는 세 계층의 기능이 한 프로그램에 묶어서 구현됨.

<br/><br/>

5. 세션 (Session)
> 텔넷, FTP, 등.. well-known port number로 연결

<br/>
상위 계층에 제공하는 기능은 세션 연결의 설정과 해제, 세션 메시지 전송 등..

두 응용 프로세스 간의 세션을 설정하기 위해 세션 연결.
> 동기 기능: 주동기점과 부동기점을 이용해 내용 복구

~~세션과 쿠키에서 자세하게 알아볼 것 같아요..?~~

<br/><br/>

6. 표현 (Presentation)

<br/>
응용 프로세스 사이에 전송되는 메시지의 표현 방법을 다룬다.
> ex. 추상 문법, ASN.1

데이터 압축과 보안 담당.
=> zip..다들 아시죠?(손실 압축과 비손실 압축 등도 있는데..)
=> 데이터 encryption 기능 또한 표현 계층에 속함.

<br/><br/>

7. 응용 (Application)

<br/>
응용 계층의 역할은 하부 계층을 이용해 사용자에게 편리한 응용 환경을 제공.

클라이언트의 요청을 메세지로 변환하고 전송 계층으로 전달.

보통 OS에서 제공되는 계층4의 인터페이스를 통해 통신 기능 구현 (소켓)

![](https://on1ystar.github.io/public/img/socket/socket-1-2.png)

클라이언트-서버 모델에서 서버와 통신하려면 응용 계층의 프로토콜을 사용해야 함.
> HTTP, FTP, SMTP, POP3, DNS 등...
