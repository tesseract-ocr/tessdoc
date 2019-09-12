# Setup

Our respository runs on python 3.7.3. We manage our dependencies and runtimes using docker containers. it is advisable to adjust your allocated ram and memory in docker settings. 

**Docker** 

For first time setup, follow the commands to setup the docker container. 

  ```bash
  cd docker

  # Build image from Dockerfile
  docker build -t our-plus:<username> .

  # Start docker container
  cd ...
  docker run --entrypoint "/bin/bash" --volume `pwd`:/workspace/ocr-plus-service -p 8777:8888 -it ocr-plus:<username>
  ```
For subsequent runs, 

  ```bash
  # Start container
  docker start <CONTAINER_NAME>

  # Enter bash of container
  docker exec -it <CONTAINER_NAME> /bin/bash

  ```