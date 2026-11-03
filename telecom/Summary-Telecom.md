### 1. The High-Level Architecture

The story begins with the **User Equipment (UE)**. In the real world, this is a 5G smartphone; at Ericsson, it is the massive C++ **UE Simulator** you will be developing to mimic thousands of these smartphones simultaneously.

When the UE wants to send data (like a video stream) or establish a connection, it must communicate wirelessly across the **Radio Access Network (RAN)**. The RAN is the physical wireless bridge consisting of the airwaves and the cell towers.

The specific tower the UE connects to is the **gNodeB (gNB)** for 5G networks (or the **eNodeB** for 4G LTE). The gNodeB receives the wireless signal, translates it, and sends it via physical fiber-optic cables deep into the telecom operator's backend server farm, known as the **Core Network (5GC)**. The Core Network acts as the brain: it authenticates the user's SIM card, handles billing, and routes the data to the public internet.

### 2. The Software Journey (The Protocol Stack)

Before the UE can actually transmit that video over the air to the gNodeB, the data must be rigorously packaged. This packaging happens inside the software processor of the UE, flowing top-to-bottom through the 5G protocol stack. Both the UE and the gNodeB run this exact same stack to talk to each other.

The process starts with the **RRC (Radio Resource Control)**. This is the connection manager. It doesn't touch your video data; instead, it sends control signals to the gNodeB to request permission to connect and manages handovers if the UE is moving.

Once the RRC establishes the rules, your actual video data enters the **PDCP (Packet Data Convergence Protocol)** layer. Here, IP headers are compressed, and the data is encrypted (ciphering) to ensure cybersecurity over the open airwaves.

Because encrypted IP packets are often too large to broadcast efficiently, they are passed down to the **RLC (Radio Link Control)** layer, which fragments them into smaller, manageable chunks.

These chunks then hit the **MAC (Medium Access Control)** layer. The MAC acts as the traffic controller, using precise scheduling algorithms to determine the exact millisecond your UE is allowed to transmit, ensuring your data does not collide with data from thousands of other UEs.

Finally, the scheduled chunks arrive at the **PHY (Physical Layer)**. This is the lowest software level, utilizing heavy mathematical **Signal Processing** to map the raw digital bits (0s and 1s) into a format ready for physical transmission.

### 3. The Physical Journey (RF, Modulation, and Hardware)

At the bottom of the PHY layer, software ends and hardware begins.

To transmit the digital bits over an analog radio wave, the system uses **Modulation Schemes** like **QAM (Quadrature Amplitude Modulation)**. By altering the amplitude and phase of the radio wave, QAM allows the hardware to pack multiple bits into a single wave cycle (e.g., 256-QAM packs 8 bits per cycle for massive throughput).

Once the signal leaves the antenna, it is subject to the harsh realities of **RF Propagation**. As the wave travels through the air, it loses energy (path loss) and bounces off buildings, arriving at the gNodeB as a messy compilation of echoes (multipath fading). The receiving gNodeB must use its own heavy digital signal processing algorithms to filter out this noise and recover the original 0s and 1s, pushing them back up its own protocol stack (PHY $\rightarrow$ MAC $\rightarrow$ RLC $\rightarrow$ PDCP).

### 4. Tying it all together: Your Role and HIL

Because the physical hardware (antennas, digital-to-analog converters) operates on strict, unyielding microsecond clocks, the software protocol stack must be perfectly optimized.

If your C++ UE Simulator has inefficient memory allocations or a multithreading deadlock in the MAC layer, it will miss the strict 10-millisecond transmission window. To guarantee this doesn't happen, Ericsson uses **Hardware-in-the-Loop (HIL)** testing. Instead of testing your C++ UE Simulator in a purely virtual environment, they connect your code directly to the underlying physical RF hardware components. HIL proves that your C++ software is fast and reliable enough to drive the hardware in real-time, effectively stress-testing the gNodeB under real-world conditions.