#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <pthread.h>

/* With and height of our image */
#define WIDTH  800
#define HEIGHT 600

unsigned char img[WIDTH * HEIGHT * 3];

/* Output data as PPM file */
void saveppm(char *filename, unsigned char *img, int width, int height){
        
        /* FILE pointer */
        FILE *f;
        
        /* Open file for writing */
        f = fopen(filename, "wb");
        
        /* PPM header info, including the size of the image */
        fprintf(f, "P6 %d %d %d\n", width, height, 255);
        
        /* Write the image data to the file - remember 3 byte per pixel */
        fwrite(img, 3, WIDTH*HEIGHT, f);
        
        /* Make sure you close the file */
        fclose(f);

}
//green----------------------------
void *Thread1(void *vargp1)
{
    sleep(1);
         //unsigned char img[WIDTH * HEIGHT * 3];

        int i,j;


        for(i=0; i<200; i++){
                for(j=0; j<WIDTH; j++){
                        //if( !(j>=250 && j<350) && !(i>=200 && i<300) ){
                                img[(j + i*WIDTH)*3 + 0] = 0;
                                img[(j + i*WIDTH)*3 + 1] = 255;
                                img[(j + i*WIDTH)*3 + 2] = 0;
                        //}
                        
                }

        }

       

    return NULL;
}
//yellow----------------
void *Thread2(void *vargp1)
{
    sleep(1);
         //unsigned char img[WIDTH * HEIGHT * 3];

        int i,j;


        for(i=201; i<400; i++){
                for(j=0; j<WIDTH; j++){
                        //if( (j>=250 && j<350) || (i>=200 && i<300) ){
                                img[(j + i*WIDTH)*3 + 0] = 255;
                                img[(j + i*WIDTH)*3 + 1] = 255;
                                img[(j + i*WIDTH)*3 + 2] = 0;
                        }
                        
                //}

        }

       

    return NULL;
}
//Red-------------------
void *Thread3(void *vargp2)
{
    sleep(1);

        int i,j;


        for(i=401; i<600; i++){
                for(j=0; j<WIDTH; j++){
                        //if( (j>=250 && j<350) || (i>=200 && i<300) ){
                                img[(j + i*WIDTH)*3 + 0] = 255;
                                img[(j + i*WIDTH)*3 + 1] = 0;
                                img[(j + i*WIDTH)*3 + 2] = 0;
                        }
                //}

        }

    

    return NULL;
}

int main(int argc, char *argv[]){

	    pthread_t thread_id1,thread_id2,thread_id3;
	       
	    pthread_create(&thread_id1, NULL, Thread1, (void *)&thread_id1);
	    pthread_join(thread_id1, NULL);
	    
	    pthread_create(&thread_id2, NULL, Thread2, (void *)&thread_id2);
	    pthread_join(thread_id2, NULL);
	    
	    pthread_create(&thread_id3, NULL, Thread3, (void *)&thread_id3);
	    pthread_join(thread_id3, NULL);
	    
	    saveppm("etflag.ppm", img, WIDTH, HEIGHT);
	    
	    exit(0);
   
	return 0;
}

