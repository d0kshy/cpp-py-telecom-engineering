# ✅ 1. Call Flows (Connection and Message transmitting Scenarious)

A sequence of messages between UE and gNodeB to **establish, maintain,** or **release a connection**:

### **1. Initial Attach: First connection:** 

The UE requests to join the network (e.g., RRC Setup Request -> RRC Setup -> RRC Setup Complete).
```
Step 1: UE (cellphone) sends RRC Setup Request.

Step 2: gNodeB (base station) answers with RRC Setup (gives radio resources).

Step 3: UE answers with RRC Setup Complete.

Step 4: Authentication through the 5G Core and downloads a Default Bearer (internet tunnel).
```

***Python***: Script reads log and seraches for these lines. If a Complete didn't showed after 5 seconds after RRC Setup, then it gives assert: connection timeout.


### **2. Handover: Reconnection between towers:** 

The UE physically moves and transfers its connection from a source gNodeB to a target gNodeB.
```
   UE always measures signal level ->

-> When signal drops, UE sends Measurement Report ->

-> Current tower connecting to the nearest one (sends Handover Command).
```

### **3. Detach: Disconnecting:**

The UE gracefully or forcefully disconnects from the network.



# 2. Protockol Stack - Where did the error come from?

**Log always shows Layer Level:**

* **L1: PHY (Physical Layer / Радиоэфир):**

Отвечает за модуляцию, передачу I/Q данных и мощность сигнала.

```ERROR: Interference (помехи), Signal-to-Noise Ratio is too low.```

* **L2: MAC (Medium Access Control):**


Отвечает за расписание (Scheduling) — кто в какую миллисекунду говорит, и за быстрые перезапросы битых данных (HARQ).

```ERRORS: HARQ NACK (пакет не долетел, запрашиваем снова), collisions.```

* **L2: RLC (Radio Link Control):**

Chopps big IP-packets into pieces for Physical Layer and clays together as it was at the start.
Разрезает большие IP-пакеты на маленькие куски для радиоэфира и собирает их обратно в правильном порядке.

```ERROR: Packets are Out-of-sequence.```

* **L2: PDCP (Packet Data Convergence Protocol):**

Compresses IP headers (RoHC) and Cipheres data.

```ERROR: Не совпали ключи шифрования, ошибка декомпрессии.```

* **L3: RRC (Radio Resource Control):**

Controls signal generators, connection, handovers.

```ERROR: RRC Reconfiguration Failure, Radio Link Failure (RLF).```


# ✅ 3. Configuration Parameters (Input data for testing)

Generated JSON and YAML files will be provisioned with specific device and network configurations.

* **IMSI (International Mobile Subscriber Identity):** Unique SIM ID (15 digit by default).

* **PLMN ID (Public Land Mobile Network):** **MCC** (Moile Country Code) + **MNC** (Mobile Network Code).

* **Supported Frequency Bands**

* **Transmission Power Levels**



# ✅ 4. Transport Protockols
Telecom equipment relies on standard networking protockols to communicate over IP networks, connecting the gNodeB to the 5G Core.

* **TCP:** Reliable, ordered (guarantied) delivery (used for control and management).
* **UDP:** Fast, best-effort delivery (used for real-time user data where speed matters more than occasional packet loss).
* **SCTP (Stream Control Transmission Protocol):** A telecom-grade protocol combining TCP's reliability with message-oriented framing, strictly used for signaling (like NGAP). Uses two IP-addresses (multi-homing).

# 5. Key Performance Indicators (KPIs)

* **Throughput:** The amount of data successfully transmitted per second in Mbps: 
```Total Bytes / Time.```

* **Latency / RTT:** The time it takes for a packet to travel from the UE to the destination and back (ms). Для 5G критически важна низкая задержка (URLLC).

* **Packet Loss Rate:** The percentage of packets dropped during transmission: 
```(Отправленные пакеты - Принятые пакеты) / Отправленные * 100%.```

* **Attach Success Rate:** 1000 virtual UE, how much of them passed an RRC Setup Complete. If result is 99% — test failed.