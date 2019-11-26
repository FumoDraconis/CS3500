all:
	@gcc -o vmTest.t virtualMachineTest.c ../vmFunctionality/*.c
	@gcc -o cTest.t calculateTest.c ../vmFunctionality/*.c
	@gcc -o prTest.t printResultTest.c ../vmFunctionality/*.c
	@prove ./*.t

clean:
	@rm *.t
