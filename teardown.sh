#! /bin/bash

docker-compose stop &&
docker rmi c_bugs_run_debug --force
