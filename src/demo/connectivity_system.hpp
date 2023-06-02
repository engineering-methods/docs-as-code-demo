#ifndef CONNECTIVITY_SYSTEM_H
#define CONNECTIVITY_SYSTEM_H

#include <string>

namespace demo {

    // Enumerations

    /**
     * @brief Enumeration for the type of smartphone connection.
     */
    enum class SmartphoneConnectionType {
        Bluetooth,  /**< Bluetooth smartphone connection. */
        USB         /**< USB smartphone connection. */
    };

    // Classes

    /**
     * @brief Phone call data structure.
     *
     * This class represents the data related to a phone call, including the caller's name and contact information.
     */
    class PhoneCall {
    public:
        std::string callerName;     /**< The name of the caller. */
        std::string contactInfo;    /**< The contact information of the caller. */
    };

    /**
     * @brief Media file data structure.
     *
     * This class represents the data of a media file, including the file name, format, and location.
     */
    class MediaFile {
    public:
        std::string fileName;   /**< The name of the media file. */
        std::string format;     /**< The format of the media file. */
        std::string location;   /**< The location of the media file. */
    };

    /**
     * @brief Connectivity System software component.
     *
     * ```
     * {rst}
     *
     * .. sw_class:: ConnectivitySystem
     *    :id: SW-CLS-CONNECT
     *    :implements: SW-COMP-006
     * ```
     *
     * The Connectivity System software component handles smartphone integration, Wi-Fi connectivity, and multimedia
     * system interaction. It enables seamless integration with smartphones via Bluetooth and USB connections, supports
     * phone call management and media streaming capabilities, provides Wi-Fi connectivity for internet access and
     * software updates, and integrates with the multimedia system for user-friendly interaction and control.
     */
    class ConnectivitySystem {
    public:
        /**
         * @brief Enables seamless integration with smartphones via Bluetooth and USB connections.
         *
         * @param connectionType The type of smartphone connection.
         *
         * This function establishes a connection between the vehicle's connectivity system and a smartphone using the
         * specified connection type (Bluetooth or USB), enabling seamless integration and communication between the two
         * devices.
         */
        void enableSmartphoneIntegration(SmartphoneConnectionType connectionType);

        /**
         * @brief Handles phone call management, including call handling and contact synchronization.
         *
         * @param phoneCall The data of the phone call.
         *
         * This function handles phone call management tasks, such as answering or rejecting incoming calls, initiating
         * outgoing calls, and synchronizing contact information between the connected smartphone and the vehicle's
         * system.
         */
        void managePhoneCalls(const PhoneCall& phoneCall);

        /**
         * @brief Provides media streaming capabilities, allowing users to play music and other media files from their smartphones.
         *
         * @param mediaFile The data of the media file.
         *
         * This function enables media streaming from a connected smartphone, allowing users to play music and other
         * media files through the vehicle's multimedia system. It takes as input the data of the media file to be
         * streamed.
         */
        void streamMedia(const MediaFile& mediaFile);

        /**
         * @brief Supports Wi-Fi connectivity for internet access and software updates.
         *
         * This function enables Wi-Fi connectivity for the vehicle's system, providing internet access for various
         * services and enabling software updates over the air.
         */
        void enableWiFiConnectivity();

        /**
         * @brief Integrates with the multimedia system to enable user-friendly interaction and control.
         *
         * This function integrates the connectivity system with the vehicle's multimedia system, allowing for
         * user-friendly interaction and control. It enables seamless access to connected smartphone features, media
         * playback controls, and other connectivity-related functionalities.
         */
        void integrateWithMultimediaSystem();
    };

}  // namespace demo

#endif // CONNECTIVITY_SYSTEM_H
