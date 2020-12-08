#!/bin/sh
pid=`ls -ltr /var/lib/systemd/coredump| tail -n 1 | awk '{print $9}' | cut -d "." -f5`
coredumpctl dump $pid  --output /tmp/core.$pid
