compile:
	@gcc -o tokeniser/tokeniser_output tokeniser/tokeniser.c
	@gcc -o translator/translator_output translator/translator.c
	@gcc -o codeGenerator/codeGenerator_output codeGenerator/codeGenerator.c
	@gcc -o virtualMachine/virtualMachine_output virtualMachine/virtualMachine.c

run:
	@./tokeniser/tokeniser_output
	@./translator/translator_output
	@./codeGenerator/codeGenerator_output
	@./virtualMachine/virtualMachine_output

all:
	@make compile
	@make run

run_tokeniser:

	@gcc -o tokeniser/tokeniser_output tokeniser/tokeniser.c
	@./tokeniser/tokeniser_output

run_translator:

	@gcc -o translator/translator_output translator/translator.c
	@./translator/translator_output

run_codeGenerator:

	@gcc -o codeGenerator/codeGenerator_output codeGenerator/codeGenerator.c
	@./codeGenerator/codeGenerator_output

run_virtualMachine:
	@gcc -o virtualMachine/virtualMachine_output virtualMachine/virtualMachine.c
	@./virtualMachine/virtualMachine_output

clean:
	@rm tokeniser/tokeniser_output
	@rm translator/tokeniserOutput.txt
	@rm translator/translator_output
	@rm codeGenerator/translatorOutput.txt
	@rm codeGenerator/codeGenerator_output
	@rm virtualMachine/codeGeneratorOutput.txt
	@rm virtualMachine/virtualMachine_output
