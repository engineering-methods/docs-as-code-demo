#ifndef VOICE_INTERFACE_H
#define VOICE_INTERFACE_H

#include <string>

namespace demo {

    // Classes

    /**
     * @brief Voice Interface software component.
     *
     * ```
     * {rst}
     *
     * .. sw_class:: VoiceInterface
     *    :id: SW-CLS-VOICE
     *    :implements: SW-COMP-010
     * ```
     *
     * The Voice Interface software component implements robust and precise voice recognition, voice feedback, and the
     * capability to query all vehicle data and control a fixed set of vehicle functions. It captures and processes voice
     * commands from the driver, supports a wide range of natural language commands, accurately recognizes and interprets
     * voice commands even in noisy environments, provides voice feedback and confirmation for executed commands, and
     * continuously adapts and improves its voice recognition capabilities through machine learning algorithms.
     */
    class VoiceInterface {
    public:
        /**
         * @brief Captures and processes voice commands from the driver.
         *
         * @return The recognized voice command.
         *
         * This function captures and processes voice commands from the driver. It uses audio input devices to capture
         * the voice input, performs signal processing and feature extraction on the captured audio, and applies voice
         * recognition algorithms to convert the voice input into a recognized command.
         */
        std::string captureAndProcessVoiceCommand();

        /**
         * @brief Supports a wide range of natural language commands for various vehicle functions.
         *
         * @param voiceCommand The recognized voice command.
         *
         * This function supports a wide range of natural language commands for various vehicle functions. It takes
         * as input the recognized voice command and maps it to the corresponding vehicle function or query. The function
         * performs natural language processing and command interpretation to identify the intended action or query
         * based on the voice command.
         */
        void processNaturalLanguageCommands(const std::string& voiceCommand);

        /**
         * @brief Provides voice feedback and confirmation for executed commands.
         *
         * @param feedback The voice feedback message.
         *
         * This function provides voice feedback and confirmation for executed commands. It takes as input the feedback
         * message to be communicated to the driver, and it uses audio output devices to deliver the feedback in the
         * form of voice prompts or synthesized speech, ensuring that the driver receives clear and understandable feedback.
         */
        void provideVoiceFeedback(const std::string& feedback);

        /**
         * @brief Continuously adapts and improves voice recognition capabilities through machine learning algorithms.
         *
         * This function continuously adapts and improves the voice recognition capabilities of the software component
         * through machine learning algorithms. It leverages collected voice data and user feedback to train and update
         * the voice recognition models, enhancing the accuracy and robustness of the voice recognition system over time.
         */
        void continuouslyAdaptVoiceRecognition();
    };

} // namespace demo

#endif // VOICE_INTERFACE_H
