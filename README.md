# KeyPressDetection
Short kernel module for an effecient keyboard detection within a linux VM

# Compile
Install Linux Kernel Build Dependencies
<pre>
sudo apt build-dep linux linux-image-unsigned-$(uname -r)
</pre>

Then simply run `make`
<pre>
make
</pre>


if for some reason it didn't build then extra possible dependencies are:
<pre>
sudo apt install libncurses-dev gawk flex bison openssl libssl-dev dkms libelf-dev libudev-dev libpci-dev libiberty-dev autoconf llvm
</pre>

Now I know, those are all the dependencies to build the Linux Kernel, but hey, why not?

Thank you for viewing.

Cheers,

1337_Tech
