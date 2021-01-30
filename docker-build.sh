#!/bin/bash

docker run -ti --rm -v $(pwd):/usr/src --workdir /usr/src debian:buster-slim /bin/bash -c /usr/src/build-deb.sh
