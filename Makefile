run: ./build.iso vm.img /usr/bin/qemu-system-x86_64
	unset GTK_PATH && \
	qemu-system-x86_64 -m 2G -cdrom ./build.iso -netdev user,id=net0
	
jonar-blindfolded-sdk:
	unset GTK_PATH && \
	cd pkg/jonar-blindfolded-sdk && \
	sudo dpkg-buildpackage -us -uc -b

jonar-blindfolded-sdk-pylib-install:
	unset GTK_PATH && \
	cd pkg/jonar-blindfolded-sdk/debian/source/python && \
	pip3 install --user --break-system-packages .