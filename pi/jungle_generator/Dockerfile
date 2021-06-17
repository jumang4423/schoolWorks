FROM --platform=amd64 ubuntu:latest
RUN mkdir /jungle_mac
WORKDIR /jungle_mac
ADD . /jungle_mac

RUN apt update
RUN apt install python3 python3-pip python3-venv -y
RUN DEBIAN_FRONTEND=noninteractive apt-get install --yes pulseaudio
