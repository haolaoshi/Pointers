
:: 如果启用了VPN，访问虚拟机的IP会路由到VPN上去. 解决办法是修改路由表

set  ip_client="192.168.49.188"
set  vm_host="192.168.49.1"

ping -n 3 %ip_client%
route delete %ip_client%
route add  %ip_client%  mask 255.255.255.255 %vm_host%
echo on

