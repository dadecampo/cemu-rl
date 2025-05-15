#include <pybind11/pybind11.h>
#include <string>

namespace py = pybind11;

class SoftwareController {
public:
    SoftwareController() : running(false) {}

    void start() {
        running = true;
    }

    void stop() {
        running = false;
    }

    std::string get_status() const {
        return running ? "Running" : "Stopped";
    }

private:
    bool running;
};

PYBIND11_MODULE(TestPythonLibrary1, m) {
    py::class_<SoftwareController>(m, "SoftwareController")
        .def(py::init<>())
        .def("start", &SoftwareController::start)
        .def("stop", &SoftwareController::stop)
        .def("get_status", &SoftwareController::get_status);
}
