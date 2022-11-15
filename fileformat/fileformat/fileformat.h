#ifndef _FILEFORMAT_H_
#define _FILEFORMAT_H_

/* Save image as bitmap */
void savebmp(char *filename, unsigned char *img, int width, int height);

/* Save image as PPM */
void saveppm(char *filename, unsigned char *img, int width, int height);

#endif /* _FILEFORMAT_H_ */
