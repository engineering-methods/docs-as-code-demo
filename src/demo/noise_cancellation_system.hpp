#ifndef NOISE_CANCELLATION_SYSTEM_H
#define NOISE_CANCELLATION_SYSTEM_H

#include <string>
#include <vector>

namespace demo {

    // Classes

    /**
     * @brief Microphone data structure.
     *
     * This class represents the data related to a microphone, including its position and captured audio signals.
     */
    class Microphone {
    public:
        std::string position;    /**< The position of the microphone inside the cabin. */
        std::vector<double> audioSignals; /**< The captured audio signals by the microphone. */
    };

    /**
     * @brief Noise Cancellation System software component.
     *
     * ```
     * {rst}
     *
     * .. sw_class:: NoiseCancellationSystem
     *    :id: SW-CLS-NOISECANCEL
     *    :implements: SW-COMP-008
     * ```
     *
     * The Noise Cancellation System software component analyzes and counteracts unwanted cabin noise to provide a quiet
     * driving experience. It receives input from strategically placed microphones inside the cabin, analyzes the captured
     * audio signals, generates anti-noise signals to counteract the identified noise sources, adjusts the anti-noise
     * signals in real-time, and integrates with the vehicle's audio system to deliver the anti-noise signals to the cabin
     * speakers.
     */
    class NoiseCancellationSystem {
    public:
        /**
         * @brief Receives input from microphones strategically placed inside the cabin.
         *
         * @param microphones The data of the microphones.
         *
         * This function receives input from the microphones placed at strategic locations inside the cabin. It takes as
         * input the data of the microphones, including their positions and captured audio signals, allowing the software
         * component to analyze and process the audio data for noise cancellation.
         */
        void receiveMicrophoneInput(const std::vector<Microphone>& microphones);

        /**
         * @brief Analyzes the captured audio signals to identify unwanted noise sources.
         *
         * @param audioSignals The captured audio signals from the microphones.
         *
         * This function analyzes the captured audio signals to identify unwanted noise sources. It takes as input the
         * audio signals captured by the microphones and performs signal processing techniques to analyze the frequency,
         * amplitude, and other characteristics of the noise.
         */
        void analyzeAudioSignals(const std::vector<double>& audioSignals);

        /**
         * @brief Generates anti-noise signals to counteract the identified noise sources.
         *
         * @param noiseSources The identified noise sources.
         *
         * This function generates anti-noise signals to counteract the identified noise sources. It takes as input the
         * identified noise sources and applies algorithms, such as adaptive filtering, to generate anti-noise signals
         * that are capable of canceling out the unwanted noise.
         */
        void generateAntiNoiseSignals(const std::vector<std::string>& noiseSources);

        /**
         * @brief Adjusts the anti-noise signals in real-time to match the characteristics of the unwanted noise.
         *
         * @param noiseCharacteristics The characteristics of the unwanted noise.
         *
         * This function adjusts the anti-noise signals in real-time to match the characteristics of the unwanted noise.
         * It takes as input the characteristics of the unwanted noise, such as its frequency spectrum and amplitude,
         * and dynamically modifies the anti-noise signals to provide optimal noise cancellation performance.
         */
        void adjustAntiNoiseSignals(const std::string& noiseCharacteristics);

        /**
         * @brief Integrates with the vehicle's audio system to deliver the anti-noise signals to the cabin speakers.
         *
         * @param antiNoiseSignals The anti-noise signals to be delivered.
         *
         * This function integrates with the vehicle's audio system to deliver the generated anti-noise signals to the
         * cabin speakers. It takes as input the anti-noise signals and interfaces with the audio system, ensuring that
         * the cancellation signals are appropriately mixed and delivered to provide a quiet driving experience for the
         * occupants.
         */
        void deliverAntiNoiseSignals(const std::vector<double>& antiNoiseSignals);
    };

} // namespace demo

#endif // NOISE_CANCELLATION_SYSTEM_H
