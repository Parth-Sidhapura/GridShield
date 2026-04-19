# Proposed Solution

GridShield proposes a hybrid architecture combining edge computing and centralized intelligence for smart grid security.

## System Architecture

1. Edge Layer (ESP32 Node):
   - Collects electrical parameters (voltage, current)
   - Performs basic preprocessing and noise filtering
   - Generates a unique integrity code for each data packet

2. Communication Layer:
   - Transmits structured telemetry data
   - Currently uses WiFi for prototyping
   - Designed to integrate with industrial protocols (Ethernet / IEC 104)

3. Backend Layer:
   - Receives real-time data
   - Performs anomaly detection using rule-based or ML models
   - Generates alerts for suspicious activity

## Key Features

- Real-time data acquisition
- Distributed monitoring architecture
- Data integrity validation
- Scalability for large grid systems

## Working Principle

The system continuously monitors electrical parameters and evaluates them for abnormal behavior. Any deviation from expected patterns or integrity violations is flagged for further analysis.

This approach ensures early detection of potential cyber-physical attacks before they impact the grid.