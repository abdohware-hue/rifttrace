FROM gcr.io/oss-fuzz-base/base-builder

RUN apt-get update && apt-get install -y cmake ninja-build

COPY . $SRC/rifttrace
WORKDIR $SRC/rifttrace

RUN chmod +x .clusterfuzzlite/build.sh
