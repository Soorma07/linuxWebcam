/*
 *  V4L2 video capture example
 *
 *  This program can be used and distributed without restrictions.
 */

#include <stdio.h>
#include "linuxwebcam.h"

class myLinuxWebcam : public linuxWebcam
{
    private:
        int i;
    public:
        myLinuxWebcam(){
            i = 0;
        }

        virtual void processImage(imageData * img)
        {
            if(img->getFormat() == RGB ) {
                int w = img->getWidth();
                int h = img->getHeight();
                bitmapImage b(w,h);

                int rgbcounter = 0;
                // Loop through all the RGB data and put them in the bitmap
                int size = img->getSize();
                for(int i=0;i<size;i+=3)
                {
                    b.setPixelRGB(rgbcounter%w, rgbcounter/w, img->data[i], img->data[i+1], img->data[i+2]);
                    rgbcounter++;
                }

                // Save the bitmap to a file
                char outputName[20];
                sprintf(outputName, "output_%d.bmp",i++);

                printf("Printing Bitmap: %s\n", outputName);
                b.saveToBitmapFile(outputName);

            } else if (img->getFormat()==YUV){

                // Do something with the YUV data
                //   img->data          <--- points to the data
                //   img->getSize()     <--- total number of bytes in the data
            }
        }

};

int
main                            (int                    argc,
                                 char **                argv)
{

    myLinuxWebcam wc;
    char dev_name[] = "/dev/video0";

    wc.open_device (dev_name);          // Open the video device
    wc.initDevice (320,200);          // initialize it to the size of the image you want

    wc.start_capturing ();              // start capturing data

        for(int i=0;i<25;i++)           // capture 25 frames
            wc.captureFrameRGB();          // Capture a frame from the stream.  This method will invoke the procesImage( ) handler.  It can be overridden.

    wc.stop_capturing ();               // stop capturing data

    wc.uninitDevice ();                // uninitialize the device
    wc.close_device ();                 // close the stream

    exit (EXIT_SUCCESS);

    return 0;
}
