#ifndef CAMERA_PROCESSING_SYSTEM_H
#define CAMERA_PROCESSING_SYSTEM_H

#include <string>
#include <vector>
#include "camera.hpp"

namespace demo {

    // Classes

    /**
     * @brief Camera Processing System software component.
     *
     * ```
     * {rst}
     *
     * .. sw_class:: CameraProcessingSystem
     *    :id: SW-CLS-CAMERAPROC
     *    :implements: SW-COMP-009
     * ```
     *
     * The Camera Processing System software component processes video feeds from rearview cameras and enhances visibility
     * with visual aids. It receives video feeds from rearview cameras, enhances video quality, provides visual aids
     * such as parking guidelines and object detection overlays, supports multiple viewing modes, and integrates with
     * the vehicle's display system to present the processed video feeds to the driver.
     */
    class CameraProcessingSystem {
    public:
        /**
         * @brief Receives video feeds from rearview cameras installed on the vehicle.
         *
         * @param cameras The data of the rearview cameras.
         *
         * This function receives video feeds from rearview cameras installed on the vehicle. It takes as input the data
         * of the cameras, including their positions and captured video feeds, allowing the software component to process
         * the video data for visibility enhancement.
         */
        void receiveCameraFeeds(const std::vector<Camera>& cameras);

        /**
         * @brief Enhances video quality, including brightness, contrast, and sharpness adjustments.
         *
         * @param videoFeed The video feed from the camera.
         *
         * This function enhances the video quality of the camera feed. It takes as input the video feed captured by the
         * camera and applies image processing techniques, such as adjusting brightness, contrast, and sharpness, to
         * improve visibility and image clarity.
         */
        void enhanceVideoQuality(cv::Mat& videoFeed);

        /**
         * @brief Provides visual aids such as parking guidelines and object detection overlays.
         *
         * @param videoFeed The video feed from the camera.
         *
         * This function provides visual aids on the camera feed, such as parking guidelines and object detection overlays.
         * It takes as input the video feed captured by the camera and overlays graphical elements on the video to assist
         * the driver in parking maneuvers and object detection.
         */
        void provideVisualAids(cv::Mat& videoFeed);

        /**
         * @brief Supports multiple viewing modes, including wide-angle and zoomed-in views.
         *
         * @param viewingMode The desired viewing mode.
         * @param videoFeed The video feed from the camera.
         *
         * This function supports multiple viewing modes for the camera feed. It takes as input the desired viewing mode,
         * such as wide-angle or zoomed-in, and adjusts the camera feed accordingly to provide the requested view to the driver.
         */
        void setViewingMode(const std::string& viewingMode, cv::Mat& videoFeed);

        /**
         * @brief Integrates with the vehicle's display system to present the processed video feeds to the driver.
         *
         * @param videoFeed The processed video feed to be displayed.
         *
         * This function integrates with the vehicle's display system to present the processed video feed to the driver.
         * It takes as input the processed video feed and interfaces with the display system, ensuring that the video
         * is appropriately rendered and presented to the driver.
         */
        void displayVideoFeed(const cv::Mat& videoFeed);
    };

} // namespace demo

#endif // CAMERA_PROCESSING_SYSTEM_H
