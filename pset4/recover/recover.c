/**
 * recovers JPEGs from a forensic image
 */
 
 #include <stdint.h>
 #include <stdio.h>
 #include <stdlib.h>
 

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    
    // remeber filename
    char *infile = argv[1];
    
    // open input file
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    
    char title[8];
    int numofjpg = 0;
    
    // bytes to read
    uint8_t buffer[512];

    
    // create output file
    FILE* outptr = NULL;
    
    // read 512 bytes into a buffer
    fread(buffer, 512, 1, inptr);
    
    while (fread(buffer, 512, 1, inptr) > 0) 
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ( buffer[3] == 0xe0  ||  buffer[3] == 0xe1 ))
        {   
            
            // generate image name e.g.001,002
            sprintf(title, "%03d.jpg", numofjpg);
            
            // inctrement image number
            numofjpg++;
            
            // close image if it's open 
            if (outptr != NULL)
            {
                fclose(outptr);
            }
            
            // open a new image
            outptr = fopen(title,"a");
            
        }
        
        // write outfile
        if (numofjpg > 0)
            fwrite(buffer, sizeof(buffer), 1, outptr);
        
        
    }
    
    // close any remaining files
    if (outptr != NULL)
    {
        fclose(outptr);
    }
    
    fclose(inptr);
    return 0;
}
