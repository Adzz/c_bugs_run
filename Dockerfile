FROM ubuntu

RUN apt-get update && apt-get -y install gcc vim build-essential cmake

WORKDIR /debugger
