# A log
log = "UE_10: SUCCESS, UE_11: RRC_ERROR, UE_12: SUCCESS"

# Chopping log
log_split = log.split(", ")
print("A list of chopped log pieces: ", log_split)

# Searching through the list to find errors
for entry in log_split:
    if "ERROR" in entry:
        print("--- WARNING: Found an connection issue: [ ", entry, "].")
