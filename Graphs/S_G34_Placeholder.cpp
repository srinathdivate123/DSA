// Better refer this video instead of seeing notes: https://youtu.be/3dINsjyfooY

// A queue ends up taking much more time by exploring much more possiblities
// A priority queue on the other hand, stores the pair with the least distance on the top hence it explores only that which has less weight
// The ones with higher weight (dist) are not explored at all because the paths with lower weight have already been explored and so the paths with higher weight will not be added into the priority queue later on

// So because of the priority queue, we only explore the minimal weight paths instead of wasting our time on exploring the higher weight paths