# lem-in
Program that when given an ant-farm will move each ant across the graph in the shortest amount of moves

<h1>Compilation and Running</h1>
To compile this program run make or make re. (note clone using git clone --recurse-submodules).
To run the program, use the comand ./lemin < "file_name"
Where file_name is the name of a file/map in the following format:
<ul>
  <li> 1st line is the number of ants in the farm </li>
  <li> thereafter comes the room names </li>
  <li> This is followed by the connections between the rooms </li>
</ul>
<sub>##marks a command i.e ##start gives the start room, likewise ##end gives the end room. 
  a single "#" means a comment. For further examples see the maps provided.
</sub>
<h1>Algorithm</h1>
This implementation uses a DFS to confirm a path and backwards propage ants along the path.
It is worht noting that one possible improvement on this could be using an iterative depth first search so
as to create more branches.
