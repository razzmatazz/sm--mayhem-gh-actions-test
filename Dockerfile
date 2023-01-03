FROM debian:buster-slim
RUN apt-get update && \
    apt-get install -y gcc make libc6-dbg && \
    rm -rf /var/lib/apt/lists/*
COPY test.c .
COPY Makefile .
RUN make a.out
