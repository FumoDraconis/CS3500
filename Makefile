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

test:
	@gcc -o tokeniser/tokeniser_test tokeniser/tests/*.c
