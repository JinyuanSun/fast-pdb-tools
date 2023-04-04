from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext

ext_modules = [
    Pybind11Extension("fast_pdb_tools", ["src/pybind_pdb_reader.cpp", "src/pdb_reader.cpp"]),
]

setup(
    name="fast_pdb_tools",
    version="0.1",
    author="Jinyuan Sun",
    author_email="jinyuansun98@gmail.com",
    description="A fast PDB file manipulation tool with C++ backend",
    long_description="",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
)
