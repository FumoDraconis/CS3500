all:
	@gcc -o tokeniser/tokeniser_output tokeniser/main.c
	@gcc -o translator/translator_output translator/main.c
	@gcc -o codeGenerator/codeGenerator_output codeGenerator/main.c
	@gcc -o virtualMachine/virtualMachine_output virtualMachine/main.c virtualMachine/vmFunctionality/*.c
	@./tokeniser/tokeniser_output
	@./translator/translator_output
	@./codeGenerator/codeGenerator_output
	@./virtualMachine/virtualMachine_output

clean:
	@rm tokeniser/tokeniser_output
	@rm translator/tokeniserOutput.txt
	@rm translator/translator_output
	@rm codeGenerator/translatorOutput.txt
	@rm codeGenerator/codeGenerator_output
	@rm virtualMachine/codeGeneratorOutput.txt
	@rm virtualMachine/virtualMachine_output
	@rm tokeniser/tokeniser_test
	@rm translator/translator_test
	@rm codeGenerator/codeGenerator_test
	@rm virtualMachine/tests/*.t

test:
	@gcc -o tokeniser/tokeniser_test tokeniser/tests/*.c
	@./tokeniser/tokeniser_test
	@gcc -o translator/translator_test translator/tests/*.c
	@./translator/translator_test
	@gcc -o codeGenerator/codeGenerator_test codeGenerator/tests/*.c
	@./codeGenerator/codeGenerator_test
	@gcc -o virtualMachine/tests/vmTest.t virtualMachine/tests/virtualMachineTest.c virtualMachine/vmFunctionality/*.c
	@gcc -o virtualMachine/tests/cTest.t virtualMachine/tests/calculateTest.c virtualMachine/vmFunctionality/*.c
	@gcc -o virtualMachine/tests/prTest.t virtualMachine/tests/printResultTest.c virtualMachine/vmFunctionality/*.c
	@./virtualMachine/tests/*.t
