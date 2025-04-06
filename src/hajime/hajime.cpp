#include <opencv2/opencv.hpp>
#include <spdlog/spdlog.h>
#include <filesystem>
#include <hajime/hajime.h>

void process_image_and_save(const std::filesystem::path& input_path, const std::filesystem::path& output_path) {
    // Read the image
    cv::Mat image = cv::imread(input_path.string());
    if (image.empty()) {
        spdlog::error("Failed to read image: {}", input_path.string());
        return;
    }

    // Process the image (example: convert to grayscale)
    cv::Mat gray_image;
    cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);
    cv::Canny(gray_image, gray_image, 100, 200);

    // Save the processed image
    if (!cv::imwrite(output_path.string(), gray_image)) {
        spdlog::error("Failed to save image: {}", output_path.string());
    } else {
        spdlog::info("Processed and saved image: {}", output_path.string());
    }
}

