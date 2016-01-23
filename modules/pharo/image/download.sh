#!/usr/bin/env bash

IMAGE_URL="http://files.pharo.org/image/50/latest.zip"
PHARO_VM=~/Pharo/VirtualMachines/spur

usage() {
    cat <<HELP
Usage: $0 [-h|--help]

Downloads the latest image and prepares it

image: $IMAGE_URL
HELP
}

get_image() {
	cp -fr /Users/luc/Pharo/Pharo-Alpha/Pharo.{changes,image} .
}
prepare_image() {
    ${PHARO_VM} Pharo.image eval --save "SystemWindow allSubInstancesDo: #delete. Gofer new directory: '/Users/luc/Pharo/MCLocalRepository/'; package: 'OpenCVBindingGenerator'; load"
}

# stop the script if a single command fails
set -e

# on mac os wget can be quite old and not recognizing --no-check-certificate
CERTCHECK="--no-check-certificate"
wget --help | grep -- "$CERTCHECK" 2>&1 > /dev/null || CERTCHECK=''

should_prepare_image=0

if [ $# -eq 0 ]; then
    get_image
    should_prepare_image=1
else
    while [ $# -gt 0 ]; do
        case "$1" in
            -h|--help|help)
                usage; exit 0;;
            i|img|image)
                get_image;
                should_prepare_image=1;;
            *) # boom
                usage; exit 1;;
        esac
        shift
    done
fi

if [[ $should_prepare_image -eq 1 ]]; then
    echo Preparing image
    prepare_image
fi
