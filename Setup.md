# Setup

Our respository runs on python 3.6.8 and tensorflow 1.14. We manage our dependencies and runtimes using docker containers. If you're using *local docker*, it is advisable to adjust your allocated ram and memory in docker settings. We recommend setting up the *gpu docker*, especially if you're working on modelling tasks. 

**Docker** 

For first time setup, follow the commands to setup the docker container. 
For subsequent runs, `docker start <inference_docker_container_name>` and wait for a minute to allow all models to be loaded. Inference service will be deployed locally.
  ```bash
  cd docker

  # Build image from Dockerfile
  docker build -t our-plus:<username> .

  # Start docker container
  cd ...
  docker run --entrypoint "/bin/bash" --volume `pwd`:/workspace/ocr-plus-service -p 8777:8888 -it ocr-plus:<username>


  ```

