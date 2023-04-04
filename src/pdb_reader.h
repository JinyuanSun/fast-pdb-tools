// pdb_reader.h

#include <string>
#include <vector>

struct Atom {
    int serial_number;
    std::string atom_name;
    std::string residue_name;
    char chain_id;
    int residue_number;
    float x, y, z;
    float occupancy;
    float temp_factor;
};

class PDBReader {
public:
    PDBReader(const std::string& file_path);
    const std::vector<Atom>& get_atoms() const;

private:
    std::vector<Atom> atoms;
};
