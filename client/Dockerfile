FROM ubuntu

RUN apt update && apt -y install g++ cmake nano git

RUN git clone https://github.com/ddeka0/docker_examples.git app

# WORKDIR /app/client

RUN cd /app/client && cmake . && make
