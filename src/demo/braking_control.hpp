#ifndef BRAKING_CONTROL_H
#define BRAKING_CONTROL_H

#include <string>
#include <vector>

namespace demo {

    // Enumerations

    /**
     * @brief Enumeration for the ABS (Anti-lock Braking System) mode.
     */
    enum class ABSType {
        Standard,   /**< Standard ABS mode. */
        Enhanced    /**< Enhanced ABS mode. */
    };

    /**
     * @brief Enumeration for the ESC (Electronic Stability Control) mode.
     */
    enum class ESCType {
        Basic,      /**< Basic ESC mode. */
        Advanced    /**< Advanced ESC mode. */
    };

    // Classes

    /**
     * @brief Wheel speed sensor data structure.
     *
     * This class represents the data obtained from a wheel speed sensor, including the wheel ID and the speed value.
     */
    class WheelSpeedSensor {
    public:
        int wheelId;    /**< The ID of the wheel. */
        float speed;    /**< The speed value of the wheel. */
    };

    /**
     * @brief Road condition data structure.
     *
     * This class represents the data about the current road conditions, including information about traction, grip, and surface conditions.
     */
    class RoadConditionData {
    public:
        float traction;     /**< The traction value of the road. */
        float grip;         /**< The grip value of the road. */
        std::string surface;/**< The surface condition of the road. */
    };

    /**
     * @brief Braking Control software component.
     *
     * ```
     * {rst}
     *
     * .. sw_class:: BrakingControl
     *    :id: SW-CLS-BRAKECTL
     *    :implements: SW-COMP-005
     * ```
     *
     * The Braking Control software component integrates ABS and ESC functionality to enhance vehicle safety and stability
     * during braking maneuvers. It receives input from wheel speed sensors to detect wheel lock-up, applies appropriate
     * braking pressure to individual wheels to prevent lock-up and maintain vehicle stability. It works in conjunction
     * with the ABS to provide smooth and controlled braking and with the ESC to enhance vehicle stability during braking
     * maneuvers. It also provides rapid response and modulation of braking force to adapt to changing road conditions.
     */
    class BrakingControl {
    public:
        /**
         * @brief Receives input from wheel speed sensors to detect wheel lock-up.
         *
         * @param wheelSpeeds The wheel speed data from the sensors.
         *
         * This function reads the wheel speed data from the sensors and analyzes it to detect any wheel lock-up
         * conditions during braking maneuvers.
         */
        void receiveWheelSpeedInput(const std::vector<WheelSpeedSensor>& wheelSpeeds);

        /**
         * @brief Applies appropriate braking pressure to individual wheels to prevent lock-up and maintain vehicle stability.
         *
         * @param wheelPressure The desired braking pressure for each wheel.
         *
         * This function controls the braking system by applying the appropriate braking pressure to individual wheels
         * based on the input data. It ensures that the wheels do not lock up during braking and helps maintain vehicle
         * stability.
         */
        void applyBrakingPressure(const std::vector<float>& wheelPressure);

        /**
         * @brief Works in conjunction with the ABS to provide smooth and controlled braking.
         *
         * @param absMode The mode of operation for the ABS.
         *
         * This function collaborates with the ABS system to provide smooth and controlled braking. It adjusts the ABS
         * mode of operation based on input parameters to optimize braking performance and prevent wheel lock-up.
         */
        void collaborateWithABS(ABSType absMode);

        /**
         * @brief Works in conjunction with the ESC to enhance vehicle stability during braking maneuvers.
         *
         * @param escMode The mode of operation for the ESC.
         *
         * This function cooperates with the ESC system to enhance vehicle stability during braking maneuvers. It adjusts
         * the ESC mode of operation based on input parameters to optimize stability control and prevent skidding or loss
         * of control.
         */
        void collaborateWithESC(ESCType escMode);

        /**
         * @brief Provides rapid response and modulation of braking force to adapt to changing road conditions.
         *
         * @param roadCondition The current road condition data.
         *
         * This function continuously monitors the road conditions and adapts the braking force and response accordingly.
         * It takes into account factors such as traction, grip, and surface conditions to ensure optimal braking
         * performance and vehicle safety.
         */
        void adaptToRoadConditions(const RoadConditionData& roadCondition);
    };

}  // namespace demo

#endif // BRAKING_CONTROL_H
