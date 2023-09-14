# Este makefile basicamente corre los otros makefiles en el orden que aparecen y
# con clean tambien borra las cosas que hayan creado los makefiles
all:
	make -C filesystem
	make -C memoria
	make -C cpu
	make -C kernel

clean:
	make clean -C filesystem
	make clean -C memoria
	make clean -C cpu
	make clean -C kernel

# si algun modulo no tiene un main esto pincha