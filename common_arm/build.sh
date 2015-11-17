arm-linux-gnueabihf-gcc -mthumb-interwork  -march=armv7 --static -o a.out test.c 
#arm-none-eabi-gcc --static -o a.out test.c 
#arm-none-eabi-gcc -o a.out test.c 

#gcc -o a.out test.c 
#sudo cp a.out  /var/lib/tftpboot/ti_omap3/home
#sudo cp a.out  /var/lib/tftpboot/rootfs_wrlinux5/home
sudo cp a.out  /var/lib/tftpboot/rootfs_sato/root

sudo cp a.out  /var/lib/tftpboot/rootfs/root
sudo cp a.out  /var/lib/tftpboot/rootfs_wrlinux5/root
