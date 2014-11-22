#!/bin/bash
rm -f wtrt*

iso=wtrt
front=wtrt_front
top=wtrt_top

cat <<EOF | env /usr/brlcad/bin/mged -c columns.g
B watertank.r
ae 35 25
saveview $iso
ae 0 0
saveview $front
ae 0 90
saveview $top
EOF
sed '2cenv /usr/brlcad/bin/rt -M \\' $iso > tempFile                   
sed '2cenv /usr/brlcad/bin/rt -M \\' $front > tempFile_front
sed '2cenv /usr/brlcad/bin/rt -M \\' $top > tempFile_top

rm $iso
rm $front
rm $top

mv tempFile $iso                                                     
mv tempFile_front $front
mv tempFile_top $top

chmod 755 $iso                                                         
chmod 755 $front
chmod 755 $top

./$iso
./$front
./$top

env /usr/brlcad/bin/pix-png < $iso.pix > $iso.png                       
env /usr/brlcad/bin/pix-png < $front.pix > $front.png
env /usr/brlcad/bin/pix-png < $top.pix > $top.png

rm ../../../../cgi-images/*

cp $iso.png ../../../../cgi-images
cp $front.png ../../../../cgi-images
cp $top.png ../../../../cgi-images


#pix-png < wtrt.pix > wtrt.png
#png-fb wtrt.png                                     
#shotwell wtrt.png
