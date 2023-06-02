#ifndef ENVIRONMENT_MONITORING_H
#define ENVIRONMENT_MONITORING_H

namespace demo {

    // Enums

    /**
     * @brief Enumerates the different sensor types used for environment monitoring.
     */
    enum class SensorType {
        CAMERA, /**< Camera sensor */
        RADAR, /**< Radar sensor */
        LIDAR /**< LIDAR sensor */
    };

    // Classes

    /**
     * @brief Environment Monitoring software component.
     *
     * ```
     * {rst}
     *
     * .. sw_class:: EnvironmentMonitoring
     *    :id: SW-CLS-ENVMON
     *    :implements: SW-COMP-011
     * ```
     *
     * The Environment Monitoring software component aggregates sensor data to create a full internal model of the environment
     * and algorithms to make automated decisions based on these inputs. It integrates with various sensors, processes
     * sensor data in real-time, generates a comprehensive understanding of the road, traffic, and obstacles, makes decisions
     * and plans trajectories based on the perceived environment and predefined rules, and controls the vehicle's acceleration,
     * steering, and braking systems to execute planned maneuvers while complying with safety regulations and prioritizing
     * passenger and pedestrian safety.
     */
    class EnvironmentMonitoring {
    public:
        /**
         * @brief Integrates with various sensors to perceive the surrounding environment.
         *
         * @param sensorType The type of sensor to integrate.
         *
         * This function integrates with various sensors, including cameras, radar, and LIDAR, to perceive the surrounding
         * environment. It takes as input the type of sensor to integrate and establishes the necessary communication
         * channels with the sensor hardware to receive the sensor data.
         */
        void integrateWithSensors(SensorType sensorType);

        /**
         * @brief Processes sensor data in real-time to generate a comprehensive understanding of the environment.
         *
         * This function processes sensor data in real-time to generate a comprehensive understanding of the road, traffic,
         * and obstacles. It applies computer vision, signal processing, and data fusion techniques to the received sensor
         * data, extracting relevant features and constructing an internal model of the environment for further analysis
         * and decision-making.
         */
        void processSensorData();

        /**
         * @brief Makes decisions and plans trajectories based on the perceived environment and predefined rules.
         *
         * This function makes decisions and plans trajectories based on the perceived environment and predefined rules.
         * It applies decision-making algorithms and trajectory planning techniques to analyze the internal model of the
         * environment, evaluate potential actions, and generate optimal trajectories that satisfy safety constraints,
         * traffic regulations, and predefined objectives.
         */
        void makeDecisionsAndPlanTrajectories();

        /**
         * @brief Controls the vehicle's acceleration, steering, and braking systems to execute planned maneuvers.
         *
         * This function controls the vehicle's acceleration, steering, and braking systems to execute planned maneuvers.
         * It sends commands and signals to the vehicle's control systems, adjusting the vehicle's motion parameters to
         * follow the planned trajectories and safely navigate through the environment.
         */
        void controlVehicleSystems();

        /**
         * @brief Complies with safety regulations and prioritizes passenger and pedestrian safety.
         *
         * This function ensures that the Environment Monitoring software component complies with safety regulations and
         * prioritizes passenger and pedestrian safety. It incorporates safety checks, risk assessment algorithms, and
         * collision avoidance mechanisms to avoid potential hazards and mitigate risks during automated driving operations.
         */
        void ensureSafetyCompliance();
    };

} // namespace demo

#endif // ENVIRONMENT_MONITORING_H
