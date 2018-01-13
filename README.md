# Lem-in
Moving an ant colony - Graphs and maximum flow

## Project Overview
This program takes as input a map of an ant colony in the form os a list of rooms and links between those rooms. The goal is to move ants from the source room to the sink room, and do it in the minimum number of turns possible, knowing that an ant can only move once per turn and that at any given time there can only be one ant per room (except for the source and the sink, where there can be as many ants as needed).

The map must be in the following format:

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
