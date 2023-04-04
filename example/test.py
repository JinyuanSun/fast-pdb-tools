from fast_pdb_tools import PDBReader
from Bio.PDB import PDBParser
import time

def cpp():
    pdb_file_path = "5xh3_prot.pdb"
    pdb_reader = PDBReader(pdb_file_path)
    atoms = pdb_reader.get_atoms()

    # for atom in atoms:
        # print(f"Atom: {atom.atom_name}, Residue: {atom.residue_name}, Chain: {atom.chain_id}, Position: ({atom.x}, {atom.y}, {atom.z}), Occupancy: {atom.occupancy}, B-Factor: {atom.temp_factor}")
def py():
    pdb_file_path = "5xh3_prot.pdb"
    parser = PDBParser()
    structure = parser.get_structure("5xh3", pdb_file_path)
    atoms = structure.get_atoms()

    # for atom in atoms:
        # print(f"Atom: {atom.name}, Residue: {atom.parent.resname}, Chain: {atom.parent.parent.id}, Position: ({atom.coord[0]}, {atom.coord[1]}, {atom.coord[2]}), Occupancy: {atom.occupancy}, B-Factor: {atom.bfactor}")

if __name__ == "__main__":
    start_time = time.time()
    i = 0
    while i < 100:
        cpp()
        i += 1
    print(f"Time taken by C++: {time.time() - start_time}")
    start_time = time.time()
    i = 0
    while i < 100:
        py()
        i += 1
    print(f"Time taken by Python: {time.time() - start_time}")
