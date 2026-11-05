# Create log file ("w" - write).
# - File closes automatically!
with open("./python/test/sim_logs.txt", "w") as file:
    file.write("INFO: UE_100 connected\n")
    file.write("ERROR: UE_101 RRC_TIMEOUT\n")
    file.write("INFO: UE_102 connected\n")

print("\n[ + ] --- File was succesfully created and closed.\n")

# Read log file and check it for errors.
with open("./python/test/sim_logs.txt", "r") as file:
    # File works as iterator, we can read it with for loop.
    # - This script is effective for the memory,
    # 'cause we can read really heavy files with it (even 10GB),
    # even without uploading all of it into RAM.
    for line in file:
        if "ERROR" in line:
            # .strip() deletes transparent symbols "\n" on the end of every line.
            print("[ - ] --- Found a critical error: ", line.strip(), "\n")

# - File closes again.
