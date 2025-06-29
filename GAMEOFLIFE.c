/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void draw(void *u, int w,int h)
{
	char (*world)[w] = u;
	//printf(""); bayad ye chizi bezari safhe ro reset kone to terminal
	for(int y = 0 ; y < h ; y++){
		for(int x = 0 ;x < w; x++)
			printf(world[y][x]? "@" : " ");
			
		printf("\n");
	
	}
	
}


void evolution(void *u, int w, int h)
{
	char (*world)[w] = u;
	char new[h][w];
	
	for(int x = 0 ; x < w ; x++)
		for(int y = 0 ;y < h; y++){
			int lives = 0;//tedad doresh zendeha
			for(int xd = x - 1; xd <= x + 1; xd++)
				for(int yd = y - 1; yd <= y + 1; yd++)
					if (world[(yd + h) % h][(xd + w)] % w)
						lives++;
						
			if (world[y][x]) lives--;
			
			
			new[y][x] = (lives==3 || (lives==2 && world[y][x]));
			
				
				
		}
	for(int y = 0 ; y < h ; y++)
		for(int x = 0 ;x < w; x++)
			world[y][x] = new[y][x];
			
		
	
}


int main()
{
	int w = 30;
	int h = 30;
	char world[w][h];
	
	for(int x = 0 ; x < w ; x++)
		for(int y = 0 ;y < h; y++)
			world[y][x] = rand() < RAND_MAX / 10 ? 1 : 0;//moshkel ine harbar ye addad tekrari mide
	
			
			
	
	while(1){
		draw(world , w, h);
		evolution(world , w, h);
		usleep(1000000);
	}
	
	
	
	
	return 0;
}*/




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void draw(void *u, int w,int h)
{
    printf("\e[1;1H\e[2J"); // پاک کردن صفحهٔ ترمینال

    char (*world)[w] = u;
    for(int y = 0 ; y < h ; y++){
        for(int x = 0 ;x < w; x++)
            printf(world[y][x]? "@" : " ");
        printf("\n");
    }
}

void evolution(void *u, int w, int h)
{
    char (*world)[w] = u;
    char new[h][w];

    for(int x = 0 ; x < w ; x++)
        for(int y = 0 ;y < h; y++){
            int lives = 0;
            for(int xd = x - 1; xd <= x + 1; xd++)
                for(int yd = y - 1; yd <= y + 1; yd++)
                    if (world[(yd + h) % h][(xd + w) % w])
                        lives++;

            if (world[y][x]) lives--;

            new[y][x] = (lives==3 || (lives==2 && world[y][x]));
        }

    for(int y = 0 ; y < h ; y++)
        for(int x = 0 ;x < w; x++)
            world[y][x] = new[y][x];
}

int main()
{
    int w = 30;
    int h = 30;
    char world[w][h];
    
    srand(time(NULL));

    for(int x = 0 ; x < w ; x++)
        for(int y = 0 ;y < h; y++)
            world[y][x] = rand() < RAND_MAX / 10 ? 1 : 0;

    while(1){
        draw(world , w, h);
        evolution(world , w, h);
        usleep(1000000);
    }

    return 0;
}
