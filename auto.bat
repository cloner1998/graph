echo salam %*
cmake-build-debug\graph.exe > graph.dot && dot -Tpdf graph.dot -o graph.pdf
