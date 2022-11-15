
#include <stdio.h>

#include "fileformat.h"

/* Output data as bitmap file */
void savebmp(char *filename, unsigned char *img, int width, int height)
{
        int i;
        int error;
        FILE *f;
        int filesize = 54 + 3 * width * height;

        unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
        unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
        unsigned char bmppad[3] = {0,0,0};

        /* Construct header with filesize part */
        bmpfileheader[ 2] = (unsigned char)(filesize    );
        bmpfileheader[ 3] = (unsigned char)(filesize>> 8);
        bmpfileheader[ 4] = (unsigned char)(filesize>>16);
        bmpfileheader[ 5] = (unsigned char)(filesize>>24);

        /* Construct header with width and height part */
        bmpinfoheader[ 4] = (unsigned char)(       width    );
        bmpinfoheader[ 5] = (unsigned char)(       width>> 8);
        bmpinfoheader[ 6] = (unsigned char)(       width>>16);
        bmpinfoheader[ 7] = (unsigned char)(       width>>24);
        bmpinfoheader[ 8] = (unsigned char)(       height    );
        bmpinfoheader[ 9] = (unsigned char)(       height>> 8);
        bmpinfoheader[10] = (unsigned char)(       height>>16);
        bmpinfoheader[11] = (unsigned char)(       height>>24);

        f = fopen(filename,"wb");
        error = fwrite(bmpfileheader, 1, 14, f);
        if (error != 14)
                printf("Error writing bmpfileheader \n");
        error = fwrite(bmpinfoheader, 1, 40, f);
        if (error != 40)
                printf("Error writing bmpinfoheader \n");

        for (i=0; i<height; i++) {
                error = fwrite(img + (width * i * 3), 3, width, f);
                if (error != width)
                        printf("Error writing line\n");
                error = fwrite(bmppad, 1, (4-(width*3)%4)%4, f);
                if (error != (4-(width*3)%4)%4)
                        printf("Error writing bmp padding\n");
        }

        fclose(f);
}

void saveppm(char *filename, unsigned char *img, int width, int height){
    /* FILE pointer */
    FILE *f;

    /* Open file for writing */
    f = fopen(filename, "wb");

    /* PPM header info, including the size of the image */
    fprintf(f, "P6 %d %d %d\n", width, height, 255);

    /* Write the image data to the file - remember 3 byte per pixel */
    fwrite(img, 3, width*height, f);

    /* Make sure you close the file */
    fclose(f);
}







