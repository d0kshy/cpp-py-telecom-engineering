class UeDevice:
    # Constructor: creates a "new" cellphone.
    def __init__(self, device_id, imsi):
        self.device_id = device_id
        self.imsi = imsi
        self.is_connected = False  # Cellphone is off by default.
        print(f"Device was created (ID): {self.device_id}")

    # Basic method.
    def attach_to_network(self):
        self.is_connected = True
        print(
            f"Device {self.device_id} was succesfully loged in to the 5G network.")

    def send_packet(self, data):
        self.data = data
        if self.is_connected:
            print(f"Sending data: {data}.")
        else:
            print(
                f"ERROR: no connection, can't send a packet to the {self.device_id}.")


phone_a = UeDevice(101, "260020000000001")
phone_b = UeDevice(102, "260020000000002")

phone_a.attach_to_network()
phone_a.send_packet("\n\tMESSAGE: Hi! It's Maria, call me!")
phone_b.send_packet("MESSAGE: Hi! It's Maria, call me!")

print(f"phone_a status: connected? -> {phone_a.is_connected}")
print(f"phone_b status: connected? -> {phone_b.is_connected}")
