
#ifndef CLIMATE_CONTROL_H
#define CLIMATE_CONTROL_H

#include <vector>

namespace demo {

    /**
     * @brief Climate Control software component.
     *
     * ```
     * {rst}
     *
     * .. sw_class:: ClimateControl
     *    :id: SW-CLS-CLIMATE
     *    :implements: SW-COMP-004
     * ```
     *
     * The Climate Control software component regulates temperature and air distribution to ensure optimal cabin comfort.
     * It receives input from temperature sensors, controls the operation of the HVAC system, and provides automatic
     * temperature control based on user-defined settings. It also adjusts air distribution to different zones within
     * the cabin, such as driver and passenger areas, and integrates with the vehicle's occupancy sensors to optimize
     * temperature settings based on passenger presence.
     */
    class ClimateControl {
    public:
        /**
         * @brief Receives input from temperature sensors located inside the cabin.
         *
         * @param sensors The temperature sensors inside the cabin.
         *
         * This function reads the temperature measurements from the sensors and updates the internal state
         * of the Climate Control software component.
         */
        void receiveTemperatureInput(const std::vector<TemperatureSensor>& sensors);

        /**
         * @brief Controls the operation of the HVAC system.
         *
         * @param fanSpeed The desired fan speed.
         * @param compressorState The state of the compressor (ON/OFF).
         *
         * This function communicates with the HVAC system to control its operation, such as adjusting the fan speed,
         * controlling the compressor, and managing air circulation.
         */
        void controlHVACSystem(int fanSpeed, bool compressorState);

        /**
         * @brief Provides automatic temperature control based on user-defined settings.
         *
         * @param desiredTemperature The desired temperature set by the user.
         * @param outsideTemperature The current outside temperature.
         *
         * This function uses the input from the temperature sensors and the user-defined settings to automatically
         * adjust the temperature inside the cabin. It takes into account factors such as desired temperature, outside
         * temperature, and passenger preferences to maintain a comfortable environment.
         */
        void automaticTemperatureControl(float desiredTemperature, float outsideTemperature);

        /**
         * @brief Adjusts air distribution to different zones within the cabin.
         *
         * @param driverVentLevel The level of air distribution for the driver zone.
         * @param passengerVentLevel The level of air distribution for the passenger zone.
         *
         * This function controls the air distribution vents inside the cabin to direct the airflow to different zones,
         * such as the driver and passenger areas, based on user preferences and the desired temperature settings.
         */
        void adjustAirDistribution(int driverVentLevel, int passengerVentLevel);

        /**
         * @brief Integrates with the vehicle's occupancy sensors to optimize temperature settings based on passenger presence.
         *
         * @param occupancyData The data from the occupancy sensors indicating the presence of passengers.
         *
         * This function utilizes the information from the vehicle's occupancy sensors to optimize the temperature
         * settings based on the number of occupants in the cabin. It adjusts the temperature distribution and airflow
         * to provide personalized comfort for each passenger.
         */
        void optimizeTemperatureSettings(const OccupancyData& occupancyData);
    };

}  // namespace demo

#endif // CLIMATE_CONTROL_H
