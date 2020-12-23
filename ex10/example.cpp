#include <pybind11/pybind11.h>
#include <string>

namespace py = pybind11;

int add(int max_time = 3000, int n_iterations = 10) {
    return max_time + n_iterations;
}

struct Pet {
    Pet(const std::string &name) : name(name) {}

    void setName(const std::string &name_) {
        name = name_;
    }

    const std::string &getName() const {
        return name;
    }

    std::string name;
};

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin";  // optional module docstring

    m.def("add", &add, "A function which adds two numbers", py::arg("max_time") = 3000, py::arg("n_iterations") = 10);

    py::class_<Pet>(m, "Pet").def(py::init<const std::string &>()).def("setName", &Pet::setName).def("getName", &Pet::getName);
}
