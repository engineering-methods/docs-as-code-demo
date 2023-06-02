#ifndef DIAGNOSTICS_AND_MONITORING_SYSTEM_H
#define DIAGNOSTICS_AND_MONITORING_SYSTEM_H

#include <string>

namespace demo {

    // Classes

    /**
     * @brief Vehicle system data structure.
     *
     * This class represents the data related to a vehicle system, including its name and status.
     */
    class VehicleSystem {
    public:
        std::string systemName; /**< The name of the vehicle system. */
        bool isFunctional;      /**< The status of the vehicle system (functional or malfunctioning). */
    };

    /**
     * @brief Diagnostics and Monitoring System software component.
     *
     * ```
     * {rst}
     *
     * .. sw_class:: DiagnosticsAndMonitoring
     *    :id: SW-CLS-DIAG
     *    :implements: SW-COMP-007
     * ```
     *
     * The Diagnostics and Monitoring System software component monitors vehicle health and alerts users of maintenance
     * or repair requirements. It continuously monitors key vehicle systems, detects and diagnoses faults or malfunctions,
     * provides timely notifications and alerts to the driver, logs diagnostic information, and communicates with external
     * diagnostic tools and service equipment for advanced diagnostics and repair.
     */
    class DiagnosticsAndMonitoringSystem {
    public:
        /**
         * @brief Continuously monitors key vehicle systems, including engine performance, battery health, and sensor functionality.
         *
         * @param engine The data of the engine system.
         * @param battery The data of the battery system.
         * @param sensors The data of the sensor systems.
         *
         * This function continuously monitors the key vehicle systems, such as engine performance, battery health, and
         * sensor functionality. It takes as input the data of the engine system, battery system, and sensor systems,
         * allowing it to monitor their status and detect any faults or malfunctions.
         */
        void monitorVehicleSystems(const VehicleSystem& engine, const VehicleSystem& battery, const VehicleSystem& sensors);

        /**
         * @brief Detects and diagnoses faults or malfunctions in the vehicle systems.
         *
         * @param system The data of the vehicle system to be diagnosed.
         *
         * This function detects and diagnoses faults or malfunctions in the specified vehicle system. It takes as input
         * the data of the system and performs the necessary checks and analysis to identify any issues.
         */
        void detectAndDiagnoseFaults(const VehicleSystem& system);

        /**
         * @brief Provides timely notifications and alerts to the driver regarding maintenance or repair requirements.
         *
         * @param message The notification or alert message.
         *
         * This function provides timely notifications and alerts to the driver regarding any maintenance or repair
         * requirements. It takes as input the message to be displayed or communicated to the driver, informing them of
         * the necessary actions to be taken.
         */
        void notifyDriver(const std::string& message);

        /**
         * @brief Logs diagnostic information for analysis and troubleshooting purposes.
         *
         * @param diagnosticData The diagnostic data to be logged.
         *
         * This function logs the diagnostic information for analysis and troubleshooting purposes. It takes as input
         * the diagnostic data, which may include system statuses, error codes, timestamps, or any relevant information
         * for further analysis.
         */
        void logDiagnosticInformation(const std::string& diagnosticData);

        /**
         * @brief Communicates with external diagnostic tools and service equipment for advanced diagnostics and repair.
         *
         * @param tool The external diagnostic tool or service equipment.
         *
         * This function establishes communication with external diagnostic tools or service equipment for advanced
         * diagnostics and repair. It allows the software component to exchange data or instructions with the tools or
         * equipment, facilitating more comprehensive diagnostic capabilities and repair procedures.
         */
        void communicateWithExternalTools(const std::string& tool);
    };

}  // namespace demo

#endif // DIAGNOSTICS_AND_MONITORING_SYSTEM_H
