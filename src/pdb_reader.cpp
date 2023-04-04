// pdb_reader.cpp

#include "pdb_reader.h"
#include <fstream>
#include <sstream>

PDBReader::PDBReader(const std::string& file_path) {
    std::ifstream pdb_file(file_path);
    std::string line;

    while (std::getline(pdb_file, line)) {
        if (line.substr(0, 4) == "ATOM" || line.substr(0, 6) == "HETATM") {
            Atom atom;
            atom.serial_number = std::stoi(line.substr(6, 5));
            atom.atom_name = line.substr(12, 4);
            atom.residue_name = line.substr(17, 3);
            atom.chain_id = line[21];
            atom.residue_number = std::stoi(line.substr(22, 4));
            atom.x = std::stof(line.substr(30, 8));
            atom.y = std::stof(line.substr(38, 8));
            atom.z = std::stof(line.substr(46, 8));
            atom.occupancy = std::stof(line.substr(54, 6));
            atom.temp_factor = std::stof(line.substr(60, 6));
            atoms.push_back(atom);
        }
    }
}

const std::vector<Atom>& PDBReader::get_atoms() const {
    return atoms;
}
