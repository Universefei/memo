#network commands




##primer

**commands:**

* `ifconfig`
* `route`
* `nslookup`
* `host`

**network interface types:**

* eth0 eth1 eth2 ...
* usb0
* wlan0

**network interface info and configure**

* `ifconfig`
* `ifconfig eth0`
* `ifconfig eth0 192.168.1.5`
* `ifconfig eth0 192.168.1.5 netmask 255.255.255.0`
* `ifconfig eth0 hw ether 00:1c:bf:87:25:d5`
* `ifconfig eth0 down`
* `ifconfig eth0 up`

**ip**

* `ping ADDRESS` ADDRESS can be hosts,ip or domain name
* `ping 192.168.0.1`
* `ping google.com`
* `ping 192.168.0.1 -c 2` '-c' option to specify package number
* if ping successfully(conneted),ping will return 0,otherwise return non-0

```
ping ADDRESS -c 2
if [ $? -eq 0 ];
then
	echo Successful;
else
	echo Failure
fi
```

**DNS**

* DNS server address conf file are at /etc/resolv.conf
* `echo nameserver 8.8.8.8 >> /etc/resolv.conf`
* `host google.com`
* `nslookup google.com`
* if NO DNS, we can use host conf file at /etc/hosts
* `echo 192.168.0.9 backupserver.com >> /etc/hosts` usable when DNS server is not availabe

**gateway and route**

* `route add default gw 192.168.0.1 eth0` set default gateway
* `route`
* `route -n`
* `traceroute google.com`





##file transfer

