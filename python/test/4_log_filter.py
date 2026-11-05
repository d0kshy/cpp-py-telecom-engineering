raw_logs = [
    "UE_101: RRC_CONNECTED",
    "UE_102: ERROR_TIMEOUT",
    "UE_103: RRC_CONNECTED",
    "UE_104: ERROR_TIMEOUT",
    "UE_105: ERROR_MAC_FAILURE"
]

print(f"1. A raw list of errors: \n\t{raw_logs}.")

error_logs = [err for err in raw_logs if "ERROR" in err]
print(f"\n2. A cleared list of errors: \n\t{error_logs}.")

un_error_logs = set(error_logs)
print(f"\n3. A set of unique errors: \n\t{un_error_logs}.")
