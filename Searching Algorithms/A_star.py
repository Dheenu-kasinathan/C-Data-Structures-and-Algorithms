#!/usr/bin/env python

import numpy as np
from heapq import *
import random

#[(move_x, move_y, move_cost)]
moves = [ (1,0, 1.), (0,1, 1.), (-1,0, 1.), (0,-1, 1.) ]



#------------------------------------------OPTIMAL PATH PLANNER----------------------------------------------------

#manhattan distance
def heuristic(p, q):
    return (abs(p[0]-q[0]) + abs(p[1]-q[1]))

#astar function
def astar(world,start, goal):
    
    #Open list for the nodes to be explored
    #[total_cost, current_cost, current_position, previous_position]
    #total_cost = current_node cost+ distance between current and goal
    #f = g + h
    not_explored = [(0.001 + heuristic(start, goal), 0.001, start, None)]

    #map_size
    extents = (len(world), len(world[0]))

    #visited nodes
    visited = np.zeros(extents, dtype=np.float32)

    #to know the previous nodes
    came_from = {}

    while not_explored:
        #pop the minimum total cost node from heap
        min_cost_node = heappop(not_explored)
        total_cost, cost, pos, previous = min_cost_node

        #if position is visted end the loop
        if(visited[pos] > 0):
            continue

        #update the visited 
        visited[pos] = cost

        #update the previous nodes
        came_from[pos] = previous

        #break if the goal is reached
        if pos == goal:
            break  

        #check for the successor_nodes
        for dx, dy, deltacost in moves:
            new_x = pos[0] + dx
            new_y = pos[1] + dy

            #check for the map dimesnions
            if(new_x < 0 or new_x >= extents[0] or new_y < 0 or new_y >= extents[1]):
                continue
            
            new_pos = (new_x, new_y)

            #check if the position is not visted and there is no obstacles
            if (not visited[new_pos] and world[new_pos] != 1):
                #push into heap
                heappush(not_explored, (cost + deltacost + heuristic(new_pos, goal), cost + deltacost, new_pos, pos))

    path = []

    if pos == goal:
        print ("Goal Acheived by Optimal Planner")
        while pos:
            path.append(pos)
            pos = came_from[pos]
        path.reverse()

    else:
        print("Failed to achieve the goal by Optimal Planner")
        return False, False

    #return path and total cost
    return path, total_cost-0.001

#--------------------------------------------------------------------------------------------------------------------

if __name__ == "__main__":

    #world
    world_state = np.array( [[0,0,1,0,0,0],
                             [0,0,1,0,1,0],
                             [0,0,0,0,1,0],
                             [0,0,0,0,1,0],
                             [0,0,1,1,1,0],
                             [0,0,0,0,0,0]])
    
    #Optimal planner
    path_optimal, cost_optimal = astar(world_state, (2,0), (5,5))
    print "Optimal Path: ", path_optimal
    print "Optimal Cost: ", cost_optimal

#--------------------------------------------------------------------------------------------------------------------
