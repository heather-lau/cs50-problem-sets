/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize infile outfile\n");
        return 1;
    }
    
    // resize
    int n = atoi(argv[1]);
    
    if ( n < 0 || n > 100 )
    {
        printf("Invalid number\n");
        return 1;
    }
    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    
    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }
    
    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    BITMAPINFOHEADER bi_new;
    BITMAPFILEHEADER bf_new;
    
    bi_new = bi;
    bf_new = bf;
    
    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int newpadding =  (4 - ((bi_new.biWidth * n) * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // update header info
    bi_new.biWidth = bi.biWidth * n;
    bi_new.biHeight = bi.biHeight * n;
    bi_new.biSizeImage = (bi_new.biWidth * sizeof(RGBTRIPLE) + newpadding) * abs(bi_new.biHeight);
    
    // update header file
    // BITMAPFILEHEADER = 40 and BITMAPINFOHEADER = 14 
    bf_new.bfSize = bi_new.biSizeImage + 54;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_new, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_new, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {       
        for (int o = 0; o < n; o++ )
        {
            
            // skip over padding, if any
            fseek(inptr, (54 + ((bi.biWidth*3 + padding)* i) ), SEEK_SET);
            
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++) 
            {   
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                // write RGB triple to outfile
                for (int k = 0; k < n; k++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
                
            }
        
        
        // fseek(inptr, padding, SEEK_CUR);
        
        // then add it back (to demonstrate how)
        for (int m = 0; m < newpadding; m++)
        {
            fputc(0x00, outptr);
        }
        
        }
        
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
