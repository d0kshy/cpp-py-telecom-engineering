import re

dirty_log = "09:00 Drop UE_554 due to noise. 09:02 UE_12 ok. 09:05 Drop UE_554 again. RRC error on UE_990."

print(f"Dirty log: \n\t{dirty_log}")

clean_log = re.findall(r"UE_\d+", dirty_log)
print(f"Cleaned log: \n\t{clean_log}")

un_dev = set(clean_log)
print(f"Unique devices: \n\t{un_dev}")
