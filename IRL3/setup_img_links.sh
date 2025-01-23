#!/bin/bash

RESOURCE_PATH=/usr/local/share/LLPP_shared
FILENAMES=(IMG_4997.ppm  IMG_5008.ppm  IMG_5067.ppm  IMG_5385.ppm  \
    IMG_5400.ppm IMG_5002.ppm  IMG_5013.ppm  IMG_5260.ppm  \
    IMG_5387.ppm  IMG_5440.ppm)

for filename in ${FILENAMES[@]}
do
    ln -s $RESOURCE_PATH/$filename
done

echo "Done making links"
