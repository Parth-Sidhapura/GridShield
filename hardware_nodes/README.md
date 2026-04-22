# Hardware Nodes – GridShield

## Overview

This directory contains sample embedded system code used in the GridShield project to represent hardware-level data acquisition and communication within a smart power grid.

The purpose is to demonstrate how edge devices (such as RTUs or sensor nodes) interact with the central AI-based intrusion detection system.

---

## Current Implementation

* Includes sample code for ESP-based microcontrollers (e.g., ESP32 / ESP8266)
* Demonstrates:

  * Sensor data simulation (CT/PT equivalent values)
  * Basic data transmission logic
  * Communication with higher-level systems

Note: This is a simplified prototype and does not represent a full production-level implementation.

---

## Security and Code Availability Notice

To maintain project integrity and prevent misuse:

* The complete hardware-level implementation is not publicly shared
* Certain modules are intentionally limited due to:

  * Security considerations
  * Academic and project ownership requirements
  * Prevention of unauthorized replication

This repository includes only a minimal working example necessary to understand the system design and workflow.

---

## Scalability and Future Implementation

In a real-world deployment, the hardware layer will be significantly enhanced:

* Integration with actual CT/PT sensors
* Use of industrial-grade RTUs (Remote Terminal Units)
* Implementation of secure communication protocols (e.g., encrypted data transfer)
* Real-time data streaming to SCADA systems
* Improved reliability, fault tolerance, and security mechanisms

The current code serves as a conceptual foundation and will evolve during scaling and deployment.

---

## Important Note

This module is intended for:

* Demonstration purposes
* Concept validation
* Academic and research use

It does not represent the final or complete hardware implementation of GridShield.

---

## Summary

The hardware nodes in GridShield form the first layer of data collection and transmission.
Although simplified, this implementation provides a clear and structured foundation for building a scalable and secure smart grid system.
