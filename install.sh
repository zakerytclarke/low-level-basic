#!/bin/bash
mkdir /usr/local/bin/low-level-basic
cp llb /usr/local/bin/low-level-basic/llb
cp LICENSE /usr/local/bin/low-level-basic/LICENSE
cp ./sample-programs /usr/local/bin/low-level-basic/sample-programs -r
echo 'export PATH=$PATH:/usr/local/bin/low-level-basic/' >> ~/.bashrc
