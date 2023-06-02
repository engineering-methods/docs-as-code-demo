#ifndef CAMERA_H
#define CAMERA_H

#include <string>

namespace demo {

/**
 * @brief Represents a camera in the Advanced Driver Assistance System.
 */
class Camera {
public:
    /**
     * @brief Constructs a Camera object with the specified ID.
     * @param id The ID of the camera.
     */
    explicit Camera(const std::string& id) : id(id) {}

    /**
     * @brief Captures a frame from the camera.
     * @return The captured frame.
     */
    Frame captureFrame() {
        // Implementation code here
    }

private:
    std::string id; ///< The ID of the camera.
};

} // namespace demo

#endif // CAMERA_H
