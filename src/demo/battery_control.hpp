#ifndef BATTERY_CONTROL_H
#define BATTERY_CONTROL_H

#include <string>

namespace demo {

    // Enums

    /**
     * @brief Enum representing the state of charge of the battery.
     */
    enum class BatteryStateOfCharge {
        LOW,        ///< Low state of charge
        MEDIUM,     ///< Medium state of charge
        HIGH        ///< High state of charge
    };

    /**
     * @brief Enum representing the health status of the battery.
     */
    enum class BatteryHealth {
        GOOD,       ///< Good battery health
        FAIR,       ///< Fair battery health
        POOR        ///< Poor battery health
    };

    // Classes

    /**
     * @brief Battery Control software component.
     *
     * ```
     * {rst}
     *
     * .. sw_class:: BatteryControl
     *    :id: SW-CLS-BATTERY
     *    :implements: SW-COMP-012
     * ```
     *
     * The Battery Control software component controls, monitors, and optimizes battery usage. It is responsible for monitoring
     * the battery's state of charge, voltage, and temperature, optimizing charging and discharging strategies to extend battery
     * life and maximize performance, protecting the battery from overcharging, over-discharging, and overheating conditions,
     * providing information about the battery's health, remaining capacity, and estimated range to the driver, and integrating
     * with the vehicle's powertrain control system to ensure efficient power distribution and usage.
     */
    class BatteryControl {
    public:
        /**
         * @brief Monitors the battery's state of charge, voltage, and temperature.
         *
         * @param stateOfCharge The current state of charge of the battery.
         * @param voltage The current voltage of the battery.
         * @param temperature The current temperature of the battery.
         */
        void monitorBattery(BatteryStateOfCharge stateOfCharge, float voltage, float temperature);

        /**
         * @brief Optimizes charging and discharging strategies to extend battery life and maximize performance.
         *
         * @param usagePattern The desired usage pattern for the battery.
         */
        void optimizeBatteryUsage(const std::string& usagePattern);

        /**
         * @brief Protects the battery from overcharging, over-discharging, and overheating conditions.
         *
         * @param chargingRate The current charging rate of the battery.
         * @param dischargingRate The current discharging rate of the battery.
         */
        void protectBattery(float chargingRate, float dischargingRate);

        /**
         * @brief Provides information about the battery's health, remaining capacity, and estimated range to the driver.
         *
         * @return The battery's health status.
         */
        BatteryHealth provideBatteryInformation();

        /**
         * @brief Integrates with the vehicle's powertrain control system for efficient power distribution and usage.
         *
         * @param powerDemand The current power demand of the vehicle.
         */
        void integrateWithPowertrainControl(float powerDemand);
    };

} // namespace demo

#endif // BATTERY_CONTROL_H
