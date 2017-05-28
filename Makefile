
pwd:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

run:
	docker run -i -t -v $(pwd):/tcp -w /tcp --rm base/archlinux:latest bash