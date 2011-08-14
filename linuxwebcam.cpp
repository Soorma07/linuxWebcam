#include "linuxwebcam.h"

linuxWebcam::linuxWebcam()
{
    //ctor
}

linuxWebcam::~linuxWebcam()
{
    //dtor
}

/*
bool linuxWebcam::open_device(char dev_name[])
{
    struct stat st;

    if (-1 == stat (dev_name, &st))
    {
        fprintf (stderr, "Cannot identify '%s': %d, %s\n", dev_name, errno, strerror (errno));
        exit (EXIT_FAILURE);
    }

    if (!S_ISCHR (st.st_mode))
    {
        fprintf (stderr, "%s is no device\n", dev_name);
        exit (EXIT_FAILURE);
    }

    fd = open (dev_name, O_RDWR  | O_NONBLOCK, 0);

    if (-1 == fd)
    {
        fprintf (stderr, "Cannot open '%s': %d, %s\n", dev_name, errno, strerror (errno));
        exit (EXIT_FAILURE);
    }
}
*/
