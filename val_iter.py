import datetime
import time
import copy
import random
import sys

debug = True
dflag = True

#Take input
rows , cols = map(int,input().split())
world = [[float(j) for j in (map(float, input().split()))] for i in range(rows)]
no_end_states , no_walls = map(int,input().split())
end_states = [[j for j in map(int,input().split())] for i in range(no_end_states)]
walls = [[j for j in map(int,input().split())] for i in range(no_walls)]
start_state = [[j for j in map(int,input().split())] for i in range(1)]
step_cost = input()

curr_utils = [ [0] * cols for i in range(rows)]
old_utils = [ [0] * cols for i in range(rows)]
curr_policy = [ [0] * cols for i in range(rows)]
final_policy = [ [0] * cols for i in range(rows)]
board = world
old_board = board

pid = 0.8
npid = 0.1
discount_factor = 0.99
tolerance = 0.001
n_deci = 3
iter_no = 0


if debug == True and dflag == False:
    print ("Board = " , board)

if debug == True and dflag == False:
    print ("Rows, Cols = " , rows, cols)
    print ("world = " , world)

if debug == True and dflag == False:
    print ("no of end states = " , no_end_states )
    print ("End states  = " , end_states )

if debug == True and dflag == False:
    print ("no of walls = " , no_walls)
    print ("Walls = ", walls )

if debug == True and dflag == False:
    print ("Start state = ", start_state)
    print ("Step Cost = " , step_cost)

if debug == True and dflag == False:
    print ("Curr_util = " , curr_utils) 

def is_valid(x,y):

    if x<0 or x>=rows or y<0 or y>=cols:
        return False
    
    for wall in walls:
        if x == wall[0] and y == wall[1]:
            return False

    return True

def init_world():
    ''' WALLS initialsed to w '''
    for i in range(len(walls)):
        x , y = walls[i]
        board[x][y] = None
        curr_policy[x][y] = None
        final_policy[x][y] = None

def init_policy():
    for i in range(len(end_states)):
        x,y = end_states[i]
        if board[x][y] > 0:
            curr_policy[x][y] = "Goal"
            final_policy[x][y] = "Goal"
        else:
            curr_policy[x][y] = "Bad"    
            final_policy[x][y] = "Bad"

def print_policy(pol):
    print()
    for i in range(rows):
        for j in range(cols):
            print ( '%15s'  % pol[i][j], end = ' ')
        print ()
    print()

def print_world():
    print()
    for i in range(rows):
        for j in range(cols):
            x = board[i][j]
            if type(x)==float:
                x = round(x,n_deci)
            print ( '%15s'  % x, end = ' ')
        print ()
    print()

def value_iteration():
    print ("Iteration #0")
    iter_no = 0
    print_world()
    while True:
        changed_pairs = []
        iter_no += 1
        flag = 1
        print ('Iteration #%d' % iter_no)
        for i in range(rows):
            for j in range(cols):
                if is_valid(i,j) ==  True and (i,j) not in end_states:
                    board[i][j] = board_update(tuple((i,j)))
                    
                    if old_board[i][j] != 0:
                        if old_board[i][j] == None:
                            if debug == True and dflag == False:
                                print ('Yipeee!')
                        diff = (board[i][j] - old_board[i][j])/old_board[i][j]
                        changed_pairs.append(diff)
                    else:
                        if old_board[i][j] == None:
                            if debug == True and dflag == False:
                                print ('Yipeee!')
                        changed_pairs.append(25.0)
        print_world()
        
        for val in changed_pairs:
            if (val > tolerance):
                flag = 0
        
        if flag == 1:
            return
        
        old_board = board

def board_update(pair):
    neigh_utilis = [0.0, 0.0, 0.0, 0.0]
    vals = neigh_utilis
    x = pair[0]
    y = pair[1]

    right_n = (x,y+1)
    left_n = (x,y-1)
    upar_n = (x-1,y)
    neeche_n = (x+1,y)

    neigh_utilis[0] = get_state_utility(right_n,old_board[x][y])
    neigh_utilis[1] = get_state_utility(neeche_n,old_board[x][y])
    neigh_utilis[2] = get_state_utility(left_n,old_board[x][y])
    neigh_utilis[3] = get_state_utility(upar_n,old_board[x][y])

    vals[0] = neigh_utilis[0] * pid + (neigh_utilis[1] + neigh_utilis[3])*npid
    vals[1] = neigh_utilis[1] * pid + (neigh_utilis[0] + neigh_utilis[2])*npid
    vals[2] = neigh_utilis[2] * pid + (neigh_utilis[1] + neigh_utilis[3])*npid
    vals[3] = neigh_utilis[3] * pid + (neigh_utilis[0] + neigh_utilis[2])*npid

    vals[0] = vals[0] * discount_factor
    vals[1] = vals[1] * discount_factor
    vals[2] = vals[2] * discount_factor
    vals[3] = vals[3] * discount_factor

    max_all = max(vals)

    # return step_cost + max_all + world[x][y]
    return step_cost 


def get_state_utility(pair,val):
    x = pair[0]
    y = pair[1]

    if (x < 0 or y < 0 or x>rows-1 or y>cols-1 or old_board[x][y]==0 or old_board[x][y]==None):
        return val
    return old_board[x][y]

init_world()
init_policy()

value_iteration()

if debug == True and dflag == False:
    print ('--------------------------------Curr_pol------------------------')
    print_policy(curr_policy)


    print ('--------------------------------Fin_pol---------------------------')
    print_policy(final_policy)

    print ('------------------------------Board------------------------------')
    print_world()

if debug == True and dflag == False:
    print ( is_valid(-3,3) )
    print ( is_valid(-1,2) )
    print ( is_valid(-10,0) )
    print ( is_valid(-1,2) )
    print ( is_valid(1,22) )







