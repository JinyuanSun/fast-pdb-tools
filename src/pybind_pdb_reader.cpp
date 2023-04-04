// pybind_pdb_reader.cpp

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "pdb_reader.h"

namespace py = pybind11;

PYBIND11_MODULE(fast_pdb_tools, m) {
    py::class_<Atom>(m, "Atom")
        .def_readonly("serial_number", &Atom::serial_number)
        .def_readonly("atom_name", &Atom::atom_name)
        .def_readonly("residue_name", &Atom::residue_name)
        .def_readonly("chain_id", &Atom::chain_id)
        .def_readonly("residue_number", &Atom::residue_number)
        .def_readonly("x", &Atom::x)
        .def_readonly("y", &Atom::y)
        .def_readonly("z", &Atom::z)
        .def_readonly("occupancy", &Atom::occupancy)
        .def_readonly("temp_factor", &Atom::temp_factor);

    py::class_<PDBReader>(m, "PDBReader")
        .def(py::init<const std::string &>())
        .def("get_atoms", &PDBReader::get_atoms);
}

