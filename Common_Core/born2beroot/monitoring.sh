#!/bin/bash

#Redirecting errors
exec 2>/dev/null

#Send info to every terminal
send_info(){
    echo "$1" | wall
}
#Architecture and Kernel Version
send_info "#Architecture : $(uname -a)"

#Amount of Physical CPUs
send_info "#pCPU : $(grep "physical id" /proc/cpuinfo | sort -u | wc -l)"

#Amount of Virtual CPUs
send_info "#vCPU: $(grep -c "processor" /proc/cpuinfo)"

#Memory Usage
free | awk 'FNR == 2 {print "#Memory Usage: " $3 "/" $2 "MB (" int($3/$2 * 100) "%)"}'

#Disk Usage
df -h --output=used,size,pcent /home | awk 'NR==2 {print "#Disk Usage: " $1 "/" $2 " (" $3 ")"}'

#CPU Usage
cpu_usage=$(top -bn1 | grep "Cpu(s)" | awk '{print $2 + $4 "%"}')
send_info "#CPU Usage : $cpu_usage"

#Last Boot Time
last_boot=$(who -b | awk '{print $3, $4}')
send_info "#Last Boot : $last_boot"

#Check if LVM is active
if lsblk | grep -q lvm; then 
  send_info "LVM is active"; 
else 
  send_info "LVM is not active"; 
fi

#Active TCP Connections
active_connections=$(netstat -tn | awk '{print $6}' | sort | uniq -c)
send_info "#Active Connections : $active_connections"

#Amount of logged-in users
users=$(who | wc -l)
send_info "#Users : $users"

#IPv4 and IPv6 Addresses with MAC Address
ipv4_address=$(ip -4 addr show | grep inet | awk '{print $2}' |cut -d/ -f1)
mac_address=$(ip link show | grep -E "ether" | awk '{print $2}')
send_info "IPv4 : $ipv4_adress, MAC Adress : $mac_adress"

#Amount of sudo commands executed
sudo_count=$(grep -c 'sudo' /var/log/auth.log)
send_info $sudo_count
