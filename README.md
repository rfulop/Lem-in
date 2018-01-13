# Lem-in
Moving an ant colony from one point to another in the least amount of time - Exploring graph traversal algorithms
Grade 117%

## Project Overview
This program takes as input a map of an ant colony in the form os a list of rooms and links between those rooms. The goal is to move ants from the source room to the sink room, and do it in the minimum number of turns possible, knowing that an ant can only move once per turn and that at any given time there can only be one ant per room.

The map must be in the following format:

```
# comment   -> comment
##verbose   -> activate verbose output mode (optional)
10          -> number of ants
a 0 0       -> definition of a room, room name followed by the coordinates
b 0 0
##start     -> the next room defined will be the source
start 0 0
##end       -> the next room defined will be the sink
end 0 0
start-a     -> definition of a link between rooms
a-b
b-end
```

## Usage:
With a file :
```
make && ./lem-in < map.txt
```
With standard input :
```
make && ./lemin
```

### Map exemple :
```
10
##start
0 0 0
## end
1 1 1
2 2 2
3 3 3
0-2
0-3
1-2
1-3
```

### Output :
A line is a turn.
L*x*-*y* with *x* is the ant's id and *y* the room where the ant is. 
```
L1-3 L2-2
L1-1 L2-1 L3-3 L4-2
L3-1 L4-1 L5-3 L6-2
L5-1 L6-1 L7-3 L8-2
L7-1 L8-1 L9-3 L10-2
L9-1 L10-1
```
