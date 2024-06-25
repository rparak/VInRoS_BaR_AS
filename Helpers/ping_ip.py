import re
import subprocess

ip_addresses = []
for i in range(1, 100):
    ip_addresses.append(f'192.168.0.{i}')

for ip_adr_i in ip_addresses:
    output = subprocess.Popen(f'ping {ip_adr_i} -n 2', stdout=subprocess.PIPE, 
                              encoding='utf-8')
    data = ''
    for line in output.stdout:
        data += line
        ping_result = re.findall('TTL', data)

    if ping_result:
        print(f"{ip_adr_i} : Successfully found.")
    else:
        print(f"{ip_adr_i} : Destination host unreachable.")
