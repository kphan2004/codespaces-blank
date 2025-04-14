.model medium
.stack 100h

.data

	Menu BYTE "1. Enter a string", newline,
			  "2. Convert to lowercase", newline,
			  "3. Remove all non-letter elements except numbers", newline,
			  "4. Display only the numbers in the string", newline,
			  "5. Display the string.", newline,
			  "6. Quit", newline,
			  "Enter choice: ", 0h
		userChoice BYTE ?
		inputString BYTE 51 DUP(0)
		stringEntered BYTE 0
	
.code
main PROC
	call Clrscr
mainMenu:
	mov edx, OFFSET menu
	call WriteString
	call ReadChar
	mov userChoice, al
	call Crlf
	
	cmp userChoice, '1'
	je getString
	cmp stringEntered, 0
	je stringMissing
	
	cmp userChoice, '2'
	je toLower
	cmp userChoice, '3'
	je removeNonLetters
	cmp userChoice, '4'
	je displayNumbers
	cmp userChoice, '5'
	je displayString
	cmp userChoice, '6'
	
	je exitProgram
	jmp invalidChoice
	
	
getString:
	mov edx, OFFSET inputString
	mov ecx, 50
	call ReadString
	mov stringEntered, 1
	jmp mainMenu
	
toLower:
	mov esi, OFFSET inputString
	call toLowerCase
	jmp mainMenu

removeNonLetters:
	mov esi, OFFSET inputString
	call RemoveNonLettersExceptDigits
	jmp mainMenu
	
displayNumbers:
	mov esi, OFFSET inputString
	call ShowOnlyNumbers
	jmp mainMenu

displayString:
	mov edx, OFFSET inputString
	call WriteString
	call Crlf
	jmp mainMenu
	
stringMissing:
	mov edx, OFFSET inputString
	call WriteString
	call Crlf
	jmp mainMenu
	
invalidChoice:
	mov edx, OFFSET msgInvalidChoice
	call WriteString
	call Crlf
	jmp mainMenu
	
exitProgram:
	call Crlf
	exit
	
main ENDP

toLowerCase PROC

nextChar:
	mov al, [esi]
	cmp al, 0
	je done
	cmp al, 'A'
	jb skip
	cmp al 'Z'
	ja skip
	add al, 32
	mov [esi], al
skip:
	inc esi
	jmp nextChar
done:
	ret
toLowerCase ENDP

RemoveNonLettersExceptDigits PROC
	push edi
	mov edi, esi 
CheckChar:
	mov al, [esi]
	cmp al, 0
	je finish
	
	cmp al, 'A'
	jb skip
	cmp al, 'Z'
	jbe save
	cmp al 'a'
	jb digitCheck
	cmp al, 'z'
	jbe save
	
digitCheck:
	cmp al, '0'
	jb skip
	cmp al, '9'
	jbe save
skip:
	inc esi
	jmp checkChar
save:
	mov [edi], al
	inc edi
	inc esi
	jmp checkChar
finish:
	mov BYTE ptr [edi], 0
	pop edi
	ret
RemoveNonLettersExceptDigits ENDP
