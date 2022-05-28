import networkx as nx
import sys

with open("output.txt", "w+") as file:

    if len(sys.argv) < 3:
        file.write("-2 -> -2\n")
        exit(1)

    n = int(sys.argv[1])
    p = min(float(sys.argv[2]), 1.0)

    G = nx.erdos_renyi_graph(n, p)

    while not nx.is_connected(G):
        G = nx.erdos_renyi_graph(n, p)

    G = nx.eulerize(G)

    for line in nx.generate_adjlist(G):
        data = line.split()
        for i in range(1, len(data)):
            file.write(f"{data[0]} -> {data[i]}\n")

    file.write("-1 -> -1\n")