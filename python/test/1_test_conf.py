# A dictionary - dict
dev_conf = {
    "dev_id": 665,
    "supp_bands": ["3G", "4G", "5G"]
}


# A function - def
def check_5g_supp(configuration):
    # Take a network list by the key "supported_bands"
    bands = configuration["supp_bands"]

    # Checking if "5G" in the list
    if "5G" in bands:
        return True
    else:
        return False


# Auto-test
is_supp = check_5g_supp(dev_conf)

# assert checks if(утверждение) проверяет, правда ли то, что написано. Если нет - роняет программу с ошибкой.
assert is_supp == True, "ERROR: Device has to support 5G band!"
print(" --- [+] Simulator works correctly!")
