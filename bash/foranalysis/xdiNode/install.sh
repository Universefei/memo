#!/bin/sh

CURRENT=`pwd`

if [ ! -r "/etc/iNode" ]
then
	mkdir /etc/iNode
fi

if [ ! -r "./clientfiles" ]
then
	mkdir ./clientfiles
fi

if [ ! -r "./conf" ]
then
	mkdir ./conf
fi

if [ ! -r "./log" ]
then
	mkdir ./log
fi

INODE_CFG="/etc/iNode/inodesys.conf"
[ -r "$INODE_CFG" ] && . "${INODE_CFG}"
if [ -z "$INSTALL_DIR" ]; then
    echo INSTALL_DIR=$CURRENT >> /etc/iNode/inodesys.conf
fi

# move .so (lib) files to specified locations
# libs that may exist use a 'if' statement
if [ ! -r "/usr/lib/libstdc++.so.5" ]
then
	cp -fr ./libs/std/libstdc++.so.5 /usr/lib/
fi

if [ ! -r "/usr/lib/libstdc++.so.6" ]
then
	cp -fr ./libs/std/libstdc++.so.6 /usr/lib/
fi
# move all files in certain directory to /usr/lib (using filename wildcard * )
cp -fr ./libs/wxWidgets/* /usr/lib/
cp -fr ./libs/ace/* /usr/lib/
cp -fr ./libs/opswat/* /usr/lib/

sed -i "s:@INSTALL_PATH:$CURRENT:g" ./iNodeClient.desktop

chmod 755 ./AuthenMngService
chmod 755 ./renew.ps
chmod 755 ./enablecards.ps
chmod 755 ./iNodeClient.desktop

OS_UBUNTU=`cat /etc/issue | grep 'Ubuntu'`

if [ "$OS_UBUNTU" != "" ]; 
then
	iNODE_SERVICE=`cat /etc/rc.local | grep 'iNodeAuthService'`
	if [ "$iNODE_SERVICE" = "" ]; then
		mv -f ./iNodeAuthService_ubuntu /etc/init.d/iNodeAuthService
		chmod 755 /etc/init.d/iNodeAuthService
		rm -f ./iNodeAuthService
		cp -fr /etc/rc.local /etc/rc.local.bak
		sed -e '/^exit 0$/d' /etc/rc.local > /etc/rc.temp
		echo "/etc/init.d/iNodeAuthService start" >> /etc/rc.temp
		echo "exit 0" >> /etc/rc.temp
		mv -f /etc/rc.temp /etc/rc.local
		chmod 755 /etc/rc.local
	fi
	if [ ! -r "/usr/lib/libtiff.so.3" ]; then
		ln -s /usr/lib/libtiff.so.4 /usr/lib/libtiff.so.3
	fi
	> ./enablecards.ps
	else
		mv -f ./iNodeAuthService /etc/init.d
		chmod 755 /etc/init.d/iNodeAuthService
		rm -f ./inodeauthservice_ubuntu
		chkconfig --add inodeauthservice
		chkconfig --level 35 inodeauthservice on
fi

selinux_flag=`getenforce 2>/dev/null | grep -x -i enforcing`
if [ "$selinux_flag" != "" ]; 
then
	chcon -t textrel_shlib_t /usr/lib/libcoreutils.so
	chcon -t textrel_shlib_t /usr/lib/libimplav.so
	chcon -t textrel_shlib_t /usr/lib/liboesiscore.so
fi

service inodeauthservice start

##my addition
#ln -s /usr/lib/i386-linux-gnu/libjpeg.so.8 /usr/lib/i386-linux-gnu/libjpeg.so.62
#ln -s /usr/lib/i386-linux-gnu/libtiff.so.4 /usr/lib/i386-linux-gnu/libtiff.so.3
