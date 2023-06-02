Software Components
===================

.. sw_comp:: Advanced Driver Assistance System
   :id: SW-COMP-001
   :tags: ADAS, software, safety, camera, lidar
   :implements: SW-REQ-001, SW-REQ-005

   The ADAS software component integrates various algorithms and sensors to provide advanced driver assistance
   features, including pedestrian detection.

   **Specification:**

   - The ADAS software component shall utilize computer vision algorithms for pedestrian detection.
   - The component shall receive input from front-facing cameras and LIDAR sensors.
   - The component shall analyze video feeds in real-time to identify pedestrians and estimate their positions.
   - The component shall provide timely alerts to the driver in case of potential collisions with pedestrians.
   - The component shall work in conjunction with the braking control system to assist in emergency braking if necessary.

.. sw_comp:: Infotainment System
   :id: SW-COMP-002
   :tags: infotainment, software
   :implements: SW-REQ-002, SW-REQ-007, SW-REQ-010

   The infotainment software component enables smartphone integration, navigation services, and voice control
   functionalities.

   **Specification:**

   - The infotainment software component shall provide seamless integration with smartphones via Bluetooth.
   - The component shall support popular smartphone platforms, including iOS and Android.
   - The component shall enable hands-free calling, music streaming, and access to contacts.
   - The component shall provide a user-friendly interface for navigation services, including turn-by-turn directions and real-time traffic updates.
   - The component shall incorporate voice recognition technology to allow users to interact with the system using voice commands.

.. sw_comp:: Powertrain Control
   :id: SW-COMP-003
   :tags: powertrain, software
   :implements: SW-REQ-004, SW-REQ-006, SW-REQ-016

   The powertrain control software component manages hybrid/electric power distribution, optimizing
   performance and energy efficiency.

   **Specification:**

   - The powertrain control software component shall monitor battery charge level and optimize power
     distribution between the electric motor and internal combustion engine.
   - The component shall adjust torque delivery based on driving conditions and driver input to provide smooth
     acceleration and efficient power usage.
   - The component shall incorporate regenerative braking to capture and store energy during deceleration.
   - The component shall provide different driving modes, such as Eco and Sport, with varying power
     characteristics and efficiency settings.
   - The component shall communicate with the instrument cluster to display relevant information, such as energy
     usage and driving range.


.. sw_comp:: Climate Control
   :id: SW-COMP-004
   :tags: climate control, software
   :implements: SW-REQ-003

   The climate control software component regulates temperature and air distribution to ensure optimal cabin comfort.

   **Specification:**

   - The component shall receive input from temperature sensors located inside the cabin.
   - The component shall control the operation of the HVAC (Heating, Ventilation, and Air Conditioning) system.
   - The component shall provide automatic temperature control based on user-defined settings.
   - The component shall adjust air distribution to different zones within the cabin, such as driver and passenger areas.
   - The component shall integrate with the vehicle's occupancy sensors to optimize temperature settings based on passenger presence.

.. sw_comp:: Braking Control
   :id: SW-COMP-005
   :tags: safety, braking, software
   :implements: SW-REQ-008, SW-REQ-019

   The braking control software component integrates ABS and ESC functionality to enhance vehicle safety and
   stability during braking maneuvers.

   **Specification:**

   - The braking control software component shall receive input from wheel speed sensors to detect wheel lock-up.
   - The component shall apply appropriate braking pressure to individual wheels to prevent wheel lock-up and maintain vehicle stability.
   - The component shall work in conjunction with the ABS (Anti-lock Braking System) to provide smooth and controlled braking.
   - The component shall work in conjunction with the ESC (Electronic Stability Control) to enhance vehicle stability during braking maneuvers.
   - The component shall provide rapid response and modulation of braking force to adapt to changing road conditions.

.. sw_comp:: Connectivity System
   :id: SW-COMP-006
   :tags: connectivity, software, infotainment
   :implements: SW-REQ-002, SW-REQ-007, SW-REQ-014, SW-REQ-018

   The connectivity software component handles smartphone integration, Wi-Fi connectivity, and multimedia
   system interaction.

   **Specification:**

   - The connectivity software component shall enable seamless integration with smartphones via Bluetooth and USB connections.
   - The component shall support phone call management, including call handling and contact synchronization.
   - The component shall provide media streaming capabilities, allowing users to play music and other media files from their smartphones.
   - The component shall support Wi-Fi connectivity for internet access and software updates.
   - The component shall integrate with the multimedia system to enable user-friendly interaction and control.

.. sw_comp:: Diagnostics and Monitoring System
   :id: SW-COMP-007
   :tags: diagnostics, software
   :implements: SW-REQ-020

   The diagnostics and monitoring software component monitors vehicle health and alerts users of maintenance
   or repair requirements.

   **Specification:**

   - The diagnostics and monitoring software component shall continuously monitor key vehicle systems, including engine performance, battery health, and sensor functionality.
   - The component shall detect and diagnose faults or malfunctions in the vehicle systems.
   - The component shall provide timely notifications and alerts to the driver regarding maintenance or repair requirements.
   - The component shall log diagnostic information for analysis and troubleshooting purposes.
   - The component shall communicate with external diagnostic tools and service equipment for advanced diagnostics and repair.

.. sw_comp:: Noice Cancellation System
   :id: SW-COMP-008
   :tags: noise cancellation, software
   :implements: SW-REQ-017

   The noise cancellation software component analyzes and counteracts unwanted cabin noise to provide a quiet
   driving experience.

   **Specification:**

   - The noise cancellation software component shall receive input from microphones strategically placed inside the cabin.
   - The component shall analyze the captured audio signals to identify unwanted noise sources.
   - The component shall generate anti-noise signals to counteract the identified noise sources.
   - The component shall adjust the anti-noise signals in real-time to match the characteristics of the unwanted noise.
   - The component shall integrate with the vehicle's audio system to deliver the anti-noise signals to the cabin speakers.

.. sw_comp:: Camera Processing System
   :id: SW-COMP-009
   :tags: camera processing, software
   :implements: SW-REQ-015

   The camera processing software component processes video feeds from rearview cameras and enhances
   visibility with visual aids.

   **Specification:**

   - The camera processing software component shall receive video feeds from rearview cameras installed on the vehicle.
   - The component shall enhance video quality, including brightness, contrast, and sharpness adjustments.
   - The component shall provide visual aids such as parking guidelines and object detection overlays.
   - The component shall support multiple viewing modes, including wide-angle and zoomed-in views.
   - The component shall integrate with the vehicle's display system to present the processed video feeds to the driver.

.. sw_comp:: Voice Interface
   :id: SW-COMP-010
   :tags: voice recognition, natural language processing, infotainment, software
   :implements: SW-REQ-010

   The Voice interface software implements a robust and precice voice recognition, voice feedback and the
   possibility to query all vehicle data and to control a fixed set of vehicle functions.

   **Specification:**

   - The voice recognition software component shall capture and process voice commands from the driver.
   - The component shall support a wide range of natural language commands for various vehicle functions.
   - The component shall accurately recognize and interpret voice commands, even in noisy environments.
   - The component shall provide voice feedback and confirmation for executed commands.
   - The component shall continuously adapt and improve its voice recognition capabilities through machine learning algorithms.


.. sw_comp:: Environment Monitoring
   :id: SW-COMP-011
   :tags: safety, environment, software
   :implements: SW-REQ-001, SW-REQ-016
   :relates: SW-COMP-001

   The environment monitoring system aggregates all sensor data to create a full internal model of the environment
   and algorithms to make automated decisions based on these inputs.

   **Specification:**

   - The autonomous driving software component shall integrate with various sensors, including cameras, radar,
     and LIDAR, to perceive the surrounding environment.
   - The component shall process sensor data in real-time to generate a comprehensive understanding of the road,
     traffic, and obstacles.
   - The component shall make decisions and plan trajectories based on the perceived environment and
     predefined rules.
   - The component shall control the vehicle's acceleration, steering, and braking systems to execute planned
     maneuvers.
   - The component shall comply with safety regulations and prioritize passenger and pedestrian safety.

.. sw_comp:: Battery Control
   :id: SW-COMP-012
   :tags: battery, monitoring, software
   :implements: SW-REQ-001, SW-REQ-020

   The battery control software component controls, monitors and optimizes battery usage.

   **Specification:**

   - The battery management software component shall monitor the battery's state of charge, voltage, and
     temperature.
   - The component shall optimize charging and discharging strategies to extend battery life and maximize
     performance.
   - The component shall protect the battery from overcharging, over-discharging, and overheating conditions.
   - The component shall provide information about the battery's health, remaining capacity, and estimated
     range to the driver.
   - The component shall integrate with the vehicle's powertrain control system to ensure efficient power
     distribution and usage.
