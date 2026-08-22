import random

distances = [
    [0, 10, 15, 20],
    [10, 0, 35, 25],
    [15, 35, 0, 30],
    [20, 25, 30, 0]
]

def get_cost(tour):
    """Calculates the total distance of the route."""
    total = 0
    for i in range(len(tour)):
        current_city = tour[i]s
        next_city = tour[(i + 1) % len(tour)] 
        total += distances[current_city][next_city]
    return total

def get_neighbors(tour):
    """Generates new routes by swapping two cities."""
    neighbors = []
    for i in range(1, len(tour)):
        for j in range(i + 1, len(tour)):
            new_tour = list(tour)             
            new_tour[i], new_tour[j] = new_tour[j], new_tour[i] 
            neighbors.append(new_tour)
    return neighbors

def simple_beam_search(k=2, steps=10):
    """
    k: How many paths we keep in memory at once (the beam width).
    """
    beams = []
    for _ in range(k):
        route = [0, 1, 2, 3] 
        tail = route[1:]       
        random.shuffle(tail)    
        beams.append([0] + tail) 

    for _ in range(steps):
        pool = []
        
        for tour in beams:
            pool.append(tour)                
            pool.extend(get_neighbors(tour)) 
            
        unique_pool = []
        for p in pool:
            if p not in unique_pool:
                unique_pool.append(p)
                
        unique_pool.sort(key=get_cost)
        
        beams = unique_pool[:k] 
        
    return beams[0], get_cost(beams[0])

best_route, cost = simple_beam_search(k=2, steps=5)
print(f"Best Route: {best_route}")
print(f"Distance: {cost}")