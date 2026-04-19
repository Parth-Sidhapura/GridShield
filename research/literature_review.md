# Literature Review

The security of smart grids has been an active area of research due to the increasing reliance on digital communication infrastructures.

Several studies have highlighted the vulnerabilities of industrial control systems, particularly those using IEC 104 and similar SCADA protocols. These systems were originally designed for reliability and interoperability, but not for resilience against cyber threats.

Research on False Data Injection Attacks (FDIA) demonstrates that attackers can manipulate system state estimation without being detected by traditional threshold-based monitoring systems. This makes FDIA one of the most dangerous threats in smart grids.

Similarly, Load Altering Attacks (LAA) exploit demand-side flexibility to create artificial load patterns, potentially destabilizing the grid.

Existing detection approaches include:

1. Statistical methods:
   - Based on thresholding and rule-based logic
   - Limited in detecting sophisticated attacks

2. Machine Learning models:
   - Supervised learning for anomaly detection
   - Requires labeled datasets and centralized processing

3. Deep Learning approaches:
   - Capable of identifying complex patterns
   - Computationally intensive and often not suitable for edge deployment

A key limitation across most existing solutions is their reliance on centralized architectures, which introduces latency and single points of failure.

Recent research trends emphasize the need for distributed, edge-based detection systems that can operate in real-time and reduce dependency on centralized infrastructure.

GridShield builds upon these insights by combining edge-level data acquisition with a scalable backend for anomaly detection.