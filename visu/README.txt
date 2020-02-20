gcc src/main.c src/visu.c -lncurses -I ../../includes -I ../../libft -lft -L../libft -I ../include/visu.h -o VISUALIZER
../resources/filler_vm -f ../resources/maps/map01 -p1 ../resources/players/superjeannot.filler -p2 ../seanseau.filler | ./VISUALIZER
