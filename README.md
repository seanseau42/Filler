# Filler
Algorithmic project with graphic interface. Create your Algorithm, and then fight !  

Filler is a game where two players / algorithm are fighting on a map.  

A virtual machine organizes the game as such :  
<pre>
Calls the players alternatively, giving each one a random tetrimino piece. 
On each turn, the current player has to insert his piece on the map, and try blocking the ennemy.  
To insert a piece, the player has to write its coordinates in the "Y X\n" format on the standard input (stdin).
</pre>

The game appears on the standard input.  

The main goal of the game is to end up having filled the grid more than your adversary did.  
  
    
# How To Use
<pre>
make  
./resources/filler_vm -f *map_path* -p1 *player1_algorithm* -p2 *player2_algorithm*  
</pre>
Example  
./resources/filler_vm -f ./resources/maps/map00 -p1 ./resources/players/superjeannot.filler -p2 ./seanseau.filler
# Algorithm
On the begining of each turn, a Heat Map is refreshed.  
This heat map represents the game grid, but each case of the map has an integer value.  
The algorithm starts from the enemy's position and increments every square as it gets further from the enemy, until it reaches the edges of the map.    
  
  
Then, the algorithm tries fitting the tetrimino piece on each and every position of the map.   
Keep in mind that one of the given tetrimino's squares must overlap one of our previous tetriminos.    
When it's done, it chooses the position that sets the tetrimino piece as close to the enemy as possible and places it here.  
The smaller a case value is, the best it is, as it will get the closest to your ennemy and prevent him from expanding as much as possible.  

# Bonus  
##VISUALIZER.  
cat readme.txt in visu/.  

