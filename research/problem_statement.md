# Problem Statement

The modern electrical grid has evolved into a highly interconnected cyber-physical system, commonly referred to as the "Smart Grid". While this transformation has significantly improved efficiency, monitoring, and automation, it has also introduced critical cybersecurity vulnerabilities.

One of the major concerns lies in the use of legacy industrial communication protocols such as IEC 60870-5-104 (IEC 104), which were not originally designed with security as a priority. These protocols lack fundamental security features such as encryption, authentication, and integrity verification.

As a result, adversaries can exploit these weaknesses to launch cyber-physical attacks, including:

- False Data Injection Attacks (FDIA), where sensor readings are manipulated
- Load Altering Attacks (LAA), where demand patterns are artificially modified
- Command injection attacks, which can lead to unauthorized control of grid components

Such attacks can result in incorrect decision-making by control systems, destabilization of the grid, and in extreme cases, large-scale blackouts.

The core problem is the absence of a lightweight, real-time, and distributed mechanism capable of detecting such anomalies at the edge of the network before they propagate through the system.

GridShield addresses this gap by introducing an IoT-based edge monitoring system integrated with intelligent anomaly detection capabilities.