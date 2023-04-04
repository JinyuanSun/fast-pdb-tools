# fast-pdb-tools
A PDB tool designed to be light and faster.

## Install

```bash
pip install pybind11
git clone https://github.com/JinyuanSun/fast-pdb-tools.git
cd fast-pdb-tools
pip install .
```

## 1. fast pdb reader

```python
from fast_pdb_tools import PDBReader
pdb_file_path = "5xh3_prot.pdb"
pdb_reader = PDBReader(pdb_file_path)
atoms = pdb_reader.get_atoms() # a list of all atoms, ATOM or HETATM
```

To compare with biopython:

```bash
# pip install bio
# my env: python=3.8.13, biopython=1.79
cd example
python test.py

Time taken by C++: 0.21043920516967773
Time taken by Python: 2.1490983963012695
```

## Dev log
1. 04Apr23: Started this project.
2. [TODO] 05Apr23: Save atom of protein to [L, 14, 3]