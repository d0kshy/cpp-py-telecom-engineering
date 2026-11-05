test_logs = [
    "INFO: system boot ok",
    "CRITICAL: UE_10 disconnected",
    "WARNING: high ping on UE_11",
    "CRITICAL: gNodeB timeout"
]

crit_logs = [mess for mess in test_logs if "CRITICAL" in mess]
print(f"Only CRITICAL messages: \n\t{crit_logs}")

new_list = len(crit_logs)

print(new_list)

for mess in crit_logs:
    print(mess)
