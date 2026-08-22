import heapq

def link_state_routing(graph, source):
    """
    Implements Link State Routing using Dijkstra's Algorithm.
    Returns the shortest distances and predecessors for path reconstruction.
    """
    distances = {node: float('inf') for node in graph}
    distances[source] = 0
    
    predecessors = {node: None for node in graph}

    
    pq = [(0, source)]

    while pq:
        current_distance, current_node = heapq.heappop(pq)

        if current_distance > distances[current_node]:
            continue

        for neighbor, link_cost in graph[current_node].items():
            distance = current_distance + link_cost

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                predecessors[neighbor] = current_node
                heapq.heappush(pq, (distance, neighbor))

    return distances, predecessors


def reconstruct_path(predecessors, target):
    """
    Backtracks from the target node to the source using the predecessors map.
    """
    path = []
    current = target
    while current is not None:
        path.insert(0, current)
        current = predecessors[current]
    return path


if __name__ == "__main__":
  
    network_topology = {
        'A': {'B': 2, 'C': 5},
        'B': {'A': 2, 'C': 2, 'D': 4},
        'C': {'A': 5, 'B': 2, 'D': 1, 'E': 6},
        'D': {'B': 4, 'C': 1, 'E': 2},
        'E': {'C': 6, 'D': 2}
    }

    source_router = 'A'
    distances, predecessors = link_state_routing(network_topology, source_router)

    print(f"Routing Table for Router {source_router}:")
    print("-" * 50)
    print(f"{'Destination':<15} {'Total Cost':<15} {'Optimal Path'}")
    print("-" * 50)

    for dest in sorted(network_topology.keys()):
        if dest != source_router:
            path = reconstruct_path(predecessors, dest)
            if distances[dest] == float('inf'):
                print(f"{dest:<15} {'Unreachable':<15} N/A")
            else:
                print(f"{dest:<15} {distances[dest]:<15} {' -> '.join(path)}")