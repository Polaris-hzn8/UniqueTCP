# tcpip

---

Write a TCP/IP protocol stack from scratch with over 10,000 lines of code.

![image-20231002192321605](assets/image-20231002192321605.png)

TCP/IP协议栈是操作系统中实现的一种组件，用于让本地计算机与网络上的计算机进行通信交互，

实现一个tcpip协议栈支持主要的协议如下，这是一个通用的软件组件，可以支持移植到不同的操作系统上（x86、ARM）：

- tftp、ntp、dns、http
- udp、tcp
- icmpv4、ipv4、arp
- ethernet

该项目支持多网卡并且参考标准socket接口实现，用户在Linux/mac平台上编写的应用代码，可无缝移植到本协议栈上，

- socket、close、listen、accept
- sendto、recvfrom、connect、bind
- send、recv、setsockopt、gethostbyname_r
- inet_ntoa、inet_addr、inet_pton、inet_ntop
- htons、ntohs、htonl、ntohl

协议栈实现顺序思路，

1. 以太网：基本的数据包收发、多网卡的支持
2. IP协议：IP数据包的收发、分片与重组、icmp响应
3. socket：基本socket接口实现、ping命令实现
4. UDP协议：udp数据包的收发、tftp客户端和服务端、dns客户端
5. TCP协议：tcp连接建立和断开、滑动窗口实现、数据重传、http服务器实现

### 1.支持应用

![image-20231002194244446](assets/image-20231002194244446.png)

同时运行多个应用程序，包括以下3中不同类型的socket传输模式：

1. ping命令（icmpv4、SOCK_RAW）
2. tftp客户/服务端、echo客户/服务端、ntp客户端、dns客户端（udp、SOCK_DGRAW）
3. echo客户端/服务器、http服务器（tcp、SOCK_STREAM）

### 2.ip协议的分片与重组

ip协议会有分片与重组机制，

即对上层应用发来的数据包，会根据底层网卡所能够发送的最大数据包大小，对数据包进行拆分，同时接收端需要重组数据包，

![image-20231002194851497](assets/image-20231002194851497.png)

### 3.多网卡路由

针对多网卡实现一个路由表，当有多个网口时根据内置路由表自动选择输出的网口，

路由表可以添加申请路由、实现路由转发功能（简单的路由器）、

![image-20231002195339340](assets/image-20231002195339340.png)



### 4.tcp协议

tcp协议特性较多，主要实现了以下几个重要的特性，

通过实现tcp状态机、超时重传、动态RTO计算、快速重传、零窗口探测、包活机制等功能，

来解决网络传输中出现的包丢失、包重复、包乱序、流量控制等主要功能，通过使用代码来实现协议栈，能够更深层次的理解相关协议（对比直接看书、抓包分析协议等方式），更深层次的理解socket接口的使用方法和规则。

![image-20231002195959088](assets/image-20231002195959088.png)

#### 数据存储

计算机网卡接受到来自网络的数据包，针对网络数据包大小不固定的情况，

不采用单个超大缓存的方式存储网络数据包，而是采用提升内存效率的链式存储方式进行优化，从而提升存储效率（极大的减少空间的浪费），

![image-20231002200458698](assets/image-20231002200458698.png)

#### 协议细节

深入tcpip协议相关细节，对每个协议数据包的格式、通信过程、具体的数据处理，

在深入学习tftp、tcp协议之后，可以学会其中进行可靠传输的基本原理和技术，同时经过大量代码提升编程能力和经验，



















