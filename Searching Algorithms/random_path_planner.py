#!/usr/bin/env python

import numpy as np
from heapq import *
import random

#[(move_x, move_y, move_cost)]
moves = [ (1,0, 1.), (0,1, 1.), (-1,0, 1.), (0,-1, 1.) ]

#-----------------------------------------RANDOM PATH PLANNER---------------------------------------------------

def random_planner(world, start, goal):
    #max number of steps acceptable
    max_step_number = 16

    #n memories ie n last steps to be remember
    n = int(round(np.sqrt(max_step_number)))
    prev_n_steps = [(0,0)]*n

    #details about the cost, current and previous nodes
    prev_move_info = [(0.001, start, None)]

    #initialize the path
    path = [start]

    count = 0

    #map size
    extents = (len(world), len(world[0]))

    #loop till the max acceptable steps
    while max_step_number > count:

        #choice a random move direction from the moves
        new_move = random.choice(moves)
        dx,dy, deltacost = new_move

        #pop the previous values store it in cost, current pos, previous pos
        prev = prev_move_info.pop()
        cost,pos,prev_pos = prev

        #check if goal is reached
        if pos == goal:
            break

        #store the new position
        new_x = pos[0] + dx
        new_y = pos[1] + dy
    
        #check for the map dimesnions
        if (new_x < 0 or new_x >= extents[0] or new_y < 0 or new_y >= extents[1]):
            prev_move_info.append(prev)
            continue

        new_pos = (new_x, new_y)

        #check if the new position is not in the last n steps and not an obstacle:
        #update the previous n steps, move to the current step, increase the count
        if( (new_pos not in  prev_n_steps) and world[new_pos] != 1 ):
            #update the previous n steps
            prev_n_steps.insert(0,new_pos)
            prev_n_steps = prev_n_steps[:n]
            #update the previous move info
            prev_move_info.append((cost + deltacost, new_pos, pos))
            #add the current to the path
            path.append(new_pos)
            #increase the count
            count = count+1

        #if the new position is in the prevvious n steps do the follwoing
        #go to previous position and choose another random move except the current one
        #check if it is not in previous n steps
        #if so, move in that direction
        #if not, repeat
        #if no moves found just move in the previous n steps
        elif((new_pos in  prev_n_steps) and world[new_pos] != 1):

            #remove the recent rrandom move from check moves
            check_moves = [(0,1,1.),(0,-1,1.),(1,0,1.),(-1,0,1.)]
            check_moves.remove(new_move)

            #check the surrondings of the pos
            while check_moves:
                new_move_1 = random.choice(check_moves)
                dx_1,dy_1, deltacost_1 = new_move_1
                check_moves.remove(new_move_1)

                new_x_1 = pos[0] + dx_1
                new_y_1 = pos[1] + dy_1

                #check for the new position map dimensions
                if (new_x_1 < 0 or new_x_1 >= extents[0] or new_y_1 < 0 or new_y_1 >= extents[1]):
                    continue
        
                new_pos_1 = (new_x_1, new_y_1)

                #if the new posiiton is not in the last n steps break this while loop
                if( (new_pos_1 not in  prev_n_steps) and world[new_pos_1] != 1):
                    break
                
            #update the previous n steps, move to the current step, increase the count
            if( (new_pos_1 not in  prev_n_steps) and world[new_pos_1] != 1 ):
                prev_n_steps.insert(0,new_pos_1)
                prev_n_steps = prev_n_steps[:n]
                prev_move_info.append((cost + deltacost_1, new_pos_1, pos))
                path.append(new_pos_1)
                count = count+1

            #if no other go, just more in the previous n steps
            else:
                prev_n_steps.insert(0,new_pos)
                prev_n_steps = prev_n_steps[:n]
                prev_move_info.append((cost + deltacost, new_pos, pos))
                path.append(new_pos)
                count = count+1

        else:
            prev_move_info.append(prev)


    if pos == goal:
        print ("Goal Acheived by Random Planner")
    else:
        print("Failed to achieve the goal by Random Planner")
            

    return path, cost-.001
#-----------------------------------------------------------------------------------------------------------------

if __name__ == "__main__":

    #world
    world_state = np.array( [[0,0,1,0,0,0],
                             [0,0,1,0,1,0],
                             [0,0,0,0,1,0],
                             [0,0,0,0,1,0],
                             [0,0,1,1,1,0],
                             [0,0,0,0,0,0]])

    #Random planner
    path_random, cost_random = random_planner(world_state, (2,0), (5,5))
    print "Random Path: ", path_random
    print "Random Cost: ", cost_random

#--------------------------------------------------------------------------------------------------------------------
