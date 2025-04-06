#include <hajime/hajime.h>
#include <CLI/CLI.hpp>
#include <spdlog/spdlog.h>

int main(int argc, char** argv) {
    CLI::App app{"Hajime CLI"};
    argv = app.ensure_utf8(argv);
    std::string input_file, output_file;
    output_file = "output.jpg";
    app.add_option("-i,--input", input_file, "input image file")->required();
    app.add_option("-o,--output", output_file, "output image file. default is 'output.jpg'")->default_str(output_file);
    
    CLI11_PARSE(app, argc, argv);
    process_image_and_save(input_file, output_file);
    return 0;
}
