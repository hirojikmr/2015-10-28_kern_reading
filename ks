#qemu-system-i386 --kernel arch/x86/boot/bzImage -gdb tcp::10000 -nographic -hda /home/hirojikmr/buildroot-2015.08.1/output/images/rootfs.ext2 -append "console=ttyS0 root=/dev/sda"
#qemu-system-i386 --kernel arch/x86/boot/bzImage -gdb tcp::10000 -hda /dev/sdb1 -append "root=/dev/sda rw"
 

#qemu-system-i386 -enable-kvm --kernel arch/x86/boot/bzImage -gdb tcp::10000 -hda /64root/qemu_lab/ubn.img -append "root=/dev/sda rw"


qemu-system-i386  --kernel arch/x86/boot/bzImage -gdb tcp::10000 -hda /64root/qemu_lab/ubn.img -append "root=/dev/sda rw"
