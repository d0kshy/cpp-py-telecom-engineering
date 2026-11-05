status_logs = [
    "UE_1: CONNECTED",
    "UE_2: TIMEOUT",
    "UE_3: CONNECTED"
]

parsed_data = []
for lines in status_logs:
    device, status = lines.split(": ")
    log_dict = {"device": device, "status": status}
    parsed_data.append(log_dict)

print(parsed_data)
