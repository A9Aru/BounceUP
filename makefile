CC=g++ 
all_sources=Ball.cpp Window.cpp main.cpp   	 #all the .cpp files which are to be compiled
all_objs=$(all_sources:.c=.o)					 #object files created from the .cpp files
CFLAGS := `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -Wall -lSDL2_image -lm

BounceUp: $(all_objs) 	makefile			 #creating excutable file
		$(CC) -o BounceUp $(all_objs) 
%.o: %.c 	Makefile			 #creating object files
	$(CC) -c $(all_sources) $(CFLAGS)

clean:								 #removing the executable file and the object file
	rm BounceUp *.o

#g++ main.cpp Wall.cpp Ball.cpp Texture.cpp Object.cpp Rock.cpp Game.cpp Coin.cpp `pkg-config --cflags --libs sdl2` -lSDL2_image -ldl
